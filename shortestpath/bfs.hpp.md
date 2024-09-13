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
  bundledCode: "#line 2 \"shortestpath/bfs.hpp\"\n\n#include <queue>\n#include <vector>\n\
    \nstd::vector<int> bfs(const std::vector<std::vector<int>>& G,\n             \
    \        const std::vector<int>& starts = {0}) {\n    std::vector<int> ret(G.size(),\
    \ -1);\n    std::queue<int> que;\n    for (int s : starts) {\n        ret[s] =\
    \ 0;\n        que.push(s);\n    }\n    while (!que.empty()) {\n        int v =\
    \ que.front();\n        que.pop();\n        for (int nv : G[v]) {\n          \
    \  if (~ret[nv]) continue;\n            ret[nv] = ret[v] + 1;\n            que.push(nv);\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <queue>\n#include <vector>\n\nstd::vector<int> bfs(const\
    \ std::vector<std::vector<int>>& G,\n                     const std::vector<int>&\
    \ starts = {0}) {\n    std::vector<int> ret(G.size(), -1);\n    std::queue<int>\
    \ que;\n    for (int s : starts) {\n        ret[s] = 0;\n        que.push(s);\n\
    \    }\n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (int nv : G[v]) {\n            if (~ret[nv]) continue;\n        \
    \    ret[nv] = ret[v] + 1;\n            que.push(nv);\n        }\n    }\n    return\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: shortestpath/bfs.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: shortestpath/bfs.hpp
layout: document
redirect_from:
- /library/shortestpath/bfs.hpp
- /library/shortestpath/bfs.hpp.html
title: shortestpath/bfs.hpp
---
