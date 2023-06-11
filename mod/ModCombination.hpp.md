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
  bundledCode: "#line 2 \"mod/ModCombination.hpp\"\n\ntemplate <class M> struct ModCombination\
    \ {\n  public:\n    ModCombination() {\n    }\n    ModCombination(int n) : n_(n),\
    \ fac_(n + 1), facinv_(n + 1) {\n        assert(1 <= n);\n        fac_[0] = 1;\n\
    \        for (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;\n        facinv_[n]\
    \ = M(1) / fac_[n];\n        for (int i = n; i >= 1; i--) facinv_[i - 1] = facinv_[i]\
    \ * i;\n    }\n\n    M fac(int k) const {\n        assert(0 <= k and k <= n_);\n\
    \        return fac_[k];\n    }\n    M facinv(int k) const {\n        assert(0\
    \ <= k and k <= n_);\n        return facinv_[k];\n    }\n    M inv(int k) const\
    \ {\n        assert(1 <= k and k <= n_);\n        return facinv_[k] * fac_[k -\
    \ 1];\n    }\n\n    M P(int n, int k) const {\n        if (k < 0 or k > n) return\
    \ M(0);\n        assert(n <= n_);\n        return fac_[n] * facinv_[n - k];\n\
    \    }\n    M C(int n, int k) const {\n        if (k < 0 or k > n) return M(0);\n\
    \        assert(n <= n_);\n        return fac_[n] * facinv_[n - k] * facinv_[k];\n\
    \    }\n\n    /**\n     * @note H(n, k) = (n \u500B \u306E\u30DC\u30FC\u30EB\u3092\
    \ k \u500B\u306E\u7BB1\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570)\n    \
    \ * @note H(n, k) = C(n + k - 1, n)\n     */\n    M H(int n, int k) const {\n\
    \        if (n == 0 and k == 0) return M(1);\n        return C(n + k - 1, n);\n\
    \    }\n    M catalan(int n) const {\n        if (n == 0) return M(1);\n     \
    \   return C(2 * n, n) - C(2 * n, n - 1);\n    }\n\n  private:\n    int n_;\n\
    \    vector<M> fac_, facinv_;\n};\n"
  code: "#pragma once\n\ntemplate <class M> struct ModCombination {\n  public:\n \
    \   ModCombination() {\n    }\n    ModCombination(int n) : n_(n), fac_(n + 1),\
    \ facinv_(n + 1) {\n        assert(1 <= n);\n        fac_[0] = 1;\n        for\
    \ (int i = 1; i <= n; i++) fac_[i] = fac_[i - 1] * i;\n        facinv_[n] = M(1)\
    \ / fac_[n];\n        for (int i = n; i >= 1; i--) facinv_[i - 1] = facinv_[i]\
    \ * i;\n    }\n\n    M fac(int k) const {\n        assert(0 <= k and k <= n_);\n\
    \        return fac_[k];\n    }\n    M facinv(int k) const {\n        assert(0\
    \ <= k and k <= n_);\n        return facinv_[k];\n    }\n    M inv(int k) const\
    \ {\n        assert(1 <= k and k <= n_);\n        return facinv_[k] * fac_[k -\
    \ 1];\n    }\n\n    M P(int n, int k) const {\n        if (k < 0 or k > n) return\
    \ M(0);\n        assert(n <= n_);\n        return fac_[n] * facinv_[n - k];\n\
    \    }\n    M C(int n, int k) const {\n        if (k < 0 or k > n) return M(0);\n\
    \        assert(n <= n_);\n        return fac_[n] * facinv_[n - k] * facinv_[k];\n\
    \    }\n\n    /**\n     * @note H(n, k) = (n \u500B \u306E\u30DC\u30FC\u30EB\u3092\
    \ k \u500B\u306E\u7BB1\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570)\n    \
    \ * @note H(n, k) = C(n + k - 1, n)\n     */\n    M H(int n, int k) const {\n\
    \        if (n == 0 and k == 0) return M(1);\n        return C(n + k - 1, n);\n\
    \    }\n    M catalan(int n) const {\n        if (n == 0) return M(1);\n     \
    \   return C(2 * n, n) - C(2 * n, n - 1);\n    }\n\n  private:\n    int n_;\n\
    \    vector<M> fac_, facinv_;\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/ModCombination.hpp
  requiredBy: []
  timestamp: '2023-06-12 01:28:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/ModCombination.hpp
layout: document
redirect_from:
- /library/mod/ModCombination.hpp
- /library/mod/ModCombination.hpp.html
title: mod/ModCombination.hpp
---
