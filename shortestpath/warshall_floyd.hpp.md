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
  bundledCode: "#line 2 \"shortestpath/warshall_floyd.hpp\"\n\ntemplate <typename\
    \ Int, Int INF> void warshall_floyd(vector<vector<Int>>& G) {\n    int N = G.size();\n\
    \n    for (int k = 0; k < N; k++) {\n        for (int i = 0; i < N; i++) {\n \
    \           if (G[i][k] == INF) continue;\n            for (int j = 0; j < N;\
    \ j++) {\n                if (G[k][j] == INF) continue;\n                G[i][j]\
    \ = min(G[i][j], G[i][k] + G[k][j]);\n            }\n        }\n    }\n    return;\n\
    }\n"
  code: "#pragma once\n\ntemplate <typename Int, Int INF> void warshall_floyd(vector<vector<Int>>&\
    \ G) {\n    int N = G.size();\n\n    for (int k = 0; k < N; k++) {\n        for\
    \ (int i = 0; i < N; i++) {\n            if (G[i][k] == INF) continue;\n     \
    \       for (int j = 0; j < N; j++) {\n                if (G[k][j] == INF) continue;\n\
    \                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);\n            }\n \
    \       }\n    }\n    return;\n}"
  dependsOn: []
  isVerificationFile: false
  path: shortestpath/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2023-01-30 01:32:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: shortestpath/warshall_floyd.hpp
layout: document
redirect_from:
- /library/shortestpath/warshall_floyd.hpp
- /library/shortestpath/warshall_floyd.hpp.html
title: shortestpath/warshall_floyd.hpp
---
