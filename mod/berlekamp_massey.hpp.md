---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/kth_term.hpp
    title: mod/kth_term.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/berlekamp_massey.hpp\"\n\n#include <vector>\n\ntemplate\
    \ <class mint>\nstd::vector<mint> berlekamp_massey(const std::vector<mint>& s)\
    \ {\n    const int N = (int)s.size();\n    std::vector<mint> b, c;\n    b.reserve(N\
    \ + 1);\n    c.reserve(N + 1);\n    b.push_back(mint(1));\n    c.push_back(mint(1));\n\
    \    mint y = mint(1);\n    for (int ed = 1; ed <= N; ed++) {\n        int l =\
    \ int(c.size()), m = int(b.size());\n        mint x = 0;\n        for (int i =\
    \ 0; i < l; i++) x += c[i] * s[ed - l + i];\n        b.emplace_back(mint(0));\n\
    \        m++;\n        if (x == mint(0)) continue;\n        mint freq = x / y;\n\
    \        if (l < m) {\n            auto tmp = c;\n            c.insert(c.begin(),\
    \ m - l, mint(0));\n            for (int i = 0; i < m; i++) c[m - 1 - i] -= freq\
    \ * b[m - 1 - i];\n            b = tmp;\n            y = x;\n        } else {\n\
    \            for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n\
    \        }\n    }\n    reverse(c.begin(), c.end());\n    return c;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class mint>\nstd::vector<mint>\
    \ berlekamp_massey(const std::vector<mint>& s) {\n    const int N = (int)s.size();\n\
    \    std::vector<mint> b, c;\n    b.reserve(N + 1);\n    c.reserve(N + 1);\n \
    \   b.push_back(mint(1));\n    c.push_back(mint(1));\n    mint y = mint(1);\n\
    \    for (int ed = 1; ed <= N; ed++) {\n        int l = int(c.size()), m = int(b.size());\n\
    \        mint x = 0;\n        for (int i = 0; i < l; i++) x += c[i] * s[ed - l\
    \ + i];\n        b.emplace_back(mint(0));\n        m++;\n        if (x == mint(0))\
    \ continue;\n        mint freq = x / y;\n        if (l < m) {\n            auto\
    \ tmp = c;\n            c.insert(c.begin(), m - l, mint(0));\n            for\
    \ (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n            b\
    \ = tmp;\n            y = x;\n        } else {\n            for (int i = 0; i\
    \ < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n        }\n    }\n    reverse(c.begin(),\
    \ c.end());\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/berlekamp_massey.hpp
  requiredBy:
  - mod/kth_term.hpp
  timestamp: '2023-10-13 01:31:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/mod/berlekamp_massey.hpp
- /library/mod/berlekamp_massey.hpp.html
title: mod/berlekamp_massey.hpp
---
