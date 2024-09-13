#pragma once

#include <cassert>
#include <vector>

template <class M> struct ModCombination {
  public:
    ModCombination() {
    }
    ModCombination(int n) : n_(n), fac_(n + 1), facinv_(n + 1) {
        assert(1 <= n);
        fac_[0] = 1;
        for (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;
        facinv_[n] = M(1) / fac_[n];
        for (int i = n; i >= 1; i--) facinv_[i - 1] = facinv_[i] * i;
    }

    M fac(int k) const {
        assert(0 <= k and k <= n_);
        return fac_[k];
    }
    M facinv(int k) const {
        assert(0 <= k and k <= n_);
        return facinv_[k];
    }
    M inv(int k) const {
        assert(1 <= k and k <= n_);
        return facinv_[k] * fac_[k - 1];
    }

    M P(int n, int k) const {
        if (k < 0 or k > n) return M(0);
        assert(n <= n_);
        return fac_[n] * facinv_[n - k];
    }
    M C(int n, int k) const {
        if (k < 0 or k > n) return M(0);
        assert(n <= n_);
        return fac_[n] * facinv_[n - k] * facinv_[k];
    }

    /**
     * @note H(n, k) = (n 個 のボールを k 個の箱に分ける方法の数)
     * @note H(n, k) = C(n + k - 1, n)
     * @note H(n, k) = [x ^ n] (1 / (1 - x) ^ k)
     */
    M H(int n, int k) const {
        if (n == 0 and k == 0) return M(1);
        return C(n + k - 1, n);
    }
    M catalan(int n) const {
        if (n == 0) return M(1);
        return C(2 * n, n) - C(2 * n, n - 1);
    }

  private:
    int n_;
    std::vector<M> fac_, facinv_;
};