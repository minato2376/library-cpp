---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/UnionFind.test.cpp
    title: test/datastructure/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/UnionFind.hpp\"\n\n/**\n * \u9AD8\u901F\u3001\
    \u7701\u30E1\u30E2\u30EA\u306A\u30B7\u30F3\u30D7\u30EB\u306A UnionFind \u3092\u4F7F\
    \u3044\u305F\u3044\u5834\u5408\u3001atcoder::dsu \u3092\u4F7F\u3046\u3002\n */\n\
    struct UnionFind {\n  private:\n    int n, group_number;\n    vector<int> parent_or_size,\
    \ nex;\n\n  public:\n    UnionFind() : n(0), group_number(0) {\n    }\n    UnionFind(int\
    \ n) : n(n), group_number(n), parent_or_size(n, -1), nex(n) {\n        iota(nex.begin(),\
    \ nex.end(), 0);\n    }\n\n    int size() const {\n        return n;\n    }\n\n\
    \    /**\n     * \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     */\n    int count() const {\n        return group_number;\n\
    \    }\n\n    bool merge(int x, int y) {\n        assert(0 <= x and x < n);\n\
    \        assert(0 <= y and y < n);\n        x = root_(x);\n        y = root_(y);\n\
    \        if (x == y) return false;\n        if (parent_or_size[x] > parent_or_size[y])\
    \ swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        swap(nex[x], nex[y]);\n        group_number--;\n        return\
    \ true;\n    }\n\n    /**\n     * @param f void f(int parent, int child)\n   \
    \  * \u30DE\u30FC\u30B8\u3059\u308B\u969B\u306E\u51E6\u7406\u3092\u884C\u3046\u95A2\
    \u6570\u3092\u6E21\u3059\u3002\n     */\n    template <class F> bool merge(int\
    \ x, int y, const F& f) {\n        assert(0 <= x and x < n);\n        assert(0\
    \ <= y and y < n);\n        x = root_(x);\n        y = root_(y);\n        if (x\
    \ == y) return false;\n        if (parent_or_size[x] > parent_or_size[y]) swap(x,\
    \ y);\n        f(x, y);\n        parent_or_size[x] += parent_or_size[y];\n   \
    \     parent_or_size[y] = x;\n        swap(nex[x], nex[y]);\n        group_number--;\n\
    \        return true;\n    }\n\n    bool same(int x, int y) {\n        assert(0\
    \ <= x and x < n);\n        assert(0 <= y and y < n);\n        return root_(x)\
    \ == root_(y);\n    }\n\n    int root(int x) {\n        assert(0 <= x and x <\
    \ n);\n        return root_(x);\n    }\n\n    /**\n     * \u9802\u70B9 x \u306E\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\
    \u3059\u3002\n     */\n    int size(int x) {\n        assert(0 <= x and x < n);\n\
    \        return -parent_or_size[root_(x)];\n    }\n\n    /**\n     * \u9802\u70B9\
    \ x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\
    \u8FD4\u3059\u3002\n     * root(x) \u3068\u540C\u3058\u3002\n     */\n    int\
    \ operator[](int x) {\n        assert(0 <= x and x < n);\n        return root_(x);\n\
    \    }\n\n    vector<vector<int>> groups() {\n        vector<int> leader_buf(n),\
    \ group_size(n);\n        for (int i = 0; i < n; i++) {\n            leader_buf[i]\
    \ = root(i);\n            group_size[leader_buf[i]]++;\n        }\n        vector<vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(),\n   \
    \                            [&](const vector<int>& v) { return v.empty(); }),\n\
    \                     result.end());\n        return result;\n    }\n\n    /**\n\
    \     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u9802\
    \u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\n     * O(size(x))\n\
    \     */\n    vector<int> group(int x) const {\n        assert(0 <= x and x <\
    \ n);\n        vector<int> ret;\n        int v = x;\n        do {\n          \
    \  ret.emplace_back(v);\n            v = nex[v];\n        } while (v != x);\n\
    \        return ret;\n    }\n\n  private:\n    int root_(int x) {\n        if\
    \ (parent_or_size[x] < 0) return x;\n        return parent_or_size[x] = root_(parent_or_size[x]);\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * \u9AD8\u901F\u3001\u7701\u30E1\u30E2\u30EA\u306A\u30B7\
    \u30F3\u30D7\u30EB\u306A UnionFind \u3092\u4F7F\u3044\u305F\u3044\u5834\u5408\u3001\
    atcoder::dsu \u3092\u4F7F\u3046\u3002\n */\nstruct UnionFind {\n  private:\n \
    \   int n, group_number;\n    vector<int> parent_or_size, nex;\n\n  public:\n\
    \    UnionFind() : n(0), group_number(0) {\n    }\n    UnionFind(int n) : n(n),\
    \ group_number(n), parent_or_size(n, -1), nex(n) {\n        iota(nex.begin(),\
    \ nex.end(), 0);\n    }\n\n    int size() const {\n        return n;\n    }\n\n\
    \    /**\n     * \u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\u3002\n     */\n    int count() const {\n        return group_number;\n\
    \    }\n\n    bool merge(int x, int y) {\n        assert(0 <= x and x < n);\n\
    \        assert(0 <= y and y < n);\n        x = root_(x);\n        y = root_(y);\n\
    \        if (x == y) return false;\n        if (parent_or_size[x] > parent_or_size[y])\
    \ swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        swap(nex[x], nex[y]);\n        group_number--;\n        return\
    \ true;\n    }\n\n    /**\n     * @param f void f(int parent, int child)\n   \
    \  * \u30DE\u30FC\u30B8\u3059\u308B\u969B\u306E\u51E6\u7406\u3092\u884C\u3046\u95A2\
    \u6570\u3092\u6E21\u3059\u3002\n     */\n    template <class F> bool merge(int\
    \ x, int y, const F& f) {\n        assert(0 <= x and x < n);\n        assert(0\
    \ <= y and y < n);\n        x = root_(x);\n        y = root_(y);\n        if (x\
    \ == y) return false;\n        if (parent_or_size[x] > parent_or_size[y]) swap(x,\
    \ y);\n        f(x, y);\n        parent_or_size[x] += parent_or_size[y];\n   \
    \     parent_or_size[y] = x;\n        swap(nex[x], nex[y]);\n        group_number--;\n\
    \        return true;\n    }\n\n    bool same(int x, int y) {\n        assert(0\
    \ <= x and x < n);\n        assert(0 <= y and y < n);\n        return root_(x)\
    \ == root_(y);\n    }\n\n    int root(int x) {\n        assert(0 <= x and x <\
    \ n);\n        return root_(x);\n    }\n\n    /**\n     * \u9802\u70B9 x \u306E\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\
    \u3059\u3002\n     */\n    int size(int x) {\n        assert(0 <= x and x < n);\n\
    \        return -parent_or_size[root_(x)];\n    }\n\n    /**\n     * \u9802\u70B9\
    \ x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\
    \u8FD4\u3059\u3002\n     * root(x) \u3068\u540C\u3058\u3002\n     */\n    int\
    \ operator[](int x) {\n        assert(0 <= x and x < n);\n        return root_(x);\n\
    \    }\n\n    vector<vector<int>> groups() {\n        vector<int> leader_buf(n),\
    \ group_size(n);\n        for (int i = 0; i < n; i++) {\n            leader_buf[i]\
    \ = root(i);\n            group_size[leader_buf[i]]++;\n        }\n        vector<vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(),\n   \
    \                            [&](const vector<int>& v) { return v.empty(); }),\n\
    \                     result.end());\n        return result;\n    }\n\n    /**\n\
    \     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u9802\
    \u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\n     * O(size(x))\n\
    \     */\n    vector<int> group(int x) const {\n        assert(0 <= x and x <\
    \ n);\n        vector<int> ret;\n        int v = x;\n        do {\n          \
    \  ret.emplace_back(v);\n            v = nex[v];\n        } while (v != x);\n\
    \        return ret;\n    }\n\n  private:\n    int root_(int x) {\n        if\
    \ (parent_or_size[x] < 0) return x;\n        return parent_or_size[x] = root_(parent_or_size[x]);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/UnionFind.hpp
  requiredBy: []
  timestamp: '2023-01-30 01:31:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/UnionFind.test.cpp
documentation_of: datastructure/UnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFind.hpp
- /library/datastructure/UnionFind.hpp.html
title: datastructure/UnionFind.hpp
---
