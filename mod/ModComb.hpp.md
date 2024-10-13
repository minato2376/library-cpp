---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/BinomialPrefixSum.hpp
    title: mod/BinomialPrefixSum.hpp
  - icon: ':warning:'
    path: mod/count_increasing_sequence.hpp
    title: mod/count_increasing_sequence.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/ModComb.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <class mint> struct ModComb {\n    static int n;\n    static std::vector<mint>\
    \ fac_, facinv_;\n\n    static void init(int n_ = 1000000) {\n        n = n_;\n\
    \        fac_.resize(n + 1);\n        facinv_.resize(n + 1);\n        fac_[0]\
    \ = 1;\n        for (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;\n    \
    \    facinv_[n] = mint(1) / fac_[n];\n        for (int i = n; i >= 1; i--) facinv_[i\
    \ - 1] = facinv_[i] * i;\n    }\n\n    static void resize(int m) {\n        if\
    \ (m <= n) return;\n        if (n == -1) {\n            init(m);\n           \
    \ return;\n        }\n        m = std::max(m, 2 * n);\n        fac_.resize(m +\
    \ 1);\n        facinv_.resize(m + 1);\n        for (int i = n + 1; i <= m; i++)\
    \ {\n            fac_[i] = fac_[i - 1] * i;\n        }\n        facinv_[m] = mint(1)\
    \ / fac_[m];\n        for (int i = m - 1; i >= n; i--) {\n            facinv_[i]\
    \ = facinv_[i + 1] * (i + 1);\n        }\n        n = m;\n    }\n\n    static\
    \ mint fac(int k) {\n        resize(k);\n        return fac_[k];\n    }\n    static\
    \ mint facinv(int k) {\n        resize(k);\n        return facinv_[k];\n    }\n\
    \    static mint inv(int k) {\n        resize(k);\n        return facinv_[k] *\
    \ fac_[k - 1];\n    }\n\n    static mint P(int n, int k) {\n        if (k < 0\
    \ or k > n) return mint(0);\n        resize(n);\n        return fac_[n] * facinv_[n\
    \ - k];\n    }\n    static mint C(int n, int k) {\n        if (k < 0 or k > n)\
    \ return mint(0);\n        resize(n);\n        return fac_[n] * facinv_[n - k]\
    \ * facinv_[k];\n    }\n\n    /**\n     * @note H(n, k) = (n \u500B \u306E\u30DC\
    \u30FC\u30EB\u3092 k \u500B\u306E\u7BB1\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\
    \u6570)\n     * @note H(n, k) = C(n + k - 1, n)\n     * @note H(n, k) = [x ^ n]\
    \ (1 / (1 - x) ^ k)\n     */\n    static mint H(int n, int k) {\n        if (n\
    \ == 0 and k == 0) return mint(1);\n        return C(n + k - 1, n);\n    }\n \
    \   static mint catalan(int n) {\n        if (n == 0) return mint(1);\n      \
    \  return C(2 * n, n) - C(2 * n, n - 1);\n    }\n};\n\ntemplate <class mint> int\
    \ ModComb<mint>::n = -1;\ntemplate <class mint> std::vector<mint> ModComb<mint>::fac_;\n\
    template <class mint> std::vector<mint> ModComb<mint>::facinv_;\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <class\
    \ mint> struct ModComb {\n    static int n;\n    static std::vector<mint> fac_,\
    \ facinv_;\n\n    static void init(int n_ = 1000000) {\n        n = n_;\n    \
    \    fac_.resize(n + 1);\n        facinv_.resize(n + 1);\n        fac_[0] = 1;\n\
    \        for (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;\n        facinv_[n]\
    \ = mint(1) / fac_[n];\n        for (int i = n; i >= 1; i--) facinv_[i - 1] =\
    \ facinv_[i] * i;\n    }\n\n    static void resize(int m) {\n        if (m <=\
    \ n) return;\n        if (n == -1) {\n            init(m);\n            return;\n\
    \        }\n        m = std::max(m, 2 * n);\n        fac_.resize(m + 1);\n   \
    \     facinv_.resize(m + 1);\n        for (int i = n + 1; i <= m; i++) {\n   \
    \         fac_[i] = fac_[i - 1] * i;\n        }\n        facinv_[m] = mint(1)\
    \ / fac_[m];\n        for (int i = m - 1; i >= n; i--) {\n            facinv_[i]\
    \ = facinv_[i + 1] * (i + 1);\n        }\n        n = m;\n    }\n\n    static\
    \ mint fac(int k) {\n        resize(k);\n        return fac_[k];\n    }\n    static\
    \ mint facinv(int k) {\n        resize(k);\n        return facinv_[k];\n    }\n\
    \    static mint inv(int k) {\n        resize(k);\n        return facinv_[k] *\
    \ fac_[k - 1];\n    }\n\n    static mint P(int n, int k) {\n        if (k < 0\
    \ or k > n) return mint(0);\n        resize(n);\n        return fac_[n] * facinv_[n\
    \ - k];\n    }\n    static mint C(int n, int k) {\n        if (k < 0 or k > n)\
    \ return mint(0);\n        resize(n);\n        return fac_[n] * facinv_[n - k]\
    \ * facinv_[k];\n    }\n\n    /**\n     * @note H(n, k) = (n \u500B \u306E\u30DC\
    \u30FC\u30EB\u3092 k \u500B\u306E\u7BB1\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\
    \u6570)\n     * @note H(n, k) = C(n + k - 1, n)\n     * @note H(n, k) = [x ^ n]\
    \ (1 / (1 - x) ^ k)\n     */\n    static mint H(int n, int k) {\n        if (n\
    \ == 0 and k == 0) return mint(1);\n        return C(n + k - 1, n);\n    }\n \
    \   static mint catalan(int n) {\n        if (n == 0) return mint(1);\n      \
    \  return C(2 * n, n) - C(2 * n, n - 1);\n    }\n};\n\ntemplate <class mint> int\
    \ ModComb<mint>::n = -1;\ntemplate <class mint> std::vector<mint> ModComb<mint>::fac_;\n\
    template <class mint> std::vector<mint> ModComb<mint>::facinv_;"
  dependsOn: []
  isVerificationFile: false
  path: mod/ModComb.hpp
  requiredBy:
  - mod/BinomialPrefixSum.hpp
  - mod/count_increasing_sequence.hpp
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/ModComb.hpp
layout: document
redirect_from:
- /library/mod/ModComb.hpp
- /library/mod/ModComb.hpp.html
title: mod/ModComb.hpp
---
