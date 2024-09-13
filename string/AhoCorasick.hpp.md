---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: AhoCorasick
    links: []
  bundledCode: "#line 2 \"string/AhoCorasick.hpp\"\n\n#include <map>\n#include <queue>\n\
    #include <vector>\n\n/**\n * @brief AhoCorasick\n * @note \u5168\u30CE\u30FC\u30C9\
    \u306F\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E prefix \u306B\u5BFE\u5FDC\
    \u3059\u308B\n * @note link \u306F suffix link \u3067\u3001\u305D\u306E node \u306B\
    \u5BFE\u5FDC\u3059\u308B\u6587\u5B57\u5217\u306E\u6700\u9577\u306E suffix\n *\
    \ \u306B\u5BFE\u5FDC\u3059\u308B node \u306B\u30EA\u30F3\u30AF\u3059\u308B\n *\
    \ @note link \u306F v \u3088\u308A\u9802\u70B9\u756A\u53F7\u306F\u5C0F\u3055\u3044\
    \u3068\u306F\u9650\u3089\u306A\u3044\u304C\u3001\u6DF1\u3055\u306F\u5FC5\u305A\
    \u5C0F\u3055\u3044\n */\ntemplate <typename Char> struct AhoCorasick {\n    struct\
    \ Node {\n        std::map<Char, int> next;\n        int link;\n        Node()\
    \ : link(-1) {\n        }\n    };\n\n    static constexpr int root = 0;\n    std::vector<Node>\
    \ nodes;\n\n    AhoCorasick() : nodes(1) {\n    }\n\n    const Node& operator[](int\
    \ v) const {\n        return nodes[v];\n    }\n\n    Node& operator[](int v) {\n\
    \        return nodes[v];\n    }\n\n    int size() const {\n        return nodes.size();\n\
    \    }\n\n    /**\n     * \u9802\u70B9 v \u304B\u3089 c \u3092\u8FBF\u3063\u305F\
    \u5148\u306E\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n     */\n    int find_char(Char c, int\
    \ v = root) {\n        return nodes[v].next.contains(c) ? nodes[v].next[c] : -1;\n\
    \    }\n\n    /**\n     * \u6587\u5B57\u5217 s \uFF08\u306E\u7D42\u7AEF\uFF09\u306B\
    \u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n     */\n    template <typename\
    \ String> int find_string(const String& s) {\n        int v = 0;\n        for\
    \ (const auto& c : s) {\n            v = find_char(c, v);\n            if (v ==\
    \ -1) break;\n        }\n        return v;\n    }\n\n    /**\n     * \u9802\u70B9\
    \ v \u304B\u3089 c \u3092\u8FBF\u3063\u305F\u5148\u306E\u9802\u70B9\u3092\u8FD4\
    \u3059\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u65B0\u305F\u306B\
    \u9802\u70B9\u3092\u4F5C\u6210\u3057\u3066\u8FD4\u3059\n     */\n    int add_char(Char\
    \ c, int v = root) {\n        int nv = find_char(c, v);\n        if (nv == -1)\
    \ {\n            nv = nodes.size();\n            nodes.emplace_back();\n     \
    \       nodes[v].next[c] = nv;\n        }\n        return nv;\n    }\n\n    /**\n\
    \     * \u6587\u5B57\u5217 s \u3092\u8FFD\u52A0\u3059\u308B\n     * \u6587\u5B57\
    \u5217 s \u306E\u7D42\u7AEF\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\
    \u3059\n     */\n    template <typename String> int add_string(const String& s)\
    \ {\n        int v = 0;\n        for (const auto& c : s) {\n            v = add_char(c,\
    \ v);\n        }\n        return v;\n    }\n\n    /**\n     * \u9802\u70B9 v \u306B\
    \u76F8\u5F53\u3059\u308B\u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066\u6587\u5B57\
    \ c \u3092\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u3068\u6700\u3082 suffix\n\
    \     * \u304C\u4E00\u81F4\u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n     * @note\
    \ \u6700\u60AA v\n     * \u306E\u6DF1\u3055\u3060\u3051\u304B\u304B\u308B\u304C\
    \u3001\u8FD4\u3059\u9802\u70B9\u306E\u6DF1\u3055\u306F\u305D\u306E\u5206\u3060\
    \u3051\u6E1B\u3063\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\u3059\u308B\
    \n     */\n    int process(int v, Char c) {\n        while (v != -1 && find_char(c,\
    \ v) == -1) v = nodes[v].link;\n        return v == -1 ? root : find_char(c, v);\n\
    \    }\n\n    void build() {\n        std::queue<int> que;\n        que.push(root);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (const auto& [c, nv] : nodes[v].next) {\n     \
    \           nodes[nv].link = process(nodes[v].link, c);\n                que.push(nv);\n\
    \            }\n        }\n    }\n\n    /**\n     * \u5404\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066\u6587\u5B57 transition[i]\
    \ \u3092\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\n     * \u9077\u79FB\u5148\u306E\
    \u9802\u70B9\u3092\u683C\u7D0D\u3057\u305F\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\
    \u3059\n     */\n    template <typename String>\n    std::vector<std::vector<int>>\
    \ transition_table(const String& transition) {\n        std::map<Char, int> char_to_index;\n\
    \        int M = 0;\n        for (const auto& c : transition) {\n            char_to_index[c]\
    \ = M++;\n        }\n        std::vector<std::vector<int>> table(size(), std::vector<int>(M));\n\
    \        std::queue<int> que;\n        que.push(root);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            if\
    \ (v != root) {\n                for (int i = 0; i < M; i++) {\n             \
    \       table[v][i] = table[nodes[v].link][i];\n                }\n          \
    \  }\n            for (const auto& [c, nv] : nodes[v].next) {\n              \
    \  table[v][char_to_index[c]] = nv;\n                que.push(nv);\n         \
    \   }\n        }\n        return table;\n    }\n\n    /**\n     * \u7981\u6B62\
    \u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u6E21\u3059\
    \u3068\u3001\u5404\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u6587\u5B57\u5217\
    \u304C\u7981\u6B62\u6587\u5B57\u5217\u3092\n     * suffix \u306B\u6301\u3064\u304B\
    \u3069\u3046\u304B\u3092\u683C\u7D0D\u3057\u305F\u30C6\u30FC\u30D6\u30EB\u3092\
    \u8FD4\u3059\n     */\n    std::vector<short> banned_table(const std::vector<int>&\
    \ banned) {\n        std::vector<short> table(size());\n        for (auto v :\
    \ banned) {\n            table[v] = true;\n        }\n        std::queue<int>\
    \ que;\n        que.push(root);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            if (v != root) table[v]\
    \ |= table[nodes[v].link];\n            for (const auto& [c, nv] : nodes[v].next)\
    \ {\n                que.push(nv);\n            }\n        }\n        return table;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <map>\n#include <queue>\n#include <vector>\n\n/**\n\
    \ * @brief AhoCorasick\n * @note \u5168\u30CE\u30FC\u30C9\u306F\u8FFD\u52A0\u3057\
    \u305F\u6587\u5B57\u5217\u306E prefix \u306B\u5BFE\u5FDC\u3059\u308B\n * @note\
    \ link \u306F suffix link \u3067\u3001\u305D\u306E node \u306B\u5BFE\u5FDC\u3059\
    \u308B\u6587\u5B57\u5217\u306E\u6700\u9577\u306E suffix\n * \u306B\u5BFE\u5FDC\
    \u3059\u308B node \u306B\u30EA\u30F3\u30AF\u3059\u308B\n * @note link \u306F v\
    \ \u3088\u308A\u9802\u70B9\u756A\u53F7\u306F\u5C0F\u3055\u3044\u3068\u306F\u9650\
    \u3089\u306A\u3044\u304C\u3001\u6DF1\u3055\u306F\u5FC5\u305A\u5C0F\u3055\u3044\
    \n */\ntemplate <typename Char> struct AhoCorasick {\n    struct Node {\n    \
    \    std::map<Char, int> next;\n        int link;\n        Node() : link(-1) {\n\
    \        }\n    };\n\n    static constexpr int root = 0;\n    std::vector<Node>\
    \ nodes;\n\n    AhoCorasick() : nodes(1) {\n    }\n\n    const Node& operator[](int\
    \ v) const {\n        return nodes[v];\n    }\n\n    Node& operator[](int v) {\n\
    \        return nodes[v];\n    }\n\n    int size() const {\n        return nodes.size();\n\
    \    }\n\n    /**\n     * \u9802\u70B9 v \u304B\u3089 c \u3092\u8FBF\u3063\u305F\
    \u5148\u306E\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n     */\n    int find_char(Char c, int\
    \ v = root) {\n        return nodes[v].next.contains(c) ? nodes[v].next[c] : -1;\n\
    \    }\n\n    /**\n     * \u6587\u5B57\u5217 s \uFF08\u306E\u7D42\u7AEF\uFF09\u306B\
    \u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n     * \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\u3059\n     */\n    template <typename\
    \ String> int find_string(const String& s) {\n        int v = 0;\n        for\
    \ (const auto& c : s) {\n            v = find_char(c, v);\n            if (v ==\
    \ -1) break;\n        }\n        return v;\n    }\n\n    /**\n     * \u9802\u70B9\
    \ v \u304B\u3089 c \u3092\u8FBF\u3063\u305F\u5148\u306E\u9802\u70B9\u3092\u8FD4\
    \u3059\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\u65B0\u305F\u306B\
    \u9802\u70B9\u3092\u4F5C\u6210\u3057\u3066\u8FD4\u3059\n     */\n    int add_char(Char\
    \ c, int v = root) {\n        int nv = find_char(c, v);\n        if (nv == -1)\
    \ {\n            nv = nodes.size();\n            nodes.emplace_back();\n     \
    \       nodes[v].next[c] = nv;\n        }\n        return nv;\n    }\n\n    /**\n\
    \     * \u6587\u5B57\u5217 s \u3092\u8FFD\u52A0\u3059\u308B\n     * \u6587\u5B57\
    \u5217 s \u306E\u7D42\u7AEF\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u8FD4\
    \u3059\n     */\n    template <typename String> int add_string(const String& s)\
    \ {\n        int v = 0;\n        for (const auto& c : s) {\n            v = add_char(c,\
    \ v);\n        }\n        return v;\n    }\n\n    /**\n     * \u9802\u70B9 v \u306B\
    \u76F8\u5F53\u3059\u308B\u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066\u6587\u5B57\
    \ c \u3092\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u3068\u6700\u3082 suffix\n\
    \     * \u304C\u4E00\u81F4\u3059\u308B\u9802\u70B9\u3092\u8FD4\u3059\n     * @note\
    \ \u6700\u60AA v\n     * \u306E\u6DF1\u3055\u3060\u3051\u304B\u304B\u308B\u304C\
    \u3001\u8FD4\u3059\u9802\u70B9\u306E\u6DF1\u3055\u306F\u305D\u306E\u5206\u3060\
    \u3051\u6E1B\u3063\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\u3059\u308B\
    \n     */\n    int process(int v, Char c) {\n        while (v != -1 && find_char(c,\
    \ v) == -1) v = nodes[v].link;\n        return v == -1 ? root : find_char(c, v);\n\
    \    }\n\n    void build() {\n        std::queue<int> que;\n        que.push(root);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (const auto& [c, nv] : nodes[v].next) {\n     \
    \           nodes[nv].link = process(nodes[v].link, c);\n                que.push(nv);\n\
    \            }\n        }\n    }\n\n    /**\n     * \u5404\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066\u6587\u5B57 transition[i]\
    \ \u3092\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\n     * \u9077\u79FB\u5148\u306E\
    \u9802\u70B9\u3092\u683C\u7D0D\u3057\u305F\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\
    \u3059\n     */\n    template <typename String>\n    std::vector<std::vector<int>>\
    \ transition_table(const String& transition) {\n        std::map<Char, int> char_to_index;\n\
    \        int M = 0;\n        for (const auto& c : transition) {\n            char_to_index[c]\
    \ = M++;\n        }\n        std::vector<std::vector<int>> table(size(), std::vector<int>(M));\n\
    \        std::queue<int> que;\n        que.push(root);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            if\
    \ (v != root) {\n                for (int i = 0; i < M; i++) {\n             \
    \       table[v][i] = table[nodes[v].link][i];\n                }\n          \
    \  }\n            for (const auto& [c, nv] : nodes[v].next) {\n              \
    \  table[v][char_to_index[c]] = nv;\n                que.push(nv);\n         \
    \   }\n        }\n        return table;\n    }\n\n    /**\n     * \u7981\u6B62\
    \u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\u308B\u9802\u70B9\u3092\u6E21\u3059\
    \u3068\u3001\u5404\u9802\u70B9\u306B\u5BFE\u5FDC\u3059\u308B\u6587\u5B57\u5217\
    \u304C\u7981\u6B62\u6587\u5B57\u5217\u3092\n     * suffix \u306B\u6301\u3064\u304B\
    \u3069\u3046\u304B\u3092\u683C\u7D0D\u3057\u305F\u30C6\u30FC\u30D6\u30EB\u3092\
    \u8FD4\u3059\n     */\n    std::vector<short> banned_table(const std::vector<int>&\
    \ banned) {\n        std::vector<short> table(size());\n        for (auto v :\
    \ banned) {\n            table[v] = true;\n        }\n        std::queue<int>\
    \ que;\n        que.push(root);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            if (v != root) table[v]\
    \ |= table[nodes[v].link];\n            for (const auto& [c, nv] : nodes[v].next)\
    \ {\n                que.push(nv);\n            }\n        }\n        return table;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/AhoCorasick.hpp
layout: document
redirect_from:
- /library/string/AhoCorasick.hpp
- /library/string/AhoCorasick.hpp.html
title: AhoCorasick
---
