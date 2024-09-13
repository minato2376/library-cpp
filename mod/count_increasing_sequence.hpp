#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "mod/ModComb.hpp"

template <class mint, class FPS>
FPS left_to_up(int Amax, int width, const FPS& left) {
    if (Amax == 0) return {left.freq(0)};
    FPS X(Amax);
    for (int i = 0; i < Amax; i++) {
        X[i] = left.freq(i) * ModComb<mint>::facinv(Amax - 1 - i);
    }
    FPS Y(Amax + width - 1);
    for (int i = 0; i < Amax + width - 1; i++) {
        Y[i] = ModComb<mint>::fac(i);
    }
    auto Z = X * Y;

    FPS ret(width);
    for (int i = 0; i < width; i++) {
        ret[i] = Z.freq(i + Amax - 1) * ModComb<mint>::facinv(i);
    }

    ret[0] += left.freq(Amax);
    return ret;
}

template <class mint, class FPS>
FPS left_to_right(int Amax, int width, const FPS& left) {
    FPS X(Amax);
    for (int i = 0; i < Amax; i++) X[i] = left.freq(i);
    FPS Y(Amax);
    for (int i = 0; i < Amax; i++)
        Y[i] = ModComb<mint>::C(i + width - 1, width - 1);
    auto Z = X * Y;
    if (int(Z.size()) > Amax) Z.resize(Amax);
    return Z;
}

template <class mint, class FPS>
FPS down_to_up(int Amax, int width, const FPS& down) {
    if (Amax == 0) return down;
    FPS Y(width);
    for (int i = 0; i < width; i++) {
        Y[i] = ModComb<mint>::C(i + Amax - 1, Amax - 1);
    }
    auto Z = down * Y;
    if (int(Z.size()) > width) Z.resize(width);
    return Z;
}

template <class mint, class FPS>
FPS down_to_right(int Amax, int width, const FPS& down) {
    FPS X(width);
    for (int i = 0; i < width; i++) {
        X[i] = down.freq(i) * ModComb<mint>::facinv(width - 1 - i);
    }
    FPS Y(Amax + width - 1);
    for (int i = 0; i < Amax + width - 1; i++) {
        Y[i] = ModComb<mint>::fac(i);
    }
    auto Z = X * Y;

    FPS ret(Amax);
    for (int i = 0; i < Amax; i++) {
        ret[i] = Z.freq(i + width - 1) * ModComb<mint>::facinv(i);
    }
    return ret;
}

template <class mint, class FPS>
FPS rec_count_increasing_sequence(const std::vector<int>& A, const FPS& down) {
    int n = A.size();
    if (n == 1) {
        FPS ret(A.front() + 1, down.freq(0));
        return ret;
    }
    int m = n / 2;
    FPS left_down(m);
    for (int i = 0; i < m; i++) left_down[i] = down.freq(i);
    FPS right_down(n - m);
    for (int i = 0; i < n - m; i++) right_down[i] = down.freq(m + i);

    FPS left = rec_count_increasing_sequence<mint, FPS>(
        std::vector<int>(A.begin(), A.begin() + m), left_down);

    auto up1 = left_to_up<mint, FPS>(A[m - 1], n - m, left);
    auto right1 = left_to_right<mint, FPS>(A[m - 1], n - m, left);
    auto up2 = down_to_up<mint, FPS>(A[m - 1], n - m, right_down);
    auto right2 = down_to_right<mint, FPS>(A[m - 1], n - m, right_down);

    for (int i = 0; i < n - m; i++) right_down[i] = up1.freq(i) + up2.freq(i);

    std::vector<int> right_A(n - m);
    for (int i = 0; i < n - m; i++) right_A[i] = A[m + i] - A[m - 1];

    auto right_result =
        rec_count_increasing_sequence<mint, FPS>(right_A, right_down);

    FPS ret(A.back() + 1);
    for (int i = 0; i < A[m - 1]; i++) {
        ret[i] = right1.freq(i) + right2.freq(i);
    }
    for (int i = A[m - 1]; i <= A.back(); i++) {
        ret[i] = right_result.freq(i - A[m - 1]);
    }

    return ret;
}

/**
 * 配列のサイズを N , Amax = M として、
 * O((N + M) * log(N + M) ^ 2)
 */
template <class mint, class FPS>
FPS count_increasing_sequence(const std::vector<int>& A) {
    assert(!A.empty());
    assert(is_sorted(A.begin(), A.end()));
    FPS down(1, mint(1));
    return rec_count_increasing_sequence<mint, FPS>(A, down);
}