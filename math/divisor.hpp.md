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
  bundledCode: "#line 2 \"math/divisor.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\n// O(sqrt(n))\ntemplate <class T> std::vector<T> divisor(T\
    \ x) {\n    assert(x >= 1);\n    std::vector<T> ret;\n    for (T i = 1; i * i\
    \ <= x; i++) {\n        if (x % i == 0) {\n            ret.emplace_back(i);\n\
    \            ret.emplace_back(x / i);\n        }\n    }\n    std::sort(ret.begin(),\
    \ ret.end());\n    ret.erase(unique(ret.begin(), ret.end()), ret.end());\n   \
    \ return ret;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n// O(sqrt(n))\ntemplate <class T> std::vector<T> divisor(T x) {\n    assert(x\
    \ >= 1);\n    std::vector<T> ret;\n    for (T i = 1; i * i <= x; i++) {\n    \
    \    if (x % i == 0) {\n            ret.emplace_back(i);\n            ret.emplace_back(x\
    \ / i);\n        }\n    }\n    std::sort(ret.begin(), ret.end());\n    ret.erase(unique(ret.begin(),\
    \ ret.end()), ret.end());\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
redirect_from:
- /library/math/divisor.hpp
- /library/math/divisor.hpp.html
title: math/divisor.hpp
---
