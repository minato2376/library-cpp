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
  bundledCode: "#line 1 \"graph/EdgeSum.hpp\"\n\nstruct EdgeSum {\n    int n;\n  \
    \  vector<vector<pair<int, ll>>> g;\n    vector<pair<int, ll>> linear_coeffs;\n\
    \    vector<int> roots;\n    vector<pair<ll, ll>> ranges;\n    EdgeSum() {\n \
    \   }\n    EdgeSum(int n) : n(n), g(n), linear_coeffs(n) {\n    }\n    void add_edge(int\
    \ u, int v, ll w) {\n        g[u].emplace_back(v, w);\n        g[v].emplace_back(u,\
    \ w);\n    }\n\n    bool solve(ll l, ll r) {\n        bool ok = true;\n      \
    \  for (int i = 0; i < n; i++) {\n            if (linear_coeffs[i].first == 0)\
    \ {\n                linear_coeffs[i] = {1, 0};\n                auto [value,\
    \ x] = dfs(i);\n            }\n        }\n        return ok;\n    }\n\n    //\
    \ x + p == -x + q -> 2x = q - p\n    pair<int, ll> dfs(int v) {\n        auto\
    \ [a, b] = linear_coeffs[v];\n        for (auto [nv, w] : g[v]) {\n          \
    \  auto [na, nb] = linear_coeffs[nv];\n            if (na == 0) {\n          \
    \      linear_coeffs[nv] = {a ^ 1, w - b};\n                auto value = dfs(nv);\n\
    \                if (value.first != 1) return value;\n            } else {\n \
    \               if (na == a) {\n                    ll xx = w - b - nb;\n    \
    \                if (na == -1) xx *= -1;\n                    if (xx % 2 != 0)\
    \ return {0, 0};\n                    return {2, xx / 2};\n                } else\
    \ {\n                    if (w - b != nb) return {0, 0};\n                }\n\
    \            }\n        }\n        return {1, 0};\n    }\n};\n"
  code: "\nstruct EdgeSum {\n    int n;\n    vector<vector<pair<int, ll>>> g;\n  \
    \  vector<pair<int, ll>> linear_coeffs;\n    vector<int> roots;\n    vector<pair<ll,\
    \ ll>> ranges;\n    EdgeSum() {\n    }\n    EdgeSum(int n) : n(n), g(n), linear_coeffs(n)\
    \ {\n    }\n    void add_edge(int u, int v, ll w) {\n        g[u].emplace_back(v,\
    \ w);\n        g[v].emplace_back(u, w);\n    }\n\n    bool solve(ll l, ll r) {\n\
    \        bool ok = true;\n        for (int i = 0; i < n; i++) {\n            if\
    \ (linear_coeffs[i].first == 0) {\n                linear_coeffs[i] = {1, 0};\n\
    \                auto [value, x] = dfs(i);\n            }\n        }\n       \
    \ return ok;\n    }\n\n    // x + p == -x + q -> 2x = q - p\n    pair<int, ll>\
    \ dfs(int v) {\n        auto [a, b] = linear_coeffs[v];\n        for (auto [nv,\
    \ w] : g[v]) {\n            auto [na, nb] = linear_coeffs[nv];\n            if\
    \ (na == 0) {\n                linear_coeffs[nv] = {a ^ 1, w - b};\n         \
    \       auto value = dfs(nv);\n                if (value.first != 1) return value;\n\
    \            } else {\n                if (na == a) {\n                    ll\
    \ xx = w - b - nb;\n                    if (na == -1) xx *= -1;\n            \
    \        if (xx % 2 != 0) return {0, 0};\n                    return {2, xx /\
    \ 2};\n                } else {\n                    if (w - b != nb) return {0,\
    \ 0};\n                }\n            }\n        }\n        return {1, 0};\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/EdgeSum.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/EdgeSum.hpp
layout: document
redirect_from:
- /library/graph/EdgeSum.hpp
- /library/graph/EdgeSum.hpp.html
title: graph/EdgeSum.hpp
---
