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
  bundledCode: "#line 2 \"string/manachar.hpp\"\n\n#include <string>\n#include <vector>\n\
    \nstd::vector<int> manachar(const std::string& s) {\n    int n = s.size();\n \
    \   std::vector<int> res(n);\n    for (int i = 0, j = 0; i < n;) {\n        while\
    \ (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;\n        res[i] = j;\n\
    \        int k = 1;\n        while (i - k >= 0 and i + k < n and k + res[i - k]\
    \ < j) {\n            res[i + k] = res[i - k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    return res;\n}\n\ntemplate <typename\
    \ T> std::vector<int> manachar(const std::vector<T>& s) {\n    int n = s.size();\n\
    \    std::vector<int> res(n);\n    for (int i = 0, j = 0;;) {\n        while (i\
    \ - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;\n        res[i] = j;\n\
    \        int k = 1;\n        while (i - k >= 0 and i + k < n and k + res[i - k]\
    \ < j) {\n            res[i + k] = res[i - k];\n            k++;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n\nstd::vector<int>\
    \ manachar(const std::string& s) {\n    int n = s.size();\n    std::vector<int>\
    \ res(n);\n    for (int i = 0, j = 0; i < n;) {\n        while (i - j >= 0 and\
    \ i + j < n and s[i - j] == s[i + j]) j++;\n        res[i] = j;\n        int k\
    \ = 1;\n        while (i - k >= 0 and i + k < n and k + res[i - k] < j) {\n  \
    \          res[i + k] = res[i - k];\n            k++;\n        }\n        i +=\
    \ k;\n        j -= k;\n    }\n    return res;\n}\n\ntemplate <typename T> std::vector<int>\
    \ manachar(const std::vector<T>& s) {\n    int n = s.size();\n    std::vector<int>\
    \ res(n);\n    for (int i = 0, j = 0;;) {\n        while (i - j >= 0 and i + j\
    \ < n and s[i - j] == s[i + j]) j++;\n        res[i] = j;\n        int k = 1;\n\
    \        while (i - k >= 0 and i + k < n and k + res[i - k] < j) {\n         \
    \   res[i + k] = res[i - k];\n            k++;\n        }\n        i += k;\n \
    \       j -= k;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manachar.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manachar.hpp
layout: document
redirect_from:
- /library/string/manachar.hpp
- /library/string/manachar.hpp.html
title: string/manachar.hpp
---
