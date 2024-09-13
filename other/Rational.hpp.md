---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/Rational.hpp\"\n\n#include <cassert>\n#include <numeric>\n\
    \ntemplate <bool REDUCE = true> struct Rational {\n    using ll = long long;\n\
    \n    ll num, den;\n\n    Rational() : num(0), den(1) {\n    }\n    Rational(ll\
    \ num_) : num(num_), den(1) {\n    }\n    Rational(ll num_, ll den_) : num(num_),\
    \ den(den_) {\n        assert(den != 0);\n        if (den < 0) {\n           \
    \ num = -num;\n            den = -den;\n        }\n        if (REDUCE) {\n   \
    \         reduce();\n        }\n    }\n\n    void reduce() {\n        ll g = std::gcd(num,\
    \ den);\n        num /= g;\n        den /= g;\n    }\n\n    static Rational raw(ll\
    \ num_, ll den_) {\n        assert(den_ != 0);\n        Rational x;\n        x.num\
    \ = num_;\n        x.den = den_;\n        if (x.den < 0) {\n            x.num\
    \ = -x.num;\n            x.den = -x.den;\n        }\n        return x;\n    }\n\
    \n    Rational& operator++() {\n        num += den;\n        return *this;\n \
    \   }\n    Rational& operator--() {\n        num -= den;\n        return *this;\n\
    \    }\n    Rational operator++(int) {\n        Rational res = *this;\n      \
    \  ++*this;\n        return res;\n    }\n    Rational operator--(int) {\n    \
    \    Rational res = *this;\n        --*this;\n        return res;\n    }\n   \
    \ Rational& operator+=(const Rational& p) {\n        ll g = (REDUCE ? std::gcd(den,\
    \ p.den) : 1);\n        num = num * (p.den / g) + p.num * (den / g);\n       \
    \ den *= p.den / g;\n        reduce();\n        return *this;\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n\ntemplate <bool\
    \ REDUCE = true> struct Rational {\n    using ll = long long;\n\n    ll num, den;\n\
    \n    Rational() : num(0), den(1) {\n    }\n    Rational(ll num_) : num(num_),\
    \ den(1) {\n    }\n    Rational(ll num_, ll den_) : num(num_), den(den_) {\n \
    \       assert(den != 0);\n        if (den < 0) {\n            num = -num;\n \
    \           den = -den;\n        }\n        if (REDUCE) {\n            reduce();\n\
    \        }\n    }\n\n    void reduce() {\n        ll g = std::gcd(num, den);\n\
    \        num /= g;\n        den /= g;\n    }\n\n    static Rational raw(ll num_,\
    \ ll den_) {\n        assert(den_ != 0);\n        Rational x;\n        x.num =\
    \ num_;\n        x.den = den_;\n        if (x.den < 0) {\n            x.num =\
    \ -x.num;\n            x.den = -x.den;\n        }\n        return x;\n    }\n\n\
    \    Rational& operator++() {\n        num += den;\n        return *this;\n  \
    \  }\n    Rational& operator--() {\n        num -= den;\n        return *this;\n\
    \    }\n    Rational operator++(int) {\n        Rational res = *this;\n      \
    \  ++*this;\n        return res;\n    }\n    Rational operator--(int) {\n    \
    \    Rational res = *this;\n        --*this;\n        return res;\n    }\n   \
    \ Rational& operator+=(const Rational& p) {\n        ll g = (REDUCE ? std::gcd(den,\
    \ p.den) : 1);\n        num = num * (p.den / g) + p.num * (den / g);\n       \
    \ den *= p.den / g;\n        reduce();\n        return *this;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/Rational.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/Rational.hpp
layout: document
redirect_from:
- /library/other/Rational.hpp
- /library/other/Rational.hpp.html
title: other/Rational.hpp
---
