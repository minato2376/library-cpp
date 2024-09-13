#pragma once

#include <vector>
#include <algorithm>

template <typename T, bool STRICT = false>
int longest_increasing_subsequence(const std::vector<T>& a) {
    std::vector<T> dp;
    dp.reserve(a.size());
    for (const auto& x : a) {
        auto it = STRICT ? std::upper_bound(dp.begin(), dp.end(), x)
                         : std::lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    return dp.size();
}