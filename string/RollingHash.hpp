#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <random>
#include <vector>

#include "mod/ModInt61.hpp"

struct RollingHash {
    using ull = unsigned long long;

  public:
    static inline ull generate_base() {
        std::mt19937_64 mt(
            std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<ull> rand(0ULL, ModInt61::get_mod() - 1);
        return rand(mt);
    }

    RollingHash(int n, ull base) : n_(n), power(n + 1, 1), base_(base) {
        for (int i = 0; i < n; i++) {
            power[i + 1] = power[i] * base_;
        }
    }

    int size() const {
        return n_ + 1;
    }

    ModInt61 operator[](int i) const {
        assert(0 <= i and i <= n_);
        return power[i];
    }

    ModInt61 get_base() const {
        return base_;
    }

    template <class String, int base_num = 1>
    std::vector<ModInt61> get_hash(const String& s) const {
        int n = int(s.size());
        assert(n <= n_);
        std::vector<ModInt61> ret(n + 1);
        for (int i = 0; i < n; i++) {
            ret[i + 1] = ret[i] * base_ + s[i] + base_num;
        }
        return ret;
    }

    // [l,r) (0-indexed)
    ModInt61 getrange(const std::vector<ModInt61>& hash, int l, int r) const {
        if (l >= r) return ModInt61(0);
        assert(0 <= l and r <= n_);
        return hash[r] - hash[l] * power[r - l];
    }

    template <class String, int base_num = 1>
    ModInt61 getval(const String& s) const {
        int n = int(s.size());
        assert(n <= n_);
        ModInt61 ret = 0;
        for (int i = 0; i < n; i++) {
            ret = ret * base_ + s[i] + base_num;
        }
        return ret;
    }

    ModInt61 concat(ModInt61 hl, ModInt61 hr, int rlen) const {
        assert(rlen <= n_);
        return hl * power[rlen] + hr;
    }

    int LCP(const std::vector<ModInt61>& a,
            const std::vector<ModInt61>& b,
            int l1,
            int r1,
            int l2,
            int r2) const {
        assert(0 <= l1 and l1 < r1 and r1 <= int(a.size()));
        assert(0 <= l2 and l2 < r2 and r2 <= int(b.size()));
        int len = std::min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (getrange(a, l1, l1 + mid) == getrange(b, l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return low;
    }

  private:
    int n_;
    std::vector<ModInt61> power;
    ModInt61 base_;
};
