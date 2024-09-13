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
  bundledCode: "#line 2 \"datastructure/RangeUnionFind.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nstruct RangeUnionFind\
    \ {\n    struct Node {\n        int l, r;\n    };\n    int n, group_number;\n\
    \    std::vector<int> parent_or_size;\n    std::vector<Node> nodes;\n\n    RangeUnionFind()\
    \ {\n    }\n    RangeUnionFind(int n_) : n(n_), group_number(n_), parent_or_size(n_,\
    \ -1) {\n        nodes.resize(n);\n        for (int i = 0; i < n; i++) {\n   \
    \         nodes[i] = {i, i};\n        }\n    }\n\n    int size() const {\n   \
    \     return n;\n    }\n\n    int group_count() const {\n        return group_number;\n\
    \    }\n\n    std::pair<int, int> range(int x) {\n        return {nodes[root(x)].l,\
    \ nodes[root(x)].r};\n    }\n\n    bool prev_merge(int x) {\n        assert(prev_root(x)\
    \ != -1);\n        return merge(x, prev_root(x));\n    }\n\n    bool next_merge(int\
    \ x) {\n        assert(next_root(x) != -1);\n        return merge(x, next_root(x));\n\
    \    }\n\n    int root(int x) {\n        if (parent_or_size[x] < 0) return x;\n\
    \        return parent_or_size[x] = root(parent_or_size[x]);\n    }\n\n    int\
    \ prev_root(int x) {\n        if (nodes[x].l == 0) return -1;\n        return\
    \ root(nodes[x].l - 1);\n    }\n\n    int next_root(int x) {\n        if (nodes[x].r\
    \ == n - 1) return -1;\n        return root(nodes[x].r + 1);\n    }\n\n    bool\
    \ merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n        if\
    \ (x == y) return false;\n        if (parent_or_size[x] > parent_or_size[y]) std::swap(x,\
    \ y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        nodes[x].r = std::max(nodes[x].r, nodes[y].r);\n        nodes[x].l\
    \ = std::min(nodes[x].l, nodes[y].l);\n        return true;\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nstruct RangeUnionFind {\n    struct Node {\n        int l,\
    \ r;\n    };\n    int n, group_number;\n    std::vector<int> parent_or_size;\n\
    \    std::vector<Node> nodes;\n\n    RangeUnionFind() {\n    }\n    RangeUnionFind(int\
    \ n_) : n(n_), group_number(n_), parent_or_size(n_, -1) {\n        nodes.resize(n);\n\
    \        for (int i = 0; i < n; i++) {\n            nodes[i] = {i, i};\n     \
    \   }\n    }\n\n    int size() const {\n        return n;\n    }\n\n    int group_count()\
    \ const {\n        return group_number;\n    }\n\n    std::pair<int, int> range(int\
    \ x) {\n        return {nodes[root(x)].l, nodes[root(x)].r};\n    }\n\n    bool\
    \ prev_merge(int x) {\n        assert(prev_root(x) != -1);\n        return merge(x,\
    \ prev_root(x));\n    }\n\n    bool next_merge(int x) {\n        assert(next_root(x)\
    \ != -1);\n        return merge(x, next_root(x));\n    }\n\n    int root(int x)\
    \ {\n        if (parent_or_size[x] < 0) return x;\n        return parent_or_size[x]\
    \ = root(parent_or_size[x]);\n    }\n\n    int prev_root(int x) {\n        if\
    \ (nodes[x].l == 0) return -1;\n        return root(nodes[x].l - 1);\n    }\n\n\
    \    int next_root(int x) {\n        if (nodes[x].r == n - 1) return -1;\n   \
    \     return root(nodes[x].r + 1);\n    }\n\n    bool merge(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if (x == y) return false;\n\
    \        if (parent_or_size[x] > parent_or_size[y]) std::swap(x, y);\n       \
    \ parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] = x;\n  \
    \      nodes[x].r = std::max(nodes[x].r, nodes[y].r);\n        nodes[x].l = std::min(nodes[x].l,\
    \ nodes[y].l);\n        return true;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/RangeUnionFind.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/RangeUnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/RangeUnionFind.hpp
- /library/datastructure/RangeUnionFind.hpp.html
title: datastructure/RangeUnionFind.hpp
---
