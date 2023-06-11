#pragma once

#include "other/type_traits.hpp"

template <int m> struct ModInt {
  public:
    static constexpr int mod() {
        return m;
    }
    static ModInt raw(int v) {
        ModInt x;
        x._v = v;
        return x;
    }

    ModInt() : _v(0) {
    }

    template <class T, internal::is_signed_int_t<T>* = nullptr> ModInt(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr> ModInt(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const {
        return _v;
    }

    ModInt& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    ModInt& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    ModInt operator++(int) {
        ModInt result = *this;
        ++*this;
        return result;
    }
    ModInt operator--(int) {
        ModInt result = *this;
        --*this;
        return result;
    }

    ModInt& operator+=(const ModInt& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    ModInt& operator-=(const ModInt& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    ModInt& operator*=(const ModInt& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    ModInt& operator^=(long long n) {
        ModInt x = *this;
        *this = 1;
        if (n < 0) x = x.inv(), n = -n;
        while (n) {
            if (n & 1) *this *= x;
            x *= x;
            n >>= 1;
        }
        return *this;
    }
    ModInt& operator/=(const ModInt& rhs) {
        return *this = *this * rhs.inv();
    }

    ModInt operator+() const {
        return *this;
    }
    ModInt operator-() const {
        return ModInt() - *this;
    }
    explicit operator bool() const {
        return _v != 0;
    }

    ModInt pow(long long n) const {
        ModInt r = *this;
        r ^= n;
        return r;
    }
    ModInt inv() const {
        int a = _v, b = umod(), y = 1, z = 0, t;
        for (;;) {
            t = a / b;
            a -= t * b;
            if (a == 0) {
                assert(b == 1 || b == -1);
                return ModInt(b * z);
            }
            y -= t * z;
            t = b / a;
            b -= t * a;
            if (b == 0) {
                assert(a == 1 || a == -1);
                return ModInt(a * y);
            }
            z -= t * y;
        }
    }

    friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
    }
    friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
    }
    friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
    }
    friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
    }
    friend ModInt operator^(const ModInt& lhs, long long rhs) {
        return ModInt(lhs) ^= rhs;
    }
    friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
        return lhs._v != rhs._v;
    }
    friend ModInt operator+(long long lhs, const ModInt& rhs) {
        return (ModInt(lhs) += rhs);
    }
    friend ModInt operator-(long long lhs, const ModInt& rhs) {
        return (ModInt(lhs) -= rhs);
    }
    friend ModInt operator*(long long lhs, const ModInt& rhs) {
        return (ModInt(lhs) *= rhs);
    }
    friend ostream& operator<<(ostream& os, const ModInt& M) {
        return os << M._v;
    }
    friend istream& operator>>(istream& is, ModInt& M) {
        long long x;
        is >> x;
        M = x;
        return is;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() {
        return m;
    }
};