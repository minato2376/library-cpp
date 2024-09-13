---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/DualSegmentTree.test.cpp
    title: test/segmenttree/DualSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/DualSegmentTree2.test.cpp
    title: test/segmenttree/DualSegmentTree2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segmenttree/DualSegmentTree.hpp\"\ntemplate <class T, class\
    \ U, class G, class H> struct DualSegmentTree {\n  private:\n    G mapping;\n\
    \    H composition;\n    U id;\n    int _n, size_, log;\n    vector<T> node;\n\
    \    vector<U> lazy;\n\n  public:\n    DualSegmentTree() {\n    }\n    DualSegmentTree(const\
    \ G& mapping,\n                    const H& composition,\n                   \
    \ U id,\n                    const vector<T>& v)\n        : mapping(mapping),\n\
    \          composition(composition),\n          id(id),\n          _n(int(v.size())),\n\
    \          log(0) {\n        while ((1 << log) < _n) log++;\n        size_ = 1\
    \ << log;\n        node.resize(size_);\n        for (int i = 0; i < _n; i++) node[i]\
    \ = v[i];\n        lazy = vector<U>(size_, id);\n    }\n\n    int size() const\
    \ {\n        return _n;\n    }\n\n    void set(int p, T x) {\n        assert(0\
    \ <= p && p < _n);\n        p += size_;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        node[p - size_] = x;\n    }\n\n    void apply(int p,\
    \ U val) {\n        assert(0 <= p && p < _n);\n        p += size_;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        node[p - size_] =\n      \
    \      val == id ? node[p - size_] : mapping(node[p - size_], val);\n    }\n\n\
    \    void apply(int l, int r, U val) {\n        if (l >= r) return;\n\n      \
    \  l += size_;\n        r += size_;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int\
    \ l2 = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ val);\n                if (r & 1) all_apply(--r, val);\n                l >>=\
    \ 1;\n                r >>= 1;\n            }\n            l = l2;\n         \
    \   r = r2;\n        }\n    }\n\n    T operator[](int p) {\n        assert(0 <=\
    \ p && p < _n);\n        p += size_;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return node[p - size_];\n    }\n\n#ifdef MINATO_LOCAL\n    friend\
    \ ostream& operator<<(ostream& os, DualSegmentTree r) {\n        vector<T> v(r.size());\n\
    \        for (int i = 0; i < r.size(); i++) {\n            v[i] = r[i];\n    \
    \    }\n        os << v;\n        return os;\n    }\n#endif\n\n  private:\n  \
    \  void all_apply(int k, U val) {\n        if (k >= size_)\n            node[k\
    \ - size_] =\n                val == id ? node[k - size_] : mapping(node[k - size_],\
    \ val);\n        else\n            lazy[k] = composition(lazy[k], val);\n    }\n\
    \n    void push(int k) {\n        if (lazy[k] == id) return;\n        all_apply(2\
    \ * k, lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n        lazy[k] = id;\n\
    \    }\n};\n"
  code: "template <class T, class U, class G, class H> struct DualSegmentTree {\n\
    \  private:\n    G mapping;\n    H composition;\n    U id;\n    int _n, size_,\
    \ log;\n    vector<T> node;\n    vector<U> lazy;\n\n  public:\n    DualSegmentTree()\
    \ {\n    }\n    DualSegmentTree(const G& mapping,\n                    const H&\
    \ composition,\n                    U id,\n                    const vector<T>&\
    \ v)\n        : mapping(mapping),\n          composition(composition),\n     \
    \     id(id),\n          _n(int(v.size())),\n          log(0) {\n        while\
    \ ((1 << log) < _n) log++;\n        size_ = 1 << log;\n        node.resize(size_);\n\
    \        for (int i = 0; i < _n; i++) node[i] = v[i];\n        lazy = vector<U>(size_,\
    \ id);\n    }\n\n    int size() const {\n        return _n;\n    }\n\n    void\
    \ set(int p, T x) {\n        assert(0 <= p && p < _n);\n        p += size_;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        node[p - size_]\
    \ = x;\n    }\n\n    void apply(int p, U val) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size_;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        node[p - size_] =\n            val == id ? node[p - size_] : mapping(node[p\
    \ - size_], val);\n    }\n\n    void apply(int l, int r, U val) {\n        if\
    \ (l >= r) return;\n\n        l += size_;\n        r += size_;\n\n        for\
    \ (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >>\
    \ i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n\
    \        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n   \
    \             if (l & 1) all_apply(l++, val);\n                if (r & 1) all_apply(--r,\
    \ val);\n                l >>= 1;\n                r >>= 1;\n            }\n \
    \           l = l2;\n            r = r2;\n        }\n    }\n\n    T operator[](int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += size_;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return node[p - size_];\n    }\n\
    \n#ifdef MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, DualSegmentTree\
    \ r) {\n        vector<T> v(r.size());\n        for (int i = 0; i < r.size();\
    \ i++) {\n            v[i] = r[i];\n        }\n        os << v;\n        return\
    \ os;\n    }\n#endif\n\n  private:\n    void all_apply(int k, U val) {\n     \
    \   if (k >= size_)\n            node[k - size_] =\n                val == id\
    \ ? node[k - size_] : mapping(node[k - size_], val);\n        else\n         \
    \   lazy[k] = composition(lazy[k], val);\n    }\n\n    void push(int k) {\n  \
    \      if (lazy[k] == id) return;\n        all_apply(2 * k, lazy[k]);\n      \
    \  all_apply(2 * k + 1, lazy[k]);\n        lazy[k] = id;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-02-18 20:47:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmenttree/DualSegmentTree2.test.cpp
  - test/segmenttree/DualSegmentTree.test.cpp
documentation_of: segmenttree/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/segmenttree/DualSegmentTree.hpp
- /library/segmenttree/DualSegmentTree.hpp.html
title: segmenttree/DualSegmentTree.hpp
---
