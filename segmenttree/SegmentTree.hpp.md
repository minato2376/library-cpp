---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/SegmentTree.test.cpp
    title: test/segmenttree/SegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segmenttree/SegmentTree.hpp\"\n\ntemplate <class T, class\
    \ F> struct SegmentTree {\n  private:\n    F op;\n    T e;\n    int _n, size,\
    \ log;\n    vector<T> node;\n\n  public:\n    SegmentTree() {\n    }\n    SegmentTree(const\
    \ F& op, T e, int n) : SegmentTree(op, e, vector<T>(n, e)) {\n    }\n    SegmentTree(const\
    \ F& op, T e, const vector<T>& v)\n        : op(op), e(e), _n(int(v.size())),\
    \ log(0) {\n        while ((1 << log) < _n) log++;\n        size = 1 << log;\n\
    \        node = vector<T>(2 * size, e);\n        for (int i = 0; i < _n; i++)\
    \ node[size + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n    \
    \        update(i);\n        }\n    }\n\n    // (0-indexed)\n    void set(int\
    \ p, T x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        node[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    //\
    \ [l, r) (0-indexed)\n    T get(int l, int r) {\n        if (l >= r) return e;\n\
    \        T resl = e, resr = e;\n        l += size;\n        r += size;\n     \
    \   while (l < r) {\n            if (l & 1) resl = op(resl, node[l++]);\n    \
    \        l >>= 1;\n            if (r & 1) resr = op(node[--r], resr);\n      \
    \      r >>= 1;\n        }\n        return op(resl, resr);\n    }\n\n    T all_get()\
    \ {\n        return node[1];\n    }\n\n    template <class C> int max_right(int\
    \ l, const C& check) {\n        assert(0 <= l && l <= _n);\n        assert(check(e));\n\
    \        if (l == _n) return _n;\n        l += size;\n        T sm = e;\n    \
    \    do {\n            while (~l & 1) l >>= 1;\n            if (!check(op(sm,\
    \ node[l]))) {\n                while (l < size) {\n                    l = (2\
    \ * l);\n                    if (check(op(sm, node[l]))) {\n                 \
    \       sm = op(sm, node[l]);\n                        l++;\n                \
    \    }\n                }\n                return l - size;\n            }\n \
    \           sm = op(sm, node[l]);\n            l++;\n        } while ((l & -l)\
    \ != l);\n        return _n;\n    }\n\n    template <class C> int min_left(int\
    \ r, const C& check) {\n        assert(0 <= r && r <= _n);\n        assert(check(e));\n\
    \        if (r == 0) return 0;\n        r += size;\n        T sm = e;\n      \
    \  do {\n            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n   \
    \         if (!check(op(node[r], sm))) {\n                while (r < size) {\n\
    \                    r = (2 * r + 1);\n                    if (check(op(node[r],\
    \ sm))) {\n                        sm = op(node[r], sm);\n                   \
    \     r--;\n                    }\n                }\n                return r\
    \ + 1 - size;\n            }\n            sm = op(node[r], sm);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n\n    T operator[](int p) {\n  \
    \      assert(0 <= p && p < _n);\n        return node[p + size];\n    }\n\n  private:\n\
    \    void update(int k) {\n        node[k] = op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n};\n\ntemplate <typename T, T INF> auto buildPointSetRangeMin(int n) {\n\
    \    return buildPointSetRangeMin(vector<T>(n, INF));\n}\n\ntemplate <typename\
    \ T, T INF> auto buildPointSetRangeMin(const vector<T>& v) {\n    auto f = [](T\
    \ a, T b) { return min(a, b); };\n    SegmentTree seg(f, INF, v);\n    return\
    \ seg;\n}\n"
  code: "#pragma once\n\ntemplate <class T, class F> struct SegmentTree {\n  private:\n\
    \    F op;\n    T e;\n    int _n, size, log;\n    vector<T> node;\n\n  public:\n\
    \    SegmentTree() {\n    }\n    SegmentTree(const F& op, T e, int n) : SegmentTree(op,\
    \ e, vector<T>(n, e)) {\n    }\n    SegmentTree(const F& op, T e, const vector<T>&\
    \ v)\n        : op(op), e(e), _n(int(v.size())), log(0) {\n        while ((1 <<\
    \ log) < _n) log++;\n        size = 1 << log;\n        node = vector<T>(2 * size,\
    \ e);\n        for (int i = 0; i < _n; i++) node[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    // (0-indexed)\n    void set(int p, T x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        node[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n\n    // [l, r) (0-indexed)\n    T get(int\
    \ l, int r) {\n        if (l >= r) return e;\n        T resl = e, resr = e;\n\
    \        l += size;\n        r += size;\n        while (l < r) {\n           \
    \ if (l & 1) resl = op(resl, node[l++]);\n            l >>= 1;\n            if\
    \ (r & 1) resr = op(node[--r], resr);\n            r >>= 1;\n        }\n     \
    \   return op(resl, resr);\n    }\n\n    T all_get() {\n        return node[1];\n\
    \    }\n\n    template <class C> int max_right(int l, const C& check) {\n    \
    \    assert(0 <= l && l <= _n);\n        assert(check(e));\n        if (l == _n)\
    \ return _n;\n        l += size;\n        T sm = e;\n        do {\n          \
    \  while (~l & 1) l >>= 1;\n            if (!check(op(sm, node[l]))) {\n     \
    \           while (l < size) {\n                    l = (2 * l);\n           \
    \         if (check(op(sm, node[l]))) {\n                        sm = op(sm, node[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, node[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    template <class C> int min_left(int r, const C& check) {\n        assert(0\
    \ <= r && r <= _n);\n        assert(check(e));\n        if (r == 0) return 0;\n\
    \        r += size;\n        T sm = e;\n        do {\n            r--;\n     \
    \       while (r > 1 && (r & 1)) r >>= 1;\n            if (!check(op(node[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (check(op(node[r], sm))) {\n                 \
    \       sm = op(node[r], sm);\n                        r--;\n                \
    \    }\n                }\n                return r + 1 - size;\n            }\n\
    \            sm = op(node[r], sm);\n        } while ((r & -r) != r);\n       \
    \ return 0;\n    }\n\n    T operator[](int p) {\n        assert(0 <= p && p <\
    \ _n);\n        return node[p + size];\n    }\n\n  private:\n    void update(int\
    \ k) {\n        node[k] = op(node[2 * k], node[2 * k + 1]);\n    }\n};\n\ntemplate\
    \ <typename T, T INF> auto buildPointSetRangeMin(int n) {\n    return buildPointSetRangeMin(vector<T>(n,\
    \ INF));\n}\n\ntemplate <typename T, T INF> auto buildPointSetRangeMin(const vector<T>&\
    \ v) {\n    auto f = [](T a, T b) { return min(a, b); };\n    SegmentTree seg(f,\
    \ INF, v);\n    return seg;\n}"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-02-18 02:25:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmenttree/SegmentTree.test.cpp
documentation_of: segmenttree/SegmentTree.hpp
layout: document
redirect_from:
- /library/segmenttree/SegmentTree.hpp
- /library/segmenttree/SegmentTree.hpp.html
title: segmenttree/SegmentTree.hpp
---
