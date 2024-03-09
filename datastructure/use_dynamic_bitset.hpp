#pragma once

#include <algorithm>
#include <bitset>
#include <cassert>

/**
 * example:
 *  auto f = [&](auto _) {
 *      using DynamicBitset = decltype(_);
 *      ...
 *  };
 *  use_dynamic_bitset<1000000>(n, f);
 */
template <int MAX_N, class F, int N = 1>
void use_dynamic_bitset(int n, const F& f) {
    assert(n <= MAX_N);
    if (n <= N) {
        std::bitset<N> bs;
        f(bs);
        return;
    }
    use_dynamic_bitset<MAX_N, F, std::min(N * 2, MAX_N)>(n, f);
}