#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>


/**
* @brief Точка входа в программу
*/
int main() {
    std::string filename;
    std::cin >> filename;

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

    std::ostream_iterator<char> outIter(outFile, " ");
    std::copy(std::istream_iterator<char>(std::cin),
        std::istream_iterator<char>(),
        outIter);

    outFile.close();
    return 0;
}