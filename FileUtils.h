#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <vector>

bool readTwoStrings(const std::string& filename, std::string& str1, std::string& str2);

bool readMultiStrings(const std::string& filename, std::vector<std::string>& strings);

#endif // FILEUTILS_H