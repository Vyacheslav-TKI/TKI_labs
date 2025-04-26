#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>   
#include <functional> 


struct point {
    double x, y;

    friend std::istream& operator>>(std::istream& is, point& p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }

    bool operator<(const point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

int main() {
    const char* filename = "name";     
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Не удалось открыть файл " << filename << "\n";
        return 1;
    }


    std::vector<point> V;
    point p;
    while (fin >> p) {
        V.push_back(p);
    }


    point origin{ 0.0, 0.0 };


    using namespace std::placeholders;
    auto is_less_than_origin =
        std::bind(std::less<point>(), _1, origin);

    std::stable_partition(
        V.begin(), V.end(),
        is_less_than_origin
    );


    std::for_each(
        V.begin(), V.end(),
        [](const point& q) {
            std::cout << q << "\n";
        }
    );

    return 0;
}
