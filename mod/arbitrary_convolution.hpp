#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include <atcoder/convolution>

namespace arbitrary_convolution {

template <class T>
std::vector<int> convolution_medium(const std::vector<T>& a,
                                    const std::vector<T>& b,
                                    const int mod) {
    static constexpr int m0 = 1045430273;
    static constexpr int m1 = 1051721729;
    static constexpr int m2 = 1053818881;
    static constexpr int r01 = 175287122;  // mint1(m0).inv()
    static constexpr int r02 = 395182206;  // mint2(m0).inv()
    static constexpr int r12 = 526909943;  // mint2(m1).inv()
    static constexpr int r02r12 = (long long)(r02)*r12 % m2;
    static constexpr long long w1 = m0;
    static constexpr long long w2 = (long long)(m0)*m1;

    const int n = int(a.size()), m = int(b.size());

    std::vector<T> v0 = atcoder::convolution<m0>(a, b);
    std::vector<T> v1 = atcoder::convolution<m1>(a, b);
    std::vector<T> v2 = atcoder::convolution<m2>(a, b);
    std::vector<int> ret(n + m - 1);

    const int W1 = w1 % mod;
    const int W2 = w2 % mod;
    for (int i = 0; i < n + m - 1; i++) {
        int n1 = v1[i], n2 = v2[i], x = v0[i];
        int y = (long long)(n1 + m1 - x) * r01 % m1;
        int z =
            ((long long)(n2 + m2 - x) * r02r12 + (long long)(m2 - y) * r12) %
            m2;
        ret[i] = ((long long)(x) + (long long)(y)*W1 + (long long)(z)*W2) % mod;
    }

    return ret;
}

template <class T>
std::vector<int> convolution_large(const std::vector<T>& a,
                                   const std::vector<T>& b,
                                   const int mod) {
    static constexpr int m0 = 167772161;
    static constexpr int m1 = 469762049;
    static constexpr int m2 = 754974721;
    static constexpr int r01 = 104391568;  // mint1(m0).inv()
    static constexpr int r02 = 323560596;  // mint2(m0).inv()
    static constexpr int r12 = 399692502;  // mint2(m1).inv()
    static constexpr int r02r12 = (long long)(r02)*r12 % m2;
    static constexpr long long w1 = m0;
    static constexpr long long w2 = (long long)(m0)*m1;

    const int n = int(a.size()), m = int(b.size());

    std::vector<T> v0 = atcoder::convolution<m0>(a, b);
    std::vector<T> v1 = atcoder::convolution<m1>(a, b);
    std::vector<T> v2 = atcoder::convolution<m2>(a, b);
    std::vector<int> ret(n + m - 1);

    const int W1 = w1 % mod;
    const int W2 = w2 % mod;
    for (int i = 0; i < n + m - 1; i++) {
        int n1 = v1[i], n2 = v2[i], x = v0[i];
        int y = (long long)(n1 + m1 - x) * r01 % m1;
        int z =
            ((long long)(n2 + m2 - x) * r02r12 + (long long)(m2 - y) * r12) %
            m2;
        ret[i] = ((long long)(x) + (long long)(y)*W1 + (long long)(z)*W2) % mod;
    }

    return ret;
}

template <class mint,
          int SMALL = 1 << 7,
          int MEDIUM = 1 << 20,
          int LARGE = 1 << 24>
std::vector<mint> multiply(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n or !m) return {};
    if (std::min(n, m) <= SMALL) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ret(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i + j] += a[i] * b[j];
            }
        }
        return ret;
    }
    std::vector<int> a_(n), b_(m);
    for (int i = 0; i < n; i++) a_[i] = a[i].val();
    for (int i = 0; i < m; i++) b_[i] = b[i].val();
    std::vector<int> c;
    if (n + m - 1 <= MEDIUM) {
        c = convolution_medium<int>(a_, b_, mint::mod());
    } else if (n + m - 1 <= LARGE) {
        c = convolution_large<int>(a_, b_, mint::mod());
    } else {
        assert(false && "size is too large");
    }
    std::vector<mint> ret(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) ret[i] = mint::raw(c[i]);
    return ret;
}
}  // namespace arbitrary_convolution