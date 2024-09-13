---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/BinaryTrie.test.cpp
    title: test/datastructure/BinaryTrie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/BinaryTrie.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <class Key, class T, int B, class F>\
    \ struct BinaryTrie {\n    struct Node {\n        int parent;\n        std::array<int,\
    \ 2> child;\n        T value;\n        Node(int parent, T value) : parent(parent),\
    \ value(value) {\n            child[0] = child[1] = -1;\n        }\n    };\n\n\
    \    F op;\n    T e;\n    std::vector<Node> nodes;\n\n    BinaryTrie(const F&\
    \ op, T e) : op(op), e(e), nodes(1, Node(-1, e)) {\n    }\n\n    int create_node(int\
    \ parent, T value) {\n        int ret = int(nodes.size());\n        nodes.emplace_back(parent,\
    \ value);\n        return ret;\n    }\n\n    void insert(Key key, T value) {\n\
    \        int cur = 0;\n\n        for (int i = B - 1; i >= 0; i--) {\n        \
    \    int b = kthbit(key, i);\n            if (nodes[cur].child[b] == -1) {\n \
    \               nodes[cur].child[b] = create_node(cur, e);\n            }\n  \
    \          cur = nodes[cur].child[b];\n        }\n\n        nodes[cur].value =\
    \ value;\n        for (int i = 0; i < B; i++) {\n            cur = nodes[cur].parent;\n\
    \            nodes[cur].value = op(\n                nodes[cur].child[0] == -1\
    \ ? e\n                                          : nodes[nodes[cur].child[0]].value,\n\
    \                nodes[cur].child[1] == -1 ? e\n                             \
    \             : nodes[nodes[cur].child[1]].value);\n        }\n    }\n\n    void\
    \ erase(Key key) {\n        int cur = 0;\n\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            int b = kthbit(key, i);\n            assert(nodes[cur].child[b]\
    \ != -1);\n            cur = nodes[cur].child[b];\n        }\n\n        for (int\
    \ i = 0; i < B; i++) {\n            cur = nodes[cur].parent;\n            int\
    \ b = kthbit(key, i);\n            nodes[cur].child[b] = -1;\n            if (nodes[cur].child[1\
    \ ^ b] != -1) {\n                nodes[cur].value = op(nodes[cur].child[0] ==\
    \ -1\n                                          ? e\n                        \
    \                  : nodes[nodes[cur].child[0]].value,\n                     \
    \                 nodes[cur].child[1] == -1\n                                \
    \          ? e\n                                          : nodes[nodes[cur].child[1]].value);\n\
    \                break;\n            }\n        }\n    }\n\n    int find(Key key)\
    \ const {\n        int cur = 0;\n        for (int i = B - 1; i >= 0; i--) {\n\
    \            int b = kthbit(key, i);\n            if (nodes[cur].child[b] == -1)\
    \ {\n                return -1;\n            }\n            cur = nodes[cur].child[b];\n\
    \        }\n\n        return cur;\n    }\n\n    /**\n     * key \u304B\u3089\u306A\
    \u308B\u96C6\u5408\u306B\u5024 x \u3067 xor \u3057\u305F\u3068\u304D\u306E\u6700\
    \u5C0F\u5024\u3092\u6C42\u3081\u308B\n     * \u6700\u5C0F\u5024\u306F xor \u3057\
    \u305F\u3042\u3068\u306E\u5024\n     * O(B)\n     */\n    Key min_element(Key\
    \ x = 0) const {\n        int cur = 0;\n\n        Key ret = 0;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            int b = kthbit(x, i);\n            if\
    \ (nodes[cur].child[b] == -1) {\n                ret ^= 1 << i;\n            \
    \    cur = nodes[cur].child[1 ^ b];\n            } else {\n                cur\
    \ = nodes[cur].child[b];\n            }\n        }\n        return ret;\n    }\n\
    \n    Key max_element(Key x = 0) const {\n        int cur = 0;\n\n        Key\
    \ ret = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            int b = kthbit(x,\
    \ i);\n            if (nodes[cur].child[1 ^ b] == -1) {\n                cur =\
    \ nodes[cur].child[b];\n            } else {\n                ret ^= 1 << i;\n\
    \                cur = nodes[cur].child[1 ^ b];\n            }\n        }\n  \
    \      return ret;\n    }\n\n    int kthbit(Key key, int k) const {\n        return\
    \ (key >> k) & 1;\n    }\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class Key, class T, int B, class F> struct BinaryTrie {\n    struct\
    \ Node {\n        int parent;\n        std::array<int, 2> child;\n        T value;\n\
    \        Node(int parent, T value) : parent(parent), value(value) {\n        \
    \    child[0] = child[1] = -1;\n        }\n    };\n\n    F op;\n    T e;\n   \
    \ std::vector<Node> nodes;\n\n    BinaryTrie(const F& op, T e) : op(op), e(e),\
    \ nodes(1, Node(-1, e)) {\n    }\n\n    int create_node(int parent, T value) {\n\
    \        int ret = int(nodes.size());\n        nodes.emplace_back(parent, value);\n\
    \        return ret;\n    }\n\n    void insert(Key key, T value) {\n        int\
    \ cur = 0;\n\n        for (int i = B - 1; i >= 0; i--) {\n            int b =\
    \ kthbit(key, i);\n            if (nodes[cur].child[b] == -1) {\n            \
    \    nodes[cur].child[b] = create_node(cur, e);\n            }\n            cur\
    \ = nodes[cur].child[b];\n        }\n\n        nodes[cur].value = value;\n   \
    \     for (int i = 0; i < B; i++) {\n            cur = nodes[cur].parent;\n  \
    \          nodes[cur].value = op(\n                nodes[cur].child[0] == -1 ?\
    \ e\n                                          : nodes[nodes[cur].child[0]].value,\n\
    \                nodes[cur].child[1] == -1 ? e\n                             \
    \             : nodes[nodes[cur].child[1]].value);\n        }\n    }\n\n    void\
    \ erase(Key key) {\n        int cur = 0;\n\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            int b = kthbit(key, i);\n            assert(nodes[cur].child[b]\
    \ != -1);\n            cur = nodes[cur].child[b];\n        }\n\n        for (int\
    \ i = 0; i < B; i++) {\n            cur = nodes[cur].parent;\n            int\
    \ b = kthbit(key, i);\n            nodes[cur].child[b] = -1;\n            if (nodes[cur].child[1\
    \ ^ b] != -1) {\n                nodes[cur].value = op(nodes[cur].child[0] ==\
    \ -1\n                                          ? e\n                        \
    \                  : nodes[nodes[cur].child[0]].value,\n                     \
    \                 nodes[cur].child[1] == -1\n                                \
    \          ? e\n                                          : nodes[nodes[cur].child[1]].value);\n\
    \                break;\n            }\n        }\n    }\n\n    int find(Key key)\
    \ const {\n        int cur = 0;\n        for (int i = B - 1; i >= 0; i--) {\n\
    \            int b = kthbit(key, i);\n            if (nodes[cur].child[b] == -1)\
    \ {\n                return -1;\n            }\n            cur = nodes[cur].child[b];\n\
    \        }\n\n        return cur;\n    }\n\n    /**\n     * key \u304B\u3089\u306A\
    \u308B\u96C6\u5408\u306B\u5024 x \u3067 xor \u3057\u305F\u3068\u304D\u306E\u6700\
    \u5C0F\u5024\u3092\u6C42\u3081\u308B\n     * \u6700\u5C0F\u5024\u306F xor \u3057\
    \u305F\u3042\u3068\u306E\u5024\n     * O(B)\n     */\n    Key min_element(Key\
    \ x = 0) const {\n        int cur = 0;\n\n        Key ret = 0;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            int b = kthbit(x, i);\n            if\
    \ (nodes[cur].child[b] == -1) {\n                ret ^= 1 << i;\n            \
    \    cur = nodes[cur].child[1 ^ b];\n            } else {\n                cur\
    \ = nodes[cur].child[b];\n            }\n        }\n        return ret;\n    }\n\
    \n    Key max_element(Key x = 0) const {\n        int cur = 0;\n\n        Key\
    \ ret = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            int b = kthbit(x,\
    \ i);\n            if (nodes[cur].child[1 ^ b] == -1) {\n                cur =\
    \ nodes[cur].child[b];\n            } else {\n                ret ^= 1 << i;\n\
    \                cur = nodes[cur].child[1 ^ b];\n            }\n        }\n  \
    \      return ret;\n    }\n\n    int kthbit(Key key, int k) const {\n        return\
    \ (key >> k) & 1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/BinaryTrie.test.cpp
documentation_of: datastructure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/datastructure/BinaryTrie.hpp
- /library/datastructure/BinaryTrie.hpp.html
title: datastructure/BinaryTrie.hpp
---
