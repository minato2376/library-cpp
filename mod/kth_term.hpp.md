---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/berlekamp_massey.hpp
    title: mod/berlekamp_massey.hpp
  - icon: ':warning:'
    path: mod/bostan_mori.hpp
    title: Bostan-Mori Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/kth_term.hpp\"\n\n#line 2 \"mod/berlekamp_massey.hpp\"\
    \n\n#include <vector>\n\ntemplate <class mint>\nstd::vector<mint> berlekamp_massey(const\
    \ std::vector<mint>& s) {\n    const int N = (int)s.size();\n    std::vector<mint>\
    \ b, c;\n    b.reserve(N + 1);\n    c.reserve(N + 1);\n    b.push_back(mint(1));\n\
    \    c.push_back(mint(1));\n    mint y = mint(1);\n    for (int ed = 1; ed <=\
    \ N; ed++) {\n        int l = int(c.size()), m = int(b.size());\n        mint\
    \ x = 0;\n        for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];\n   \
    \     b.emplace_back(mint(0));\n        m++;\n        if (x == mint(0)) continue;\n\
    \        mint freq = x / y;\n        if (l < m) {\n            auto tmp = c;\n\
    \            c.insert(c.begin(), m - l, mint(0));\n            for (int i = 0;\
    \ i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n            b = tmp;\n   \
    \         y = x;\n        } else {\n            for (int i = 0; i < m; i++) c[l\
    \ - 1 - i] -= freq * b[m - 1 - i];\n        }\n    }\n    reverse(c.begin(), c.end());\n\
    \    return c;\n}\n#line 2 \"mod/bostan_mori.hpp\"\n\n#include <cassert>\n#line\
    \ 5 \"mod/bostan_mori.hpp\"\n\n/**\n * @brief Bostan-Mori Algorithm\n *\n */\n\
    template <class mint,\n          std::vector<mint> (*convolution)(std::vector<mint>,\n\
    \                                           std::vector<mint>)>\nmint bostan_mori(std::vector<mint>\
    \ P, std::vector<mint> Q, long long N) {\n    assert(Q[0] == 1);\n    assert(P.size()\
    \ < Q.size());\n    int D = Q.size();\n    while (N) {\n        auto Q_neg = Q;\n\
    \        for (int i = 1; i < int(Q.size()); i += 2) Q_neg[i] *= -1;\n        P\
    \ = convolution(P, Q_neg);\n        Q = convolution(Q, Q_neg);\n        for (int\
    \ i = N & 1; i < int(P.size()); i += 2) P[i >> 1] = P[i];\n        for (int i\
    \ = 0; i < int(Q.size()); i += 2) Q[i >> 1] = Q[i];\n        P.resize(D - 1);\n\
    \        Q.resize(D);\n        N >>= 1;\n    }\n    return P[0];\n}\n#line 6 \"\
    mod/kth_term.hpp\"\n\ntemplate <class mint,\n          std::vector<mint> (*convolution)(std::vector<mint>,\n\
    \                                           std::vector<mint>)>\nmint kth_term(std::vector<mint>\
    \ a, long long N) {\n    std::vector<mint> c = berlekamp_massey(a);\n    auto\
    \ b = convolution(a, c);\n    b.resize(c.size() - 1);\n    return bostan_mori<mint,\
    \ convolution>(b, c, N);\n}\n"
  code: "#pragma once\n\n#include \"mod/berlekamp_massey.hpp\"\n#include \"mod/bostan_mori.hpp\"\
    \n#include <vector>\n\ntemplate <class mint,\n          std::vector<mint> (*convolution)(std::vector<mint>,\n\
    \                                           std::vector<mint>)>\nmint kth_term(std::vector<mint>\
    \ a, long long N) {\n    std::vector<mint> c = berlekamp_massey(a);\n    auto\
    \ b = convolution(a, c);\n    b.resize(c.size() - 1);\n    return bostan_mori<mint,\
    \ convolution>(b, c, N);\n}"
  dependsOn:
  - mod/berlekamp_massey.hpp
  - mod/bostan_mori.hpp
  isVerificationFile: false
  path: mod/kth_term.hpp
  requiredBy: []
  timestamp: '2023-10-13 01:31:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/kth_term.hpp
layout: document
redirect_from:
- /library/mod/kth_term.hpp
- /library/mod/kth_term.hpp.html
title: mod/kth_term.hpp
---
