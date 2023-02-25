---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/SlidingWindowAggregation.test.cpp
    title: test/datastructure/SlidingWindowAggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/SlidingWindowAggregation.hpp\"\n\ntemplate\
    \ <class T, class F> struct SlidingWindowAggregation {\n    F op;\n    T e;\n\
    \    vector<pair<T, T>> front, back;\n\n    SlidingWindowAggregation(F op, T e)\
    \ : op(op), e(e) {\n    }\n\n    void clear() {\n        front.clear();\n    \
    \    back.clear();\n    }\n\n    void reserve(size_t n) {\n        front.reserve(n);\n\
    \        back.reserve(n);\n    }\n\n    bool empty() const {\n        return front.empty()\
    \ and back.empty();\n    }\n\n    int size() const {\n        return front.size()\
    \ + back.size();\n    }\n\n    T fold_all() const {\n        T vf = front.empty()\
    \ ? e : front.back().second;\n        T vb = back.empty() ? e : back.back().second;\n\
    \        return op(vf, vb);\n    }\n\n    void emplace(const T& val) {\n     \
    \   if (back.empty()) {\n            back.emplace_back(val, val);\n        } else\
    \ {\n            back.emplace_back(val, op(back.back().second, val));\n      \
    \  }\n    }\n\n    void pop() {\n        assert(!empty());\n        if (front.empty())\
    \ {\n            front.emplace_back(back.back().first, back.back().first);\n \
    \           back.pop_back();\n            while (!back.empty()) {\n          \
    \      front.emplace_back(back.back().first,\n                               \
    \    op(back.back().first, front.back().second));\n                back.pop_back();\n\
    \            }\n        }\n        front.pop_back();\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, class F> struct SlidingWindowAggregation\
    \ {\n    F op;\n    T e;\n    vector<pair<T, T>> front, back;\n\n    SlidingWindowAggregation(F\
    \ op, T e) : op(op), e(e) {\n    }\n\n    void clear() {\n        front.clear();\n\
    \        back.clear();\n    }\n\n    void reserve(size_t n) {\n        front.reserve(n);\n\
    \        back.reserve(n);\n    }\n\n    bool empty() const {\n        return front.empty()\
    \ and back.empty();\n    }\n\n    int size() const {\n        return front.size()\
    \ + back.size();\n    }\n\n    T fold_all() const {\n        T vf = front.empty()\
    \ ? e : front.back().second;\n        T vb = back.empty() ? e : back.back().second;\n\
    \        return op(vf, vb);\n    }\n\n    void emplace(const T& val) {\n     \
    \   if (back.empty()) {\n            back.emplace_back(val, val);\n        } else\
    \ {\n            back.emplace_back(val, op(back.back().second, val));\n      \
    \  }\n    }\n\n    void pop() {\n        assert(!empty());\n        if (front.empty())\
    \ {\n            front.emplace_back(back.back().first, back.back().first);\n \
    \           back.pop_back();\n            while (!back.empty()) {\n          \
    \      front.emplace_back(back.back().first,\n                               \
    \    op(back.back().first, front.back().second));\n                back.pop_back();\n\
    \            }\n        }\n        front.pop_back();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2023-02-26 03:42:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/SlidingWindowAggregation.test.cpp
documentation_of: datastructure/SlidingWindowAggregation.hpp
layout: document
redirect_from:
- /library/datastructure/SlidingWindowAggregation.hpp
- /library/datastructure/SlidingWindowAggregation.hpp.html
title: datastructure/SlidingWindowAggregation.hpp
---
