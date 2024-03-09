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
  bundledCode: "#line 2 \"shortestpath/Dijkstra.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <vector>\ntemplate <class T, bool RESTORE\
    \ = false> struct Dijkstra {\n  public:\n    struct edge {\n        int from,\
    \ to, idx;\n        T cost;\n    };\n\n    Dijkstra() {\n    }\n    Dijkstra(int\
    \ n_, T INF_) : n(n_), INF(INF_), g(n_), dist(n_) {\n        if (RESTORE) from.resize(n_);\n\
    \    }\n\n    int size() const {\n        return n;\n    }\n\n    int add_edge(int\
    \ u, int v, T cost) {\n        assert(0 <= v and v < n);\n        assert(0 <=\
    \ cost);\n\n        int m = int(edges.size());\n        g[u].push_back(edge{u,\
    \ v, m, cost});\n        edges.push_back(edge{u, v, m, cost});\n        return\
    \ m;\n    }\n\n    void shortest_path(const std::vector<int>& vs = {0}) {\n  \
    \      fill(dist.begin(), dist.end(), INF);\n        if (RESTORE) fill(from.begin(),\
    \ from.end(), -1);\n        std::priority_queue<vertex> pq;\n        for (int\
    \ v : vs) {\n            dist[v] = 0;\n            pq.push(vertex{v, 0});\n  \
    \      }\n\n        while (!pq.empty()) {\n            vertex v = pq.top();\n\
    \            pq.pop();\n            if (v.dist > dist[v.idx]) continue;\n    \
    \        for (const edge& e : g[v.idx]) {\n                if (dist[e.to] > v.dist\
    \ + e.cost) {\n                    dist[e.to] = v.dist + e.cost;\n           \
    \         if (RESTORE) from[e.to] = e.idx;\n                    pq.push(vertex{e.to,\
    \ dist[e.to]});\n                }\n            }\n        }\n    }\n\n    T operator[](int\
    \ v) const {\n        return dist[v];\n    }\n\n    std::vector<edge> restore(int\
    \ t) const {\n        static_assert(RESTORE);\n        std::vector<edge> ret;\n\
    \        while (~from[t]) {\n            int idx = from[t];\n            ret.push_back(edges[idx]);\n\
    \            t = edges[idx].from;\n        }\n        std::reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n  private:\n    int n;\n    T INF;\n\
    \    std::vector<std::vector<edge>> g;\n    std::vector<T> dist;\n    std::vector<int>\
    \ from;\n    std::vector<edge> edges;\n    struct vertex {\n        int idx;\n\
    \        T dist;\n        bool operator<(const vertex& o) const {\n          \
    \  return dist > o.dist;\n        }\n    };\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <vector>\ntemplate <class T, bool RESTORE = false> struct Dijkstra {\n\
    \  public:\n    struct edge {\n        int from, to, idx;\n        T cost;\n \
    \   };\n\n    Dijkstra() {\n    }\n    Dijkstra(int n_, T INF_) : n(n_), INF(INF_),\
    \ g(n_), dist(n_) {\n        if (RESTORE) from.resize(n_);\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int add_edge(int u, int v, T cost)\
    \ {\n        assert(0 <= v and v < n);\n        assert(0 <= cost);\n\n       \
    \ int m = int(edges.size());\n        g[u].push_back(edge{u, v, m, cost});\n \
    \       edges.push_back(edge{u, v, m, cost});\n        return m;\n    }\n\n  \
    \  void shortest_path(const std::vector<int>& vs = {0}) {\n        fill(dist.begin(),\
    \ dist.end(), INF);\n        if (RESTORE) fill(from.begin(), from.end(), -1);\n\
    \        std::priority_queue<vertex> pq;\n        for (int v : vs) {\n       \
    \     dist[v] = 0;\n            pq.push(vertex{v, 0});\n        }\n\n        while\
    \ (!pq.empty()) {\n            vertex v = pq.top();\n            pq.pop();\n \
    \           if (v.dist > dist[v.idx]) continue;\n            for (const edge&\
    \ e : g[v.idx]) {\n                if (dist[e.to] > v.dist + e.cost) {\n     \
    \               dist[e.to] = v.dist + e.cost;\n                    if (RESTORE)\
    \ from[e.to] = e.idx;\n                    pq.push(vertex{e.to, dist[e.to]});\n\
    \                }\n            }\n        }\n    }\n\n    T operator[](int v)\
    \ const {\n        return dist[v];\n    }\n\n    std::vector<edge> restore(int\
    \ t) const {\n        static_assert(RESTORE);\n        std::vector<edge> ret;\n\
    \        while (~from[t]) {\n            int idx = from[t];\n            ret.push_back(edges[idx]);\n\
    \            t = edges[idx].from;\n        }\n        std::reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n  private:\n    int n;\n    T INF;\n\
    \    std::vector<std::vector<edge>> g;\n    std::vector<T> dist;\n    std::vector<int>\
    \ from;\n    std::vector<edge> edges;\n    struct vertex {\n        int idx;\n\
    \        T dist;\n        bool operator<(const vertex& o) const {\n          \
    \  return dist > o.dist;\n        }\n    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: shortestpath/Dijkstra.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: shortestpath/Dijkstra.hpp
layout: document
redirect_from:
- /library/shortestpath/Dijkstra.hpp
- /library/shortestpath/Dijkstra.hpp.html
title: shortestpath/Dijkstra.hpp
---
