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
  bundledCode: "#line 2 \"datastructure/ErasablePriorityQueue.hpp\"\n\n#include <cassert>\n\
    #include <functional>\n#include <queue>\n#include <vector>\n\ntemplate <class\
    \ T,\n          class Container = std::vector<T>,\n          class Compare = std::less<typename\
    \ Container::value_type>>\nstruct ErasablePriorityQueue {\n    std::priority_queue<T,\
    \ Container, Compare> pq, erased;\n\n    int size() const {\n        return pq.size()\
    \ - erased.size();\n    }\n\n    bool empty() const {\n        return size() ==\
    \ 0;\n    }\n\n    void push(T x) {\n        pq.push(x);\n    }\n\n    void erase(T\
    \ x) {\n        erased.push(x);\n        assert(erased.size() <= pq.size());\n\
    \    }\n\n    T top() {\n        assert(!empty());\n        update();\n      \
    \  return pq.top();\n    }\n\n  private:\n    void update() {\n        while (!erased.empty()\
    \ && pq.top() == erased.top()) {\n            pq.pop();\n            erased.pop();\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <queue>\n\
    #include <vector>\n\ntemplate <class T,\n          class Container = std::vector<T>,\n\
    \          class Compare = std::less<typename Container::value_type>>\nstruct\
    \ ErasablePriorityQueue {\n    std::priority_queue<T, Container, Compare> pq,\
    \ erased;\n\n    int size() const {\n        return pq.size() - erased.size();\n\
    \    }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\n   \
    \ void push(T x) {\n        pq.push(x);\n    }\n\n    void erase(T x) {\n    \
    \    erased.push(x);\n        assert(erased.size() <= pq.size());\n    }\n\n \
    \   T top() {\n        assert(!empty());\n        update();\n        return pq.top();\n\
    \    }\n\n  private:\n    void update() {\n        while (!erased.empty() && pq.top()\
    \ == erased.top()) {\n            pq.pop();\n            erased.pop();\n     \
    \   }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/ErasablePriorityQueue.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/ErasablePriorityQueue.hpp
layout: document
redirect_from:
- /library/datastructure/ErasablePriorityQueue.hpp
- /library/datastructure/ErasablePriorityQueue.hpp.html
title: datastructure/ErasablePriorityQueue.hpp
---
