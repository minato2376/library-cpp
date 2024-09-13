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
  bundledCode: "#line 2 \"other/BigInt.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <string>\n#include <vector>\nstruct BigInt {\n    using ll = long long;\n\
    \    static constexpr int BASE = 1000000000;\n    static constexpr int WIDTH =\
    \ 9;\n    std::vector<int> d;\n    bool negative;\n    BigInt() : BigInt(0) {\n\
    \    }\n    BigInt(ll x) : negative(false) {\n        if (x == 0) return;\n  \
    \      if (x < 0) {\n            negative = true;\n            x = -x;\n     \
    \   }\n        while (x) {\n            d.push_back(x % BASE);\n            x\
    \ /= BASE;\n        }\n    }\n    BigInt(std::string s) : negative(false) {\n\
    \        assert(!s.empty());\n        if (s == \"0\") return;\n        if (s[0]\
    \ == '-') {\n            negative = true;\n            s = s.substr(1);\n    \
    \    }\n        for (int r = int(s.size()); r > 0; r -= WIDTH) {\n           \
    \ int l = std::max(0, r - WIDTH);\n            d.push_back(std::stoi(s.substr(l,\
    \ r - l)));\n        }\n    }\n\n    template <class T>\n    BigInt(std::vector<T>\
    \ d_, bool negative_)\n        : d(d_.begin(), d_.end()), negative(negative_)\
    \ {\n    }\n\n    BigInt operator-() const {\n        BigInt res = *this;\n  \
    \      res.negative = !res.negative;\n        return res;\n    }\n\n    BigInt\
    \ operator+=(const BigInt& rhs) {\n        if (negative == rhs.negative)\n   \
    \         return *this = BigInt(add_(d, rhs.d), negative);\n    }\n    BigInt\
    \ operator-=(const BigInt& rhs) {\n        if (rhs.negative) return *this += -rhs;\n\
    \        if (negative) return -*this += rhs;\n    }\n    BigInt operator+(const\
    \ BigInt& rhs) {\n        return BigInt(*this) += rhs;\n    }\n    BigInt operator-(const\
    \ BigInt& rhs) {\n        return BigInt(*this) -= rhs;\n    }\n\n  private:\n\
    \    static void shrink_(std::vector<int>& a) {\n        while (!a.empty() &&\
    \ a.back() == 0) a.pop_back();\n    }\n\n    static std::vector<int> add_(const\
    \ std::vector<int>& a,\n                                 const std::vector<int>&\
    \ b) {\n        std::vector<int> res(std::max(a.size(), b.size()) + 1);\n    \
    \    for (int i = 0; i < (int)a.size(); i++) res[i] += a[i];\n        for (int\
    \ i = 0; i < (int)b.size(); i++) res[i] += b[i];\n        for (int i = 0; i <\
    \ (int)res.size() - 1; i++) {\n            if (res[i] >= BASE) {\n           \
    \     res[i] -= BASE;\n                res[i + 1]++;\n            }\n        }\n\
    \        shrink_(res);\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <string>\n\
    #include <vector>\nstruct BigInt {\n    using ll = long long;\n    static constexpr\
    \ int BASE = 1000000000;\n    static constexpr int WIDTH = 9;\n    std::vector<int>\
    \ d;\n    bool negative;\n    BigInt() : BigInt(0) {\n    }\n    BigInt(ll x)\
    \ : negative(false) {\n        if (x == 0) return;\n        if (x < 0) {\n   \
    \         negative = true;\n            x = -x;\n        }\n        while (x)\
    \ {\n            d.push_back(x % BASE);\n            x /= BASE;\n        }\n \
    \   }\n    BigInt(std::string s) : negative(false) {\n        assert(!s.empty());\n\
    \        if (s == \"0\") return;\n        if (s[0] == '-') {\n            negative\
    \ = true;\n            s = s.substr(1);\n        }\n        for (int r = int(s.size());\
    \ r > 0; r -= WIDTH) {\n            int l = std::max(0, r - WIDTH);\n        \
    \    d.push_back(std::stoi(s.substr(l, r - l)));\n        }\n    }\n\n    template\
    \ <class T>\n    BigInt(std::vector<T> d_, bool negative_)\n        : d(d_.begin(),\
    \ d_.end()), negative(negative_) {\n    }\n\n    BigInt operator-() const {\n\
    \        BigInt res = *this;\n        res.negative = !res.negative;\n        return\
    \ res;\n    }\n\n    BigInt operator+=(const BigInt& rhs) {\n        if (negative\
    \ == rhs.negative)\n            return *this = BigInt(add_(d, rhs.d), negative);\n\
    \    }\n    BigInt operator-=(const BigInt& rhs) {\n        if (rhs.negative)\
    \ return *this += -rhs;\n        if (negative) return -*this += rhs;\n    }\n\
    \    BigInt operator+(const BigInt& rhs) {\n        return BigInt(*this) += rhs;\n\
    \    }\n    BigInt operator-(const BigInt& rhs) {\n        return BigInt(*this)\
    \ -= rhs;\n    }\n\n  private:\n    static void shrink_(std::vector<int>& a) {\n\
    \        while (!a.empty() && a.back() == 0) a.pop_back();\n    }\n\n    static\
    \ std::vector<int> add_(const std::vector<int>& a,\n                         \
    \        const std::vector<int>& b) {\n        std::vector<int> res(std::max(a.size(),\
    \ b.size()) + 1);\n        for (int i = 0; i < (int)a.size(); i++) res[i] += a[i];\n\
    \        for (int i = 0; i < (int)b.size(); i++) res[i] += b[i];\n        for\
    \ (int i = 0; i < (int)res.size() - 1; i++) {\n            if (res[i] >= BASE)\
    \ {\n                res[i] -= BASE;\n                res[i + 1]++;\n        \
    \    }\n        }\n        shrink_(res);\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/BigInt.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/BigInt.hpp
layout: document
redirect_from:
- /library/other/BigInt.hpp
- /library/other/BigInt.hpp.html
title: other/BigInt.hpp
---
