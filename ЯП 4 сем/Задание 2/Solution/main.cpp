#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>
#include <list>
#include <iterator>

/**
* @brief Функция для удвоения элементов в контейнере
*/
template <typename Container>
void doubleElements(Container& container) {
    if (container.size() < 3 || container.size() % 2 == 0) {
        throw std::invalid_argument("Контейнер должен иметь больше 3 элементов и нечетный размер.");
    }

    
    container.front() *= 2;

    
    auto middleIndex = container.size() / 2;
    auto it = container.begin();
    std::advance(it, middleIndex);
    (*it) *= 2;

    
    container.back() *= 2;
}

/**
* @brief Точка входа в программу
*/
int main() {
    
    std::vector<int> V = { 1, 2, 3, 4, 5 };
    std::deque<int> D = { 6, 7, 8, 9, 10 };
    std::list<int> L = { 11, 12, 13, 14, 15 };

    doubleElements(V);
    doubleElements(D);
    doubleElements(L);

    
    std::cout << "Вектор: ";
    for (int v : V) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "Дек: ";
    for (int d : D) std::cout << d << " ";
    std::cout << std::endl;

    std::cout << "Список: ";
    for (int l : L) std::cout << l << " ";
    std::cout << std::endl;

    return 0;
}