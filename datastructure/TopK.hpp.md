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
    \ <array>\n#include <cassert>\n#include <utility>\n#include <vector>\n\ntemplate\
    \ <class Key,\n          class T,\n          int K,\n          T (*op)(T, T),\n\
    \          bool (*comp)(std::pair<Key, T>, std::pair<Key, T>),\n          std::pair<Key,\
    \ T> (*e)()>\nstruct TopK {\n    using P = std::pair<Key, T>;\n    std::array<P,\
    \ K> data;\n\n    TopK() {\n        std::fill(data.begin(), data.end(), e());\n\
    \    }\n    TopK(std::vector<P> v) {\n        std::fill(data.begin(), data.end(),\
    \ e());\n        for (int i = 0; i < int(v.size()); i++) {\n            data[i]\
    \ = v[i];\n        }\n    }\n\n    void push(P x) {\n        std::array<P, K +\
    \ 1> buf = {};\n        for (int i = 0; i < K; i++) {\n            if (comp(x,\
    \ data[i])) {\n                swap(x, data[i]);\n            }\n        }\n \
    \   }\n\n    const S& operator[](int i) const {\n        assert(0 <= i && i <\
    \ K);\n        return data[i];\n    }\n\n    void merge(const TopK& rhs) {\n \
    \       std::array<S, K> new_data;\n        int l = 0, r = 0;\n        for (int\
    \ i = 0; i < K; i++) {\n            if (comp(data[l], rhs[r])) {\n           \
    \     new_data[i] = data[l++];\n            } else {\n                new_data[i]\
    \ = rhs[r++];\n            }\n        }\n        data = new_data;\n    }\n\n#ifdef\
    \ MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, TopK r) {\n      \
    \  os << r.data;\n        return os;\n    }\n#endif\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\ntemplate <class Key,\n          class\
    \ T,\n          int K,\n          T (*op)(T, T),\n          bool (*comp)(std::pair<Key,\
    \ T>, std::pair<Key, T>),\n          std::pair<Key, T> (*e)()>\nstruct TopK {\n\
    \    using P = std::pair<Key, T>;\n    std::array<P, K> data;\n\n    TopK() {\n\
    \        std::fill(data.begin(), data.end(), e());\n    }\n    TopK(std::vector<P>\
    \ v) {\n        std::fill(data.begin(), data.end(), e());\n        for (int i\
    \ = 0; i < int(v.size()); i++) {\n            data[i] = v[i];\n        }\n   \
    \ }\n\n    void push(P x) {\n        std::array<P, K + 1> buf = {};\n        for\
    \ (int i = 0; i < K; i++) {\n            if (comp(x, data[i])) {\n           \
    \     swap(x, data[i]);\n            }\n        }\n    }\n\n    const S& operator[](int\
    \ i) const {\n        assert(0 <= i && i < K);\n        return data[i];\n    }\n\
    \n    void merge(const TopK& rhs) {\n        std::array<S, K> new_data;\n    \
    \    int l = 0, r = 0;\n        for (int i = 0; i < K; i++) {\n            if\
    \ (comp(data[l], rhs[r])) {\n                new_data[i] = data[l++];\n      \
    \      } else {\n                new_data[i] = rhs[r++];\n            }\n    \
    \    }\n        data = new_data;\n    }\n\n#ifdef MINATO_LOCAL\n    friend ostream&\
    \ operator<<(ostream& os, TopK r) {\n        os << r.data;\n        return os;\n\
    \    }\n#endif\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/TopK.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/TopK.hpp
layout: document
redirect_from:
- /library/datastructure/TopK.hpp
- /library/datastructure/TopK.hpp.html
title: datastructure/TopK.hpp
---
