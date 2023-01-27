---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: datastructure/BinaryIndexedTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/inversion_number.test.cpp
    title: test/algorithm/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/BinaryIndexedTree.hpp\"\n\ntemplate <class\
    \ T> struct BinaryIndexedTree {\n  private:\n    int n;\n    vector<T> data;\n\
    \n    // [0,i) (0-indexed) a[0] + \u2026 + a[i-1]\n    T sum(int i) const {\n\
    \        T ret = 0;\n        for (; i > 0; i -= i & -i) ret += data[i];\n    \
    \    return ret;\n    }\n\n  public:\n    BinaryIndexedTree() {\n    }\n    BinaryIndexedTree(int\
    \ n) : n(n), data(n + 1, 0) {\n    }\n\n    int size() const {\n        return\
    \ n;\n    }\n\n    /**\n     * (0-indexed)\n     * a[i] += x\n     */\n    void\
    \ add(int i, T x) {\n        assert(0 <= i and i < n);\n        for (++i; i <=\
    \ n; i += i & -i) data[i] += x;\n    }\n\n    /**\n     * [l, r) (0-indexed)\n\
    \     * @return a[l] + \u2026\u3000+ a[r-1]\n     */\n    T sum(int l, int r)\
    \ const {\n        if (l >= r) return T(0);\n        assert(0 <= l and r <= n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    /**\n     * (0-indexed)\n     *\
    \ r = 0 or a[0] + a[1] + ... + a[r-1] < x\n     * r = n or a[0] + a[1] + ... +\
    \ a[r] >= x\n     * a[0] + a[1] + ... + a[r] >= x \u3068\u306A\u308B\u6700\u5C0F\
    \u306E r \u3092\u8FD4\u3059\u3002\n     */\n    int lower_bound(T x) const {\n\
    \        int k = 1;\n        int ret = 0;\n        while ((k << 1) <= n) k <<=\
    \ 1;\n        while (k > 0) {\n            if (ret + k <= n and data[ret + k]\
    \ < x) {\n                x -= data[ret + k];\n                ret += k;\n   \
    \         }\n            k >>= 1;\n        }\n        return ret;\n    }\n\n \
    \   int upper_bound(T x) const {\n        return lower_bound(x + 1);\n    }\n\
    };\n#line 3 \"algorithm/inversion_number.hpp\"\n\ntemplate <class T> long long\
    \ inversion_number(const vector<T>& v) {\n    int n = int(v.size());\n    vector<T>\
    \ com = v;\n    sort(com.begin(), com.end());\n    com.erase(unique(com.begin(),\
    \ com.end()), com.end());\n    int m = int(com.size());\n\n    BinaryIndexedTree<int>\
    \ BIT(m);\n    long long ret = 0;\n    for (int i = 0; i < n; i++) {\n       \
    \ int k = lower_bound(com.begin(), com.end(), v[i]) - com.begin();\n        ret\
    \ += BIT.sum(k + 1, m);\n        BIT.add(k, 1);\n    }\n\n    return ret;\n}\n"
  code: "#pragma once\n#include \"datastructure/BinaryIndexedTree.hpp\"\n\ntemplate\
    \ <class T> long long inversion_number(const vector<T>& v) {\n    int n = int(v.size());\n\
    \    vector<T> com = v;\n    sort(com.begin(), com.end());\n    com.erase(unique(com.begin(),\
    \ com.end()), com.end());\n    int m = int(com.size());\n\n    BinaryIndexedTree<int>\
    \ BIT(m);\n    long long ret = 0;\n    for (int i = 0; i < n; i++) {\n       \
    \ int k = lower_bound(com.begin(), com.end(), v[i]) - com.begin();\n        ret\
    \ += BIT.sum(k + 1, m);\n        BIT.add(k, 1);\n    }\n\n    return ret;\n}"
  dependsOn:
  - datastructure/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: algorithm/inversion_number.hpp
  requiredBy: []
  timestamp: '2023-01-27 11:21:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/inversion_number.test.cpp
documentation_of: algorithm/inversion_number.hpp
layout: document
redirect_from:
- /library/algorithm/inversion_number.hpp
- /library/algorithm/inversion_number.hpp.html
title: algorithm/inversion_number.hpp
---
