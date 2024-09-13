#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
#include <numeric>

/**
 * * * * | * * *
 * * 7 * 6 * 5 *
 * * * * | * * *
 * --8---4---4--
 * * * * | * * *
 * * 1 * 2 * 3 *
 * * * * | * * *
 */
template <class T>
std::vector<int> arg_sort(const std::vector<T>& X, const std::vector<T>& Y) {
    assert(X.size() == Y.size());
    int n = X.size();

    std::vector<int> ids(n), pos(n);
    std::iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < n; i++) {
        if (Y[i] < 0)
            pos[i] = -1;
        else if (Y[i] == 0 and 0 <= X[i])
            pos[i] = 0;
        else
            pos[i] = 1;
    }

    std::sort(ids.begin(), ids.end(), [&](int i, int j) {
        if (pos[i] != pos[j]) return pos[i] < pos[j];
        if ((long long)X[i] * Y[j] != (long long)X[j] * Y[i])
            return (long long)X[i] * Y[j] < (long long)X[j] * Y[i];
        return (long long)X[i] * X[i] + (long long)Y[i] * Y[i] <
               (long long)X[j] * X[j] + (long long)Y[j] * Y[j];
    });
    return ids;
}