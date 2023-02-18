---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: datastructure/BinaryIndexedTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/RangeAddRangeSum.test.cpp
    title: test/segmenttree/RangeAddRangeSum.test.cpp
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
    \ os;\n    }\n#endif\n};\n#line 2 \"segmenttree/RangeAddRangeSum.hpp\"\n\ntemplate\
    \ <typename T> struct RangeAddRangeSum {\n    int n;\n    BinaryIndexedTree<T>\
    \ a, b;\n    RangeAddRangeSum() {\n    }\n    RangeAddRangeSum(int n) : n(n),\
    \ a(n + 1), b(n + 1) {\n    }\n\n    int size() const {\n        return n;\n \
    \   }\n\n    // add x to [l, r)\n    void add(int l, int r, T x) {\n        if\
    \ (l >= r) return;\n        a.add(l, x);\n        a.add(r, -x);\n        b.add(l,\
    \ x * (1 - l));\n        b.add(r, x * (r - 1));\n    }\n\n    T sum(int i) const\
    \ {\n        return a.sum(i) * (i - 1) + b.sum(i);\n    }\n\n    // return sum\
    \ of [l, r)\n    T sum(int l, int r) const {\n        return sum(r) - sum(l);\n\
    \    }\n};\n"
  code: "#include \"datastructure/BinaryIndexedTree.hpp\"\n\ntemplate <typename T>\
    \ struct RangeAddRangeSum {\n    int n;\n    BinaryIndexedTree<T> a, b;\n    RangeAddRangeSum()\
    \ {\n    }\n    RangeAddRangeSum(int n) : n(n), a(n + 1), b(n + 1) {\n    }\n\n\
    \    int size() const {\n        return n;\n    }\n\n    // add x to [l, r)\n\
    \    void add(int l, int r, T x) {\n        if (l >= r) return;\n        a.add(l,\
    \ x);\n        a.add(r, -x);\n        b.add(l, x * (1 - l));\n        b.add(r,\
    \ x * (r - 1));\n    }\n\n    T sum(int i) const {\n        return a.sum(i) *\
    \ (i - 1) + b.sum(i);\n    }\n\n    // return sum of [l, r)\n    T sum(int l,\
    \ int r) const {\n        return sum(r) - sum(l);\n    }\n};"
  dependsOn:
  - datastructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: segmenttree/RangeAddRangeSum.hpp
  requiredBy: []
  timestamp: '2023-02-18 14:52:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmenttree/RangeAddRangeSum.test.cpp
documentation_of: segmenttree/RangeAddRangeSum.hpp
layout: document
redirect_from:
- /library/segmenttree/RangeAddRangeSum.hpp
- /library/segmenttree/RangeAddRangeSum.hpp.html
title: segmenttree/RangeAddRangeSum.hpp
---
