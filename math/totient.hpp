#pragma once
#include <cassert>
/**
 * n と互いに素な整数の個数を求める。
 * O(sqrt(N))
 */
template <typename Int> Int totient(Int n) {
    assert(n >= 1);
    Int ret = n;
    for (Int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret = ret / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ret = ret / n * (n - 1);
    return ret;
}