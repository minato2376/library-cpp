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
  bundledCode: "#line 2 \"segmenttree/SegmentTree.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <class T, class F> struct SegmentTree {\n  private:\n \
    \   F op;\n    T e;\n    int _n, size_, log;\n    std::vector<T> node;\n\n  public:\n\
    \    SegmentTree() {\n    }\n    SegmentTree(const F& op, T e, int n)\n      \
    \  : SegmentTree(op, e, std::vector<T>(n, e)) {\n    }\n    SegmentTree(const\
    \ F& op, T e, const std::vector<T>& v)\n        : op(op), e(e), _n(int(v.size())),\
    \ log(0) {\n        while ((1 << log) < _n) log++;\n        size_ = 1 << log;\n\
    \        node = std::vector<T>(2 * size_, e);\n        for (int i = 0; i < _n;\
    \ i++) node[size_ + i] = v[i];\n        for (int i = size_ - 1; i >= 1; i--) {\n\
    \            update(i);\n        }\n    }\n\n    int size() const {\n        return\
    \ _n;\n    }\n\n    // (0-indexed)\n    void set(int p, T x) {\n        assert(0\
    \ <= p && p < _n);\n        p += size_;\n        node[p] = x;\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n\n    // [l, r) (0-indexed)\n\
    \    T get(int l, int r) {\n        if (l >= r) return e;\n        T resl = e,\
    \ resr = e;\n        l += size_;\n        r += size_;\n        while (l < r) {\n\
    \            if (l & 1) resl = op(resl, node[l++]);\n            l >>= 1;\n  \
    \          if (r & 1) resr = op(node[--r], resr);\n            r >>= 1;\n    \
    \    }\n        return op(resl, resr);\n    }\n\n    T all_get() {\n        return\
    \ node[1];\n    }\n\n    template <class C> int max_right(int l, const C& check)\
    \ {\n        assert(0 <= l && l <= _n);\n        assert(check(e));\n        if\
    \ (l == _n) return _n;\n        l += size_;\n        T sm = e;\n        do {\n\
    \            while (~l & 1) l >>= 1;\n            if (!check(op(sm, node[l])))\
    \ {\n                while (l < size_) {\n                    l = (2 * l);\n \
    \                   if (check(op(sm, node[l]))) {\n                        sm\
    \ = op(sm, node[l]);\n                        l++;\n                    }\n  \
    \              }\n                return l - size_;\n            }\n         \
    \   sm = op(sm, node[l]);\n            l++;\n        } while ((l & -l) != l);\n\
    \        return _n;\n    }\n\n    template <class C> int min_left(int r, const\
    \ C& check) {\n        assert(0 <= r && r <= _n);\n        assert(check(e));\n\
    \        if (r == 0) return 0;\n        r += size_;\n        T sm = e;\n     \
    \   do {\n            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n  \
    \          if (!check(op(node[r], sm))) {\n                while (r < size_) {\n\
    \                    r = (2 * r + 1);\n                    if (check(op(node[r],\
    \ sm))) {\n                        sm = op(node[r], sm);\n                   \
    \     r--;\n                    }\n                }\n                return r\
    \ + 1 - size_;\n            }\n            sm = op(node[r], sm);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n\n    T operator[](int p) {\n  \
    \      assert(0 <= p && p < _n);\n        return node[p + size_];\n    }\n\n#ifdef\
    \ MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, SegmentTree r) {\n\
    \        std::vector<T> v(r.size());\n        for (int i = 0; i < r.size(); i++)\
    \ {\n            v[i] = r[i];\n        }\n        os << v;\n        return os;\n\
    \    }\n#endif\n\n  private:\n    void update(int k) {\n        node[k] = op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n};\n\ntemplate <typename T> auto buildPointSetRangeMin(int\
    \ n, T e) {\n    auto f = [](T a, T b) { return min(a, b); };\n    SegmentTree\
    \ seg(f, e, n);\n    return seg;\n}\n\ntemplate <typename T> auto buildPointSetRangeMin(const\
    \ std::vector<T>& v, T e) {\n    auto f = [](T a, T b) { return min(a, b); };\n\
    \    SegmentTree seg(f, e, v);\n    return seg;\n}\n\ntemplate <typename T> auto\
    \ buildPointSetRangeMax(int n, T e) {\n    auto f = [](T a, T b) { return max(a,\
    \ b); };\n    SegmentTree seg(f, e, n);\n    return seg;\n}\n\ntemplate <typename\
    \ T> auto buildPointSetRangeMax(const std::vector<T>& v, T e) {\n    auto f =\
    \ [](T a, T b) { return max(a, b); };\n    SegmentTree seg(f, e, v);\n    return\
    \ seg;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <class\
    \ T, class F> struct SegmentTree {\n  private:\n    F op;\n    T e;\n    int _n,\
    \ size_, log;\n    std::vector<T> node;\n\n  public:\n    SegmentTree() {\n  \
    \  }\n    SegmentTree(const F& op, T e, int n)\n        : SegmentTree(op, e, std::vector<T>(n,\
    \ e)) {\n    }\n    SegmentTree(const F& op, T e, const std::vector<T>& v)\n \
    \       : op(op), e(e), _n(int(v.size())), log(0) {\n        while ((1 << log)\
    \ < _n) log++;\n        size_ = 1 << log;\n        node = std::vector<T>(2 * size_,\
    \ e);\n        for (int i = 0; i < _n; i++) node[size_ + i] = v[i];\n        for\
    \ (int i = size_ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    int size() const {\n        return _n;\n    }\n\n    // (0-indexed)\n  \
    \  void set(int p, T x) {\n        assert(0 <= p && p < _n);\n        p += size_;\n\
    \        node[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    // [l, r) (0-indexed)\n    T get(int l, int r) {\n        if (l\
    \ >= r) return e;\n        T resl = e, resr = e;\n        l += size_;\n      \
    \  r += size_;\n        while (l < r) {\n            if (l & 1) resl = op(resl,\
    \ node[l++]);\n            l >>= 1;\n            if (r & 1) resr = op(node[--r],\
    \ resr);\n            r >>= 1;\n        }\n        return op(resl, resr);\n  \
    \  }\n\n    T all_get() {\n        return node[1];\n    }\n\n    template <class\
    \ C> int max_right(int l, const C& check) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(check(e));\n        if (l == _n) return _n;\n        l += size_;\n\
    \        T sm = e;\n        do {\n            while (~l & 1) l >>= 1;\n      \
    \      if (!check(op(sm, node[l]))) {\n                while (l < size_) {\n \
    \                   l = (2 * l);\n                    if (check(op(sm, node[l])))\
    \ {\n                        sm = op(sm, node[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - size_;\n\
    \            }\n            sm = op(sm, node[l]);\n            l++;\n        }\
    \ while ((l & -l) != l);\n        return _n;\n    }\n\n    template <class C>\
    \ int min_left(int r, const C& check) {\n        assert(0 <= r && r <= _n);\n\
    \        assert(check(e));\n        if (r == 0) return 0;\n        r += size_;\n\
    \        T sm = e;\n        do {\n            r--;\n            while (r > 1 &&\
    \ (r & 1)) r >>= 1;\n            if (!check(op(node[r], sm))) {\n            \
    \    while (r < size_) {\n                    r = (2 * r + 1);\n             \
    \       if (check(op(node[r], sm))) {\n                        sm = op(node[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size_;\n            }\n            sm = op(node[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n    T operator[](int\
    \ p) {\n        assert(0 <= p && p < _n);\n        return node[p + size_];\n \
    \   }\n\n#ifdef MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, SegmentTree\
    \ r) {\n        std::vector<T> v(r.size());\n        for (int i = 0; i < r.size();\
    \ i++) {\n            v[i] = r[i];\n        }\n        os << v;\n        return\
    \ os;\n    }\n#endif\n\n  private:\n    void update(int k) {\n        node[k]\
    \ = op(node[2 * k], node[2 * k + 1]);\n    }\n};\n\ntemplate <typename T> auto\
    \ buildPointSetRangeMin(int n, T e) {\n    auto f = [](T a, T b) { return min(a,\
    \ b); };\n    SegmentTree seg(f, e, n);\n    return seg;\n}\n\ntemplate <typename\
    \ T> auto buildPointSetRangeMin(const std::vector<T>& v, T e) {\n    auto f =\
    \ [](T a, T b) { return min(a, b); };\n    SegmentTree seg(f, e, v);\n    return\
    \ seg;\n}\n\ntemplate <typename T> auto buildPointSetRangeMax(int n, T e) {\n\
    \    auto f = [](T a, T b) { return max(a, b); };\n    SegmentTree seg(f, e, n);\n\
    \    return seg;\n}\n\ntemplate <typename T> auto buildPointSetRangeMax(const\
    \ std::vector<T>& v, T e) {\n    auto f = [](T a, T b) { return max(a, b); };\n\
    \    SegmentTree seg(f, e, v);\n    return seg;\n}"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/SegmentTree.hpp
  requiredBy: []
  timestamp: '2023-06-20 01:18:34+09:00'
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
