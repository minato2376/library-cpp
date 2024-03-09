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
  bundledCode: "#line 2 \"datastructure/TopK.hpp\"\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\n\ntemplate <class S, int K,\
    \ bool (*comp)(S, S), S (*e)()> struct TopK {\n    std::array<S, K> data;\n\n\
    \    TopK() {\n        std::fill(data.begin(), data.end(), e());\n    }\n    TopK(std::vector<S>\
    \ v) {\n        assert(int(v.size()) <= K);\n        std::fill(data.begin(), data.end(),\
    \ e());\n        for (int i = 0; i < int(v.size()); i++) {\n            data[i]\
    \ = v[i];\n        }\n    }\n\n    void push(S x) {\n        for (int i = 0; i\
    \ < K; i++) {\n            if (comp(x, data[i])) {\n                swap(x, data[i]);\n\
    \            }\n        }\n    }\n\n    const S& operator[](int i) const {\n \
    \       assert(0 <= i && i < K);\n        return data[i];\n    }\n\n    void merge(const\
    \ TopK& rhs) {\n        std::array<S, K> new_data;\n        int l = 0, r = 0;\n\
    \        for (int i = 0; i < K; i++) {\n            if (comp(data[l], rhs[r]))\
    \ {\n                new_data[i] = data[l++];\n            } else {\n        \
    \        new_data[i] = rhs[r++];\n            }\n        }\n        data = new_data;\n\
    \    }\n\n#ifdef MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, TopK\
    \ r) {\n        os << r.data;\n        return os;\n    }\n#endif\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class S, int K, bool (*comp)(S, S), S (*e)()> struct\
    \ TopK {\n    std::array<S, K> data;\n\n    TopK() {\n        std::fill(data.begin(),\
    \ data.end(), e());\n    }\n    TopK(std::vector<S> v) {\n        assert(int(v.size())\
    \ <= K);\n        std::fill(data.begin(), data.end(), e());\n        for (int\
    \ i = 0; i < int(v.size()); i++) {\n            data[i] = v[i];\n        }\n \
    \   }\n\n    void push(S x) {\n        for (int i = 0; i < K; i++) {\n       \
    \     if (comp(x, data[i])) {\n                swap(x, data[i]);\n           \
    \ }\n        }\n    }\n\n    const S& operator[](int i) const {\n        assert(0\
    \ <= i && i < K);\n        return data[i];\n    }\n\n    void merge(const TopK&\
    \ rhs) {\n        std::array<S, K> new_data;\n        int l = 0, r = 0;\n    \
    \    for (int i = 0; i < K; i++) {\n            if (comp(data[l], rhs[r])) {\n\
    \                new_data[i] = data[l++];\n            } else {\n            \
    \    new_data[i] = rhs[r++];\n            }\n        }\n        data = new_data;\n\
    \    }\n\n#ifdef MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, TopK\
    \ r) {\n        os << r.data;\n        return os;\n    }\n#endif\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/TopK.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/TopK.hpp
layout: document
redirect_from:
- /library/datastructure/TopK.hpp
- /library/datastructure/TopK.hpp.html
title: datastructure/TopK.hpp
---