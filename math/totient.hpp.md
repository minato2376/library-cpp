---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/totient.test.cpp
    title: test/math/totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/totient.hpp\"\n/**\n * n \u3068\u4E92\u3044\u306B\u7D20\
    \u306A\u6574\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\u3002\n * O(sqrt(N))\n\
    \ */\ntemplate <typename Int> Int totient(Int n) {\n    assert(n >= 1);\n    Int\
    \ ret = n;\n    for (Int i = 2; i * i <= n; i++) {\n        if (n % i == 0) {\n\
    \            ret = ret / i * (i - 1);\n            while (n % i == 0) n /= i;\n\
    \        }\n    }\n    if (n != 1) ret = ret / n * (n - 1);\n    return ret;\n\
    }\n"
  code: "/**\n * n \u3068\u4E92\u3044\u306B\u7D20\u306A\u6574\u6570\u306E\u500B\u6570\
    \u3092\u6C42\u3081\u308B\u3002\n * O(sqrt(N))\n */\ntemplate <typename Int> Int\
    \ totient(Int n) {\n    assert(n >= 1);\n    Int ret = n;\n    for (Int i = 2;\
    \ i * i <= n; i++) {\n        if (n % i == 0) {\n            ret = ret / i * (i\
    \ - 1);\n            while (n % i == 0) n /= i;\n        }\n    }\n    if (n !=\
    \ 1) ret = ret / n * (n - 1);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/totient.hpp
  requiredBy: []
  timestamp: '2023-01-31 15:10:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/totient.test.cpp
documentation_of: math/totient.hpp
layout: document
redirect_from:
- /library/math/totient.hpp
- /library/math/totient.hpp.html
title: math/totient.hpp
---
