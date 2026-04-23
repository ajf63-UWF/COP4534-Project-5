#include <iostream>
#include "FileUtils.h"

int main() {
    std:: string a, b;

    if (readTwoStrings("twoStrings.txt", a, b)) {
        std::cout << "First string: " << a << std::endl;
        std::cout << "Second string: " << b << std::endl;
    } else {
        std::cerr << "Failed to read file." << std::endl;
    }

    return 0;
}