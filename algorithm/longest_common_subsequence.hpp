#pragma once

#include <string>
#include <vector>
#include <algorithm>

int longest_common_subsequence(const std::string& s, const std::string t) {
    int n = int(s.size()), m = int(t.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[n][m];
}

template <class T>
int longest_common_subsequence(const std::vector<T>& s,
                               const std::vector<T> t) {
    int n = int(s.size()), m = int(t.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[n][m];
}
