---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: datastructure/BinaryIndexedTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/PointAddRectangleSum.test.cpp
    title: test/segmenttree/PointAddRectangleSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/BinaryIndexedTree.hpp\"\n\ntemplate <class\
    \ T> struct BinaryIndexedTree {\n    int n;\n    vector<T> data;\n\n    BinaryIndexedTree()\
    \ {\n    }\n    BinaryIndexedTree(int n) : n(n), data(n + 1, 0) {\n    }\n\n \
    \   int size() const {\n        return n;\n    }\n\n    /**\n     * (0-indexed)\n\
    \     * a[i] += x\n     */\n    void add(int i, T x) {\n        assert(0 <= i\
    \ and i < n);\n        for (++i; i <= n; i += i & -i) data[i] += x;\n    }\n\n\
    \    // [0,i) (0-indexed) a[0] + \u2026 + a[i-1]\n    T sum(int i) const {\n \
    \       assert(0 <= i and i <= n);\n        T ret = 0;\n        for (; i > 0;\
    \ i -= i & -i) ret += data[i];\n        return ret;\n    }\n\n    /**\n     *\
    \ [l, r) (0-indexed)\n     * @return a[l] + \u2026\u3000+ a[r-1]\n     */\n  \
    \  T sum(int l, int r) const {\n        if (l >= r) return T(0);\n        return\
    \ sum(r) - sum(l);\n    }\n\n    /**\n     * (0-indexed)\n     * r = 0 or a[0]\
    \ + a[1] + ... + a[r-1] < x\n     * r = n or a[0] + a[1] + ... + a[r] >= x\n \
    \    * a[0] + a[1] + ... + a[r] >= x \u3068\u306A\u308B\u6700\u5C0F\u306E r \u3092\
    \u8FD4\u3059\u3002\n     */\n    int lower_bound(T x) const {\n        int k =\
    \ 1;\n        int ret = 0;\n        while ((k << 1) <= n) k <<= 1;\n        while\
    \ (k > 0) {\n            if (ret + k <= n and data[ret + k] < x) {\n         \
    \       x -= data[ret + k];\n                ret += k;\n            }\n      \
    \      k >>= 1;\n        }\n        return ret;\n    }\n\n    int upper_bound(T\
    \ x) const {\n        return lower_bound(x + 1);\n    }\n\n#ifdef MINATO_LOCAL\n\
    \    friend ostream& operator<<(ostream& os, const BinaryIndexedTree& r) {\n \
    \       vector<T> v(r.size());\n        for (int i = 0; i < r.size(); i++) {\n\
    \            v[i] = r.sum(i, i + 1);\n        }\n        os << v;\n        return\
    \ os;\n    }\n#endif\n};\n#line 3 \"segmenttree/PointAddRectangleSum.hpp\"\n\n\
    #include <vector>\n\ntemplate <class S, class T> struct PointAddRectangleSum {\n\
    \    using P = pair<S, S>;\n    int n, log, size, sz;\n    std::vector<P> points;\n\
    \    std::vector<S> xs, ls, rs, ys;\n    std::vector<BinaryIndexedTree<T>> BITs;\n\
    \    PointAddRectangleSum() {\n    }\n\n    void push_point(S x, S y) {\n    \
    \    points.emplace_back(x, y);\n    }\n\n    void build() {\n        sort(points.begin(),\
    \ points.end());\n        points.erase(unique(points.begin(), points.end()), points.end());\n\
    \        xs.reserve(points.size());\n        for (const auto& p : points) {\n\
    \            xs.push_back(p.first);\n        }\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = int(xs.size());\n\n        log = 0;\n   \
    \     while ((1 << log) < n) log++;\n        sz = 1 << log;\n        BITs.resize(sz\
    \ * 2);\n        ls.resize(sz * 2);\n        rs.resize(sz * 2);\n        ys.reserve(points.size());\n\
    \        int xs_index = 0;\n        for (int i = 0; i < int(points.size()); i++)\
    \ {\n            if (i > 0 && points[i].first != points[i - 1].first) {\n    \
    \            rs[sz + xs_index] = int(ys.size());\n                xs_index++;\n\
    \            }\n            if (i == 0 || points[i].first != points[i - 1].first)\
    \ {\n                ls[sz + xs_index] = int(ys.size());\n            }\n    \
    \        ys.push_back(points[i].second);\n        }\n        rs[sz + n - 1] =\
    \ int(ys.size());\n        for (int i = n; i < sz; i++) {\n            ls[sz +\
    \ i] = int(ys.size());\n            rs[sz + i] = int(ys.size());\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            BITs[sz + i] = BinaryIndexedTree<T>(rs[sz\
    \ + i] - ls[sz + i]);\n        }\n        for (int i = sz - 1; i >= 1; i--) {\n\
    \            ls[i] = int(ys.size());\n            vector<int> vs;\n          \
    \  vs.reserve(rs[i * 2] - ls[i * 2] + rs[i * 2 + 1] - ls[i * 2 + 1]);\n      \
    \      merge(ys.begin() + ls[i * 2], ys.begin() + rs[i * 2],\n               \
    \   ys.begin() + ls[i * 2 + 1], ys.begin() + rs[i * 2 + 1],\n                \
    \  back_inserter(vs));\n            vs.erase(unique(vs.begin(), vs.end()), vs.end());\n\
    \            move(vs.begin(), vs.end(), back_inserter(ys));\n            rs[i]\
    \ = int(ys.size());\n            BITs[i] = BinaryIndexedTree<T>(rs[i] - ls[i]);\n\
    \        }\n    }\n\n    void add(S x, S y, T value) {\n        int k = lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n        assert(k < n && xs[k] == x);\n        k\
    \ += sz;\n        int l = get_y_index(y, k);\n        assert(l < rs[k] - ls[k]\
    \ && ys[ls[k] + l] == y);\n        BITs[k].add(l, value);\n        for (int i\
    \ = 1; i <= log; i++) {\n            int p = k >> i;\n            int l = get_y_index(y,\
    \ p);\n            assert(l < rs[p] - ls[p] && ys[ls[p] + l] == y);\n        \
    \    BITs[p].add(l, value);\n        }\n    }\n\n    T get(S xl, S xr, S yl, S\
    \ yr) const {\n        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n\
    \        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n       \
    \ l += sz;\n        r += sz;\n        T ret = 0;\n        while (l < r) {\n  \
    \          if (l & 1) {\n                int ll = get_y_index(yl, l);\n      \
    \          int rr = get_y_index(yr, l);\n                ret += BITs[l].sum(ll,\
    \ rr);\n                l++;\n            }\n            if (r & 1) {\n      \
    \          r--;\n                int ll = get_y_index(yl, r);\n              \
    \  int rr = get_y_index(yr, r);\n                ret += BITs[r].sum(ll, rr);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return ret;\n    }\n\n  private:\n    int get_y_index(S y, int x_index) const\
    \ {\n        return lower_bound(ys.begin() + ls[x_index], ys.begin() + rs[x_index],\n\
    \                           y) -\n               (ys.begin() + ls[x_index]);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"datastructure/BinaryIndexedTree.hpp\"\n\n#include\
    \ <vector>\n\ntemplate <class S, class T> struct PointAddRectangleSum {\n    using\
    \ P = pair<S, S>;\n    int n, log, size, sz;\n    std::vector<P> points;\n   \
    \ std::vector<S> xs, ls, rs, ys;\n    std::vector<BinaryIndexedTree<T>> BITs;\n\
    \    PointAddRectangleSum() {\n    }\n\n    void push_point(S x, S y) {\n    \
    \    points.emplace_back(x, y);\n    }\n\n    void build() {\n        sort(points.begin(),\
    \ points.end());\n        points.erase(unique(points.begin(), points.end()), points.end());\n\
    \        xs.reserve(points.size());\n        for (const auto& p : points) {\n\
    \            xs.push_back(p.first);\n        }\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = int(xs.size());\n\n        log = 0;\n   \
    \     while ((1 << log) < n) log++;\n        sz = 1 << log;\n        BITs.resize(sz\
    \ * 2);\n        ls.resize(sz * 2);\n        rs.resize(sz * 2);\n        ys.reserve(points.size());\n\
    \        int xs_index = 0;\n        for (int i = 0; i < int(points.size()); i++)\
    \ {\n            if (i > 0 && points[i].first != points[i - 1].first) {\n    \
    \            rs[sz + xs_index] = int(ys.size());\n                xs_index++;\n\
    \            }\n            if (i == 0 || points[i].first != points[i - 1].first)\
    \ {\n                ls[sz + xs_index] = int(ys.size());\n            }\n    \
    \        ys.push_back(points[i].second);\n        }\n        rs[sz + n - 1] =\
    \ int(ys.size());\n        for (int i = n; i < sz; i++) {\n            ls[sz +\
    \ i] = int(ys.size());\n            rs[sz + i] = int(ys.size());\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            BITs[sz + i] = BinaryIndexedTree<T>(rs[sz\
    \ + i] - ls[sz + i]);\n        }\n        for (int i = sz - 1; i >= 1; i--) {\n\
    \            ls[i] = int(ys.size());\n            vector<int> vs;\n          \
    \  vs.reserve(rs[i * 2] - ls[i * 2] + rs[i * 2 + 1] - ls[i * 2 + 1]);\n      \
    \      merge(ys.begin() + ls[i * 2], ys.begin() + rs[i * 2],\n               \
    \   ys.begin() + ls[i * 2 + 1], ys.begin() + rs[i * 2 + 1],\n                \
    \  back_inserter(vs));\n            vs.erase(unique(vs.begin(), vs.end()), vs.end());\n\
    \            move(vs.begin(), vs.end(), back_inserter(ys));\n            rs[i]\
    \ = int(ys.size());\n            BITs[i] = BinaryIndexedTree<T>(rs[i] - ls[i]);\n\
    \        }\n    }\n\n    void add(S x, S y, T value) {\n        int k = lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n        assert(k < n && xs[k] == x);\n        k\
    \ += sz;\n        int l = get_y_index(y, k);\n        assert(l < rs[k] - ls[k]\
    \ && ys[ls[k] + l] == y);\n        BITs[k].add(l, value);\n        for (int i\
    \ = 1; i <= log; i++) {\n            int p = k >> i;\n            int l = get_y_index(y,\
    \ p);\n            assert(l < rs[p] - ls[p] && ys[ls[p] + l] == y);\n        \
    \    BITs[p].add(l, value);\n        }\n    }\n\n    T get(S xl, S xr, S yl, S\
    \ yr) const {\n        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n\
    \        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n       \
    \ l += sz;\n        r += sz;\n        T ret = 0;\n        while (l < r) {\n  \
    \          if (l & 1) {\n                int ll = get_y_index(yl, l);\n      \
    \          int rr = get_y_index(yr, l);\n                ret += BITs[l].sum(ll,\
    \ rr);\n                l++;\n            }\n            if (r & 1) {\n      \
    \          r--;\n                int ll = get_y_index(yl, r);\n              \
    \  int rr = get_y_index(yr, r);\n                ret += BITs[r].sum(ll, rr);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return ret;\n    }\n\n  private:\n    int get_y_index(S y, int x_index) const\
    \ {\n        return lower_bound(ys.begin() + ls[x_index], ys.begin() + rs[x_index],\n\
    \                           y) -\n               (ys.begin() + ls[x_index]);\n\
    \    }\n};"
  dependsOn:
  - datastructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: segmenttree/PointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2023-06-20 01:18:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmenttree/PointAddRectangleSum.test.cpp
documentation_of: segmenttree/PointAddRectangleSum.hpp
layout: document
redirect_from:
- /library/segmenttree/PointAddRectangleSum.hpp
- /library/segmenttree/PointAddRectangleSum.hpp.html
title: segmenttree/PointAddRectangleSum.hpp
---
