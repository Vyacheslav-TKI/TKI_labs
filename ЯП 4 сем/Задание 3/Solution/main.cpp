#include <iostream>
#include <vector>
#include <map>
#include <algorithm>   
#include <numeric>
#include <functional>   

int main() {
    
    std::vector<int> V = { 12, 25, 37, 42, 52, 67, 72, 85, 97, 102, 112, 125 };

    
    std::map<int, int> M;

    
    for (int digit = 0; digit <= 9; ++digit) {
        
        auto it_first = std::find_if(
            V.begin(), V.end(),
            [digit](int x) { return std::abs(x) % 10 == digit; }
        );

        
        if (it_first == V.end()) {
            
            continue;
        }

        
        auto it_sum_begin = std::next(it_first);
        if (it_sum_begin == V.end()) {
            M[digit] = 0;
        }
        else {
            
            int sum = std::accumulate(
                it_sum_begin, V.end(),
                0,
                [digit](int acc, int x) {
                    return acc + ((std::abs(x) % 10 == digit) ? x : 0);
                }
            );

            auto it_map = M.find(digit);
            if (it_map == M.end()) {
                M[digit] = sum;
            }
            else {
                it_map->second += sum;
            }
        }
    }


    std::for_each(
        M.begin(), M.end(),
        [](const std::pair<const int, int>& p) {
            std::cout << "Цифра " << p.first
                << " → сумма (без первого) = " << p.second << "\n";
        }
    );

    return 0;
}
