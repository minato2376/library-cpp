---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/generator/generate_random_sequence.test.cpp
    title: test/generator/generate_random_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"generator/generate_random_sequence.hpp\"\n/**\n * \u5024\
    \u304C lower \u4EE5\u4E0A upper \u672A\u6E80\u3067\u3042\u308B\u9577\u3055 n \u306E\
    \u6570\u5217\u3092\u5168\u3066\u751F\u6210\u3059\u308B\u3002\n * O(D**n * n)\n\
    \ */\ntemplate <typename T>\nvector<vector<T>> generate_random_sequence(int n,\
    \ T upper, T lower = 0) {\n    int D = upper - lower;\n    int size = 1;\n   \
    \ for (int i = 0; i < n; i++) size *= D;\n    vector<vector<T>> ret(size);\n \
    \   for (int k = 0; k < size; k++) {\n        vector<T> v(n);\n        int x =\
    \ k;\n        for (int i = 0; i < n; i++) {\n            v[i] = lower + x % D;\n\
    \            x /= D;\n        }\n        reverse(v.begin(), v.end());\n      \
    \  ret[k] = v;\n    }\n    return ret;\n}\n"
  code: "/**\n * \u5024\u304C lower \u4EE5\u4E0A upper \u672A\u6E80\u3067\u3042\u308B\
    \u9577\u3055 n \u306E\u6570\u5217\u3092\u5168\u3066\u751F\u6210\u3059\u308B\u3002\
    \n * O(D**n * n)\n */\ntemplate <typename T>\nvector<vector<T>> generate_random_sequence(int\
    \ n, T upper, T lower = 0) {\n    int D = upper - lower;\n    int size = 1;\n\
    \    for (int i = 0; i < n; i++) size *= D;\n    vector<vector<T>> ret(size);\n\
    \    for (int k = 0; k < size; k++) {\n        vector<T> v(n);\n        int x\
    \ = k;\n        for (int i = 0; i < n; i++) {\n            v[i] = lower + x %\
    \ D;\n            x /= D;\n        }\n        reverse(v.begin(), v.end());\n \
    \       ret[k] = v;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: generator/generate_random_sequence.hpp
  requiredBy: []
  timestamp: '2023-02-19 02:28:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/generator/generate_random_sequence.test.cpp
documentation_of: generator/generate_random_sequence.hpp
layout: document
redirect_from:
- /library/generator/generate_random_sequence.hpp
- /library/generator/generate_random_sequence.hpp.html
title: generator/generate_random_sequence.hpp
---
