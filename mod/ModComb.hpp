#pragma once

#include <algorithm>
#include <vector>

template <class mint> struct ModComb {
    static int n;
    static std::vector<mint> fac_, facinv_;

    static void init(int n_ = 1000000) {
        n = n_;
        fac_.resize(n + 1);
        facinv_.resize(n + 1);
        fac_[0] = 1;
        for (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;
        facinv_[n] = mint(1) / fac_[n];
        for (int i = n; i >= 1; i--) facinv_[i - 1] = facinv_[i] * i;
    }

    static void resize(int m) {
        if (m <= n) return;
        if (n == -1) {
            init(m);
            return;
        }
        m = std::max(m, 2 * n);
        fac_.resize(m + 1);
        facinv_.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            fac_[i] = fac_[i - 1] * i;
        }
        facinv_[m] = mint(1) / fac_[m];
        for (int i = m - 1; i >= n; i--) {
            facinv_[i] = facinv_[i + 1] * (i + 1);
        }
        n = m;
    }

    static mint fac(int k) {
        resize(k);
        return fac_[k];
    }
    static mint facinv(int k) {
        resize(k);
        return facinv_[k];
    }
    static mint inv(int k) {
        resize(k);
        return facinv_[k] * fac_[k - 1];
    }

    static mint P(int n, int k) {
        if (k < 0 or k > n) return mint(0);
        resize(n);
        return fac_[n] * facinv_[n - k];
    }
    static mint C(int n, int k) {
        if (k < 0 or k > n) return mint(0);
        resize(n);
        return fac_[n] * facinv_[n - k] * facinv_[k];
    }

    /**
     * @note H(n, k) = (n 個 のボールを k 個の箱に分ける方法の数)
     * @note H(n, k) = C(n + k - 1, n)
     * @note H(n, k) = [x ^ n] (1 / (1 - x) ^ k)
     */
    static mint H(int n, int k) {
        if (n == 0 and k == 0) return mint(1);
        return C(n + k - 1, n);
    }
    static mint catalan(int n) {
        if (n == 0) return mint(1);
        return C(2 * n, n) - C(2 * n, n - 1);
    }
};

template <class mint> int ModComb<mint>::n = -1;
template <class mint> std::vector<mint> ModComb<mint>::fac_;
template <class mint> std::vector<mint> ModComb<mint>::facinv_;