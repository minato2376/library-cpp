---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mod/convolution.test.cpp
    title: test/mod/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mod/exp_of_formal_power_series.test.cpp
    title: test/mod/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mod/inv_of_formal_power_series.test.cpp
    title: test/mod/inv_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/FormalPowerSeriesNTTFriendly.hpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include <atcoder/convolution>\n\ntemplate <typename M, int SPARSE = 10>\nstruct\
    \ FormalPowerSeriesNTTFriendly : std::vector<M> {\n    using std::vector<M>::vector;\n\
    \    using FPS = FormalPowerSeriesNTTFriendly;\n\n    FPS static read(int n) {\n\
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
    \  }\n        auto res = atcoder::convolution(*this, r);\n        return *this\
    \ = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const M& v) {\n  \
    \      for (auto& x : (*this)) x *= v;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS& operator*=(const std::vector<std::pair<int, M>>& r) {\n   \
    \     assert(!r.empty());\n        const int m = r.back().first;\n        FPS\
    \ ret(this->size() + m);\n        for (int i = 0; i < (int)this->size(); i++)\
    \ {\n            for (const auto& [j, c] : r) {\n                ret[i + j] +=\
    \ (*this)[i] * c;\n            }\n        }\n        ret.shrink();\n        return\
    \ *this = ret;\n    }\n\n    FPS& operator/=(const FPS& r) {\n        if (this->size()\
    \ < r.size()) {\n            this->clear();\n            return *this;\n     \
    \   }\n        const int z = r.count_nonzero();\n        assert(z != 0);\n   \
    \     if (z <= SPARSE) {\n            auto sparse = r.get_sparse();\n        \
    \    return *this /= sparse;\n        }\n        int n = this->size() - r.size()\
    \ + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
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
    \ ret.reserve(deg);\n        for (int d = 1; d < deg; d <<= 1) {\n           \
    \ FPS f(d << 1), g(d << 1);\n            std::copy(this->begin(), this->begin()\
    \ + std::min(n, d << 1),\n                      f.begin());\n            std::copy(ret.begin(),\
    \ ret.end(), g.begin());\n            atcoder::internal::butterfly(f);\n     \
    \       atcoder::internal::butterfly(g);\n            for (int i = 0; i < (d <<\
    \ 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n \
    \           std::fill(f.begin(), f.begin() + d, M(0));\n            atcoder::internal::butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            M iz = M(d << 1).inv();\n            iz *= -iz;\n            for\
    \ (int i = d; i < std::min(d << 1, deg); i++)\n                ret.push_back(f[i]\
    \ * iz);\n        }\n        return ret.pre(deg);\n    }\n\n    FPS log(int deg\
    \ = -1) const {\n        assert((*this)[0] == M(1));\n        if (deg == -1) deg\
    \ = (int)this->size();\n        return (differential() * inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    FPS sqrt(const std::function<M(M)>& get_sqrt, int deg = -1) const\
    \ {\n        const int n = this->size();\n        if (deg == -1) deg = n;\n  \
    \      if (this->empty()) return FPS(deg, 0);\n        if ((*this)[0] == M(0))\
    \ {\n            for (int i = 1; i < n; i++) {\n                if ((*this)[i]\
    \ != M(0)) {\n                    if (i & 1) return {};\n                    if\
    \ (deg - i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(get_sqrt,\
    \ deg - i / 2);\n                    if (ret.empty()) return {};\n           \
    \         ret = ret << (i / 2);\n                    if ((int)ret.size() < deg)\
    \ ret.resize(deg, M(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, M(0));\n        }\n        auto sqrtf0\
    \ = M(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0 != (*this)[0]) return\
    \ {};\n        FPS ret{sqrtf0};\n        M inv2 = M(2).inv();\n        for (int\
    \ i = 1; i < deg; i <<= 1)\n            ret = (ret + pre(i << 1) * ret.inv(i <<\
    \ 1)) * inv2;\n        return ret.pre(deg);\n    }\n\n    FPS exp(int deg = -1)\
    \ const {\n        assert(this->empty() or (*this)[0] == M(0));\n        if (this->size()\
    \ <= 1) return {M(1)};\n        if (deg == -1) deg = (int)this->size();\n    \
    \    FPS inv;\n        inv.reserve(deg + 1);\n        inv.push_back(M(0));\n \
    \       inv.push_back(M(1));\n        auto inplace_integral = [&](FPS& F) -> void\
    \ {\n            const int n = (int)F.size();\n            auto mod = M::mod();\n\
    \            while ((int)inv.size() <= n) {\n                int i = inv.size();\n\
    \                inv.push_back(-inv[mod % i] * (mod / i));\n            }\n  \
    \          F.insert(F.begin(), M(0));\n            for (int i = 1; i <= n; i++)\
    \ F[i] *= inv[i];\n        };\n        auto inplace_differential = [](FPS& F)\
    \ -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
    \            for (size_t i = 0; i < F.size(); i++) F[i] *= M(i + 1);\n       \
    \ };\n        FPS f{1, (*this)[1]}, g{M(1)}, g_fft{M(1), M(1)};\n        for (int\
    \ m = 2; m < deg; m <<= 1) {\n            const M iz1 = M(m).inv(), iz2 = M(m\
    \ << 1).inv();\n            auto f_fft = f;\n            f_fft.resize(m << 1);\n\
    \            atcoder::internal::butterfly(f_fft);\n            {\n           \
    \     FPS _g(m);\n                for (int i = 0; i < m; i++) _g[i] = f_fft[i]\
    \ * g_fft[i];\n                atcoder::internal::butterfly_inv(_g);\n       \
    \         std::fill(_g.begin(), _g.begin() + (m >> 1), M(0));\n              \
    \  atcoder::internal::butterfly(_g);\n                for (int i = 0; i < m; i++)\
    \ _g[i] *= -g_fft[i] * iz1 * iz1;\n                atcoder::internal::butterfly_inv(_g);\n\
    \                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());\n\n     \
    \           g_fft = g;\n                g_fft.resize(m << 1);\n              \
    \  atcoder::internal::butterfly(g_fft);\n            }\n            FPS x(this->begin(),\n\
    \                  this->begin() + std::min((int)this->size(), m));\n        \
    \    {\n                x.resize(m);\n                inplace_differential(x);\n\
    \                x.push_back(M(0));\n                atcoder::internal::butterfly(x);\n\
    \            }\n            {\n                for (int i = 0; i < m; i++) x[i]\
    \ *= f_fft[i] * iz1;\n                atcoder::internal::butterfly_inv(x);\n \
    \           }\n            {\n                x -= f.differential();\n       \
    \         x.resize(m << 1);\n                for (int i = 0; i < m - 1; i++) x[m\
    \ + i] = x[i], x[i] = M(0);\n                atcoder::internal::butterfly(x);\n\
    \                for (int i = 0; i < (m << 1); i++) x[i] *= g_fft[i] * iz2;\n\
    \                atcoder::internal::butterfly_inv(x);\n            }\n       \
    \     {\n                x.pop_back();\n                inplace_integral(x);\n\
    \                for (int i = m; i < std::min((int)this->size(), m << 1); i++)\n\
    \                    x[i] += (*this)[i];\n                std::fill(x.begin(),\
    \ x.begin() + m, M(0));\n            }\n            {\n                atcoder::internal::butterfly(x);\n\
    \                for (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;\n\
    \                atcoder::internal::butterfly_inv(x);\n                f.insert(f.end(),\
    \ x.begin() + m, x.end());\n            }\n        }\n        return FPS{f.begin(),\
    \ f.begin() + deg};\n    }\n\n    FPS pow(int64_t k, int deg = -1) const {\n \
    \       const int n = (int)this->size();\n        if (deg == -1) deg = n;\n  \
    \      if (k == 0) {\n            auto res = FPS(deg, M(0));\n            res[0]\
    \ = M(1);\n            return res;\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if ((*this)[i] != M(0)) {\n                if (i >= (deg\
    \ + k - 1) / k) return FPS(deg, M(0));\n                M rev = (*this)[i].inv();\n\
    \                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg) *\n  \
    \                        ((*this)[i].pow(k));\n                ret = (ret << (i\
    \ * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ M(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, M(0));\n    }\n\n    M eval(M x) const {\n        M ret = 0, w = 1;\n\
    \        for (const auto& v : *this) ret += w * v, w *= x;\n        return ret;\n\
    \    }\n};\n\ntemplate <class M, int SPARSE>\nvoid print(const FormalPowerSeriesNTTFriendly<M,\
    \ SPARSE>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n        if (i) std::cout\
    \ << \" \";\n        std::cout << v[i].val();\n    }\n    cout << \"\\n\";\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#include <atcoder/convolution>\n\ntemplate\
    \ <typename M, int SPARSE = 10>\nstruct FormalPowerSeriesNTTFriendly : std::vector<M>\
    \ {\n    using std::vector<M>::vector;\n    using FPS = FormalPowerSeriesNTTFriendly;\n\
    \n    FPS static read(int n) {\n        FPS ret(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            long long x;\n            std::cin >> x;\n        \
    \    ret[i] = x;\n        }\n        return ret;\n    }\n\n    M freq(int p) const\
    \ {\n        return p < (int)this->size() ? (*this)[p] : M(0);\n    }\n\n    void\
    \ shrink() {\n        while (!this->empty() and this->back().val() == 0) this->pop_back();\n\
    \    }\n\n    FPS pre(int le) const {\n        return FPS(this->begin(),\n   \
    \                this->begin() + std::min((int)this->size(), le));\n    }\n\n\
    \    FPS rev() const {\n        FPS ret(*this);\n        std::reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    int count_nonzero() const {\n\
    \        return std::count_if(this->begin(), this->end(),\n                  \
    \           [](M x) { return x.val() != 0; });\n    }\n\n    std::vector<std::pair<int,\
    \ M>> get_sparse() const {\n        std::vector<std::pair<int, M>> ret;\n    \
    \    for (size_t i = 0; i < this->size(); i++) {\n            if ((*this)[i].val()\
    \ != 0) ret.emplace_back(i, (*this)[i]);\n        }\n        return ret;\n   \
    \ }\n\n    FPS operator>>(int s) const {\n        if ((int)this->size() <= s)\
    \ return {};\n        return FPS(this->begin() + s, this->end());\n    }\n\n \
    \   FPS operator<<(int s) const {\n        if (this->empty()) return {};\n   \
    \     FPS ret(*this);\n        ret.insert(ret.begin(), s, M(0));\n        return\
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
    \  }\n        auto res = atcoder::convolution(*this, r);\n        return *this\
    \ = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const M& v) {\n  \
    \      for (auto& x : (*this)) x *= v;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS& operator*=(const std::vector<std::pair<int, M>>& r) {\n   \
    \     assert(!r.empty());\n        const int m = r.back().first;\n        FPS\
    \ ret(this->size() + m);\n        for (int i = 0; i < (int)this->size(); i++)\
    \ {\n            for (const auto& [j, c] : r) {\n                ret[i + j] +=\
    \ (*this)[i] * c;\n            }\n        }\n        ret.shrink();\n        return\
    \ *this = ret;\n    }\n\n    FPS& operator/=(const FPS& r) {\n        if (this->size()\
    \ < r.size()) {\n            this->clear();\n            return *this;\n     \
    \   }\n        const int z = r.count_nonzero();\n        assert(z != 0);\n   \
    \     if (z <= SPARSE) {\n            auto sparse = r.get_sparse();\n        \
    \    return *this /= sparse;\n        }\n        int n = this->size() - r.size()\
    \ + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
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
    \ ret.reserve(deg);\n        for (int d = 1; d < deg; d <<= 1) {\n           \
    \ FPS f(d << 1), g(d << 1);\n            std::copy(this->begin(), this->begin()\
    \ + std::min(n, d << 1),\n                      f.begin());\n            std::copy(ret.begin(),\
    \ ret.end(), g.begin());\n            atcoder::internal::butterfly(f);\n     \
    \       atcoder::internal::butterfly(g);\n            for (int i = 0; i < (d <<\
    \ 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n \
    \           std::fill(f.begin(), f.begin() + d, M(0));\n            atcoder::internal::butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            M iz = M(d << 1).inv();\n            iz *= -iz;\n            for\
    \ (int i = d; i < std::min(d << 1, deg); i++)\n                ret.push_back(f[i]\
    \ * iz);\n        }\n        return ret.pre(deg);\n    }\n\n    FPS log(int deg\
    \ = -1) const {\n        assert((*this)[0] == M(1));\n        if (deg == -1) deg\
    \ = (int)this->size();\n        return (differential() * inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    FPS sqrt(const std::function<M(M)>& get_sqrt, int deg = -1) const\
    \ {\n        const int n = this->size();\n        if (deg == -1) deg = n;\n  \
    \      if (this->empty()) return FPS(deg, 0);\n        if ((*this)[0] == M(0))\
    \ {\n            for (int i = 1; i < n; i++) {\n                if ((*this)[i]\
    \ != M(0)) {\n                    if (i & 1) return {};\n                    if\
    \ (deg - i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(get_sqrt,\
    \ deg - i / 2);\n                    if (ret.empty()) return {};\n           \
    \         ret = ret << (i / 2);\n                    if ((int)ret.size() < deg)\
    \ ret.resize(deg, M(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, M(0));\n        }\n        auto sqrtf0\
    \ = M(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0 != (*this)[0]) return\
    \ {};\n        FPS ret{sqrtf0};\n        M inv2 = M(2).inv();\n        for (int\
    \ i = 1; i < deg; i <<= 1)\n            ret = (ret + pre(i << 1) * ret.inv(i <<\
    \ 1)) * inv2;\n        return ret.pre(deg);\n    }\n\n    FPS exp(int deg = -1)\
    \ const {\n        assert(this->empty() or (*this)[0] == M(0));\n        if (this->size()\
    \ <= 1) return {M(1)};\n        if (deg == -1) deg = (int)this->size();\n    \
    \    FPS inv;\n        inv.reserve(deg + 1);\n        inv.push_back(M(0));\n \
    \       inv.push_back(M(1));\n        auto inplace_integral = [&](FPS& F) -> void\
    \ {\n            const int n = (int)F.size();\n            auto mod = M::mod();\n\
    \            while ((int)inv.size() <= n) {\n                int i = inv.size();\n\
    \                inv.push_back(-inv[mod % i] * (mod / i));\n            }\n  \
    \          F.insert(F.begin(), M(0));\n            for (int i = 1; i <= n; i++)\
    \ F[i] *= inv[i];\n        };\n        auto inplace_differential = [](FPS& F)\
    \ -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
    \            for (size_t i = 0; i < F.size(); i++) F[i] *= M(i + 1);\n       \
    \ };\n        FPS f{1, (*this)[1]}, g{M(1)}, g_fft{M(1), M(1)};\n        for (int\
    \ m = 2; m < deg; m <<= 1) {\n            const M iz1 = M(m).inv(), iz2 = M(m\
    \ << 1).inv();\n            auto f_fft = f;\n            f_fft.resize(m << 1);\n\
    \            atcoder::internal::butterfly(f_fft);\n            {\n           \
    \     FPS _g(m);\n                for (int i = 0; i < m; i++) _g[i] = f_fft[i]\
    \ * g_fft[i];\n                atcoder::internal::butterfly_inv(_g);\n       \
    \         std::fill(_g.begin(), _g.begin() + (m >> 1), M(0));\n              \
    \  atcoder::internal::butterfly(_g);\n                for (int i = 0; i < m; i++)\
    \ _g[i] *= -g_fft[i] * iz1 * iz1;\n                atcoder::internal::butterfly_inv(_g);\n\
    \                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());\n\n     \
    \           g_fft = g;\n                g_fft.resize(m << 1);\n              \
    \  atcoder::internal::butterfly(g_fft);\n            }\n            FPS x(this->begin(),\n\
    \                  this->begin() + std::min((int)this->size(), m));\n        \
    \    {\n                x.resize(m);\n                inplace_differential(x);\n\
    \                x.push_back(M(0));\n                atcoder::internal::butterfly(x);\n\
    \            }\n            {\n                for (int i = 0; i < m; i++) x[i]\
    \ *= f_fft[i] * iz1;\n                atcoder::internal::butterfly_inv(x);\n \
    \           }\n            {\n                x -= f.differential();\n       \
    \         x.resize(m << 1);\n                for (int i = 0; i < m - 1; i++) x[m\
    \ + i] = x[i], x[i] = M(0);\n                atcoder::internal::butterfly(x);\n\
    \                for (int i = 0; i < (m << 1); i++) x[i] *= g_fft[i] * iz2;\n\
    \                atcoder::internal::butterfly_inv(x);\n            }\n       \
    \     {\n                x.pop_back();\n                inplace_integral(x);\n\
    \                for (int i = m; i < std::min((int)this->size(), m << 1); i++)\n\
    \                    x[i] += (*this)[i];\n                std::fill(x.begin(),\
    \ x.begin() + m, M(0));\n            }\n            {\n                atcoder::internal::butterfly(x);\n\
    \                for (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;\n\
    \                atcoder::internal::butterfly_inv(x);\n                f.insert(f.end(),\
    \ x.begin() + m, x.end());\n            }\n        }\n        return FPS{f.begin(),\
    \ f.begin() + deg};\n    }\n\n    FPS pow(int64_t k, int deg = -1) const {\n \
    \       const int n = (int)this->size();\n        if (deg == -1) deg = n;\n  \
    \      if (k == 0) {\n            auto res = FPS(deg, M(0));\n            res[0]\
    \ = M(1);\n            return res;\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if ((*this)[i] != M(0)) {\n                if (i >= (deg\
    \ + k - 1) / k) return FPS(deg, M(0));\n                M rev = (*this)[i].inv();\n\
    \                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg) *\n  \
    \                        ((*this)[i].pow(k));\n                ret = (ret << (i\
    \ * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ M(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, M(0));\n    }\n\n    M eval(M x) const {\n        M ret = 0, w = 1;\n\
    \        for (const auto& v : *this) ret += w * v, w *= x;\n        return ret;\n\
    \    }\n};\n\ntemplate <class M, int SPARSE>\nvoid print(const FormalPowerSeriesNTTFriendly<M,\
    \ SPARSE>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n        if (i) std::cout\
    \ << \" \";\n        std::cout << v[i].val();\n    }\n    cout << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/FormalPowerSeriesNTTFriendly.hpp
  requiredBy: []
  timestamp: '2024-10-13 22:59:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mod/inv_of_formal_power_series.test.cpp
  - test/mod/convolution.test.cpp
  - test/mod/exp_of_formal_power_series.test.cpp
documentation_of: mod/FormalPowerSeriesNTTFriendly.hpp
layout: document
redirect_from:
- /library/mod/FormalPowerSeriesNTTFriendly.hpp
- /library/mod/FormalPowerSeriesNTTFriendly.hpp.html
title: mod/FormalPowerSeriesNTTFriendly.hpp
---
