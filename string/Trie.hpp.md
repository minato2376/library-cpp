---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Trie
    links: []
  bundledCode: "#line 2 \"string/Trie.hpp\"\n\n#include <map>\n#include <vector>\n\
    \n/**\n * @brief Trie\n * \u5168\u30CE\u30FC\u30C9\u306F\u8FFD\u52A0\u3057\u305F\
    \u6587\u5B57\u5217\u306E prefix \u306B\u5BFE\u5FDC\u3059\u308B\n */\ntemplate\
    \ <typename Char> struct Trie {\n    struct Node {\n        std::map<Char, int>\
    \ next;\n        Node() {\n        }\n    };\n\n    static constexpr int root\
    \ = 0;\n    std::vector<Node> nodes;\n\n    Trie() : nodes(1) {\n    }\n\n   \
    \ int size() const {\n        return nodes.size();\n    }\n\n    const Node& operator[](int\
    \ v) const {\n        return nodes[v];\n    }\n\n    Node& operator[](int v) {\n\
    \        return nodes[v];\n    }\n\n    /**\n     * \u9802\u70B9 v \u304B\u3089\
    \ c \u3092\u8FBF\u3063\u305F\u5148\u306E\u9802\u70B9\u3092\u8FD4\u3059\n     *\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n   \
    \  */\n    int find_char(Char c, int v = root) {\n        return nodes[v].next.contains(c)\
    \ ? nodes[v].next[c] : -1;\n    }\n\n    /**\n     * \u6587\u5B57\u5217 s \uFF08\
    \u306E\u7D42\u7AEF\uFF09\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\
    \u3059\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\
    \u3059\n     */\n    template <typename String> int find_string(const String&\
    \ s) {\n        int v = 0;\n        for (const auto& c : s) {\n            v =\
    \ find_char(c, v);\n            if (v == -1) break;\n        }\n        return\
    \ v;\n    }\n\n    /**\n     * \u9802\u70B9 v \u304B\u3089 c \u3092\u8FBF\u3063\
    \u305F\u5148\u306E\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306F\u65B0\u305F\u306B\u9802\u70B9\u3092\u4F5C\u6210\u3057\
    \u3066\u8FD4\u3059\n     */\n    int add_char(Char c, int v = root) {\n      \
    \  int nv = find_char(c, v);\n        if (nv == -1) {\n            nv = nodes.size();\n\
    \            nodes.emplace_back();\n            nodes[v].next[c] = nv;\n     \
    \   }\n        return nv;\n    }\n\n    /**\n     * \u6587\u5B57\u5217 s \u3092\
    \u8FFD\u52A0\u3059\u308B\n     * \u6587\u5B57\u5217 s \u306E\u7D42\u7AEF\u306B\
    \u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n     */\n    template\
    \ <typename String> int add_string(const String& s) {\n        int v = 0;\n  \
    \      for (const auto& c : s) {\n            v = add_char(c, v);\n        }\n\
    \        return v;\n    }\n};\n"
  code: "#pragma once\n\n#include <map>\n#include <vector>\n\n/**\n * @brief Trie\n\
    \ * \u5168\u30CE\u30FC\u30C9\u306F\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\
    \ prefix \u306B\u5BFE\u5FDC\u3059\u308B\n */\ntemplate <typename Char> struct\
    \ Trie {\n    struct Node {\n        std::map<Char, int> next;\n        Node()\
    \ {\n        }\n    };\n\n    static constexpr int root = 0;\n    std::vector<Node>\
    \ nodes;\n\n    Trie() : nodes(1) {\n    }\n\n    int size() const {\n       \
    \ return nodes.size();\n    }\n\n    const Node& operator[](int v) const {\n \
    \       return nodes[v];\n    }\n\n    Node& operator[](int v) {\n        return\
    \ nodes[v];\n    }\n\n    /**\n     * \u9802\u70B9 v \u304B\u3089 c \u3092\u8FBF\
    \u3063\u305F\u5148\u306E\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n     */\n    int find_char(Char\
    \ c, int v = root) {\n        return nodes[v].next.contains(c) ? nodes[v].next[c]\
    \ : -1;\n    }\n\n    /**\n     * \u6587\u5B57\u5217 s \uFF08\u306E\u7D42\u7AEF\
    \uFF09\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n     */\n  \
    \  template <typename String> int find_string(const String& s) {\n        int\
    \ v = 0;\n        for (const auto& c : s) {\n            v = find_char(c, v);\n\
    \            if (v == -1) break;\n        }\n        return v;\n    }\n\n    /**\n\
    \     * \u9802\u70B9 v \u304B\u3089 c \u3092\u8FBF\u3063\u305F\u5148\u306E\u9802\
    \u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\
    \u65B0\u305F\u306B\u9802\u70B9\u3092\u4F5C\u6210\u3057\u3066\u8FD4\u3059\n   \
    \  */\n    int add_char(Char c, int v = root) {\n        int nv = find_char(c,\
    \ v);\n        if (nv == -1) {\n            nv = nodes.size();\n            nodes.emplace_back();\n\
    \            nodes[v].next[c] = nv;\n        }\n        return nv;\n    }\n\n\
    \    /**\n     * \u6587\u5B57\u5217 s \u3092\u8FFD\u52A0\u3059\u308B\n     * \u6587\
    \u5B57\u5217 s \u306E\u7D42\u7AEF\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\
    \u8FD4\u3059\n     */\n    template <typename String> int add_string(const String&\
    \ s) {\n        int v = 0;\n        for (const auto& c : s) {\n            v =\
    \ add_char(c, v);\n        }\n        return v;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Trie.hpp
layout: document
redirect_from:
- /library/string/Trie.hpp
- /library/string/Trie.hpp.html
title: Trie
---
