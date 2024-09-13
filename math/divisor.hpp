#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

// O(sqrt(n))
template <class T> std::vector<T> divisor(T x) {
    assert(x >= 1);
    std::vector<T> ret;
    for (T i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ret.emplace_back(i);
            ret.emplace_back(x / i);
        }
    }
    std::sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}