#pragma once

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
struct BigInt {
    using ll = long long;
    static constexpr int BASE = 1000000000;
    static constexpr int WIDTH = 9;
    std::vector<int> d;
    bool negative;
    BigInt() : BigInt(0) {
    }
    BigInt(ll x) : negative(false) {
        if (x == 0) return;
        if (x < 0) {
            negative = true;
            x = -x;
        }
        while (x) {
            d.push_back(x % BASE);
            x /= BASE;
        }
    }
    BigInt(std::string s) : negative(false) {
        assert(!s.empty());
        if (s == "0") return;
        if (s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }
        for (int r = int(s.size()); r > 0; r -= WIDTH) {
            int l = std::max(0, r - WIDTH);
            d.push_back(std::stoi(s.substr(l, r - l)));
        }
    }

    template <class T>
    BigInt(std::vector<T> d_, bool negative_)
        : d(d_.begin(), d_.end()), negative(negative_) {
    }

    BigInt operator-() const {
        BigInt res = *this;
        res.negative = !res.negative;
        return res;
    }

    BigInt operator+=(const BigInt& rhs) {
        if (negative == rhs.negative)
            return *this = BigInt(add_(d, rhs.d), negative);
    }
    BigInt operator-=(const BigInt& rhs) {
        if (rhs.negative) return *this += -rhs;
        if (negative) return -*this += rhs;
    }
    BigInt operator+(const BigInt& rhs) {
        return BigInt(*this) += rhs;
    }
    BigInt operator-(const BigInt& rhs) {
        return BigInt(*this) -= rhs;
    }

  private:
    static void shrink_(std::vector<int>& a) {
        while (!a.empty() && a.back() == 0) a.pop_back();
    }

    static std::vector<int> add_(const std::vector<int>& a,
                                 const std::vector<int>& b) {
        std::vector<int> res(std::max(a.size(), b.size()) + 1);
        for (int i = 0; i < (int)a.size(); i++) res[i] += a[i];
        for (int i = 0; i < (int)b.size(); i++) res[i] += b[i];
        for (int i = 0; i < (int)res.size() - 1; i++) {
            if (res[i] >= BASE) {
                res[i] -= BASE;
                res[i + 1]++;
            }
        }
        shrink_(res);
        return res;
    }
};