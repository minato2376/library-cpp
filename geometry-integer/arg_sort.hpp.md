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
  bundledCode: "#line 2 \"geometry-integer/arg_sort.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n#include <numeric>\n\n/**\n * * * * | *\
    \ * *\n * * 7 * 6 * 5 *\n * * * * | * * *\n * --8---4---4--\n * * * * | * * *\n\
    \ * * 1 * 2 * 3 *\n * * * * | * * *\n */\nstd::vector<int> arg_sort(const std::vector<int>&\
    \ X,\n                          const std::vector<int>& Y) {\n    assert(X.size()\
    \ == Y.size());\n    int n = X.size();\n\n    std::vector<int> ids(n), pos(n);\n\
    \    std::iota(ids.begin(), ids.end(), 0);\n    for (int i = 0; i < n; i++) {\n\
    \        if (Y[i] < 0)\n            pos[i] = -1;\n        else if (Y[i] == 0 and\
    \ 0 <= X[i])\n            pos[i] = 0;\n        else\n            pos[i] = 1;\n\
    \    }\n\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n        if\
    \ (pos[i] != pos[j]) return pos[i] < pos[j];\n        return X[i] * Y[j] < X[j]\
    \ * Y[i];\n    });\n    return ids;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include <numeric>\n\n/**\n * * * * | * * *\n * * 7 * 6 * 5 *\n * * * * | * *\
    \ *\n * --8---4---4--\n * * * * | * * *\n * * 1 * 2 * 3 *\n * * * * | * * *\n\
    \ */\nstd::vector<int> arg_sort(const std::vector<int>& X,\n                 \
    \         const std::vector<int>& Y) {\n    assert(X.size() == Y.size());\n  \
    \  int n = X.size();\n\n    std::vector<int> ids(n), pos(n);\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    for (int i = 0; i < n; i++) {\n        if (Y[i] < 0)\n \
    \           pos[i] = -1;\n        else if (Y[i] == 0 and 0 <= X[i])\n        \
    \    pos[i] = 0;\n        else\n            pos[i] = 1;\n    }\n\n    std::sort(ids.begin(),\
    \ ids.end(), [&](int i, int j) {\n        if (pos[i] != pos[j]) return pos[i]\
    \ < pos[j];\n        return X[i] * Y[j] < X[j] * Y[i];\n    });\n    return ids;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: geometry-integer/arg_sort.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry-integer/arg_sort.hpp
layout: document
redirect_from:
- /library/geometry-integer/arg_sort.hpp
- /library/geometry-integer/arg_sort.hpp.html
title: geometry-integer/arg_sort.hpp
---
