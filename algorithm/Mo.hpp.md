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
  bundledCode: "#line 2 \"algorithm/Mo.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\n\ntemplate <int B> struct Mo {\n  public:\n\
    \    Mo() {\n    }\n    Mo(int n) : n_(n) {\n    }\n    Mo(int n, int q) : n_(n)\
    \ {\n        L.reserve(q);\n        R.reserve(q);\n    }\n\n    // (0-indexed)\
    \ [l, r)\n    void add(int l, int r) {\n        assert(0 <= l && l < r && r <=\
    \ n_);\n        L.push_back(l);\n        R.push_back(r);\n    }\n\n    template\
    \ <class AL, class AR, class EL, class ER, class C>\n    void build(const AL&\
    \ add_left,\n               const AR& add_right,\n               const EL& erase_left,\n\
    \               const ER& erase_right,\n               const C& calc) const {\n\
    \        int q = int(L.size());\n        std::vector<int> ord(q);\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        std::sort(ord.begin(), ord.end(), [&](int i, int j)\
    \ {\n            int a = L[i] / B, b = L[j] / B;\n            if (a != b) return\
    \ a < b;\n            return (a & 1) ? R[i] > R[j] : R[i] < R[j];\n        });\n\
    \n        int l = 0, r = 0;\n        for (int idx : ord) {\n            while\
    \ (l > L[idx]) add_left(--l);\n            while (r < R[idx]) add_right(r++);\n\
    \            while (l < L[idx]) erase_left(l++);\n            while (r > R[idx])\
    \ erase_right(--r);\n            calc(idx);\n        }\n    }\n\n  private:\n\
    \    int n_;\n    std::vector<int> L, R;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n\
    #include <vector>\n\ntemplate <int B> struct Mo {\n  public:\n    Mo() {\n   \
    \ }\n    Mo(int n) : n_(n) {\n    }\n    Mo(int n, int q) : n_(n) {\n        L.reserve(q);\n\
    \        R.reserve(q);\n    }\n\n    // (0-indexed) [l, r)\n    void add(int l,\
    \ int r) {\n        assert(0 <= l && l < r && r <= n_);\n        L.push_back(l);\n\
    \        R.push_back(r);\n    }\n\n    template <class AL, class AR, class EL,\
    \ class ER, class C>\n    void build(const AL& add_left,\n               const\
    \ AR& add_right,\n               const EL& erase_left,\n               const ER&\
    \ erase_right,\n               const C& calc) const {\n        int q = int(L.size());\n\
    \        std::vector<int> ord(q);\n        std::iota(ord.begin(), ord.end(), 0);\n\
    \        std::sort(ord.begin(), ord.end(), [&](int i, int j) {\n            int\
    \ a = L[i] / B, b = L[j] / B;\n            if (a != b) return a < b;\n       \
    \     return (a & 1) ? R[i] > R[j] : R[i] < R[j];\n        });\n\n        int\
    \ l = 0, r = 0;\n        for (int idx : ord) {\n            while (l > L[idx])\
    \ add_left(--l);\n            while (r < R[idx]) add_right(r++);\n           \
    \ while (l < L[idx]) erase_left(l++);\n            while (r > R[idx]) erase_right(--r);\n\
    \            calc(idx);\n        }\n    }\n\n  private:\n    int n_;\n    std::vector<int>\
    \ L, R;\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Mo.hpp
layout: document
redirect_from:
- /library/algorithm/Mo.hpp
- /library/algorithm/Mo.hpp.html
title: algorithm/Mo.hpp
---
