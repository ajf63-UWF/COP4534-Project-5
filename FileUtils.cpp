#include "FileUtils.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>

bool readTwoStrings( const std::string& filename, std::string& str1, std::string& str2) {
    std::ifstream inFile(filename);

    // Check if file opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // Read first line
    if (!std::getline(inFile, str1)) {
        std::cerr << "Error: Could not read first string from file " << filename << std::endl;
        return false;
    }

    // Read second line
    if (!std::getline(inFile, str2)) {
        std::cerr << "Error: Could not read second string from file " << filename << std::endl;
        return false;
    }

    inFile.close();
    return true;
}

bool readMultiStrings(const std::string& filename, std::vector<std::string>& strings) {
    std::ifstream inFile(filename);

    // Check if file opened right
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    int count;

    // Read the number of strings
    if (!(inFile >> count)) {
        std::cerr << "Error: Could not read the number of strings from file " << filename << std::endl;
        return false;
    }

    strings.clear();

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string line;

    // Read each string line by line
    for (int i = 0; i < count; ++i) {
        if (!std::getline(inFile, line)) {
            std::cerr << "Error: Could not read string " << (i + 1) << " from file " << filename << std::endl;
            return false;
        }
        strings.push_back(line);
    }

    inFile.close();
    return true;
}