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
  bundledCode: "#line 2 \"segmenttree/DynamicSegmentTree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class T, class F, int B> struct DynamicSegmentTree\
    \ {\n    using ll = long long;\n    struct Node {\n        T value;\n        int\
    \ parent = -1, left = -1, right = -1;\n        Node() {\n        }\n        Node(T\
    \ value, int parent) : value(value), parent(parent) {\n        }\n    };\n   \
    \ F op;\n    T e;\n    std::vector<Node> nodes;\n\n    DynamicSegmentTree() {\n\
    \    }\n    DynamicSegmentTree(F op, T e) : op(op), e(e), nodes(1, Node(e, -1))\
    \ {\n    }\n\n    void set(ll p, T x) {\n        assert(0 <= p && p < (1LL <<\
    \ B));\n        int idx = 0;\n        for (int b = B - 1; b >= 0; b--) {\n   \
    \         if (p >> b & 1) {\n                if (nodes[idx].right == -1) {\n \
    \                   nodes[idx].right = nodes.size();\n                    nodes.emplace_back(e,\
    \ idx);\n                }\n                idx = nodes[idx].right;\n        \
    \    } else {\n                if (nodes[idx].left == -1) {\n                \
    \    nodes[idx].left = nodes.size();\n                    nodes.emplace_back(e,\
    \ idx);\n                }\n                idx = nodes[idx].left;\n         \
    \   }\n        }\n        nodes[idx].value = x;\n        for (int b = 0; b < B;\
    \ b++) {\n            idx = nodes[idx].parent;\n            update(idx);\n   \
    \     }\n    }\n\n    T get(ll p) const {\n        assert(0 <= p && p < (1LL <<\
    \ B));\n        int idx = 0;\n        for (int b = B - 1; b >= 0; b--) {\n   \
    \         if (p >> b & 1) {\n                if (nodes[idx].right == -1) {\n \
    \                   return e;\n                }\n                idx = nodes[idx].right;\n\
    \            } else {\n                if (nodes[idx].left == -1) {\n        \
    \            return e;\n                }\n                idx = nodes[idx].left;\n\
    \            }\n        }\n        return nodes[idx].value;\n    }\n\n    T prod(ll\
    \ l, ll r) const {\n        assert(0 <= l && l <= r && r <= (1LL << B));\n   \
    \     return inner_prod(l, r, 0, 0, (1LL << B));\n    }\n\n    T all_prod() const\
    \ {\n        return nodes[0].value;\n    }\n\n  private:\n    void update(int\
    \ idx) {\n        T vl = nodes[idx].left == -1 ? e : nodes[nodes[idx].left].value;\n\
    \        T vr = nodes[idx].right == -1 ? e : nodes[nodes[idx].right].value;\n\
    \        nodes[idx].value = op(vl, vr);\n    }\n\n    T inner_prod(ll l, ll r,\
    \ int idx, ll tl, ll tr) const {\n        if (r <= tl || tr <= l) {\n        \
    \    return e;\n        }\n        if (idx == -1) {\n            return e;\n \
    \       }\n        if (l <= tl && tr <= r) {\n            return nodes[idx].value;\n\
    \        }\n        ll tm = (tl + tr) / 2;\n        return op(inner_prod(l, r,\
    \ nodes[idx].left, tl, tm),\n                  inner_prod(l, r, nodes[idx].right,\
    \ tm, tr));\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <class\
    \ T, class F, int B> struct DynamicSegmentTree {\n    using ll = long long;\n\
    \    struct Node {\n        T value;\n        int parent = -1, left = -1, right\
    \ = -1;\n        Node() {\n        }\n        Node(T value, int parent) : value(value),\
    \ parent(parent) {\n        }\n    };\n    F op;\n    T e;\n    std::vector<Node>\
    \ nodes;\n\n    DynamicSegmentTree() {\n    }\n    DynamicSegmentTree(F op, T\
    \ e) : op(op), e(e), nodes(1, Node(e, -1)) {\n    }\n\n    void set(ll p, T x)\
    \ {\n        assert(0 <= p && p < (1LL << B));\n        int idx = 0;\n       \
    \ for (int b = B - 1; b >= 0; b--) {\n            if (p >> b & 1) {\n        \
    \        if (nodes[idx].right == -1) {\n                    nodes[idx].right =\
    \ nodes.size();\n                    nodes.emplace_back(e, idx);\n           \
    \     }\n                idx = nodes[idx].right;\n            } else {\n     \
    \           if (nodes[idx].left == -1) {\n                    nodes[idx].left\
    \ = nodes.size();\n                    nodes.emplace_back(e, idx);\n         \
    \       }\n                idx = nodes[idx].left;\n            }\n        }\n\
    \        nodes[idx].value = x;\n        for (int b = 0; b < B; b++) {\n      \
    \      idx = nodes[idx].parent;\n            update(idx);\n        }\n    }\n\n\
    \    T get(ll p) const {\n        assert(0 <= p && p < (1LL << B));\n        int\
    \ idx = 0;\n        for (int b = B - 1; b >= 0; b--) {\n            if (p >> b\
    \ & 1) {\n                if (nodes[idx].right == -1) {\n                    return\
    \ e;\n                }\n                idx = nodes[idx].right;\n           \
    \ } else {\n                if (nodes[idx].left == -1) {\n                   \
    \ return e;\n                }\n                idx = nodes[idx].left;\n     \
    \       }\n        }\n        return nodes[idx].value;\n    }\n\n    T prod(ll\
    \ l, ll r) const {\n        assert(0 <= l && l <= r && r <= (1LL << B));\n   \
    \     return inner_prod(l, r, 0, 0, (1LL << B));\n    }\n\n    T all_prod() const\
    \ {\n        return nodes[0].value;\n    }\n\n  private:\n    void update(int\
    \ idx) {\n        T vl = nodes[idx].left == -1 ? e : nodes[nodes[idx].left].value;\n\
    \        T vr = nodes[idx].right == -1 ? e : nodes[nodes[idx].right].value;\n\
    \        nodes[idx].value = op(vl, vr);\n    }\n\n    T inner_prod(ll l, ll r,\
    \ int idx, ll tl, ll tr) const {\n        if (r <= tl || tr <= l) {\n        \
    \    return e;\n        }\n        if (idx == -1) {\n            return e;\n \
    \       }\n        if (l <= tl && tr <= r) {\n            return nodes[idx].value;\n\
    \        }\n        ll tm = (tl + tr) / 2;\n        return op(inner_prod(l, r,\
    \ nodes[idx].left, tl, tm),\n                  inner_prod(l, r, nodes[idx].right,\
    \ tm, tr));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/DynamicSegmentTree.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segmenttree/DynamicSegmentTree.hpp
layout: document
redirect_from:
- /library/segmenttree/DynamicSegmentTree.hpp
- /library/segmenttree/DynamicSegmentTree.hpp.html
title: segmenttree/DynamicSegmentTree.hpp
---
