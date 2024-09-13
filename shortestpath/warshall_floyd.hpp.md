---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/shortestpath/warshall_floyd.test.cpp
    title: test/shortestpath/warshall_floyd.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortestpath/warshall_floyd.hpp\"\n\n#include <vector>\n\
    \ntemplate <typename Int>\nstd::vector<std::vector<Int>> warshall_floyd(\n   \
    \ const std::vector<std::vector<Int>>& G,\n    Int INF) {\n    int N = G.size();\n\
    \    auto dist = G;\n\n    for (int k = 0; k < N; k++) {\n        for (int i =\
    \ 0; i < N; i++) {\n            if (dist[i][k] == INF) continue;\n           \
    \ for (int j = 0; j < N; j++) {\n                if (dist[k][j] == INF) continue;\n\
    \                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\n    \
    \        }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <typename Int>\nstd::vector<std::vector<Int>>\
    \ warshall_floyd(\n    const std::vector<std::vector<Int>>& G,\n    Int INF) {\n\
    \    int N = G.size();\n    auto dist = G;\n\n    for (int k = 0; k < N; k++)\
    \ {\n        for (int i = 0; i < N; i++) {\n            if (dist[i][k] == INF)\
    \ continue;\n            for (int j = 0; j < N; j++) {\n                if (dist[k][j]\
    \ == INF) continue;\n                dist[i][j] = min(dist[i][j], dist[i][k] +\
    \ dist[k][j]);\n            }\n        }\n    }\n    return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: shortestpath/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/shortestpath/warshall_floyd.test.cpp
documentation_of: shortestpath/warshall_floyd.hpp
layout: document
redirect_from:
- /library/shortestpath/warshall_floyd.hpp
- /library/shortestpath/warshall_floyd.hpp.html
title: shortestpath/warshall_floyd.hpp
---
