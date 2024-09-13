#pragma once

#include <cassert>

#include "mod/ModComb.hpp"

template <class mint> struct BinomialPrefixSum {
    int n, k;
    mint value;

    BinomialPrefixSum() : BinomialPrefixSum(0, 0) {
    }
    BinomialPrefixSum(int n_, int k_) : n(n_), k(k_), value(0) {
        assert(n >= 0);
        assert(0 <= k && k <= n);
        for (int i = 0; i <= k; i++) {
            value += ModComb<mint>::C(n, i);
        }
    }

    void increase_n() {
        value = value * 2 - ModComb<mint>::C(n, k);
        n++;
    }

    void decrease_n() {
        assert(n > 0);
        n--;
        value = (value + ModComb<mint>::C(n, k)) * ModComb<mint>::inv(2);
    }

    void increase_k() {
        assert(k < n);
        k++;
        value += ModComb<mint>::C(n, k);
    }

    void decrease_k() {
        assert(k > 0);
        value -= ModComb<mint>::C(n, k);
        k--;
    }

    void shift(int n_, int k_) {
        while (n < n_) increase_n();
        while (k < k_) increase_k();
        while (k > k_) decrease_k();
        while (n > n_) decrease_n();
    }
};