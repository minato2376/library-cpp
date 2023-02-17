---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/LazySegmentTree.test.cpp
    title: test/segmenttree/LazySegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segmenttree/LazySegmentTree.hpp\"\ntemplate <class T, class\
    \ U, class F, class G, class H> struct LazySegmentTree {\n  private:\n    F op;\n\
    \    G mapping;\n    H composition;\n    T e;\n    U id;\n    int _n, size, log;\n\
    \    vector<T> node;\n    vector<U> lazy;\n\n  public:\n    LazySegmentTree()\
    \ {\n    }\n    LazySegmentTree(const F& op,\n                    const G& mapping,\n\
    \                    const H& composition,\n                    T e,\n       \
    \             U id,\n                    int n)\n        : LazySegmentTree(op,\
    \ mapping, composition, e, id, vector<T>(n, e)) {\n    }\n    LazySegmentTree(const\
    \ F& op,\n                    const G& mapping,\n                    const H&\
    \ composition,\n                    T e,\n                    U id,\n        \
    \            const vector<T>& v)\n        : op(op),\n          mapping(mapping),\n\
    \          composition(composition),\n          e(e),\n          id(id),\n   \
    \       _n(int(v.size())),\n          log(0) {\n        while ((1 << log) < _n)\
    \ log++;\n        size = 1 << log;\n        node = vector<T>(2 * size, e);\n \
    \       lazy = vector<U>(size, id);\n        for (int i = 0; i < _n; i++) node[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, T x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        node[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    // [l, r) (0-indexed)\n    T get(int l, int r) {\n        if (l\
    \ >= r) return e;\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push(r >> i);\n        }\n\n        T sml\
    \ = e, smr = e;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ node[l++]);\n            if (r & 1) smr = op(node[--r], smr);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n  \
    \  }\n\n    T all_get() const {\n        return node[1];\n    }\n\n    void apply(int\
    \ p, U val) {\n        assert(0 <= p && p < _n);\n        p += size;\n       \
    \ for (int i = log; i >= 1; i--) push(p >> i);\n        node[p] = val == id ?\
    \ node[p] : mapping(node[p], val);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    void apply(int l, int r, U val) {\n        if (l >= r)\
    \ return;\n\n        l += size;\n        r += size;\n\n        for (int i = log;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n\
    \            int l2 = l, r2 = r;\n            while (l < r) {\n              \
    \  if (l & 1) all_apply(l++, val);\n                if (r & 1) all_apply(--r,\
    \ val);\n                l >>= 1;\n                r >>= 1;\n            }\n \
    \           l = l2;\n            r = r2;\n        }\n\n        for (int i = 1;\
    \ i <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n  \
    \          if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \n    template <typename C> int max_right(int l, const C& check) {\n        assert(0\
    \ <= l && l <= _n);\n        assert(check(e));\n        if (l == _n) return _n;\n\
    \        l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n  \
    \      T sm = e;\n        do {\n            while (~l & 1) l >>= 1;\n        \
    \    if (!check(op(sm, node[l]))) {\n                while (l < size) {\n    \
    \                push(l);\n                    l = (2 * l);\n                \
    \    if (check(op(sm, node[l]))) {\n                        sm = op(sm, node[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, node[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \n    template <typename C> int min_left(int r, const C& check) {\n        assert(0\
    \ <= r && r <= _n);\n        assert(check(e));\n        if (r == 0) return 0;\n\
    \        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        T sm = e;\n        do {\n            r--;\n            while (r > 1 &&\
    \ (r & 1)) r >>= 1;\n            if (!check(op(node[r], sm))) {\n            \
    \    while (r < size) {\n                    push(r);\n                    r =\
    \ (2 * r + 1);\n                    if (check(op(node[r], sm))) {\n          \
    \              sm = op(node[r], sm);\n                        r--;\n         \
    \           }\n                }\n                return r + 1 - size;\n     \
    \       }\n            sm = op(node[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n    T operator[](int p) {\n        assert(0 <= p\
    \ && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return node[p];\n    }\n\n  private:\n    void update(int k)\
    \ {\n        node[k] = op(node[2 * k], node[2 * k + 1]);\n    }\n\n    void all_apply(int\
    \ k, U val) {\n        node[k] = val == id ? node[k] : mapping(node[k], val);\n\
    \        if (k < size) lazy[k] = composition(lazy[k], val);\n    }\n\n    void\
    \ push(int k) {\n        if (lazy[k] == id) return;\n        all_apply(2 * k,\
    \ lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n        lazy[k] = id;\n \
    \   }\n};\n\ntemplate <typename T, T INF> auto buildRangeSetRangeMin(int n) {\n\
    \    return buildRangeSetRangeMin(vector<T>(n, INF));\n}\n\ntemplate <typename\
    \ T, T INF> auto buildRangeSetRangeMin(const vector<T>& v) {\n    auto f = [](T\
    \ a, T b) { return min(a, b); };\n    auto g = [](T a, T b) {\n        (void)a;\n\
    \        return b;\n    };\n    auto h = [](T a, T b) {\n        (void)a;\n  \
    \      return b;\n    };\n    LazySegmentTree seg(f, g, h, INF, INF, v);\n   \
    \ return seg;\n}\n"
  code: "template <class T, class U, class F, class G, class H> struct LazySegmentTree\
    \ {\n  private:\n    F op;\n    G mapping;\n    H composition;\n    T e;\n   \
    \ U id;\n    int _n, size, log;\n    vector<T> node;\n    vector<U> lazy;\n\n\
    \  public:\n    LazySegmentTree() {\n    }\n    LazySegmentTree(const F& op,\n\
    \                    const G& mapping,\n                    const H& composition,\n\
    \                    T e,\n                    U id,\n                    int\
    \ n)\n        : LazySegmentTree(op, mapping, composition, e, id, vector<T>(n,\
    \ e)) {\n    }\n    LazySegmentTree(const F& op,\n                    const G&\
    \ mapping,\n                    const H& composition,\n                    T e,\n\
    \                    U id,\n                    const vector<T>& v)\n        :\
    \ op(op),\n          mapping(mapping),\n          composition(composition),\n\
    \          e(e),\n          id(id),\n          _n(int(v.size())),\n          log(0)\
    \ {\n        while ((1 << log) < _n) log++;\n        size = 1 << log;\n      \
    \  node = vector<T>(2 * size, e);\n        lazy = vector<U>(size, id);\n     \
    \   for (int i = 0; i < _n; i++) node[size + i] = v[i];\n        for (int i =\
    \ size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void\
    \ set(int p, T x) {\n        assert(0 <= p && p < _n);\n        p += size;\n \
    \       for (int i = log; i >= 1; i--) push(p >> i);\n        node[p] = x;\n \
    \       for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    // [l, r)\
    \ (0-indexed)\n    T get(int l, int r) {\n        if (l >= r) return e;\n\n  \
    \      l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push(r >> i);\n        }\n\n        T sml = e, smr = e;\n\
    \        while (l < r) {\n            if (l & 1) sml = op(sml, node[l++]);\n \
    \           if (r & 1) smr = op(node[--r], smr);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    T all_get()\
    \ const {\n        return node[1];\n    }\n\n    void apply(int p, U val) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        node[p] = val == id ? node[p] : mapping(node[p],\
    \ val);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n   \
    \ void apply(int l, int r, U val) {\n        if (l >= r) return;\n\n        l\
    \ += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--) {\n \
    \           if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int l2\
    \ = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ val);\n                if (r & 1) all_apply(--r, val);\n                l >>=\
    \ 1;\n                r >>= 1;\n            }\n            l = l2;\n         \
    \   r = r2;\n        }\n\n        for (int i = 1; i <= log; i++) {\n         \
    \   if (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i)\
    \ != r) update((r - 1) >> i);\n        }\n    }\n\n    template <typename C> int\
    \ max_right(int l, const C& check) {\n        assert(0 <= l && l <= _n);\n   \
    \     assert(check(e));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        T sm = e;\n   \
    \     do {\n            while (~l & 1) l >>= 1;\n            if (!check(op(sm,\
    \ node[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (check(op(sm, node[l])))\
    \ {\n                        sm = op(sm, node[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, node[l]);\n            l++;\n        }\
    \ while ((l & -l) != l);\n        return _n;\n    }\n\n    template <typename\
    \ C> int min_left(int r, const C& check) {\n        assert(0 <= r && r <= _n);\n\
    \        assert(check(e));\n        if (r == 0) return 0;\n        r += size;\n\
    \        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        T sm = e;\n\
    \        do {\n            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n\
    \            if (!check(op(node[r], sm))) {\n                while (r < size)\
    \ {\n                    push(r);\n                    r = (2 * r + 1);\n    \
    \                if (check(op(node[r], sm))) {\n                        sm = op(node[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(node[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n    T operator[](int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return node[p];\n    }\n\n  private:\n\
    \    void update(int k) {\n        node[k] = op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n\n    void all_apply(int k, U val) {\n        node[k] = val == id ? node[k]\
    \ : mapping(node[k], val);\n        if (k < size) lazy[k] = composition(lazy[k],\
    \ val);\n    }\n\n    void push(int k) {\n        if (lazy[k] == id) return;\n\
    \        all_apply(2 * k, lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n\
    \        lazy[k] = id;\n    }\n};\n\ntemplate <typename T, T INF> auto buildRangeSetRangeMin(int\
    \ n) {\n    return buildRangeSetRangeMin(vector<T>(n, INF));\n}\n\ntemplate <typename\
    \ T, T INF> auto buildRangeSetRangeMin(const vector<T>& v) {\n    auto f = [](T\
    \ a, T b) { return min(a, b); };\n    auto g = [](T a, T b) {\n        (void)a;\n\
    \        return b;\n    };\n    auto h = [](T a, T b) {\n        (void)a;\n  \
    \      return b;\n    };\n    LazySegmentTree seg(f, g, h, INF, INF, v);\n   \
    \ return seg;\n}"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2023-02-18 04:05:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmenttree/LazySegmentTree.test.cpp
documentation_of: segmenttree/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/segmenttree/LazySegmentTree.hpp
- /library/segmenttree/LazySegmentTree.hpp.html
title: segmenttree/LazySegmentTree.hpp
---
