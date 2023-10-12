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
  bundledCode: "#line 2 \"flow/MaximumFlowLowerBound.hpp\"\n\n#include <atcoder/maxflow>\n\
    #include <cassert>\n#include <limits>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename Cap> struct MaximumFlowLowerBound {\n\
    \    struct Edge {\n        int from, to;\n        Cap lower, upper, flow;\n \
    \   };\n    int n;\n    atcoder::mf_graph<Cap> g;\n    int S, T;\n    Cap lower_bound_sum;\n\
    \    std::vector<std::pair<int, int>> edge_ids;\n\n    MaximumFlowLowerBound()\
    \ : MaximumFlowLowerBound(0) {\n    }\n\n    MaximumFlowLowerBound(int n)\n  \
    \      : n(n), g(n + 2), S(n), T(n + 1), lower_bound_sum(0) {\n    }\n\n    int\
    \ add_edge(int from, int to, Cap lower, Cap upper) {\n        assert(lower <=\
    \ upper);\n        int from_to = g.add_edge(from, to, upper - lower);\n      \
    \  int s_to = g.add_edge(S, to, lower);\n        g.add_edge(from, T, lower);\n\
    \        lower_bound_sum += lower;\n        int m = int(edge_ids.size());\n  \
    \      edge_ids.emplace_back(from_to, s_to);\n        return m;\n    }\n\n   \
    \ bool can_flow(int s, int t) {\n        assert(s != t);\n        g.add_edge(t,\
    \ s, std::numeric_limits<Cap>::max());\n        Cap lower_bound_flow = g.flow(S,\
    \ T);\n        return lower_bound_flow == lower_bound_sum;\n    }\n\n    std::optional<Cap>\
    \ flow(int s, int t) {\n        assert(s != t);\n        Cap max_flow = 0;\n \
    \       max_flow += g.flow(S, T);\n        max_flow += g.flow(S, t);\n       \
    \ max_flow += g.flow(s, T);\n        max_flow += g.flow(s, t);\n        auto edges\
    \ = g.edges();\n        for (const auto& edge : edges) {\n            if (edge.from\
    \ == S || edge.to == T) {\n                if (edge.flow != edge.cap) return std::nullopt;\n\
    \            }\n        }\n        return max_flow;\n    }\n\n    Edge get_edge(int\
    \ i) {\n        assert(0 <= i && i < int(edge_ids.size()));\n        auto [from_to,\
    \ s_to] = edge_ids[i];\n        auto from_to_edge = g.get_edge(from_to);\n   \
    \     auto s_to_edge = g.get_edge(s_to);\n        int from = from_to_edge.from;\n\
    \        int to = from_to_edge.to;\n        Cap lower = s_to_edge.cap;\n     \
    \   Cap upper = lower + from_to_edge.cap;\n        Cap flow = from_to_edge.flow\
    \ + lower;\n        return Edge{from, to, lower, upper, flow};\n    }\n\n    std::vector<Edge>\
    \ get_edges() {\n        std::vector<Edge> edges;\n        edges.reserve(edge_ids.size());\n\
    \        for (int i = 0; i < int(edge_ids.size()); i++) {\n            edges.push_back(get_edge(i));\n\
    \        }\n        return edges;\n    }\n};\n"
  code: "#pragma once\n\n#include <atcoder/maxflow>\n#include <cassert>\n#include\
    \ <limits>\n#include <optional>\n#include <utility>\n#include <vector>\n\ntemplate\
    \ <typename Cap> struct MaximumFlowLowerBound {\n    struct Edge {\n        int\
    \ from, to;\n        Cap lower, upper, flow;\n    };\n    int n;\n    atcoder::mf_graph<Cap>\
    \ g;\n    int S, T;\n    Cap lower_bound_sum;\n    std::vector<std::pair<int,\
    \ int>> edge_ids;\n\n    MaximumFlowLowerBound() : MaximumFlowLowerBound(0) {\n\
    \    }\n\n    MaximumFlowLowerBound(int n)\n        : n(n), g(n + 2), S(n), T(n\
    \ + 1), lower_bound_sum(0) {\n    }\n\n    int add_edge(int from, int to, Cap\
    \ lower, Cap upper) {\n        assert(lower <= upper);\n        int from_to =\
    \ g.add_edge(from, to, upper - lower);\n        int s_to = g.add_edge(S, to, lower);\n\
    \        g.add_edge(from, T, lower);\n        lower_bound_sum += lower;\n    \
    \    int m = int(edge_ids.size());\n        edge_ids.emplace_back(from_to, s_to);\n\
    \        return m;\n    }\n\n    bool can_flow(int s, int t) {\n        assert(s\
    \ != t);\n        g.add_edge(t, s, std::numeric_limits<Cap>::max());\n       \
    \ Cap lower_bound_flow = g.flow(S, T);\n        return lower_bound_flow == lower_bound_sum;\n\
    \    }\n\n    std::optional<Cap> flow(int s, int t) {\n        assert(s != t);\n\
    \        Cap max_flow = 0;\n        max_flow += g.flow(S, T);\n        max_flow\
    \ += g.flow(S, t);\n        max_flow += g.flow(s, T);\n        max_flow += g.flow(s,\
    \ t);\n        auto edges = g.edges();\n        for (const auto& edge : edges)\
    \ {\n            if (edge.from == S || edge.to == T) {\n                if (edge.flow\
    \ != edge.cap) return std::nullopt;\n            }\n        }\n        return\
    \ max_flow;\n    }\n\n    Edge get_edge(int i) {\n        assert(0 <= i && i <\
    \ int(edge_ids.size()));\n        auto [from_to, s_to] = edge_ids[i];\n      \
    \  auto from_to_edge = g.get_edge(from_to);\n        auto s_to_edge = g.get_edge(s_to);\n\
    \        int from = from_to_edge.from;\n        int to = from_to_edge.to;\n  \
    \      Cap lower = s_to_edge.cap;\n        Cap upper = lower + from_to_edge.cap;\n\
    \        Cap flow = from_to_edge.flow + lower;\n        return Edge{from, to,\
    \ lower, upper, flow};\n    }\n\n    std::vector<Edge> get_edges() {\n       \
    \ std::vector<Edge> edges;\n        edges.reserve(edge_ids.size());\n        for\
    \ (int i = 0; i < int(edge_ids.size()); i++) {\n            edges.push_back(get_edge(i));\n\
    \        }\n        return edges;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/MaximumFlowLowerBound.hpp
  requiredBy: []
  timestamp: '2023-10-13 01:31:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/MaximumFlowLowerBound.hpp
layout: document
redirect_from:
- /library/flow/MaximumFlowLowerBound.hpp
- /library/flow/MaximumFlowLowerBound.hpp.html
title: flow/MaximumFlowLowerBound.hpp
---
