#include "FileUtils.h"
#include <fstream>
#include <iostream>

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