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
  bundledCode: "#line 2 \"algorithm/longest_increasing_subsequence.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n\ntemplate <typename T, bool STRICT = false>\n\
    int longest_increasing_subsequence(const std::vector<T>& a) {\n    std::vector<T>\
    \ dp;\n    dp.reserve(a.size());\n    for (const auto& x : a) {\n        auto\
    \ it = STRICT ? std::upper_bound(dp.begin(), dp.end(), x)\n                  \
    \       : std::lower_bound(dp.begin(), dp.end(), x);\n        if (it == dp.end())\
    \ {\n            dp.push_back(x);\n        } else {\n            *it = x;\n  \
    \      }\n    }\n    return dp.size();\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\ntemplate <typename\
    \ T, bool STRICT = false>\nint longest_increasing_subsequence(const std::vector<T>&\
    \ a) {\n    std::vector<T> dp;\n    dp.reserve(a.size());\n    for (const auto&\
    \ x : a) {\n        auto it = STRICT ? std::upper_bound(dp.begin(), dp.end(),\
    \ x)\n                         : std::lower_bound(dp.begin(), dp.end(), x);\n\
    \        if (it == dp.end()) {\n            dp.push_back(x);\n        } else {\n\
    \            *it = x;\n        }\n    }\n    return dp.size();\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/algorithm/longest_increasing_subsequence.hpp
- /library/algorithm/longest_increasing_subsequence.hpp.html
title: algorithm/longest_increasing_subsequence.hpp
---
