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
  bundledCode: "#line 2 \"datastructure/use_dynamic_bitset.hpp\"\n\n#include <algorithm>\n\
    #include <bitset>\n#include <cassert>\n\n/**\n * example:\n *  auto f = [&](auto\
    \ _) {\n *      using DynamicBitset = decltype(_);\n *      ...\n *  };\n *  use_dynamic_bitset<1000000>(n,\
    \ f);\n */\ntemplate <int MAX_N, class F, int N = 1>\nvoid use_dynamic_bitset(int\
    \ n, const F& f) {\n    assert(n <= MAX_N);\n    if (n <= N) {\n        std::bitset<N>\
    \ bs;\n        f(bs);\n        return;\n    }\n    use_dynamic_bitset<MAX_N, F,\
    \ std::min(N * 2, MAX_N)>(n, f);\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n\
    \n/**\n * example:\n *  auto f = [&](auto _) {\n *      using DynamicBitset =\
    \ decltype(_);\n *      ...\n *  };\n *  use_dynamic_bitset<1000000>(n, f);\n\
    \ */\ntemplate <int MAX_N, class F, int N = 1>\nvoid use_dynamic_bitset(int n,\
    \ const F& f) {\n    assert(n <= MAX_N);\n    if (n <= N) {\n        std::bitset<N>\
    \ bs;\n        f(bs);\n        return;\n    }\n    use_dynamic_bitset<MAX_N, F,\
    \ std::min(N * 2, MAX_N)>(n, f);\n}"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/use_dynamic_bitset.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/use_dynamic_bitset.hpp
layout: document
redirect_from:
- /library/datastructure/use_dynamic_bitset.hpp
- /library/datastructure/use_dynamic_bitset.hpp.html
title: datastructure/use_dynamic_bitset.hpp
---
