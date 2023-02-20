---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mod/ModInt.test.cpp
    title: test/mod/ModInt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/ModInt.hpp\"\ntemplate <int m> struct ModInt {\n  public:\n\
    \    static constexpr int mod() {\n        return m;\n    }\n    static ModInt\
    \ raw(int v) {\n        ModInt x;\n        x._v = v;\n        return x;\n    }\n\
    \n    ModInt() : _v(0) {\n    }\n    ModInt(long long v) {\n        long long\
    \ x = (long long)(v % (long long)(umod()));\n        if (x < 0) x += umod();\n\
    \        _v = (unsigned int)(x);\n    }\n\n    unsigned int val() const {\n  \
    \      return _v;\n    }\n\n    ModInt& operator++() {\n        _v++;\n      \
    \  if (_v == umod()) _v = 0;\n        return *this;\n    }\n    ModInt& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    ModInt operator++(int) {\n        ModInt result = *this;\n       \
    \ ++*this;\n        return result;\n    }\n    ModInt operator--(int) {\n    \
    \    ModInt result = *this;\n        --*this;\n        return result;\n    }\n\
    \n    ModInt& operator+=(const ModInt& rhs) {\n        _v += rhs._v;\n       \
    \ if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    ModInt& operator-=(const\
    \ ModInt& rhs) {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n\
    \        return *this;\n    }\n    ModInt& operator*=(const ModInt& rhs) {\n \
    \       unsigned long long z = _v;\n        z *= rhs._v;\n        _v = (unsigned\
    \ int)(z % umod());\n        return *this;\n    }\n    ModInt& operator^=(long\
    \ long n) {\n        ModInt x = *this;\n        *this = 1;\n        if (n < 0)\
    \ x = x.inv(), n = -n;\n        while (n) {\n            if (n & 1) *this *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return *this;\n\
    \    }\n    ModInt& operator/=(const ModInt& rhs) {\n        return *this = *this\
    \ * rhs.inv();\n    }\n\n    ModInt operator+() const {\n        return *this;\n\
    \    }\n    ModInt operator-() const {\n        return ModInt() - *this;\n   \
    \ }\n    explicit operator bool() const {\n        return _v != 0;\n    }\n\n\
    \    ModInt pow(long long n) const {\n        ModInt r = *this;\n        r ^=\
    \ n;\n        return r;\n    }\n    ModInt inv() const {\n        int a = _v,\
    \ b = umod(), y = 1, z = 0, t;\n        for (;;) {\n            t = a / b;\n \
    \           a -= t * b;\n            if (a == 0) {\n                assert(b ==\
    \ 1 || b == -1);\n                return ModInt(b * z);\n            }\n     \
    \       y -= t * z;\n            t = b / a;\n            b -= t * a;\n       \
    \     if (b == 0) {\n                assert(a == 1 || a == -1);\n            \
    \    return ModInt(a * y);\n            }\n            z -= t * y;\n        }\n\
    \    }\n\n    friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {\n\
    \        return ModInt(lhs) += rhs;\n    }\n    friend ModInt operator-(const\
    \ ModInt& lhs, const ModInt& rhs) {\n        return ModInt(lhs) -= rhs;\n    }\n\
    \    friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {\n       \
    \ return ModInt(lhs) *= rhs;\n    }\n    friend ModInt operator/(const ModInt&\
    \ lhs, const ModInt& rhs) {\n        return ModInt(lhs) /= rhs;\n    }\n    friend\
    \ ModInt operator^(const ModInt& lhs, long long rhs) {\n        return ModInt(lhs)\
    \ ^= rhs;\n    }\n    friend bool operator==(const ModInt& lhs, const ModInt&\
    \ rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ ModInt& lhs, const ModInt& rhs) {\n        return lhs._v != rhs._v;\n    }\n\
    \    friend ModInt operator+(long long lhs, const ModInt& rhs) {\n        return\
    \ (ModInt(lhs) += rhs);\n    }\n    friend ModInt operator-(long long lhs, const\
    \ ModInt& rhs) {\n        return (ModInt(lhs) -= rhs);\n    }\n    friend ModInt\
    \ operator*(long long lhs, const ModInt& rhs) {\n        return (ModInt(lhs) *=\
    \ rhs);\n    }\n    friend ostream& operator<<(ostream& os, const ModInt& M) {\n\
    \        return os << M._v;\n    }\n    friend istream& operator>>(istream& is,\
    \ ModInt& M) {\n        long long x;\n        is >> x;\n        M = x;\n     \
    \   return is;\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() {\n        return m;\n    }\n};\n"
  code: "template <int m> struct ModInt {\n  public:\n    static constexpr int mod()\
    \ {\n        return m;\n    }\n    static ModInt raw(int v) {\n        ModInt\
    \ x;\n        x._v = v;\n        return x;\n    }\n\n    ModInt() : _v(0) {\n\
    \    }\n    ModInt(long long v) {\n        long long x = (long long)(v % (long\
    \ long)(umod()));\n        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n\
    \    }\n\n    unsigned int val() const {\n        return _v;\n    }\n\n    ModInt&\
    \ operator++() {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return\
    \ *this;\n    }\n    ModInt& operator--() {\n        if (_v == 0) _v = umod();\n\
    \        _v--;\n        return *this;\n    }\n    ModInt operator++(int) {\n \
    \       ModInt result = *this;\n        ++*this;\n        return result;\n   \
    \ }\n    ModInt operator--(int) {\n        ModInt result = *this;\n        --*this;\n\
    \        return result;\n    }\n\n    ModInt& operator+=(const ModInt& rhs) {\n\
    \        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    ModInt& operator-=(const ModInt& rhs) {\n        _v -= rhs._v;\n\
    \        if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    ModInt&\
    \ operator*=(const ModInt& rhs) {\n        unsigned long long z = _v;\n      \
    \  z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n        return *this;\n\
    \    }\n    ModInt& operator^=(long long n) {\n        ModInt x = *this;\n   \
    \     *this = 1;\n        if (n < 0) x = x.inv(), n = -n;\n        while (n) {\n\
    \            if (n & 1) *this *= x;\n            x *= x;\n            n >>= 1;\n\
    \        }\n        return *this;\n    }\n    ModInt& operator/=(const ModInt&\
    \ rhs) {\n        return *this = *this * rhs.inv();\n    }\n\n    ModInt operator+()\
    \ const {\n        return *this;\n    }\n    ModInt operator-() const {\n    \
    \    return ModInt() - *this;\n    }\n    explicit operator bool() const {\n \
    \       return _v != 0;\n    }\n\n    ModInt pow(long long n) const {\n      \
    \  ModInt r = *this;\n        r ^= n;\n        return r;\n    }\n    ModInt inv()\
    \ const {\n        int a = _v, b = umod(), y = 1, z = 0, t;\n        for (;;)\
    \ {\n            t = a / b;\n            a -= t * b;\n            if (a == 0)\
    \ {\n                assert(b == 1 || b == -1);\n                return ModInt(b\
    \ * z);\n            }\n            y -= t * z;\n            t = b / a;\n    \
    \        b -= t * a;\n            if (b == 0) {\n                assert(a == 1\
    \ || a == -1);\n                return ModInt(a * y);\n            }\n       \
    \     z -= t * y;\n        }\n    }\n\n    friend ModInt operator+(const ModInt&\
    \ lhs, const ModInt& rhs) {\n        return ModInt(lhs) += rhs;\n    }\n    friend\
    \ ModInt operator-(const ModInt& lhs, const ModInt& rhs) {\n        return ModInt(lhs)\
    \ -= rhs;\n    }\n    friend ModInt operator*(const ModInt& lhs, const ModInt&\
    \ rhs) {\n        return ModInt(lhs) *= rhs;\n    }\n    friend ModInt operator/(const\
    \ ModInt& lhs, const ModInt& rhs) {\n        return ModInt(lhs) /= rhs;\n    }\n\
    \    friend ModInt operator^(const ModInt& lhs, long long rhs) {\n        return\
    \ ModInt(lhs) ^= rhs;\n    }\n    friend bool operator==(const ModInt& lhs, const\
    \ ModInt& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ ModInt& lhs, const ModInt& rhs) {\n        return lhs._v != rhs._v;\n    }\n\
    \    friend ModInt operator+(long long lhs, const ModInt& rhs) {\n        return\
    \ (ModInt(lhs) += rhs);\n    }\n    friend ModInt operator-(long long lhs, const\
    \ ModInt& rhs) {\n        return (ModInt(lhs) -= rhs);\n    }\n    friend ModInt\
    \ operator*(long long lhs, const ModInt& rhs) {\n        return (ModInt(lhs) *=\
    \ rhs);\n    }\n    friend ostream& operator<<(ostream& os, const ModInt& M) {\n\
    \        return os << M._v;\n    }\n    friend istream& operator>>(istream& is,\
    \ ModInt& M) {\n        long long x;\n        is >> x;\n        M = x;\n     \
    \   return is;\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() {\n        return m;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/ModInt.hpp
  requiredBy: []
  timestamp: '2023-02-18 04:05:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mod/ModInt.test.cpp
documentation_of: mod/ModInt.hpp
layout: document
redirect_from:
- /library/mod/ModInt.hpp
- /library/mod/ModInt.hpp.html
title: mod/ModInt.hpp
---
