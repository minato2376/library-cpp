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
  bundledCode: "#line 2 \"datastructure/UndoUnionFind.hpp\"\n\n#include <algorithm>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n\nstruct UndoUnionFind\
    \ {\n  private:\n    struct History {\n        int v, prev;\n        History()\
    \ {\n        }\n        History(int v, int prev) : v(v), prev(prev) {\n      \
    \  }\n    };\n    int n, group_number;\n    std::vector<int> parent_or_size, nex;\n\
    \    std::vector<History> histories;\n\n  public:\n    UndoUnionFind() : n(0),\
    \ group_number(0) {\n    }\n    UndoUnionFind(int n)\n        : n(n), group_number(n),\
    \ parent_or_size(n, -1), nex(n) {\n        std::iota(nex.begin(), nex.end(), 0);\n\
    \    }\n\n    int size() const {\n        return n;\n    }\n\n    int count()\
    \ const {\n        return group_number;\n    }\n\n    bool merge(int x, int y)\
    \ {\n        x = root(x);\n        y = root(y);\n        histories.emplace_back(x,\
    \ parent_or_size[x]);\n        histories.emplace_back(y, parent_or_size[y]);\n\
    \        if (x == y) return false;\n        if (parent_or_size[x] > parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        std::swap(nex[x], nex[y]);\n        group_number--;\n        return\
    \ true;\n    }\n\n    template <class F> bool merge(int x, int y, const F& f)\
    \ {\n        x = root(x);\n        y = root(y);\n        histories.emplace_back(x,\
    \ parent_or_size[x]);\n        histories.emplace_back(y, parent_or_size[y]);\n\
    \        if (x == y) return false;\n        if (parent_or_size[x] > parent_or_size[y])\
    \ std::swap(x, y);\n        f(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        std::swap(nex[x], nex[y]);\n        group_number--;\n\
    \        return true;\n    }\n\n    /**\n     * O(log n)\n     */\n    bool same(int\
    \ x, int y) const {\n        return root(x) == root(y);\n    }\n\n    /**\n  \
    \   * O(log n)\n     */\n    int size(int x) const {\n        return -parent_or_size[root(x)];\n\
    \    }\n\n    /**\n     * O(log n)\n     */\n    int root(int x) const {\n   \
    \     if (parent_or_size[x] < 0) return x;\n        return root(parent_or_size[x]);\n\
    \    }\n\n    /**\n     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u3002\n     * root(x) \u3068\u540C\
    \u3058\u3002\n     */\n    int operator[](int x) {\n        return root(x);\n\
    \    }\n\n    /**\n     * O(n)\n     */\n    std::vector<std::vector<int>> groups()\
    \ const {\n        std::vector<int> leader_buf(n, -1), group_size(n);\n      \
    \  auto dfs = [&](auto self, int v) -> int {\n            if (leader_buf[v] !=\
    \ -1) return leader_buf[v];\n            if (parent_or_size[v] < 0) return leader_buf[v]\
    \ = v;\n            return leader_buf[v] = self(self, parent_or_size[v]);\n  \
    \      };\n        for (int i = 0; i < n; i++) {\n            if (leader_buf[i]\
    \ == -1) dfs(dfs, i);\n            group_size[leader_buf[i]]++;\n        }\n \
    \       std::vector<std::vector<int>> result(n);\n        for (int i = 0; i <\
    \ n; i++) {\n            result[i].reserve(group_size[i]);\n        }\n      \
    \  for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n\n    /**\n     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\
    \u3002\n     * O(size(x))\n     */\n    std::vector<int> group(int x) const {\n\
    \        std::vector<int> ret;\n        ret.reserve(size(x));\n        int v =\
    \ x;\n        do {\n            ret.push_back(v);\n            v = nex[v];\n \
    \       } while (v != x);\n        return ret;\n    }\n\n    bool undo() {\n \
    \       auto [x, prev_x] = histories.back();\n        histories.pop_back();\n\
    \        auto [y, prev_y] = histories.back();\n        histories.pop_back();\n\
    \        if (x == y) return false;\n        group_number++;\n        std::swap(nex[x],\
    \ nex[y]);\n        parent_or_size[x] = prev_x;\n        parent_or_size[y] = prev_y;\n\
    \        return true;\n    }\n\n    void snapshot() {\n        while (!histories.empty())\
    \ histories.pop_back();\n    }\n\n    void rollback() {\n        while (!histories.empty())\
    \ undo();\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\nstruct UndoUnionFind {\n  private:\n    struct History {\n\
    \        int v, prev;\n        History() {\n        }\n        History(int v,\
    \ int prev) : v(v), prev(prev) {\n        }\n    };\n    int n, group_number;\n\
    \    std::vector<int> parent_or_size, nex;\n    std::vector<History> histories;\n\
    \n  public:\n    UndoUnionFind() : n(0), group_number(0) {\n    }\n    UndoUnionFind(int\
    \ n)\n        : n(n), group_number(n), parent_or_size(n, -1), nex(n) {\n     \
    \   std::iota(nex.begin(), nex.end(), 0);\n    }\n\n    int size() const {\n \
    \       return n;\n    }\n\n    int count() const {\n        return group_number;\n\
    \    }\n\n    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        histories.emplace_back(x, parent_or_size[x]);\n        histories.emplace_back(y,\
    \ parent_or_size[y]);\n        if (x == y) return false;\n        if (parent_or_size[x]\
    \ > parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        std::swap(nex[x], nex[y]);\n        group_number--;\n\
    \        return true;\n    }\n\n    template <class F> bool merge(int x, int y,\
    \ const F& f) {\n        x = root(x);\n        y = root(y);\n        histories.emplace_back(x,\
    \ parent_or_size[x]);\n        histories.emplace_back(y, parent_or_size[y]);\n\
    \        if (x == y) return false;\n        if (parent_or_size[x] > parent_or_size[y])\
    \ std::swap(x, y);\n        f(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        std::swap(nex[x], nex[y]);\n        group_number--;\n\
    \        return true;\n    }\n\n    /**\n     * O(log n)\n     */\n    bool same(int\
    \ x, int y) const {\n        return root(x) == root(y);\n    }\n\n    /**\n  \
    \   * O(log n)\n     */\n    int size(int x) const {\n        return -parent_or_size[root(x)];\n\
    \    }\n\n    /**\n     * O(log n)\n     */\n    int root(int x) const {\n   \
    \     if (parent_or_size[x] < 0) return x;\n        return root(parent_or_size[x]);\n\
    \    }\n\n    /**\n     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u3002\n     * root(x) \u3068\u540C\
    \u3058\u3002\n     */\n    int operator[](int x) {\n        return root(x);\n\
    \    }\n\n    /**\n     * O(n)\n     */\n    std::vector<std::vector<int>> groups()\
    \ const {\n        std::vector<int> leader_buf(n, -1), group_size(n);\n      \
    \  auto dfs = [&](auto self, int v) -> int {\n            if (leader_buf[v] !=\
    \ -1) return leader_buf[v];\n            if (parent_or_size[v] < 0) return leader_buf[v]\
    \ = v;\n            return leader_buf[v] = self(self, parent_or_size[v]);\n  \
    \      };\n        for (int i = 0; i < n; i++) {\n            if (leader_buf[i]\
    \ == -1) dfs(dfs, i);\n            group_size[leader_buf[i]]++;\n        }\n \
    \       std::vector<std::vector<int>> result(n);\n        for (int i = 0; i <\
    \ n; i++) {\n            result[i].reserve(group_size[i]);\n        }\n      \
    \  for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n\n    /**\n     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\
    \u3002\n     * O(size(x))\n     */\n    std::vector<int> group(int x) const {\n\
    \        std::vector<int> ret;\n        ret.reserve(size(x));\n        int v =\
    \ x;\n        do {\n            ret.push_back(v);\n            v = nex[v];\n \
    \       } while (v != x);\n        return ret;\n    }\n\n    bool undo() {\n \
    \       auto [x, prev_x] = histories.back();\n        histories.pop_back();\n\
    \        auto [y, prev_y] = histories.back();\n        histories.pop_back();\n\
    \        if (x == y) return false;\n        group_number++;\n        std::swap(nex[x],\
    \ nex[y]);\n        parent_or_size[x] = prev_x;\n        parent_or_size[y] = prev_y;\n\
    \        return true;\n    }\n\n    void snapshot() {\n        while (!histories.empty())\
    \ histories.pop_back();\n    }\n\n    void rollback() {\n        while (!histories.empty())\
    \ undo();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/UndoUnionFind.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/UndoUnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/UndoUnionFind.hpp
- /library/datastructure/UndoUnionFind.hpp.html
title: datastructure/UndoUnionFind.hpp
---
