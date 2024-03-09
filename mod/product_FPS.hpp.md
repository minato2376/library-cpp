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
  bundledCode: "#line 2 \"mod/product_FPS.hpp\"\n\n#include <queue>\n#include <vector>\n\
    template <class FPS> FPS product_FPS(const std::vector<FPS>& fpss) {\n    if (fpss.empty())\
    \ return FPS(1);\n    auto comp = [&](const FPS& a, const FPS& b) { return a.size()\
    \ > b.size(); };\n    std::priority_queue<FPS, std::vector<FPS>, decltype(comp)>\
    \ pq(comp, fpss);\n\n    while (pq.size() > 1) {\n        FPS a = pq.top();\n\
    \        pq.pop();\n        FPS b = pq.top();\n        pq.pop();\n        pq.push(a\
    \ * b);\n    }\n    return pq.top();\n}\n"
  code: "#pragma once\n\n#include <queue>\n#include <vector>\ntemplate <class FPS>\
    \ FPS product_FPS(const std::vector<FPS>& fpss) {\n    if (fpss.empty()) return\
    \ FPS(1);\n    auto comp = [&](const FPS& a, const FPS& b) { return a.size() >\
    \ b.size(); };\n    std::priority_queue<FPS, std::vector<FPS>, decltype(comp)>\
    \ pq(comp, fpss);\n\n    while (pq.size() > 1) {\n        FPS a = pq.top();\n\
    \        pq.pop();\n        FPS b = pq.top();\n        pq.pop();\n        pq.push(a\
    \ * b);\n    }\n    return pq.top();\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/product_FPS.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/product_FPS.hpp
layout: document
redirect_from:
- /library/mod/product_FPS.hpp
- /library/mod/product_FPS.hpp.html
title: mod/product_FPS.hpp
---
