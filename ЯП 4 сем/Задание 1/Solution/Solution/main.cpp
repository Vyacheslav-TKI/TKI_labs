#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>


/**
* @brief ����� ����� � ���������
*/
int main() {
    std::string filename;
    std::cin >> filename;

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "������ ��� �������� �����!" << std::endl;
        return 1;
    }

    std::ostream_iterator<char> outIter(outFile, " ");
    std::copy(std::istream_iterator<char>(std::cin),
        std::istream_iterator<char>(),
        outIter);

    outFile.close();
    return 0;
}