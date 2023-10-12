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
  bundledCode: "#line 2 \"mod/convolution998244353.hpp\"\n\n#include <array>\n#include\
    \ <vector>\n\nnamespace internal {\n\n// @param n `0 <= n`\n// @return minimum\
    \ non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n\
    \    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param\
    \ n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\n\
    int bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\ntemplate\
    \ <class mint> struct fft_info {\n    static constexpr int rank2 = 23;\n    static\
    \ constexpr int g = 3;\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i)\
    \ == 1\n    std::array<mint, rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n\
    \    std::array<mint, rank2 - 1> rate2;\n    std::array<mint, rank2 - 1> irate2;\n\
    \n    std::array<mint, rank2 - 2> rate3;\n    std::array<mint, rank2 - 2> irate3;\n\
    \n    fft_info() {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n\
    \        iroot[rank2] = root[rank2].inv();\n        for (int i = rank2 - 1; i\
    \ >= 0; i--) {\n            root[i] = root[i + 1] * root[i + 1];\n           \
    \ iroot[i] = iroot[i + 1] * iroot[i + 1];\n        }\n\n        {\n          \
    \  mint prod = 1, iprod = 1;\n            for (int i = 0; i <= rank2 - 2; i++)\
    \ {\n                rate2[i] = root[i + 2] * prod;\n                irate2[i]\
    \ = iroot[i + 2] * iprod;\n                prod *= iroot[i + 2];\n           \
    \     iprod *= root[i + 2];\n            }\n        }\n        {\n           \
    \ mint prod = 1, iprod = 1;\n            for (int i = 0; i <= rank2 - 3; i++)\
    \ {\n                rate3[i] = root[i + 3] * prod;\n                irate3[i]\
    \ = iroot[i + 3] * iprod;\n                prod *= iroot[i + 3];\n           \
    \     iprod *= root[i + 3];\n            }\n        }\n    }\n};\n\ntemplate <class\
    \ mint> void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n \
    \   int h = internal::ceil_pow2(n);\n\n    static const fft_info<mint> info;\n\
    \n    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   \
    \ while (len < h) {\n        if (h - len == 1) {\n            int p = 1 << (h\
    \ - len - 1);\n            mint rot = 1;\n            for (int s = 0; s < (1 <<\
    \ len); s++) {\n                int offset = s << (h - len);\n               \
    \ for (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p] * rot;\n                    a[i\
    \ + offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
    \         }\n                if (s + 1 != (1 << len))\n                    rot\
    \ *= info.rate2[bsf(~(unsigned int)(s))];\n            }\n            len++;\n\
    \        } else {\n            // 4-base\n            int p = 1 << (h - len -\
    \ 2);\n            mint rot = 1, imag = info.root[2];\n            for (int s\
    \ = 0; s < (1 << len); s++) {\n                mint rot2 = rot * rot;\n      \
    \          mint rot3 = rot2 * rot;\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    auto mod2\
    \ = 1ULL * mint::mod() * mint::mod();\n                    auto a0 = 1ULL * a[i\
    \ + offset].val();\n                    auto a1 = 1ULL * a[i + offset + p].val()\
    \ * rot.val();\n                    auto a2 = 1ULL * a[i + offset + 2 * p].val()\
    \ * rot2.val();\n                    auto a3 = 1ULL * a[i + offset + 3 * p].val()\
    \ * rot3.val();\n                    auto a1na3imag =\n                      \
    \  1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n                    auto na2\
    \ = mod2 - a2;\n                    a[i + offset] = a0 + a2 + a1 + a3;\n     \
    \               a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n  \
    \                  a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n           \
    \         a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n           \
    \     }\n                if (s + 1 != (1 << len))\n                    rot *=\
    \ info.rate3[bsf(~(unsigned int)(s))];\n            }\n            len += 2;\n\
    \        }\n    }\n}\n\ntemplate <class mint> void butterfly_inv(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = h;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len) {\n        if (len == 1) {\n\
    \            int p = 1 << (h - len);\n            mint irot = 1;\n           \
    \ for (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s\
    \ << (h - len + 1);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] =\n                        (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) *\n                        irot.val();\n                    ;\n \
    \               }\n                if (s + 1 != (1 << (len - 1)))\n          \
    \          irot *= info.irate2[bsf(~(unsigned int)(s))];\n            }\n    \
    \        len--;\n        } else {\n            // 4-base\n            int p =\
    \ 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n       \
    \     for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = 1ULL * a[i + offset + 0 * p].val();\n     \
    \               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n              \
    \      auto a2 = 1ULL * a[i + offset + 2 * p].val();\n                    auto\
    \ a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                    auto a2na3iimag\
    \ =\n                        1ULL *\n                        mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + 1 * p] =\n               \
    \         (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n             \
    \       a[i + offset + 2 * p] =\n                        (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n      \
    \              a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[bsf(~(unsigned int)(s))];\n            }\n   \
    \         len -= 2;\n        }\n    }\n}\n\ntemplate <class mint>\nstd::vector<mint>\
    \ convolution_fft(std::vector<mint> a, std::vector<mint> b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    int z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n\
    \    internal::butterfly(a);\n    b.resize(z);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < z; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i\
    \ < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n}  // namespace internal\n\n\
    template <class mint>\nstd::vector<mint> convolution_naive(const std::vector<mint>&\
    \ a,\n                                    const std::vector<mint>& b) {\n    int\
    \ n = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint>\n\
    std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \    if (std::min(n, m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n\ntemplate <class mint>\nstd::vector<mint> convolution(const std::vector<mint>&\
    \ a,\n                              const std::vector<mint>& b) {\n    int n =\
    \ int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n"
  code: "#pragma once\n\n#include <array>\n#include <vector>\n\nnamespace internal\
    \ {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\n\
    int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\ntemplate <class mint> struct\
    \ fft_info {\n    static constexpr int rank2 = 23;\n    static constexpr int g\
    \ = 3;\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, rank2\
    \ - 1> rate2;\n    std::array<mint, rank2 - 1> irate2;\n\n    std::array<mint,\
    \ rank2 - 2> rate3;\n    std::array<mint, rank2 - 2> irate3;\n\n    fft_info()\
    \ {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            iroot[i] = iroot[i +\
    \ 1] * iroot[i + 1];\n        }\n\n        {\n            mint prod = 1, iprod\
    \ = 1;\n            for (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i]\
    \ = root[i + 2] * prod;\n                irate2[i] = iroot[i + 2] * iprod;\n \
    \               prod *= iroot[i + 2];\n                iprod *= root[i + 2];\n\
    \            }\n        }\n        {\n            mint prod = 1, iprod = 1;\n\
    \            for (int i = 0; i <= rank2 - 3; i++) {\n                rate3[i]\
    \ = root[i + 3] * prod;\n                irate3[i] = iroot[i + 3] * iprod;\n \
    \               prod *= iroot[i + 3];\n                iprod *= root[i + 3];\n\
    \            }\n        }\n    }\n};\n\ntemplate <class mint> void butterfly(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = 0;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len < h) {\n        if (h - len\
    \ == 1) {\n            int p = 1 << (h - len - 1);\n            mint rot = 1;\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                int offset\
    \ = s << (h - len);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p] * rot;\n                    a[i + offset] = l + r;\n                  \
    \  a[i + offset + p] = l - r;\n                }\n                if (s + 1 !=\
    \ (1 << len))\n                    rot *= info.rate2[bsf(~(unsigned int)(s))];\n\
    \            }\n            len++;\n        } else {\n            // 4-base\n\
    \            int p = 1 << (h - len - 2);\n            mint rot = 1, imag = info.root[2];\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
    \ = rot * rot;\n                mint rot3 = rot2 * rot;\n                int offset\
    \ = s << (h - len);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto mod2 = 1ULL * mint::mod() * mint::mod();\n                  \
    \  auto a0 = 1ULL * a[i + offset].val();\n                    auto a1 = 1ULL *\
    \ a[i + offset + p].val() * rot.val();\n                    auto a2 = 1ULL * a[i\
    \ + offset + 2 * p].val() * rot2.val();\n                    auto a3 = 1ULL *\
    \ a[i + offset + 3 * p].val() * rot3.val();\n                    auto a1na3imag\
    \ =\n                        1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n\
    \                    auto na2 = mod2 - a2;\n                    a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n                    a[i + offset + 1 * p] = a0 + a2 +\
    \ (2 * mod2 - (a1 + a3));\n                    a[i + offset + 2 * p] = a0 + na2\
    \ + a1na3imag;\n                    a[i + offset + 3 * p] = a0 + na2 + (mod2 -\
    \ a1na3imag);\n                }\n                if (s + 1 != (1 << len))\n \
    \                   rot *= info.rate3[bsf(~(unsigned int)(s))];\n            }\n\
    \            len += 2;\n        }\n    }\n}\n\ntemplate <class mint> void butterfly_inv(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = h;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len) {\n        if (len == 1) {\n\
    \            int p = 1 << (h - len);\n            mint irot = 1;\n           \
    \ for (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s\
    \ << (h - len + 1);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] =\n                        (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) *\n                        irot.val();\n                    ;\n \
    \               }\n                if (s + 1 != (1 << (len - 1)))\n          \
    \          irot *= info.irate2[bsf(~(unsigned int)(s))];\n            }\n    \
    \        len--;\n        } else {\n            // 4-base\n            int p =\
    \ 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n       \
    \     for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = 1ULL * a[i + offset + 0 * p].val();\n     \
    \               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n              \
    \      auto a2 = 1ULL * a[i + offset + 2 * p].val();\n                    auto\
    \ a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                    auto a2na3iimag\
    \ =\n                        1ULL *\n                        mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + 1 * p] =\n               \
    \         (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n             \
    \       a[i + offset + 2 * p] =\n                        (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n      \
    \              a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[bsf(~(unsigned int)(s))];\n            }\n   \
    \         len -= 2;\n        }\n    }\n}\n\ntemplate <class mint>\nstd::vector<mint>\
    \ convolution_fft(std::vector<mint> a, std::vector<mint> b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    int z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n\
    \    internal::butterfly(a);\n    b.resize(z);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < z; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i\
    \ < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n}  // namespace internal\n\n\
    template <class mint>\nstd::vector<mint> convolution_naive(const std::vector<mint>&\
    \ a,\n                                    const std::vector<mint>& b) {\n    int\
    \ n = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint>\n\
    std::vector<mint> convolution(std::vector<mint>&& a, std::vector<mint>&& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \    if (std::min(n, m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n\ntemplate <class mint>\nstd::vector<mint> convolution(const std::vector<mint>&\
    \ a,\n                              const std::vector<mint>& b) {\n    int n =\
    \ int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/convolution998244353.hpp
  requiredBy: []
  timestamp: '2023-10-13 01:31:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/convolution998244353.hpp
layout: document
redirect_from:
- /library/mod/convolution998244353.hpp
- /library/mod/convolution998244353.hpp.html
title: mod/convolution998244353.hpp
---
