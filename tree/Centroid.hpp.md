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
  bundledCode: "#line 2 \"tree/Centroid.hpp\"\n\n#include <cassert>\n#include <cstdint>\n\
    #include <optional>\n#include <queue>\n#include <vector>\n\n#line 2 \"datastructure/Csr.hpp\"\
    \n\n#include <algorithm>\n#include <ranges>\n#include <utility>\n#line 7 \"datastructure/Csr.hpp\"\
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
    };\n#line 10 \"tree/Centroid.hpp\"\n\nstruct Centroid {\n    using Res = std::pair<int,\
    \ std::optional<int>>;\n    int n;\n    Csr<int> g;\n    std::vector<int8_t> dead;\n\
    \n    Centroid() {\n    }\n    Centroid(int n_) : n(n_), g(n_), dead(n_) {\n \
    \   }\n\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        g.add_edge(u, v);\n        g.add_edge(v,\
    \ u);\n    }\n\n    void build() {\n        g.build();\n    }\n\n    Res find_centroids(int\
    \ v) const {\n        int all_sub = get_size(v);\n        Res res(-1, std::nullopt);\n\
    \        get_centroid(v, -1, all_sub, res);\n        return res;\n    }\n\n  \
    \  int find_centroid(int v) const {\n        return find_centroids(v).first;\n\
    \    }\n\n    bool is_dead(int v) const {\n        return dead[v];\n    }\n\n\
    \    void disable(int v) {\n        dead[v] = true;\n    }\n\n    const auto operator[](int\
    \ v) const {\n        return g[v];\n    }\n\n  private:\n    int get_size(int\
    \ r) const {\n        std::queue<std::pair<int, int>> que;\n        que.emplace(r,\
    \ -1);\n        int res = 0;\n        while (!que.empty()) {\n            auto\
    \ [v, pv] = que.front();\n            que.pop();\n            for (int nv : g[v])\
    \ {\n                if (nv == pv || dead[nv]) continue;\n                que.emplace(nv,\
    \ v);\n            }\n            res++;\n        }\n        return res;\n   \
    \ }\n\n    int get_centroid(int v, int pv, int all_sub, Res& res) const {\n  \
    \      int sub = 1;\n        bool is_centroid = true;\n        for (int nv : g[v])\
    \ {\n            if (nv == pv || dead[nv]) continue;\n            int tmp = get_centroid(nv,\
    \ v, all_sub, res);\n            if (tmp > all_sub / 2) is_centroid = false;\n\
    \            sub += tmp;\n        }\n        if (all_sub - sub > all_sub / 2)\
    \ is_centroid = false;\n        if (is_centroid) {\n            if (res.first\
    \ == -1) {\n                res.first = v;\n            } else {\n           \
    \     res.second = v;\n            }\n        }\n        return sub;\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n#include <optional>\n\
    #include <queue>\n#include <vector>\n\n#include \"datastructure/Csr.hpp\"\n\n\
    struct Centroid {\n    using Res = std::pair<int, std::optional<int>>;\n    int\
    \ n;\n    Csr<int> g;\n    std::vector<int8_t> dead;\n\n    Centroid() {\n   \
    \ }\n    Centroid(int n_) : n(n_), g(n_), dead(n_) {\n    }\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        g.add_edge(u, v);\n        g.add_edge(v, u);\n    }\n\n    void\
    \ build() {\n        g.build();\n    }\n\n    Res find_centroids(int v) const\
    \ {\n        int all_sub = get_size(v);\n        Res res(-1, std::nullopt);\n\
    \        get_centroid(v, -1, all_sub, res);\n        return res;\n    }\n\n  \
    \  int find_centroid(int v) const {\n        return find_centroids(v).first;\n\
    \    }\n\n    bool is_dead(int v) const {\n        return dead[v];\n    }\n\n\
    \    void disable(int v) {\n        dead[v] = true;\n    }\n\n    const auto operator[](int\
    \ v) const {\n        return g[v];\n    }\n\n  private:\n    int get_size(int\
    \ r) const {\n        std::queue<std::pair<int, int>> que;\n        que.emplace(r,\
    \ -1);\n        int res = 0;\n        while (!que.empty()) {\n            auto\
    \ [v, pv] = que.front();\n            que.pop();\n            for (int nv : g[v])\
    \ {\n                if (nv == pv || dead[nv]) continue;\n                que.emplace(nv,\
    \ v);\n            }\n            res++;\n        }\n        return res;\n   \
    \ }\n\n    int get_centroid(int v, int pv, int all_sub, Res& res) const {\n  \
    \      int sub = 1;\n        bool is_centroid = true;\n        for (int nv : g[v])\
    \ {\n            if (nv == pv || dead[nv]) continue;\n            int tmp = get_centroid(nv,\
    \ v, all_sub, res);\n            if (tmp > all_sub / 2) is_centroid = false;\n\
    \            sub += tmp;\n        }\n        if (all_sub - sub > all_sub / 2)\
    \ is_centroid = false;\n        if (is_centroid) {\n            if (res.first\
    \ == -1) {\n                res.first = v;\n            } else {\n           \
    \     res.second = v;\n            }\n        }\n        return sub;\n    }\n\
    };"
  dependsOn:
  - datastructure/Csr.hpp
  isVerificationFile: false
  path: tree/Centroid.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/Centroid.hpp
layout: document
redirect_from:
- /library/tree/Centroid.hpp
- /library/tree/Centroid.hpp.html
title: tree/Centroid.hpp
---
