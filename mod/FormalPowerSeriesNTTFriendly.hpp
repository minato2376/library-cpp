#pragma once

#include <iostream>
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

#include <atcoder/convolution>

template <typename M, int SPARSE = 10>
struct FormalPowerSeriesNTTFriendly : std::vector<M> {
    using std::vector<M>::vector;
    using FPS = FormalPowerSeriesNTTFriendly;

    FPS static read(int n) {
        FPS ret(n);
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            ret[i] = x;
        }
        return ret;
    }

    M freq(int p) const {
        return p < (int)this->size() ? (*this)[p] : M(0);
    }

    void shrink() {
        while (!this->empty() and this->back().val() == 0) this->pop_back();
    }

    FPS pre(int le) const {
        return FPS(this->begin(),
                   this->begin() + std::min((int)this->size(), le));
    }

    FPS rev() const {
        FPS ret(*this);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    int count_nonzero() const {
        return std::count_if(this->begin(), this->end(),
                             [](M x) { return x.val() != 0; });
    }

    std::vector<std::pair<int, M>> get_sparse() const {
        std::vector<std::pair<int, M>> ret;
        for (size_t i = 0; i < this->size(); i++) {
            if ((*this)[i].val() != 0) ret.emplace_back(i, (*this)[i]);
        }
        return ret;
    }

    FPS operator>>(int s) const {
        if ((int)this->size() <= s) return {};
        return FPS(this->begin() + s, this->end());
    }

    FPS operator<<(int s) const {
        if (this->empty()) return {};
        FPS ret(*this);
        ret.insert(ret.begin(), s, M(0));
        return ret;
    }

    FPS& operator+=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (size_t i = 0; i < r.size(); i++) (*this)[i] += r[i];
        shrink();
        return *this;
    }

    FPS& operator+=(const M& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] += v;
        shrink();
        return *this;
    }

    FPS& operator-=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < int(r.size()); i++) (*this)[i] -= r[i];
        shrink();
        return *this;
    }

    FPS& operator-=(const M& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= v;
        shrink();
        return *this;
    }

    FPS& operator*=(const FPS& r) {
        const int z = r.count_nonzero();
        if (z == 0) {
            this->clear();
            return *this;
        }
        if (z <= SPARSE) {
            auto sparse = r.get_sparse();
            return *this *= sparse;
        }
        auto res = atcoder::convolution(*this, r);
        return *this = {res.begin(), res.end()};
    }

    FPS& operator*=(const M& v) {
        for (auto& x : (*this)) x *= v;
        shrink();
        return *this;
    }

    FPS& operator*=(const std::vector<std::pair<int, M>>& r) {
        assert(!r.empty());
        const int m = r.back().first;
        FPS ret(this->size() + m);
        for (int i = 0; i < (int)this->size(); i++) {
            for (const auto& [j, c] : r) {
                ret[i + j] += (*this)[i] * c;
            }
        }
        ret.shrink();
        return *this = ret;
    }

    FPS& operator/=(const FPS& r) {
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        const int z = r.count_nonzero();
        assert(z != 0);
        if (z <= SPARSE) {
            auto sparse = r.get_sparse();
            return *this /= sparse;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();
    }

    FPS& operator/=(const M& v) {
        assert(v.val() != 0);
        auto vinv = v.inv();
        for (auto& x : (*this)) x *= vinv;
        return *this;
    }

    FPS& operator/=(const std::vector<std::pair<int, M>>& r) {
        assert(!r.empty());
        auto [j0, c0] = r.front();
        assert(j0 == 0 && c0.val() != 0);
        auto ic = c0.inv();
        FPS ret(this->size());
        for (int i = 0; i < (int)this->size(); i++) {
            for (const auto& [j, c] : r) {
                if (j >= 1 && j <= i) {
                    ret[i] -= ret[i - j] * c;
                }
            }
            ret[i] += (*this)[i];
            ret[i] *= ic;
        }
        ret.shrink();
        return *this = ret;
    }

    FPS& operator%=(const FPS& r) {
        *this -= *this / r * r;
        shrink();
        return *this;
    }

    FPS operator+(const FPS& r) const {
        return FPS(*this) += r;
    }

    FPS operator+(const M& v) const {
        return FPS(*this) += v;
    }

    FPS operator-(const FPS& r) const {
        return FPS(*this) -= r;
    }

    FPS operator-(const M& v) const {
        return FPS(*this) -= v;
    }

    FPS operator*(const FPS& r) const {
        return FPS(*this) *= r;
    }

    FPS operator*(const M& v) const {
        return FPS(*this) *= v;
    }

    FPS operator/(const FPS& r) const {
        return FPS(*this) /= r;
    }

    FPS operator%(const FPS& r) const {
        return FPS(*this) %= r;
    }

    FPS operator-() const {
        FPS ret = *this;
        for (auto& v : ret) v = -v;
        return ret;
    }

    FPS differential() const {
        const int n = (int)this->size();
        FPS ret(std::max(0, n - 1));
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * M(i);
        return ret;
    }

    FPS integral() const {
        const int n = (int)this->size();
        FPS ret(n + 1);
        ret[0] = M(0);
        if (n > 0) ret[1] = M(1);
        auto mod = M::mod();
        for (int i = 2; i <= n; i++) ret[i] = -ret[mod % i] * (mod / i);
        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];
        return ret;
    }

    FPS inv(int deg = -1) const {
        assert((*this)[0] != M(0));
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        FPS ret{(*this)[0].inv()};
        ret.reserve(deg);
        for (int d = 1; d < deg; d <<= 1) {
            FPS f(d << 1), g(d << 1);
            std::copy(this->begin(), this->begin() + std::min(n, d << 1),
                      f.begin());
            std::copy(ret.begin(), ret.end(), g.begin());
            atcoder::internal::butterfly(f);
            atcoder::internal::butterfly(g);
            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];
            atcoder::internal::butterfly_inv(f);
            std::fill(f.begin(), f.begin() + d, M(0));
            atcoder::internal::butterfly(f);
            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];
            atcoder::internal::butterfly_inv(f);
            M iz = M(d << 1).inv();
            iz *= -iz;
            for (int i = d; i < std::min(d << 1, deg); i++)
                ret.push_back(f[i] * iz);
        }
        return ret.pre(deg);
    }

    FPS log(int deg = -1) const {
        assert((*this)[0] == M(1));
        if (deg == -1) deg = (int)this->size();
        return (differential() * inv(deg)).pre(deg - 1).integral();
    }

    FPS sqrt(const std::function<M(M)>& get_sqrt, int deg = -1) const {
        const int n = this->size();
        if (deg == -1) deg = n;
        if (this->empty()) return FPS(deg, 0);
        if ((*this)[0] == M(0)) {
            for (int i = 1; i < n; i++) {
                if ((*this)[i] != M(0)) {
                    if (i & 1) return {};
                    if (deg - i / 2 <= 0) break;
                    auto ret = (*this >> i).sqrt(get_sqrt, deg - i / 2);
                    if (ret.empty()) return {};
                    ret = ret << (i / 2);
                    if ((int)ret.size() < deg) ret.resize(deg, M(0));
                    return ret;
                }
            }
            return FPS(deg, M(0));
        }
        auto sqrtf0 = M(get_sqrt((*this)[0]));
        if (sqrtf0 * sqrtf0 != (*this)[0]) return {};
        FPS ret{sqrtf0};
        M inv2 = M(2).inv();
        for (int i = 1; i < deg; i <<= 1)
            ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
        return ret.pre(deg);
    }

    FPS exp(int deg = -1) const {
        assert(this->empty() or (*this)[0] == M(0));
        if (this->size() <= 1) return {M(1)};
        if (deg == -1) deg = (int)this->size();
        FPS inv;
        inv.reserve(deg + 1);
        inv.push_back(M(0));
        inv.push_back(M(1));
        auto inplace_integral = [&](FPS& F) -> void {
            const int n = (int)F.size();
            auto mod = M::mod();
            while ((int)inv.size() <= n) {
                int i = inv.size();
                inv.push_back(-inv[mod % i] * (mod / i));
            }
            F.insert(F.begin(), M(0));
            for (int i = 1; i <= n; i++) F[i] *= inv[i];
        };
        auto inplace_differential = [](FPS& F) -> void {
            if (F.empty()) return;
            F.erase(F.begin());
            for (size_t i = 0; i < F.size(); i++) F[i] *= M(i + 1);
        };
        FPS f{1, (*this)[1]}, g{M(1)}, g_fft{M(1), M(1)};
        for (int m = 2; m < deg; m <<= 1) {
            const M iz1 = M(m).inv(), iz2 = M(m << 1).inv();
            auto f_fft = f;
            f_fft.resize(m << 1);
            atcoder::internal::butterfly(f_fft);
            {
                FPS _g(m);
                for (int i = 0; i < m; i++) _g[i] = f_fft[i] * g_fft[i];
                atcoder::internal::butterfly_inv(_g);
                std::fill(_g.begin(), _g.begin() + (m >> 1), M(0));
                atcoder::internal::butterfly(_g);
                for (int i = 0; i < m; i++) _g[i] *= -g_fft[i] * iz1 * iz1;
                atcoder::internal::butterfly_inv(_g);
                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());

                g_fft = g;
                g_fft.resize(m << 1);
                atcoder::internal::butterfly(g_fft);
            }
            FPS x(this->begin(),
                  this->begin() + std::min((int)this->size(), m));
            {
                x.resize(m);
                inplace_differential(x);
                x.push_back(M(0));
                atcoder::internal::butterfly(x);
            }
            {
                for (int i = 0; i < m; i++) x[i] *= f_fft[i] * iz1;
                atcoder::internal::butterfly_inv(x);
            }
            {
                x -= f.differential();
                x.resize(m << 1);
                for (int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = M(0);
                atcoder::internal::butterfly(x);
                for (int i = 0; i < (m << 1); i++) x[i] *= g_fft[i] * iz2;
                atcoder::internal::butterfly_inv(x);
            }
            {
                x.pop_back();
                inplace_integral(x);
                for (int i = m; i < std::min((int)this->size(), m << 1); i++)
                    x[i] += (*this)[i];
                std::fill(x.begin(), x.begin() + m, M(0));
            }
            {
                atcoder::internal::butterfly(x);
                for (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;
                atcoder::internal::butterfly_inv(x);
                f.insert(f.end(), x.begin() + m, x.end());
            }
        }
        return FPS{f.begin(), f.begin() + deg};
    }

    FPS pow(int64_t k, int deg = -1) const {
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        if (k == 0) {
            auto res = FPS(deg, M(0));
            res[0] = M(1);
            return res;
        }
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != M(0)) {
                if (i >= (deg + k - 1) / k) return FPS(deg, M(0));
                M rev = (*this)[i].inv();
                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg) *
                          ((*this)[i].pow(k));
                ret = (ret << (i * k)).pre(deg);
                if ((int)ret.size() < deg) ret.resize(deg, M(0));
                return ret;
            }
        }
        return FPS(deg, M(0));
    }

    M eval(M x) const {
        M ret = 0, w = 1;
        for (const auto& v : *this) ret += w * v, w *= x;
        return ret;
    }
};

template <class M, int SPARSE>
void print(const FormalPowerSeriesNTTFriendly<M, SPARSE>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i) std::cout << " ";
        std::cout << v[i].val();
    }
    cout << "\n";
}