---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/Centroid.hpp
    title: tree/Centroid.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/Csr.hpp\"\n\n#include <algorithm>\n#include\
    \ <ranges>\n#include <utility>\n#include <vector>\n\ntemplate <class E> struct\
    \ Csr {\n    int n;\n    std::vector<int> start;\n    std::vector<E> elist;\n\
    \    std::vector<std::pair<int, E>> edges;\n\n    Csr() {\n    }\n    Csr(int\
    \ n_) : n(n_), start(n_ + 1) {\n    }\n\n    void add_edge(int from, E value)\
    \ {\n        assert(0 <= from && from < n);\n        edges.emplace_back(from,\
    \ value);\n    }\n\n    void build() {\n        for (const auto& e : edges) {\n\
    \            start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n;\
    \ i++) {\n            start[i] += start[i - 1];\n        }\n        elist.resize(edges.size());\n\
    \        auto counter = start;\n        for (auto& e : edges) {\n            elist[counter[e.first]++]\
    \ = std::move(e.second);\n        }\n    }\n\n    const auto operator[](int idx)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[idx],\n\
    \                                     elist.begin() + start[idx + 1]);\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <ranges>\n#include <utility>\n\
    #include <vector>\n\ntemplate <class E> struct Csr {\n    int n;\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    std::vector<std::pair<int, E>> edges;\n\
    \n    Csr() {\n    }\n    Csr(int n_) : n(n_), start(n_ + 1) {\n    }\n\n    void\
    \ add_edge(int from, E value) {\n        assert(0 <= from && from < n);\n    \
    \    edges.emplace_back(from, value);\n    }\n\n    void build() {\n        for\
    \ (const auto& e : edges) {\n            start[e.first + 1]++;\n        }\n  \
    \      for (int i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n\
    \        }\n        elist.resize(edges.size());\n        auto counter = start;\n\
    \        for (auto& e : edges) {\n            elist[counter[e.first]++] = std::move(e.second);\n\
    \        }\n    }\n\n    const auto operator[](int idx) const {\n        return\
    \ std::ranges::subrange(elist.begin() + start[idx],\n                        \
    \             elist.begin() + start[idx + 1]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/Csr.hpp
  requiredBy:
  - tree/Centroid.hpp
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/Csr.hpp
layout: document
redirect_from:
- /library/datastructure/Csr.hpp
- /library/datastructure/Csr.hpp.html
title: datastructure/Csr.hpp
---
