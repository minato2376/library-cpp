#pragma once

#include <cassert>
#include <numeric>

template <bool REDUCE = true> struct Rational {
    using ll = long long;

    ll num, den;

    Rational() : num(0), den(1) {
    }
    Rational(ll num_) : num(num_), den(1) {
    }
    Rational(ll num_, ll den_) : num(num_), den(den_) {
        assert(den != 0);
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (REDUCE) {
            reduce();
        }
    }

    void reduce() {
        ll g = std::gcd(num, den);
        num /= g;
        den /= g;
    }

    static Rational raw(ll num_, ll den_) {
        assert(den_ != 0);
        Rational x;
        x.num = num_;
        x.den = den_;
        if (x.den < 0) {
            x.num = -x.num;
            x.den = -x.den;
        }
        return x;
    }

    Rational& operator++() {
        num += den;
        return *this;
    }
    Rational& operator--() {
        num -= den;
        return *this;
    }
    Rational operator++(int) {
        Rational res = *this;
        ++*this;
        return res;
    }
    Rational operator--(int) {
        Rational res = *this;
        --*this;
        return res;
    }
    Rational& operator+=(const Rational& p) {
        ll g = (REDUCE ? std::gcd(den, p.den) : 1);
        num = num * (p.den / g) + p.num * (den / g);
        den *= p.den / g;
        reduce();
        return *this;
    }
};