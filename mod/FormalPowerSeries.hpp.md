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
  bundledCode: "#line 2 \"mod/FormalPowerSeries.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\ntemplate <class mint,\n\
    \          std::vector<mint> (*convolution)(std::vector<mint>,\n             \
    \                              std::vector<mint>),\n          void (*butterfly)(std::vector<mint>&),\n\
    \          void (*butterfly_inv)(std::vector<mint>&),\n          int SPARSE =\
    \ 10>\nstruct FormalPowerSeries {\n    using FPS = FormalPowerSeries;\n    std::vector<mint>\
    \ v;\n\n    template <class T>\n    FormalPowerSeries(const std::vector<T>& v_)\
    \ : v(v_.begin(), v_.end()) {\n        shrink();\n    }\n    void shrink() {\n\
    \        while (!v.empty() && v.back() == 0) v.pop_back();\n    }\n\n    int size()\
    \ const {\n        return int(v.size());\n    }\n\n    bool empty() const {\n\
    \        return v.empty();\n    }\n\n    mint freq(int p) const {\n        return\
    \ (p < size()) ? v[p] : mint(0);\n    }\n\n    const mint& operator[](int i) const\
    \ {\n        assert(0 <= i && i < size());\n        return v[i];\n    }\n\n  \
    \  mint& operator[](int i) {\n        assert(0 <= i && i < size());\n        return\
    \ v[i];\n    }\n\n    int count_nonzero() const {\n        return std::count_if(v.begin(),\
    \ v.end(), [](mint x) { return x != 0; });\n    }\n\n    std::vector<std::pair<int,\
    \ mint>> get_sparse() const {\n        std::vector<std::pair<int, mint>> ret;\n\
    \        for (int i = 0; i < size(); i++) {\n            if (v[i] != 0) ret.emplace_back(i,\
    \ v[i]);\n        }\n        return ret;\n    }\n\n    FPS operator+(const FPS&\
    \ r) const {\n        int n = std::max(size(), r.size());\n        std::vector\
    \ ret(n);\n        for (int i = 0; i < n; i++) ret[i] = freq(i) + r.freq(i);\n\
    \        return ret;\n    }\n    FPS operator-(const FPS& r) const {\n       \
    \ int n = std::max(size(), r.size());\n        std::vector ret(n);\n        for\
    \ (int i = 0; i < n; i++) ret[i] = freq(i) - r.freq(i);\n        return ret;\n\
    \    }\n    FPS operator*(const FPS& r) const {\n        int count_nonzero = r.count_nonzero();\n\
    \        if (count_nonzero == 0) return std::vector<mint>();\n        if (count_nonzero\
    \ <= SPARSE) {\n            std::vector<std::pair<int, mint>> vr = r.get_sparse();\n\
    \            return *this * vr;\n        }\n        return convolution(v, r.v);\n\
    \    }\n    FPS operator*(const mint& r) const {\n        std::vector<mint> ret(size());\n\
    \        for (int i = 0; i < size(); i++) ret[i] = v[i] * r;\n        return ret;\n\
    \    }\n    FPS operator*(const std::vector<std::pair<int, mint>>& r) const {\n\
    \        assert(!r.empty());\n        int m = r.back().first;\n        std::vector<mint>\
    \ ret(size() + m);\n        for (int i = 0; i < size(); i++) {\n            for\
    \ (auto& e : r) {\n                ret[i + e.first] += v[i] * e.second;\n    \
    \        }\n        }\n        return ret;\n    }\n    FPS& operator+=(const FPS&\
    \ r) {\n        return *this = *this + r;\n    }\n    FPS& operator-=(const FPS&\
    \ r) {\n        return *this = *this - r;\n    }\n    FPS& operator*=(const FPS&\
    \ r) {\n        return *this = *this * r;\n    }\n    FPS& operator*=(const mint&\
    \ r) {\n        return *this = *this * r;\n    }\n    FPS& operator*=(const std::vector<std::pair<int,\
    \ mint>>& r) {\n        return *this = *this * r;\n    }\n\n    FPS pre(int le)\
    \ const {\n        return std::vector<mint>(v.begin(), v.begin() + min(size(),\
    \ le));\n    }\n\n    FPS inv(int deg = -1) const {\n        assert(freq(0) !=\
    \ 0);\n        const int n = size();\n        if (deg == -1) deg = n;\n      \
    \  std::vector<mint> ret = {freq(0).inv()};\n        ret.reserve(deg);\n     \
    \   for (int d = 1; d < deg; d <<= 1) {\n            std::vector<mint> f(d <<\
    \ 1), g(d << 1);\n            std::copy(v.begin(), v.begin() + std::min(n, d <<\
    \ 1), f.begin());\n            std::copy(ret.begin(), ret.end(), g.begin());\n\
    \            butterfly(f);\n            butterfly(g);\n            for (int i\
    \ = 0; i < (d << 1); i++) f[i] *= g[i];\n            butterfly_inv(f);\n     \
    \       std::fill(f.begin(), f.begin() + d, mint(0));\n            butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            butterfly_inv(f);\n\
    \            mint iz = mint(d << 1).inv();\n            iz *= -iz;\n         \
    \   for (int i = d; i < std::min(d << 1, deg); i++)\n                ret.push_back(f[i]\
    \ * iz);\n        }\n        return FPS(ret).pre(deg);\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <class mint,\n          std::vector<mint> (*convolution)(std::vector<mint>,\n\
    \                                           std::vector<mint>),\n          void\
    \ (*butterfly)(std::vector<mint>&),\n          void (*butterfly_inv)(std::vector<mint>&),\n\
    \          int SPARSE = 10>\nstruct FormalPowerSeries {\n    using FPS = FormalPowerSeries;\n\
    \    std::vector<mint> v;\n\n    template <class T>\n    FormalPowerSeries(const\
    \ std::vector<T>& v_) : v(v_.begin(), v_.end()) {\n        shrink();\n    }\n\
    \    void shrink() {\n        while (!v.empty() && v.back() == 0) v.pop_back();\n\
    \    }\n\n    int size() const {\n        return int(v.size());\n    }\n\n   \
    \ bool empty() const {\n        return v.empty();\n    }\n\n    mint freq(int\
    \ p) const {\n        return (p < size()) ? v[p] : mint(0);\n    }\n\n    const\
    \ mint& operator[](int i) const {\n        assert(0 <= i && i < size());\n   \
    \     return v[i];\n    }\n\n    mint& operator[](int i) {\n        assert(0 <=\
    \ i && i < size());\n        return v[i];\n    }\n\n    int count_nonzero() const\
    \ {\n        return std::count_if(v.begin(), v.end(), [](mint x) { return x !=\
    \ 0; });\n    }\n\n    std::vector<std::pair<int, mint>> get_sparse() const {\n\
    \        std::vector<std::pair<int, mint>> ret;\n        for (int i = 0; i < size();\
    \ i++) {\n            if (v[i] != 0) ret.emplace_back(i, v[i]);\n        }\n \
    \       return ret;\n    }\n\n    FPS operator+(const FPS& r) const {\n      \
    \  int n = std::max(size(), r.size());\n        std::vector ret(n);\n        for\
    \ (int i = 0; i < n; i++) ret[i] = freq(i) + r.freq(i);\n        return ret;\n\
    \    }\n    FPS operator-(const FPS& r) const {\n        int n = std::max(size(),\
    \ r.size());\n        std::vector ret(n);\n        for (int i = 0; i < n; i++)\
    \ ret[i] = freq(i) - r.freq(i);\n        return ret;\n    }\n    FPS operator*(const\
    \ FPS& r) const {\n        int count_nonzero = r.count_nonzero();\n        if\
    \ (count_nonzero == 0) return std::vector<mint>();\n        if (count_nonzero\
    \ <= SPARSE) {\n            std::vector<std::pair<int, mint>> vr = r.get_sparse();\n\
    \            return *this * vr;\n        }\n        return convolution(v, r.v);\n\
    \    }\n    FPS operator*(const mint& r) const {\n        std::vector<mint> ret(size());\n\
    \        for (int i = 0; i < size(); i++) ret[i] = v[i] * r;\n        return ret;\n\
    \    }\n    FPS operator*(const std::vector<std::pair<int, mint>>& r) const {\n\
    \        assert(!r.empty());\n        int m = r.back().first;\n        std::vector<mint>\
    \ ret(size() + m);\n        for (int i = 0; i < size(); i++) {\n            for\
    \ (auto& e : r) {\n                ret[i + e.first] += v[i] * e.second;\n    \
    \        }\n        }\n        return ret;\n    }\n    FPS& operator+=(const FPS&\
    \ r) {\n        return *this = *this + r;\n    }\n    FPS& operator-=(const FPS&\
    \ r) {\n        return *this = *this - r;\n    }\n    FPS& operator*=(const FPS&\
    \ r) {\n        return *this = *this * r;\n    }\n    FPS& operator*=(const mint&\
    \ r) {\n        return *this = *this * r;\n    }\n    FPS& operator*=(const std::vector<std::pair<int,\
    \ mint>>& r) {\n        return *this = *this * r;\n    }\n\n    FPS pre(int le)\
    \ const {\n        return std::vector<mint>(v.begin(), v.begin() + min(size(),\
    \ le));\n    }\n\n    FPS inv(int deg = -1) const {\n        assert(freq(0) !=\
    \ 0);\n        const int n = size();\n        if (deg == -1) deg = n;\n      \
    \  std::vector<mint> ret = {freq(0).inv()};\n        ret.reserve(deg);\n     \
    \   for (int d = 1; d < deg; d <<= 1) {\n            std::vector<mint> f(d <<\
    \ 1), g(d << 1);\n            std::copy(v.begin(), v.begin() + std::min(n, d <<\
    \ 1), f.begin());\n            std::copy(ret.begin(), ret.end(), g.begin());\n\
    \            butterfly(f);\n            butterfly(g);\n            for (int i\
    \ = 0; i < (d << 1); i++) f[i] *= g[i];\n            butterfly_inv(f);\n     \
    \       std::fill(f.begin(), f.begin() + d, mint(0));\n            butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            butterfly_inv(f);\n\
    \            mint iz = mint(d << 1).inv();\n            iz *= -iz;\n         \
    \   for (int i = d; i < std::min(d << 1, deg); i++)\n                ret.push_back(f[i]\
    \ * iz);\n        }\n        return FPS(ret).pre(deg);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2023-10-13 01:31:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/mod/FormalPowerSeries.hpp
- /library/mod/FormalPowerSeries.hpp.html
title: mod/FormalPowerSeries.hpp
---
