#pragma once

#include "mod/berlekamp_massey.hpp"
#include "mod/bostan_mori.hpp"

#include <atcoder/convolution>
#include <vector>

template <class mint> mint kth_term(std::vector<mint> a, long long N) {
    std::vector<mint> c = berlekamp_massey(a);
    auto b = convolution(a, c);
    b.resize(c.size() - 1);
    return bostan_mori<mint>(b, c, N);
}