---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/Rerooting.test.cpp
    title: test/tree/Rerooting.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u5168\u65B9\u4F4D\u6728 DP"
    links: []
  bundledCode: "#line 2 \"tree/Rerooting.hpp\"\n\n/**\n * @brief \u5168\u65B9\u4F4D\
    \u6728 DP\n * @param n int \u9802\u70B9\u6570\n * @param op (EdgeValue a, EdgeValue\
    \ b) -> EdgeValue : dp \u306E\u5024\u306E\u6F14\u7B97\n * @param vtoe (VertexValue\
    \ a, auto(Edge) e) -> EdgeValue : \u9802\u70B9\u306E dp\n * \u306E\u5024\u3092\
    \u304B\u3089\u8FBA\u306E dp \u306E\u5024\u3092\u8A08\u7B97\u3059\u308B\n * @param\
    \ etov (EdgeValue a, int v) -> VertexValue : \u8FBA\u306E dp \u306E\u5024\u304B\
    \u3089\u9802\u70B9\u306E dp\n * \u306E\u5024\u3092\u8A08\u7B97\u3059\u308B\n *\
    \ @param id EdgeValue \u5358\u4F4D\u5143\n */\ntemplate <class EdgeValue,\n  \
    \        class VertexValue,\n          class Weight,\n          class F,\n   \
    \       class G,\n          class H>\nstruct Rerooting {\n    struct Edge {\n\
    \        int from;\n        int to;\n        Weight weight;\n        Edge(int\
    \ from, int to, const Weight& weight)\n            : from(from), to(to), weight(weight)\
    \ {\n        }\n    };\n    int n;\n    vector<vector<Edge>> g;\n    vector<VertexValue>\
    \ subdp, dp;\n    F op;\n    G vtoe;\n    H etov;\n    EdgeValue id;\n\n    Rerooting()\
    \ {\n    }\n    Rerooting(int n,\n              const F& op,\n              const\
    \ G& vtoe,\n              const H& etov,\n              const EdgeValue& id)\n\
    \        : n(n), g(n), subdp(n), dp(n), op(op), vtoe(vtoe), etov(etov), id(id)\
    \ {\n    }\n\n    void add_edge(int u, int v, const Weight& weight = Weight())\
    \ {\n        g[u].emplace_back(u, v, weight);\n        g[v].emplace_back(v, u,\
    \ weight);\n    }\n\n    void build() {\n        dfs_sub(0, -1);\n        dfs_all(0,\
    \ -1, VertexValue());\n        return;\n    }\n\n    VertexValue operator[](int\
    \ i) const {\n        return dp[i];\n    }\n\n#ifdef MINATO_LOCAL\n    friend\
    \ ostream& operator<<(ostream& os, const Rerooting& r) {\n        os << \"\\nsubdp\
    \ = \" << r.subdp;\n        os << \"\\ndp = \" << r.dp;\n        return os;\n\
    \    }\n#endif\n\n  private:\n    void dfs_sub(int v, int pv) {\n        EdgeValue\
    \ merge_value = id;\n        for (const Edge& edge : g[v]) {\n            if (edge.to\
    \ == pv) continue;\n            dfs_sub(edge.to, v);\n            merge_value\
    \ = op(merge_value, vtoe(subdp[edge.to], edge));\n        }\n        subdp[v]\
    \ = etov(merge_value, v);\n        return;\n    }\n\n    void dfs_all(int v, int\
    \ pv, const VertexValue& top) {\n        dp[v] = calc_dp(v, pv, top);\n\n    \
    \    vector<EdgeValue> prefix_sum = get_prefix_sum(v, pv, top);\n        EdgeValue\
    \ merge_value = id;\n        for (int i = int(g[v].size()) - 1; i >= 0; i--) {\n\
    \            if (g[v][i].to != pv) {\n                dfs_all(g[v][i].to, v, etov(op(merge_value,\
    \ prefix_sum[i]), v));\n                merge_value = op(merge_value, vtoe(subdp[g[v][i].to],\
    \ g[v][i]));\n            } else {\n                merge_value = op(merge_value,\
    \ vtoe(top, g[v][i]));\n            }\n        }\n        return;\n    }\n\n \
    \   VertexValue calc_dp(int v, int pv, const VertexValue& top) const {\n     \
    \   EdgeValue merge_value = id;\n        for (const Edge& edge : g[v]) {\n   \
    \         if (edge.to == pv) {\n                merge_value = op(merge_value,\
    \ vtoe(top, edge));\n            } else {\n                merge_value = op(merge_value,\
    \ vtoe(subdp[edge.to], edge));\n            }\n        }\n        return etov(merge_value,\
    \ v);\n    }\n\n    vector<EdgeValue> get_prefix_sum(int v,\n                \
    \                     int pv,\n                                     const VertexValue&\
    \ top) const {\n        vector<EdgeValue> prefix_sum(g[v].size(), id);\n     \
    \   for (int i = 0; i < int(g[v].size()) - 1; i++) {\n            if (g[v][i].to\
    \ == pv) {\n                prefix_sum[i + 1] = op(prefix_sum[i], vtoe(top, g[v][i]));\n\
    \            } else {\n                prefix_sum[i + 1] =\n                 \
    \   op(prefix_sum[i], vtoe(subdp[g[v][i].to], g[v][i]));\n            }\n    \
    \    }\n        return prefix_sum;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u5168\u65B9\u4F4D\u6728 DP\n * @param n int\
    \ \u9802\u70B9\u6570\n * @param op (EdgeValue a, EdgeValue b) -> EdgeValue : dp\
    \ \u306E\u5024\u306E\u6F14\u7B97\n * @param vtoe (VertexValue a, auto(Edge) e)\
    \ -> EdgeValue : \u9802\u70B9\u306E dp\n * \u306E\u5024\u3092\u304B\u3089\u8FBA\
    \u306E dp \u306E\u5024\u3092\u8A08\u7B97\u3059\u308B\n * @param etov (EdgeValue\
    \ a, int v) -> VertexValue : \u8FBA\u306E dp \u306E\u5024\u304B\u3089\u9802\u70B9\
    \u306E dp\n * \u306E\u5024\u3092\u8A08\u7B97\u3059\u308B\n * @param id EdgeValue\
    \ \u5358\u4F4D\u5143\n */\ntemplate <class EdgeValue,\n          class VertexValue,\n\
    \          class Weight,\n          class F,\n          class G,\n          class\
    \ H>\nstruct Rerooting {\n    struct Edge {\n        int from;\n        int to;\n\
    \        Weight weight;\n        Edge(int from, int to, const Weight& weight)\n\
    \            : from(from), to(to), weight(weight) {\n        }\n    };\n    int\
    \ n;\n    vector<vector<Edge>> g;\n    vector<VertexValue> subdp, dp;\n    F op;\n\
    \    G vtoe;\n    H etov;\n    EdgeValue id;\n\n    Rerooting() {\n    }\n   \
    \ Rerooting(int n,\n              const F& op,\n              const G& vtoe,\n\
    \              const H& etov,\n              const EdgeValue& id)\n        : n(n),\
    \ g(n), subdp(n), dp(n), op(op), vtoe(vtoe), etov(etov), id(id) {\n    }\n\n \
    \   void add_edge(int u, int v, const Weight& weight = Weight()) {\n        g[u].emplace_back(u,\
    \ v, weight);\n        g[v].emplace_back(v, u, weight);\n    }\n\n    void build()\
    \ {\n        dfs_sub(0, -1);\n        dfs_all(0, -1, VertexValue());\n       \
    \ return;\n    }\n\n    VertexValue operator[](int i) const {\n        return\
    \ dp[i];\n    }\n\n#ifdef MINATO_LOCAL\n    friend ostream& operator<<(ostream&\
    \ os, const Rerooting& r) {\n        os << \"\\nsubdp = \" << r.subdp;\n     \
    \   os << \"\\ndp = \" << r.dp;\n        return os;\n    }\n#endif\n\n  private:\n\
    \    void dfs_sub(int v, int pv) {\n        EdgeValue merge_value = id;\n    \
    \    for (const Edge& edge : g[v]) {\n            if (edge.to == pv) continue;\n\
    \            dfs_sub(edge.to, v);\n            merge_value = op(merge_value, vtoe(subdp[edge.to],\
    \ edge));\n        }\n        subdp[v] = etov(merge_value, v);\n        return;\n\
    \    }\n\n    void dfs_all(int v, int pv, const VertexValue& top) {\n        dp[v]\
    \ = calc_dp(v, pv, top);\n\n        vector<EdgeValue> prefix_sum = get_prefix_sum(v,\
    \ pv, top);\n        EdgeValue merge_value = id;\n        for (int i = int(g[v].size())\
    \ - 1; i >= 0; i--) {\n            if (g[v][i].to != pv) {\n                dfs_all(g[v][i].to,\
    \ v, etov(op(merge_value, prefix_sum[i]), v));\n                merge_value =\
    \ op(merge_value, vtoe(subdp[g[v][i].to], g[v][i]));\n            } else {\n \
    \               merge_value = op(merge_value, vtoe(top, g[v][i]));\n         \
    \   }\n        }\n        return;\n    }\n\n    VertexValue calc_dp(int v, int\
    \ pv, const VertexValue& top) const {\n        EdgeValue merge_value = id;\n \
    \       for (const Edge& edge : g[v]) {\n            if (edge.to == pv) {\n  \
    \              merge_value = op(merge_value, vtoe(top, edge));\n            }\
    \ else {\n                merge_value = op(merge_value, vtoe(subdp[edge.to], edge));\n\
    \            }\n        }\n        return etov(merge_value, v);\n    }\n\n   \
    \ vector<EdgeValue> get_prefix_sum(int v,\n                                  \
    \   int pv,\n                                     const VertexValue& top) const\
    \ {\n        vector<EdgeValue> prefix_sum(g[v].size(), id);\n        for (int\
    \ i = 0; i < int(g[v].size()) - 1; i++) {\n            if (g[v][i].to == pv) {\n\
    \                prefix_sum[i + 1] = op(prefix_sum[i], vtoe(top, g[v][i]));\n\
    \            } else {\n                prefix_sum[i + 1] =\n                 \
    \   op(prefix_sum[i], vtoe(subdp[g[v][i].to], g[v][i]));\n            }\n    \
    \    }\n        return prefix_sum;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2023-03-20 23:19:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/Rerooting.test.cpp
documentation_of: tree/Rerooting.hpp
layout: document
redirect_from:
- /library/tree/Rerooting.hpp
- /library/tree/Rerooting.hpp.html
title: "\u5168\u65B9\u4F4D\u6728 DP"
---
