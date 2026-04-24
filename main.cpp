#include <iostream>
#include <vector>
#include <iomanip>
#include "FileUtils.h"
#include "LCS.h"
#include "Similarity.h"

void printSimilarityTable(const std::vector<std::string>& strings) {
    int count = strings.size();

    std::cout << "\nSimilarity Table:\n\n";

    // Print column names
    std::cout << "   ";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(2) << std::setfill('0') << i + 1 << " ";
    }
    std::cout << std::setfill(' ') << std::endl;

    // Rows
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(2) << std::setfill('0') << i + 1 << " ";
        std::cout << std::setfill(' ');

        for (int j = 0; j < count; j++) {
            if (j <= i) {
                std::cout << " - ";
            } else {
                std::cout << " " << classifySimilarity(strings[i], strings[j]) << " ";
            }
        }

        std::cout << std::endl;
    }
}


int main() {
    std::string a, b;

    if (!readTwoStrings("twoStrings.txt", a, b)) {
        std::cerr << "Failed to read twoStrings.txt" << std::endl;
        return 1;
    }

    // Compute the longest common subsequence
    std::string lcs = lcsFullTable(a, b);

    // Output the longest common subsequence
    std::cout << "First string: " << a << std::endl;
    std::cout << "Second string: " << b << std::endl;
    std::cout << "LCS: " << lcs << std::endl;
    std::cout << "LCS length: " << lcs.length() << std::endl;

    std::vector<std::string> strings;

    if (!readMultiStrings("multiStrings.txt", strings)) {
        std::cerr << "Failed to read multiStrings.txt" << std::endl;
        return 1;
    }

    printSimilarityTable(strings);

    return 0;
}