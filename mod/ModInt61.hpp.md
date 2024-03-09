---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/RollingHash.hpp
    title: string/RollingHash.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/ModInt61.hpp\"\n#include <ostream>\n\nstruct ModInt61\
    \ {\n    using ull = unsigned long long;\n    static constexpr ull MD = (1ULL\
    \ << 61) - 1;\n    using M = ModInt61;\n    static constexpr ull get_mod() {\n\
    \        return MD;\n    }\n    ull v;\n    ModInt61(long long _v = 0) {\n   \
    \     set_v(_v % MD + MD);\n    }\n    M& set_v(ull _v) {\n        v = (_v < MD)\
    \ ? _v : _v - MD;\n        return *this;\n    }\n    ull val() const {\n     \
    \   return v;\n    }\n    explicit operator bool() const {\n        return v !=\
    \ 0;\n    }\n    M operator-() const {\n        return M() - *this;\n    }\n \
    \   M operator+(const M& r) const {\n        return M().set_v(v + r.v);\n    }\n\
    \    M operator-(const M& r) const {\n        return M().set_v(v + MD - r.v);\n\
    \    }\n    M operator*(const M& r) const {\n        __uint128_t z = __uint128_t(v)\
    \ * r.v;\n        return M().set_v(ull((z & ((1ULL << 61) - 1)) + (z >> 61)));\n\
    \    }\n    M operator/(const M& r) const {\n        return *this * r.inv();\n\
    \    }\n    M& operator+=(const M& r) {\n        return *this = *this + r;\n \
    \   }\n    M& operator-=(const M& r) {\n        return *this = *this - r;\n  \
    \  }\n    M& operator*=(const M& r) {\n        return *this = *this * r;\n   \
    \ }\n    M& operator/=(const M& r) {\n        return *this = *this / r;\n    }\n\
    \    bool operator==(const M& r) const {\n        return v == r.v;\n    }\n  \
    \  M pow(long long n) const {\n        M x = *this, r = 1;\n        while (n)\
    \ {\n            if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n\
    \        }\n        return r;\n    }\n    M inv() const {\n        return pow(MD\
    \ - 2);\n    }\n    friend std::ostream& operator<<(std::ostream& os, const M&\
    \ r) {\n        return os << r.v;\n    }\n};\n"
  code: "#pragma once\n#include <ostream>\n\nstruct ModInt61 {\n    using ull = unsigned\
    \ long long;\n    static constexpr ull MD = (1ULL << 61) - 1;\n    using M = ModInt61;\n\
    \    static constexpr ull get_mod() {\n        return MD;\n    }\n    ull v;\n\
    \    ModInt61(long long _v = 0) {\n        set_v(_v % MD + MD);\n    }\n    M&\
    \ set_v(ull _v) {\n        v = (_v < MD) ? _v : _v - MD;\n        return *this;\n\
    \    }\n    ull val() const {\n        return v;\n    }\n    explicit operator\
    \ bool() const {\n        return v != 0;\n    }\n    M operator-() const {\n \
    \       return M() - *this;\n    }\n    M operator+(const M& r) const {\n    \
    \    return M().set_v(v + r.v);\n    }\n    M operator-(const M& r) const {\n\
    \        return M().set_v(v + MD - r.v);\n    }\n    M operator*(const M& r) const\
    \ {\n        __uint128_t z = __uint128_t(v) * r.v;\n        return M().set_v(ull((z\
    \ & ((1ULL << 61) - 1)) + (z >> 61)));\n    }\n    M operator/(const M& r) const\
    \ {\n        return *this * r.inv();\n    }\n    M& operator+=(const M& r) {\n\
    \        return *this = *this + r;\n    }\n    M& operator-=(const M& r) {\n \
    \       return *this = *this - r;\n    }\n    M& operator*=(const M& r) {\n  \
    \      return *this = *this * r;\n    }\n    M& operator/=(const M& r) {\n   \
    \     return *this = *this / r;\n    }\n    bool operator==(const M& r) const\
    \ {\n        return v == r.v;\n    }\n    M pow(long long n) const {\n       \
    \ M x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n \
    \           x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n\
    \    M inv() const {\n        return pow(MD - 2);\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const M& r) {\n        return os << r.v;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/ModInt61.hpp
  requiredBy:
  - string/RollingHash.hpp
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/ModInt61.hpp
layout: document
redirect_from:
- /library/mod/ModInt61.hpp
- /library/mod/ModInt61.hpp.html
title: mod/ModInt61.hpp
---
