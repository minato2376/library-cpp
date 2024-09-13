#pragma once

#include <cassert>
#include <vector>

#include <atcoder/convolution>

/**
 * @brief Bostan-Mori Algorithm
 *
 */
template <class mint>
mint bostan_mori(std::vector<mint> P, std::vector<mint> Q, long long N) {
    assert(Q[0] == 1);
    assert(P.size() < Q.size());
    int D = Q.size();
    while (N) {
        auto Q_neg = Q;
        for (int i = 1; i < int(Q.size()); i += 2) Q_neg[i] *= -1;
        P = atcoder::convolution(P, Q_neg);
        Q = atcoder::convolution(Q, Q_neg);
        for (int i = N & 1; i < int(P.size()); i += 2) P[i >> 1] = P[i];
        for (int i = 0; i < int(Q.size()); i += 2) Q[i >> 1] = Q[i];
        P.resize(D - 1);
        Q.resize(D);
        N >>= 1;
    }
    return P[0];
}
