---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/kth_term.hpp
    title: mod/kth_term.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Bostan-Mori Algorithm
    links: []
  bundledCode: "#line 2 \"mod/bostan_mori.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#include <atcoder/convolution>\n\n/**\n * @brief Bostan-Mori Algorithm\n *\n\
    \ */\ntemplate <class mint>\nmint bostan_mori(std::vector<mint> P, std::vector<mint>\
    \ Q, long long N) {\n    assert(Q[0] == 1);\n    assert(P.size() < Q.size());\n\
    \    int D = Q.size();\n    while (N) {\n        auto Q_neg = Q;\n        for\
    \ (int i = 1; i < int(Q.size()); i += 2) Q_neg[i] *= -1;\n        P = atcoder::convolution(P,\
    \ Q_neg);\n        Q = atcoder::convolution(Q, Q_neg);\n        for (int i = N\
    \ & 1; i < int(P.size()); i += 2) P[i >> 1] = P[i];\n        for (int i = 0; i\
    \ < int(Q.size()); i += 2) Q[i >> 1] = Q[i];\n        P.resize(D - 1);\n     \
    \   Q.resize(D);\n        N >>= 1;\n    }\n    return P[0];\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include <atcoder/convolution>\n\
    \n/**\n * @brief Bostan-Mori Algorithm\n *\n */\ntemplate <class mint>\nmint bostan_mori(std::vector<mint>\
    \ P, std::vector<mint> Q, long long N) {\n    assert(Q[0] == 1);\n    assert(P.size()\
    \ < Q.size());\n    int D = Q.size();\n    while (N) {\n        auto Q_neg = Q;\n\
    \        for (int i = 1; i < int(Q.size()); i += 2) Q_neg[i] *= -1;\n        P\
    \ = atcoder::convolution(P, Q_neg);\n        Q = atcoder::convolution(Q, Q_neg);\n\
    \        for (int i = N & 1; i < int(P.size()); i += 2) P[i >> 1] = P[i];\n  \
    \      for (int i = 0; i < int(Q.size()); i += 2) Q[i >> 1] = Q[i];\n        P.resize(D\
    \ - 1);\n        Q.resize(D);\n        N >>= 1;\n    }\n    return P[0];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/bostan_mori.hpp
  requiredBy:
  - mod/kth_term.hpp
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/bostan_mori.hpp
layout: document
redirect_from:
- /library/mod/bostan_mori.hpp
- /library/mod/bostan_mori.hpp.html
title: Bostan-Mori Algorithm
---
