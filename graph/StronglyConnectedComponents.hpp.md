---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents.test.cpp
    title: test/graph/StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/StronglyConnectedComponents.hpp\"\n\n#include <atcoder/internal_scc>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nstruct StronglyConnectedComponents\
    \ {\n    int n;\n    int group_num;\n    /**\n     * \u5143\u306E\u30B0\u30E9\u30D5\
    \u306E\u9802\u70B9\u304C\u3069\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\
    \u5C5E\u3059\u308B\u304B\u3092\u8868\u3059\u914D\u5217\n     */\n    std::vector<int>\
    \ scc_ids;\n\n    StronglyConnectedComponents() : n(0), internal(0) {\n    }\n\
    \    explicit StronglyConnectedComponents(int n) : n(n), internal(n) {\n    }\n\
    \n    int size() const {\n        return n;\n    }\n\n    void add_edge(int from,\
    \ int to) {\n        assert(0 <= from && from < n);\n        assert(0 <= to &&\
    \ to < n);\n        internal.add_edge(from, to);\n        edges.emplace_back(from,\
    \ to);\n    }\n\n    int build() {\n        tie(group_num, scc_ids) = internal.scc_ids();\n\
    \        return group_num;\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ const {\n        std::vector<std::vector<int>> groups(group_num);\n        std::vector<int>\
    \ counts(group_num);\n        for (auto x : scc_ids) counts[x]++;\n        for\
    \ (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            groups[scc_ids[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\n    std::vector<std::vector<int>>\
    \ scc_graph() const {\n        std::vector<int> counts(group_num);\n        std::vector<std::vector<int>>\
    \ naive_scc_graph(group_num),\n            scc_graph(group_num);\n        for\
    \ (auto [from, to] : edges) counts[scc_ids[from]]++;\n        for (int i = 0;\
    \ i < group_num; i++) {\n            naive_scc_graph[i].reserve(counts[i]);\n\
    \            scc_graph[i].reserve(counts[i]);\n        }\n        for (auto [from,\
    \ to] : edges) {\n            naive_scc_graph[scc_ids[from]].push_back(scc_ids[to]);\n\
    \        }\n        std::vector<int> exists(group_num);\n        for (int from\
    \ = 0; from < group_num; from++) {\n            for (auto to : naive_scc_graph[from])\
    \ {\n                if (exists[to]) continue;\n                scc_graph[from].push_back(to);\n\
    \                exists[to] = 1;\n            }\n            for (auto to : scc_graph[from])\
    \ {\n                exists[to] = 0;\n            }\n        }\n        return\
    \ scc_graph;\n    }\n\n    int operator[](int i) const {\n        assert(0 <=\
    \ i && i < n);\n        return scc_ids[i];\n    }\n\n  private:\n    atcoder::internal::scc_graph\
    \ internal;\n    std::vector<std::pair<int, int>> edges;\n};\n"
  code: "#pragma once\n\n#include <atcoder/internal_scc>\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nstruct StronglyConnectedComponents {\n    int\
    \ n;\n    int group_num;\n    /**\n     * \u5143\u306E\u30B0\u30E9\u30D5\u306E\
    \u9802\u70B9\u304C\u3069\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\
    \u3059\u308B\u304B\u3092\u8868\u3059\u914D\u5217\n     */\n    std::vector<int>\
    \ scc_ids;\n\n    StronglyConnectedComponents() : n(0), internal(0) {\n    }\n\
    \    explicit StronglyConnectedComponents(int n) : n(n), internal(n) {\n    }\n\
    \n    int size() const {\n        return n;\n    }\n\n    void add_edge(int from,\
    \ int to) {\n        assert(0 <= from && from < n);\n        assert(0 <= to &&\
    \ to < n);\n        internal.add_edge(from, to);\n        edges.emplace_back(from,\
    \ to);\n    }\n\n    int build() {\n        tie(group_num, scc_ids) = internal.scc_ids();\n\
    \        return group_num;\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ const {\n        std::vector<std::vector<int>> groups(group_num);\n        std::vector<int>\
    \ counts(group_num);\n        for (auto x : scc_ids) counts[x]++;\n        for\
    \ (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            groups[scc_ids[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\n    std::vector<std::vector<int>>\
    \ scc_graph() const {\n        std::vector<int> counts(group_num);\n        std::vector<std::vector<int>>\
    \ naive_scc_graph(group_num),\n            scc_graph(group_num);\n        for\
    \ (auto [from, to] : edges) counts[scc_ids[from]]++;\n        for (int i = 0;\
    \ i < group_num; i++) {\n            naive_scc_graph[i].reserve(counts[i]);\n\
    \            scc_graph[i].reserve(counts[i]);\n        }\n        for (auto [from,\
    \ to] : edges) {\n            naive_scc_graph[scc_ids[from]].push_back(scc_ids[to]);\n\
    \        }\n        std::vector<int> exists(group_num);\n        for (int from\
    \ = 0; from < group_num; from++) {\n            for (auto to : naive_scc_graph[from])\
    \ {\n                if (exists[to]) continue;\n                scc_graph[from].push_back(to);\n\
    \                exists[to] = 1;\n            }\n            for (auto to : scc_graph[from])\
    \ {\n                exists[to] = 0;\n            }\n        }\n        return\
    \ scc_graph;\n    }\n\n    int operator[](int i) const {\n        assert(0 <=\
    \ i && i < n);\n        return scc_ids[i];\n    }\n\n  private:\n    atcoder::internal::scc_graph\
    \ internal;\n    std::vector<std::pair<int, int>> edges;\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/StronglyConnectedComponents.hpp
  requiredBy: []
  timestamp: '2023-08-20 19:19:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/StronglyConnectedComponents.test.cpp
documentation_of: graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/StronglyConnectedComponents.hpp
- /library/graph/StronglyConnectedComponents.hpp.html
title: graph/StronglyConnectedComponents.hpp
---
