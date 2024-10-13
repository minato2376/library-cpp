---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/arbitrary_convolution.hpp
    title: mod/arbitrary_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/FormalPowerSeriesArbitrary.hpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include <atcoder/convolution>\n\n#line 2 \"mod/arbitrary_convolution.hpp\"\n\
    \n#line 6 \"mod/arbitrary_convolution.hpp\"\n\n#line 8 \"mod/arbitrary_convolution.hpp\"\
    \n\nnamespace arbitrary_convolution {\n\ntemplate <class T>\nstd::vector<int>\
    \ convolution_medium(const std::vector<T>& a,\n                              \
    \      const std::vector<T>& b,\n                                    const int\
    \ mod) {\n    static constexpr int m0 = 1045430273;\n    static constexpr int\
    \ m1 = 1051721729;\n    static constexpr int m2 = 1053818881;\n    static constexpr\
    \ int r01 = 175287122;  // mint1(m0).inv()\n    static constexpr int r02 = 395182206;\
    \  // mint2(m0).inv()\n    static constexpr int r12 = 526909943;  // mint2(m1).inv()\n\
    \    static constexpr int r02r12 = (long long)(r02)*r12 % m2;\n    static constexpr\
    \ long long w1 = m0;\n    static constexpr long long w2 = (long long)(m0)*m1;\n\
    \n    const int n = int(a.size()), m = int(b.size());\n\n    std::vector<T> v0\
    \ = atcoder::convolution<m0>(a, b);\n    std::vector<T> v1 = atcoder::convolution<m1>(a,\
    \ b);\n    std::vector<T> v2 = atcoder::convolution<m2>(a, b);\n    std::vector<int>\
    \ ret(n + m - 1);\n\n    const int W1 = w1 % mod;\n    const int W2 = w2 % mod;\n\
    \    for (int i = 0; i < n + m - 1; i++) {\n        int n1 = v1[i], n2 = v2[i],\
    \ x = v0[i];\n        int y = (long long)(n1 + m1 - x) * r01 % m1;\n        int\
    \ z =\n            ((long long)(n2 + m2 - x) * r02r12 + (long long)(m2 - y) *\
    \ r12) %\n            m2;\n        ret[i] = ((long long)(x) + (long long)(y)*W1\
    \ + (long long)(z)*W2) % mod;\n    }\n\n    return ret;\n}\n\ntemplate <class\
    \ T>\nstd::vector<int> convolution_large(const std::vector<T>& a,\n          \
    \                         const std::vector<T>& b,\n                         \
    \          const int mod) {\n    static constexpr int m0 = 167772161;\n    static\
    \ constexpr int m1 = 469762049;\n    static constexpr int m2 = 754974721;\n  \
    \  static constexpr int r01 = 104391568;  // mint1(m0).inv()\n    static constexpr\
    \ int r02 = 323560596;  // mint2(m0).inv()\n    static constexpr int r12 = 399692502;\
    \  // mint2(m1).inv()\n    static constexpr int r02r12 = (long long)(r02)*r12\
    \ % m2;\n    static constexpr long long w1 = m0;\n    static constexpr long long\
    \ w2 = (long long)(m0)*m1;\n\n    const int n = int(a.size()), m = int(b.size());\n\
    \n    std::vector<T> v0 = atcoder::convolution<m0>(a, b);\n    std::vector<T>\
    \ v1 = atcoder::convolution<m1>(a, b);\n    std::vector<T> v2 = atcoder::convolution<m2>(a,\
    \ b);\n    std::vector<int> ret(n + m - 1);\n\n    const int W1 = w1 % mod;\n\
    \    const int W2 = w2 % mod;\n    for (int i = 0; i < n + m - 1; i++) {\n   \
    \     int n1 = v1[i], n2 = v2[i], x = v0[i];\n        int y = (long long)(n1 +\
    \ m1 - x) * r01 % m1;\n        int z =\n            ((long long)(n2 + m2 - x)\
    \ * r02r12 + (long long)(m2 - y) * r12) %\n            m2;\n        ret[i] = ((long\
    \ long)(x) + (long long)(y)*W1 + (long long)(z)*W2) % mod;\n    }\n\n    return\
    \ ret;\n}\n\ntemplate <class mint,\n          int SMALL = 1 << 7,\n          int\
    \ MEDIUM = 1 << 20,\n          int LARGE = 1 << 24>\nstd::vector<mint> multiply(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   if (!n or !m) return {};\n    if (std::min(n, m) <= SMALL) {\n        if (n\
    \ < m) {\n            std::swap(n, m);\n            std::swap(a, b);\n       \
    \ }\n        std::vector<mint> ret(n + m - 1);\n        for (int i = 0; i < n;\
    \ i++) {\n            for (int j = 0; j < m; j++) {\n                ret[i + j]\
    \ += a[i] * b[j];\n            }\n        }\n        return ret;\n    }\n    std::vector<int>\
    \ a_(n), b_(m);\n    for (int i = 0; i < n; i++) a_[i] = a[i].val();\n    for\
    \ (int i = 0; i < m; i++) b_[i] = b[i].val();\n    std::vector<int> c;\n    if\
    \ (n + m - 1 <= MEDIUM) {\n        c = convolution_medium<int>(a_, b_, mint::mod());\n\
    \    } else if (n + m - 1 <= LARGE) {\n        c = convolution_large<int>(a_,\
    \ b_, mint::mod());\n    } else {\n        assert(false && \"size is too large\"\
    );\n    }\n    std::vector<mint> ret(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) ret[i] = mint::raw(c[i]);\n    return ret;\n}\n}  // namespace arbitrary_convolution\n\
    #line 12 \"mod/FormalPowerSeriesArbitrary.hpp\"\n\ntemplate <typename M, int SPARSE\
    \ = 10>\nstruct FormalPowerSeriesArbitarary : std::vector<M> {\n    using std::vector<M>::vector;\n\
    \    using FPS = FormalPowerSeriesArbitarary;\n\n    FPS static read(int n) {\n\
    \        FPS ret(n);\n        for (int i = 0; i < n; i++) {\n            long\
    \ long x;\n            std::cin >> x;\n            ret[i] = x;\n        }\n  \
    \      return ret;\n    }\n\n    M freq(int p) const {\n        return p < (int)this->size()\
    \ ? (*this)[p] : M(0);\n    }\n\n    void shrink() {\n        while (!this->empty()\
    \ and this->back().val() == 0) this->pop_back();\n    }\n\n    FPS pre(int le)\
    \ const {\n        return FPS(this->begin(),\n                   this->begin()\
    \ + std::min((int)this->size(), le));\n    }\n\n    FPS rev() const {\n      \
    \  FPS ret(*this);\n        std::reverse(ret.begin(), ret.end());\n        return\
    \ ret;\n    }\n\n    int count_nonzero() const {\n        return std::count_if(this->begin(),\
    \ this->end(),\n                             [](M x) { return x.val() != 0; });\n\
    \    }\n\n    std::vector<std::pair<int, M>> get_sparse() const {\n        std::vector<std::pair<int,\
    \ M>> ret;\n        for (size_t i = 0; i < this->size(); i++) {\n            if\
    \ ((*this)[i].val() != 0) ret.emplace_back(i, (*this)[i]);\n        }\n      \
    \  return ret;\n    }\n\n    FPS operator>>(int s) const {\n        if ((int)this->size()\
    \ <= s) return {};\n        return FPS(this->begin() + s, this->end());\n    }\n\
    \n    FPS operator<<(int s) const {\n        if (this->empty()) return {};\n \
    \       FPS ret(*this);\n        ret.insert(ret.begin(), s, M(0));\n        return\
    \ ret;\n    }\n\n    FPS& operator+=(const FPS& r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (size_t i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];\n        shrink();\n        return *this;\n    }\n\n    FPS& operator+=(const\
    \ M& v) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] +=\
    \ v;\n        shrink();\n        return *this;\n    }\n\n    FPS& operator-=(const\
    \ FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < int(r.size()); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator-=(const M& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator*=(const FPS& r) {\n       \
    \ const int z = r.count_nonzero();\n        if (z == 0) {\n            this->clear();\n\
    \            return *this;\n        }\n        if (z <= SPARSE) {\n          \
    \  auto sparse = r.get_sparse();\n            return *this *= sparse;\n      \
    \  }\n        auto res = arbitrary_convolution::multiply(*this, r);\n        return\
    \ *this = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const M& v)\
    \ {\n        for (auto& x : (*this)) x *= v;\n        shrink();\n        return\
    \ *this;\n    }\n\n    FPS& operator*=(const std::vector<std::pair<int, M>>& r)\
    \ {\n        assert(!r.empty());\n        const int m = r.back().first;\n    \
    \    FPS ret(this->size() + m);\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            for (const auto& [j, c] : r) {\n                ret[i +\
    \ j] += (*this)[i] * c;\n            }\n        }\n        ret.shrink();\n   \
    \     return *this = ret;\n    }\n\n    FPS& operator/=(const FPS& r) {\n    \
    \    if (this->size() < r.size()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        const int z = r.count_nonzero();\n        assert(z\
    \ != 0);\n        if (z <= SPARSE) {\n            auto sparse = r.get_sparse();\n\
    \            return *this /= sparse;\n        }\n        int n = this->size()\
    \ - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS& operator/=(const M& v) {\n        assert(v.val() != 0);\n \
    \       auto vinv = v.inv();\n        for (auto& x : (*this)) x *= vinv;\n   \
    \     return *this;\n    }\n\n    FPS& operator/=(const std::vector<std::pair<int,\
    \ M>>& r) {\n        assert(!r.empty());\n        auto [j0, c0] = r.front();\n\
    \        assert(j0 == 0 && c0.val() != 0);\n        auto ic = c0.inv();\n    \
    \    FPS ret(this->size());\n        for (int i = 0; i < (int)this->size(); i++)\
    \ {\n            for (const auto& [j, c] : r) {\n                if (j >= 1 &&\
    \ j <= i) {\n                    ret[i] -= ret[i - j] * c;\n                }\n\
    \            }\n            ret[i] += (*this)[i];\n            ret[i] *= ic;\n\
    \        }\n        ret.shrink();\n        return *this = ret;\n    }\n\n    FPS&\
    \ operator%=(const FPS& r) {\n        *this -= *this / r * r;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS operator+(const FPS& r) const {\n   \
    \     return FPS(*this) += r;\n    }\n\n    FPS operator+(const M& v) const {\n\
    \        return FPS(*this) += v;\n    }\n\n    FPS operator-(const FPS& r) const\
    \ {\n        return FPS(*this) -= r;\n    }\n\n    FPS operator-(const M& v) const\
    \ {\n        return FPS(*this) -= v;\n    }\n\n    FPS operator*(const FPS& r)\
    \ const {\n        return FPS(*this) *= r;\n    }\n\n    FPS operator*(const M&\
    \ v) const {\n        return FPS(*this) *= v;\n    }\n\n    FPS operator/(const\
    \ FPS& r) const {\n        return FPS(*this) /= r;\n    }\n\n    FPS operator%(const\
    \ FPS& r) const {\n        return FPS(*this) %= r;\n    }\n\n    FPS operator-()\
    \ const {\n        FPS ret = *this;\n        for (auto& v : ret) v = -v;\n   \
    \     return ret;\n    }\n\n    FPS differential() const {\n        const int\
    \ n = (int)this->size();\n        FPS ret(std::max(0, n - 1));\n        for (int\
    \ i = 1; i < n; i++) ret[i - 1] = (*this)[i] * M(i);\n        return ret;\n  \
    \  }\n\n    FPS integral() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(n + 1);\n        ret[0] = M(0);\n        if (n > 0) ret[1] =\
    \ M(1);\n        auto mod = M::mod();\n        for (int i = 2; i <= n; i++) ret[i]\
    \ = -ret[mod % i] * (mod / i);\n        for (int i = 0; i < n; i++) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n\n    FPS inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != M(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        FPS ret{(*this)[0].inv()};\n       \
    \ ret.reserve(deg);\n        for (int i = 1; i < deg; i <<= 1)\n            ret\
    \ = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);\n        return\
    \ ret.pre(deg);\n    }\n\n    FPS log(int deg = -1) const {\n        assert((*this)[0]\
    \ == M(1));\n        if (deg == -1) deg = (int)this->size();\n        return (differential()\
    \ * inv(deg)).pre(deg - 1).integral();\n    }\n\n    FPS sqrt(const std::function<M(M)>&\
    \ get_sqrt, int deg = -1) const {\n        const int n = this->size();\n     \
    \   if (deg == -1) deg = n;\n        if (this->empty()) return FPS(deg, 0);\n\
    \        if ((*this)[0] == M(0)) {\n            for (int i = 1; i < n; i++) {\n\
    \                if ((*this)[i] != M(0)) {\n                    if (i & 1) return\
    \ {};\n                    if (deg - i / 2 <= 0) break;\n                    auto\
    \ ret = (*this >> i).sqrt(get_sqrt, deg - i / 2);\n                    if (ret.empty())\
    \ return {};\n                    ret = ret << (i / 2);\n                    if\
    \ ((int)ret.size() < deg) ret.resize(deg, M(0));\n                    return ret;\n\
    \                }\n            }\n            return FPS(deg, M(0));\n      \
    \  }\n        auto sqrtf0 = M(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0\
    \ != (*this)[0]) return {};\n        FPS ret{sqrtf0};\n        M inv2 = M(2).inv();\n\
    \        for (int i = 1; i < deg; i <<= 1)\n            ret = (ret + pre(i <<\
    \ 1) * ret.inv(i << 1)) * inv2;\n        return ret.pre(deg);\n    }\n\n    FPS\
    \ exp(int deg = -1) const {\n        assert(this->empty() or (*this)[0] == M(0));\n\
    \        if (this->size() <= 1) return {M(1)};\n        if (deg == -1) deg = (int)this->size();\n\
    \        FPS ret({M(1)});\n        for (int i = 1; i < deg; i <<= 1) {\n     \
    \       ret = (ret * (pre(i << 1) + M(1) - ret.log(i << 1))).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    FPS pow(int64_t k, int deg\
    \ = -1) const {\n        const int n = (int)this->size();\n        if (deg ==\
    \ -1) deg = n;\n        if (k == 0) {\n            auto res = FPS(deg, M(0));\n\
    \            res[0] = M(1);\n            return res;\n        }\n        for (int\
    \ i = 0; i < n; i++) {\n            if ((*this)[i] != M(0)) {\n              \
    \  if (i >= (deg + k - 1) / k) return FPS(deg, M(0));\n                M rev =\
    \ (*this)[i].inv();\n                FPS ret = (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) *\n                          ((*this)[i].pow(k));\n          \
    \      ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size() <\
    \ deg) ret.resize(deg, M(0));\n                return ret;\n            }\n  \
    \      }\n        return FPS(deg, M(0));\n    }\n\n    M eval(M x) const {\n \
    \       M ret = 0, w = 1;\n        for (const auto& v : *this) ret += w * v, w\
    \ *= x;\n        return ret;\n    }\n};\n\ntemplate <class M, int SPARSE>\nvoid\
    \ print(const FormalPowerSeriesArbitarary<M, SPARSE>& v) {\n    for (size_t i\
    \ = 0; i < v.size(); i++) {\n        if (i) std::cout << \" \";\n        std::cout\
    \ << v[i].val();\n    }\n    cout << \"\\n\";\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#include <atcoder/convolution>\n\n#include\
    \ \"mod/arbitrary_convolution.hpp\"\n\ntemplate <typename M, int SPARSE = 10>\n\
    struct FormalPowerSeriesArbitarary : std::vector<M> {\n    using std::vector<M>::vector;\n\
    \    using FPS = FormalPowerSeriesArbitarary;\n\n    FPS static read(int n) {\n\
    \        FPS ret(n);\n        for (int i = 0; i < n; i++) {\n            long\
    \ long x;\n            std::cin >> x;\n            ret[i] = x;\n        }\n  \
    \      return ret;\n    }\n\n    M freq(int p) const {\n        return p < (int)this->size()\
    \ ? (*this)[p] : M(0);\n    }\n\n    void shrink() {\n        while (!this->empty()\
    \ and this->back().val() == 0) this->pop_back();\n    }\n\n    FPS pre(int le)\
    \ const {\n        return FPS(this->begin(),\n                   this->begin()\
    \ + std::min((int)this->size(), le));\n    }\n\n    FPS rev() const {\n      \
    \  FPS ret(*this);\n        std::reverse(ret.begin(), ret.end());\n        return\
    \ ret;\n    }\n\n    int count_nonzero() const {\n        return std::count_if(this->begin(),\
    \ this->end(),\n                             [](M x) { return x.val() != 0; });\n\
    \    }\n\n    std::vector<std::pair<int, M>> get_sparse() const {\n        std::vector<std::pair<int,\
    \ M>> ret;\n        for (size_t i = 0; i < this->size(); i++) {\n            if\
    \ ((*this)[i].val() != 0) ret.emplace_back(i, (*this)[i]);\n        }\n      \
    \  return ret;\n    }\n\n    FPS operator>>(int s) const {\n        if ((int)this->size()\
    \ <= s) return {};\n        return FPS(this->begin() + s, this->end());\n    }\n\
    \n    FPS operator<<(int s) const {\n        if (this->empty()) return {};\n \
    \       FPS ret(*this);\n        ret.insert(ret.begin(), s, M(0));\n        return\
    \ ret;\n    }\n\n    FPS& operator+=(const FPS& r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (size_t i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];\n        shrink();\n        return *this;\n    }\n\n    FPS& operator+=(const\
    \ M& v) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] +=\
    \ v;\n        shrink();\n        return *this;\n    }\n\n    FPS& operator-=(const\
    \ FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < int(r.size()); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator-=(const M& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator*=(const FPS& r) {\n       \
    \ const int z = r.count_nonzero();\n        if (z == 0) {\n            this->clear();\n\
    \            return *this;\n        }\n        if (z <= SPARSE) {\n          \
    \  auto sparse = r.get_sparse();\n            return *this *= sparse;\n      \
    \  }\n        auto res = arbitrary_convolution::multiply(*this, r);\n        return\
    \ *this = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const M& v)\
    \ {\n        for (auto& x : (*this)) x *= v;\n        shrink();\n        return\
    \ *this;\n    }\n\n    FPS& operator*=(const std::vector<std::pair<int, M>>& r)\
    \ {\n        assert(!r.empty());\n        const int m = r.back().first;\n    \
    \    FPS ret(this->size() + m);\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            for (const auto& [j, c] : r) {\n                ret[i +\
    \ j] += (*this)[i] * c;\n            }\n        }\n        ret.shrink();\n   \
    \     return *this = ret;\n    }\n\n    FPS& operator/=(const FPS& r) {\n    \
    \    if (this->size() < r.size()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        const int z = r.count_nonzero();\n        assert(z\
    \ != 0);\n        if (z <= SPARSE) {\n            auto sparse = r.get_sparse();\n\
    \            return *this /= sparse;\n        }\n        int n = this->size()\
    \ - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS& operator/=(const M& v) {\n        assert(v.val() != 0);\n \
    \       auto vinv = v.inv();\n        for (auto& x : (*this)) x *= vinv;\n   \
    \     return *this;\n    }\n\n    FPS& operator/=(const std::vector<std::pair<int,\
    \ M>>& r) {\n        assert(!r.empty());\n        auto [j0, c0] = r.front();\n\
    \        assert(j0 == 0 && c0.val() != 0);\n        auto ic = c0.inv();\n    \
    \    FPS ret(this->size());\n        for (int i = 0; i < (int)this->size(); i++)\
    \ {\n            for (const auto& [j, c] : r) {\n                if (j >= 1 &&\
    \ j <= i) {\n                    ret[i] -= ret[i - j] * c;\n                }\n\
    \            }\n            ret[i] += (*this)[i];\n            ret[i] *= ic;\n\
    \        }\n        ret.shrink();\n        return *this = ret;\n    }\n\n    FPS&\
    \ operator%=(const FPS& r) {\n        *this -= *this / r * r;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS operator+(const FPS& r) const {\n   \
    \     return FPS(*this) += r;\n    }\n\n    FPS operator+(const M& v) const {\n\
    \        return FPS(*this) += v;\n    }\n\n    FPS operator-(const FPS& r) const\
    \ {\n        return FPS(*this) -= r;\n    }\n\n    FPS operator-(const M& v) const\
    \ {\n        return FPS(*this) -= v;\n    }\n\n    FPS operator*(const FPS& r)\
    \ const {\n        return FPS(*this) *= r;\n    }\n\n    FPS operator*(const M&\
    \ v) const {\n        return FPS(*this) *= v;\n    }\n\n    FPS operator/(const\
    \ FPS& r) const {\n        return FPS(*this) /= r;\n    }\n\n    FPS operator%(const\
    \ FPS& r) const {\n        return FPS(*this) %= r;\n    }\n\n    FPS operator-()\
    \ const {\n        FPS ret = *this;\n        for (auto& v : ret) v = -v;\n   \
    \     return ret;\n    }\n\n    FPS differential() const {\n        const int\
    \ n = (int)this->size();\n        FPS ret(std::max(0, n - 1));\n        for (int\
    \ i = 1; i < n; i++) ret[i - 1] = (*this)[i] * M(i);\n        return ret;\n  \
    \  }\n\n    FPS integral() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(n + 1);\n        ret[0] = M(0);\n        if (n > 0) ret[1] =\
    \ M(1);\n        auto mod = M::mod();\n        for (int i = 2; i <= n; i++) ret[i]\
    \ = -ret[mod % i] * (mod / i);\n        for (int i = 0; i < n; i++) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n\n    FPS inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != M(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        FPS ret{(*this)[0].inv()};\n       \
    \ ret.reserve(deg);\n        for (int i = 1; i < deg; i <<= 1)\n            ret\
    \ = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);\n        return\
    \ ret.pre(deg);\n    }\n\n    FPS log(int deg = -1) const {\n        assert((*this)[0]\
    \ == M(1));\n        if (deg == -1) deg = (int)this->size();\n        return (differential()\
    \ * inv(deg)).pre(deg - 1).integral();\n    }\n\n    FPS sqrt(const std::function<M(M)>&\
    \ get_sqrt, int deg = -1) const {\n        const int n = this->size();\n     \
    \   if (deg == -1) deg = n;\n        if (this->empty()) return FPS(deg, 0);\n\
    \        if ((*this)[0] == M(0)) {\n            for (int i = 1; i < n; i++) {\n\
    \                if ((*this)[i] != M(0)) {\n                    if (i & 1) return\
    \ {};\n                    if (deg - i / 2 <= 0) break;\n                    auto\
    \ ret = (*this >> i).sqrt(get_sqrt, deg - i / 2);\n                    if (ret.empty())\
    \ return {};\n                    ret = ret << (i / 2);\n                    if\
    \ ((int)ret.size() < deg) ret.resize(deg, M(0));\n                    return ret;\n\
    \                }\n            }\n            return FPS(deg, M(0));\n      \
    \  }\n        auto sqrtf0 = M(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0\
    \ != (*this)[0]) return {};\n        FPS ret{sqrtf0};\n        M inv2 = M(2).inv();\n\
    \        for (int i = 1; i < deg; i <<= 1)\n            ret = (ret + pre(i <<\
    \ 1) * ret.inv(i << 1)) * inv2;\n        return ret.pre(deg);\n    }\n\n    FPS\
    \ exp(int deg = -1) const {\n        assert(this->empty() or (*this)[0] == M(0));\n\
    \        if (this->size() <= 1) return {M(1)};\n        if (deg == -1) deg = (int)this->size();\n\
    \        FPS ret({M(1)});\n        for (int i = 1; i < deg; i <<= 1) {\n     \
    \       ret = (ret * (pre(i << 1) + M(1) - ret.log(i << 1))).pre(i << 1);\n  \
    \      }\n        return ret.pre(deg);\n    }\n\n    FPS pow(int64_t k, int deg\
    \ = -1) const {\n        const int n = (int)this->size();\n        if (deg ==\
    \ -1) deg = n;\n        if (k == 0) {\n            auto res = FPS(deg, M(0));\n\
    \            res[0] = M(1);\n            return res;\n        }\n        for (int\
    \ i = 0; i < n; i++) {\n            if ((*this)[i] != M(0)) {\n              \
    \  if (i >= (deg + k - 1) / k) return FPS(deg, M(0));\n                M rev =\
    \ (*this)[i].inv();\n                FPS ret = (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) *\n                          ((*this)[i].pow(k));\n          \
    \      ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size() <\
    \ deg) ret.resize(deg, M(0));\n                return ret;\n            }\n  \
    \      }\n        return FPS(deg, M(0));\n    }\n\n    M eval(M x) const {\n \
    \       M ret = 0, w = 1;\n        for (const auto& v : *this) ret += w * v, w\
    \ *= x;\n        return ret;\n    }\n};\n\ntemplate <class M, int SPARSE>\nvoid\
    \ print(const FormalPowerSeriesArbitarary<M, SPARSE>& v) {\n    for (size_t i\
    \ = 0; i < v.size(); i++) {\n        if (i) std::cout << \" \";\n        std::cout\
    \ << v[i].val();\n    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - mod/arbitrary_convolution.hpp
  isVerificationFile: false
  path: mod/FormalPowerSeriesArbitrary.hpp
  requiredBy: []
  timestamp: '2024-10-13 22:59:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/FormalPowerSeriesArbitrary.hpp
layout: document
redirect_from:
- /library/mod/FormalPowerSeriesArbitrary.hpp
- /library/mod/FormalPowerSeriesArbitrary.hpp.html
title: mod/FormalPowerSeriesArbitrary.hpp
---
