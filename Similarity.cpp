#include "Similarity.h"
#include "LCS.h"
#include <algorithm>

char classifySimilarity(const std::string& a, const std::string& b) {
    int lenA = a.length();
    int lenB = b.length();

    int shorter = std::min(lenA, lenB);
    int longer = std::max(lenA, lenB);

    int lcsLength = lcsLengthTwoRows(a, b);

    if (shorter == 0) {
        return longer == 0 ? 'H' : 'D';
    }

    if (shorter >= 0.90 * longer && lcsLength >= 0.90 * shorter) {
        return 'H';
    }

    if (shorter >= 0.80 * longer && lcsLength >= 0.80 * shorter) {
        return 'M';
    }

    if (shorter >= 0.60 * longer && lcsLength >= 0.50 * shorter) {
        return 'L';
    }

    return 'D';
}