#include "LCS.h"
#include <algorithm>
#include <vector>

// Compute the longest Common Subsequence
std::string lcsFullTable(const std::string& x, const std::string& y) {
    int m = x.length();
    int n = y.length();
    
    // Create a table to store lengths of longest common subsequence of substrings
    std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1, 0));

    // Fill the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    // Backtrack to find the longest common subsequence
    std::string lcs;

    int i = m;
    int j = n;

    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs.push_back(x[i - 1]);
            i--;
            j--;
        } else if (c[i - 1][j] >= c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // The lcs is built in reverse order
    std::reverse(lcs.begin(), lcs.end());
    return lcs;

}

int lcsLengthTwoRows(const std::string& x, const std::string& y) {
    int m = x.length();
    int n = y.length();

    // Create two rows to store lengths of longest common subsequence of substrings
    std::vector<int> prev(n + 1, 0);
    std::vector<int> curr(n + 1, 0);

    // Fill the table using only two rows
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = std::max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
        std::fill(curr.begin(), curr.end(), 0);
    }

    return prev[n];
}