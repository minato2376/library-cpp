---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/FormalPowerSeriesArbitrary.hpp
    title: mod/FormalPowerSeriesArbitrary.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/arbitrary_convolution.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#include <atcoder/convolution>\n\nnamespace\
    \ arbitrary_convolution {\n\ntemplate <class T>\nstd::vector<int> convolution_medium(const\
    \ std::vector<T>& a,\n                                    const std::vector<T>&\
    \ b,\n                                    const int mod) {\n    static constexpr\
    \ int m0 = 1045430273;\n    static constexpr int m1 = 1051721729;\n    static\
    \ constexpr int m2 = 1053818881;\n    static constexpr int r01 = 175287122;  //\
    \ mint1(m0).inv()\n    static constexpr int r02 = 395182206;  // mint2(m0).inv()\n\
    \    static constexpr int r12 = 526909943;  // mint2(m1).inv()\n    static constexpr\
    \ int r02r12 = (long long)(r02)*r12 % m2;\n    static constexpr long long w1 =\
    \ m0;\n    static constexpr long long w2 = (long long)(m0)*m1;\n\n    const int\
    \ n = int(a.size()), m = int(b.size());\n\n    std::vector<T> v0 = atcoder::convolution<m0>(a,\
    \ b);\n    std::vector<T> v1 = atcoder::convolution<m1>(a, b);\n    std::vector<T>\
    \ v2 = atcoder::convolution<m2>(a, b);\n    std::vector<int> ret(n + m - 1);\n\
    \n    const int W1 = w1 % mod;\n    const int W2 = w2 % mod;\n    for (int i =\
    \ 0; i < n + m - 1; i++) {\n        int n1 = v1[i], n2 = v2[i], x = v0[i];\n \
    \       int y = (long long)(n1 + m1 - x) * r01 % m1;\n        int z =\n      \
    \      ((long long)(n2 + m2 - x) * r02r12 + (long long)(m2 - y) * r12) %\n   \
    \         m2;\n        ret[i] = ((long long)(x) + (long long)(y)*W1 + (long long)(z)*W2)\
    \ % mod;\n    }\n\n    return ret;\n}\n\ntemplate <class T>\nstd::vector<int>\
    \ convolution_large(const std::vector<T>& a,\n                               \
    \    const std::vector<T>& b,\n                                   const int mod)\
    \ {\n    static constexpr int m0 = 167772161;\n    static constexpr int m1 = 469762049;\n\
    \    static constexpr int m2 = 754974721;\n    static constexpr int r01 = 104391568;\
    \  // mint1(m0).inv()\n    static constexpr int r02 = 323560596;  // mint2(m0).inv()\n\
    \    static constexpr int r12 = 399692502;  // mint2(m1).inv()\n    static constexpr\
    \ int r02r12 = (long long)(r02)*r12 % m2;\n    static constexpr long long w1 =\
    \ m0;\n    static constexpr long long w2 = (long long)(m0)*m1;\n\n    const int\
    \ n = int(a.size()), m = int(b.size());\n\n    std::vector<T> v0 = atcoder::convolution<m0>(a,\
    \ b);\n    std::vector<T> v1 = atcoder::convolution<m1>(a, b);\n    std::vector<T>\
    \ v2 = atcoder::convolution<m2>(a, b);\n    std::vector<int> ret(n + m - 1);\n\
    \n    const int W1 = w1 % mod;\n    const int W2 = w2 % mod;\n    for (int i =\
    \ 0; i < n + m - 1; i++) {\n        int n1 = v1[i], n2 = v2[i], x = v0[i];\n \
    \       int y = (long long)(n1 + m1 - x) * r01 % m1;\n        int z =\n      \
    \      ((long long)(n2 + m2 - x) * r02r12 + (long long)(m2 - y) * r12) %\n   \
    \         m2;\n        ret[i] = ((long long)(x) + (long long)(y)*W1 + (long long)(z)*W2)\
    \ % mod;\n    }\n\n    return ret;\n}\n\ntemplate <class mint,\n          int\
    \ SMALL = 1 << 7,\n          int MEDIUM = 1 << 20,\n          int LARGE = 1 <<\
    \ 24>\nstd::vector<mint> multiply(std::vector<mint> a, std::vector<mint> b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n or !m) return {};\n\
    \    if (std::min(n, m) <= SMALL) {\n        if (n < m) {\n            std::swap(n,\
    \ m);\n            std::swap(a, b);\n        }\n        std::vector<mint> ret(n\
    \ + m - 1);\n        for (int i = 0; i < n; i++) {\n            for (int j = 0;\
    \ j < m; j++) {\n                ret[i + j] += a[i] * b[j];\n            }\n \
    \       }\n        return ret;\n    }\n    std::vector<int> a_(n), b_(m);\n  \
    \  for (int i = 0; i < n; i++) a_[i] = a[i].val();\n    for (int i = 0; i < m;\
    \ i++) b_[i] = b[i].val();\n    std::vector<int> c;\n    if (n + m - 1 <= MEDIUM)\
    \ {\n        c = convolution_medium<int>(a_, b_, mint::mod());\n    } else if\
    \ (n + m - 1 <= LARGE) {\n        c = convolution_large<int>(a_, b_, mint::mod());\n\
    \    } else {\n        assert(false && \"size is too large\");\n    }\n    std::vector<mint>\
    \ ret(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) ret[i] = mint::raw(c[i]);\n\
    \    return ret;\n}\n}  // namespace arbitrary_convolution\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include <atcoder/convolution>\n\nnamespace arbitrary_convolution {\n\ntemplate\
    \ <class T>\nstd::vector<int> convolution_medium(const std::vector<T>& a,\n  \
    \                                  const std::vector<T>& b,\n                \
    \                    const int mod) {\n    static constexpr int m0 = 1045430273;\n\
    \    static constexpr int m1 = 1051721729;\n    static constexpr int m2 = 1053818881;\n\
    \    static constexpr int r01 = 175287122;  // mint1(m0).inv()\n    static constexpr\
    \ int r02 = 395182206;  // mint2(m0).inv()\n    static constexpr int r12 = 526909943;\
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
    \ ret;\n}\n\ntemplate <class T>\nstd::vector<int> convolution_large(const std::vector<T>&\
    \ a,\n                                   const std::vector<T>& b,\n          \
    \                         const int mod) {\n    static constexpr int m0 = 167772161;\n\
    \    static constexpr int m1 = 469762049;\n    static constexpr int m2 = 754974721;\n\
    \    static constexpr int r01 = 104391568;  // mint1(m0).inv()\n    static constexpr\
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
    \ m - 1; i++) ret[i] = mint::raw(c[i]);\n    return ret;\n}\n}  // namespace arbitrary_convolution"
  dependsOn: []
  isVerificationFile: false
  path: mod/arbitrary_convolution.hpp
  requiredBy:
  - mod/FormalPowerSeriesArbitrary.hpp
  timestamp: '2024-10-13 22:59:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/arbitrary_convolution.hpp
layout: document
redirect_from:
- /library/mod/arbitrary_convolution.hpp
- /library/mod/arbitrary_convolution.hpp.html
title: mod/arbitrary_convolution.hpp
---
