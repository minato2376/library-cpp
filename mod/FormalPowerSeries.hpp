#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

template <class mint,
          std::vector<mint> (*convolution)(std::vector<mint>,
                                           std::vector<mint>),
          void (*butterfly)(std::vector<mint>&),
          void (*butterfly_inv)(std::vector<mint>&),
          int SPARSE = 10>
struct FormalPowerSeries {
    using FPS = FormalPowerSeries;
    std::vector<mint> v;

    template <class T>
    FormalPowerSeries(const std::vector<T>& v_) : v(v_.begin(), v_.end()) {
        shrink();
    }
    void shrink() {
        while (!v.empty() && v.back() == 0) v.pop_back();
    }

    int size() const {
        return int(v.size());
    }

    bool empty() const {
        return v.empty();
    }

    mint freq(int p) const {
        return (p < size()) ? v[p] : mint(0);
    }

    const mint& operator[](int i) const {
        assert(0 <= i && i < size());
        return v[i];
    }

    mint& operator[](int i) {
        assert(0 <= i && i < size());
        return v[i];
    }

    int count_nonzero() const {
        return std::count_if(v.begin(), v.end(), [](mint x) { return x != 0; });
    }

    std::vector<std::pair<int, mint>> get_sparse() const {
        std::vector<std::pair<int, mint>> ret;
        for (int i = 0; i < size(); i++) {
            if (v[i] != 0) ret.emplace_back(i, v[i]);
        }
        return ret;
    }

    FPS operator+(const FPS& r) const {
        int n = std::max(size(), r.size());
        std::vector ret(n);
        for (int i = 0; i < n; i++) ret[i] = freq(i) + r.freq(i);
        return ret;
    }
    FPS operator-(const FPS& r) const {
        int n = std::max(size(), r.size());
        std::vector ret(n);
        for (int i = 0; i < n; i++) ret[i] = freq(i) - r.freq(i);
        return ret;
    }
    FPS operator*(const FPS& r) const {
        int count_nonzero = r.count_nonzero();
        if (count_nonzero == 0) return std::vector<mint>();
        if (count_nonzero <= SPARSE) {
            std::vector<std::pair<int, mint>> vr = r.get_sparse();
            return *this * vr;
        }
        return convolution(v, r.v);
    }
    FPS operator*(const mint& r) const {
        std::vector<mint> ret(size());
        for (int i = 0; i < size(); i++) ret[i] = v[i] * r;
        return ret;
    }
    FPS operator*(const std::vector<std::pair<int, mint>>& r) const {
        assert(!r.empty());
        int m = r.back().first;
        std::vector<mint> ret(size() + m);
        for (int i = 0; i < size(); i++) {
            for (auto& e : r) {
                ret[i + e.first] += v[i] * e.second;
            }
        }
        return ret;
    }
    FPS& operator+=(const FPS& r) {
        return *this = *this + r;
    }
    FPS& operator-=(const FPS& r) {
        return *this = *this - r;
    }
    FPS& operator*=(const FPS& r) {
        return *this = *this * r;
    }
    FPS& operator*=(const mint& r) {
        return *this = *this * r;
    }
    FPS& operator*=(const std::vector<std::pair<int, mint>>& r) {
        return *this = *this * r;
    }

    FPS pre(int le) const {
        return std::vector<mint>(v.begin(), v.begin() + min(size(), le));
    }

    FPS inv(int deg = -1) const {
        assert(freq(0) != 0);
        const int n = size();
        if (deg == -1) deg = n;
        std::vector<mint> ret = {freq(0).inv()};
        ret.reserve(deg);
        for (int d = 1; d < deg; d <<= 1) {
            std::vector<mint> f(d << 1), g(d << 1);
            std::copy(v.begin(), v.begin() + std::min(n, d << 1), f.begin());
            std::copy(ret.begin(), ret.end(), g.begin());
            butterfly(f);
            butterfly(g);
            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];
            butterfly_inv(f);
            std::fill(f.begin(), f.begin() + d, mint(0));
            butterfly(f);
            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];
            butterfly_inv(f);
            mint iz = mint(d << 1).inv();
            iz *= -iz;
            for (int i = d; i < std::min(d << 1, deg); i++)
                ret.push_back(f[i] * iz);
        }
        return FPS(ret).pre(deg);
    }
};