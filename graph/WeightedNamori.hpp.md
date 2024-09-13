---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructure/Csr.hpp
    title: datastructure/Csr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/WeightedNamori.hpp\"\n\n#include <algorithm>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\n#line 2 \"datastructure/Csr.hpp\"\
    \n\n#line 4 \"datastructure/Csr.hpp\"\n#include <ranges>\n#line 7 \"datastructure/Csr.hpp\"\
    \n\ntemplate <class E> struct Csr {\n    int n;\n    std::vector<int> start;\n\
    \    std::vector<E> elist;\n    std::vector<std::pair<int, E>> edges;\n\n    Csr()\
    \ {\n    }\n    Csr(int n_) : n(n_), start(n_ + 1) {\n    }\n\n    void add_edge(int\
    \ from, E value) {\n        assert(0 <= from && from < n);\n        edges.emplace_back(from,\
    \ value);\n    }\n\n    void build() {\n        for (const auto& e : edges) {\n\
    \            start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n;\
    \ i++) {\n            start[i] += start[i - 1];\n        }\n        elist.resize(edges.size());\n\
    \        auto counter = start;\n        for (auto& e : edges) {\n            elist[counter[e.first]++]\
    \ = std::move(e.second);\n        }\n    }\n\n    const auto operator[](int idx)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[idx],\n\
    \                                     elist.begin() + start[idx + 1]);\n    }\n\
    };\n#line 9 \"graph/WeightedNamori.hpp\"\n\ntemplate <class T> struct WeightedNamori\
    \ {\n    int n;\n    Csr<std::pair<int, T>> g, forests;\n    std::vector<int>\
    \ deg, types, roots;\n\n    WeightedNamori() {\n    }\n    WeightedNamori(int\
    \ n_) : n(n_), g(n_), forests(n_), deg(n_), types(n_) {\n    }\n\n    void add_edge(int\
    \ u, int v, T w) {\n        g.add_edge(u, std::make_pair(v, w));\n        g.add_edge(v,\
    \ std::make_pair(u, w));\n        deg[u]++;\n        deg[v]++;\n    }\n\n    /**\n\
    \     * roots \u306F\u6839\u306E\u9802\u70B9\u756A\u53F7\u304C\u683C\u7D0D\u3055\
    \u308C\u3001\u96A3\u308A\u5408\u3046\u9802\u70B9\u306F\u5143\u306E\u30B0\u30E9\
    \u30D5\u3067\u96A3\u63A5\u3057\u3066\u3044\u308B\n     */\n    void build() {\n\
    \        g.build();\n\n        std::queue<int> que;\n        for (int v = 0; v\
    \ < n; v++) {\n            if (deg[v] == 1) que.push(v);\n        }\n\n      \
    \  std::vector<short> visited(n);\n        while (!que.empty()) {\n          \
    \  int v = que.front();\n            que.pop();\n            visited[v] = true;\n\
    \            for (auto [nv, w] : g[v]) {\n                if (visited[nv]) continue;\n\
    \                forests.add_edge(nv, std::make_pair(v, w));\n               \
    \ deg[nv]--;\n                if (deg[nv] == 1) que.push(nv);\n            }\n\
    \        }\n\n        forests.build();\n\n        roots.reserve(std::count(visited.begin(),\
    \ visited.end(), false));\n        {\n            int v = std::find(visited.begin(),\
    \ visited.end(), false) -\n                    visited.begin();\n            while\
    \ (!visited[v]) {\n                visited[v] = true;\n                roots.push_back(v);\n\
    \                for (auto [nv, w] : g[v]) {\n                    if (!visited[nv])\
    \ {\n                        v = nv;\n                        break;\n       \
    \             }\n                }\n            }\n        }\n\n        for (int\
    \ r : roots) {\n            que.push(r);\n            while (!que.empty()) {\n\
    \                int v = que.front();\n                que.pop();\n          \
    \      types[v] = r;\n                for (auto [nv, w] : forests[v]) {\n    \
    \                types[nv] = r;\n                    que.push(nv);\n         \
    \       }\n            }\n        }\n    }\n\n    /**\n     * v \u304C\u5C5E\u3059\
    \u308B\u6839\u4ED8\u304D\u68EE\u306E\u6839\u3092\u8FD4\u3059\n     */\n    int\
    \ type(int v) const {\n        return types[v];\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\n#include \"datastructure/Csr.hpp\"\n\ntemplate <class T>\
    \ struct WeightedNamori {\n    int n;\n    Csr<std::pair<int, T>> g, forests;\n\
    \    std::vector<int> deg, types, roots;\n\n    WeightedNamori() {\n    }\n  \
    \  WeightedNamori(int n_) : n(n_), g(n_), forests(n_), deg(n_), types(n_) {\n\
    \    }\n\n    void add_edge(int u, int v, T w) {\n        g.add_edge(u, std::make_pair(v,\
    \ w));\n        g.add_edge(v, std::make_pair(u, w));\n        deg[u]++;\n    \
    \    deg[v]++;\n    }\n\n    /**\n     * roots \u306F\u6839\u306E\u9802\u70B9\u756A\
    \u53F7\u304C\u683C\u7D0D\u3055\u308C\u3001\u96A3\u308A\u5408\u3046\u9802\u70B9\
    \u306F\u5143\u306E\u30B0\u30E9\u30D5\u3067\u96A3\u63A5\u3057\u3066\u3044\u308B\
    \n     */\n    void build() {\n        g.build();\n\n        std::queue<int> que;\n\
    \        for (int v = 0; v < n; v++) {\n            if (deg[v] == 1) que.push(v);\n\
    \        }\n\n        std::vector<short> visited(n);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            visited[v]\
    \ = true;\n            for (auto [nv, w] : g[v]) {\n                if (visited[nv])\
    \ continue;\n                forests.add_edge(nv, std::make_pair(v, w));\n   \
    \             deg[nv]--;\n                if (deg[nv] == 1) que.push(nv);\n  \
    \          }\n        }\n\n        forests.build();\n\n        roots.reserve(std::count(visited.begin(),\
    \ visited.end(), false));\n        {\n            int v = std::find(visited.begin(),\
    \ visited.end(), false) -\n                    visited.begin();\n            while\
    \ (!visited[v]) {\n                visited[v] = true;\n                roots.push_back(v);\n\
    \                for (auto [nv, w] : g[v]) {\n                    if (!visited[nv])\
    \ {\n                        v = nv;\n                        break;\n       \
    \             }\n                }\n            }\n        }\n\n        for (int\
    \ r : roots) {\n            que.push(r);\n            while (!que.empty()) {\n\
    \                int v = que.front();\n                que.pop();\n          \
    \      types[v] = r;\n                for (auto [nv, w] : forests[v]) {\n    \
    \                types[nv] = r;\n                    que.push(nv);\n         \
    \       }\n            }\n        }\n    }\n\n    /**\n     * v \u304C\u5C5E\u3059\
    \u308B\u6839\u4ED8\u304D\u68EE\u306E\u6839\u3092\u8FD4\u3059\n     */\n    int\
    \ type(int v) const {\n        return types[v];\n    }\n};"
  dependsOn:
  - datastructure/Csr.hpp
  isVerificationFile: false
  path: graph/WeightedNamori.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/WeightedNamori.hpp
layout: document
redirect_from:
- /library/graph/WeightedNamori.hpp
- /library/graph/WeightedNamori.hpp.html
title: graph/WeightedNamori.hpp
---
