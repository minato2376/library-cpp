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
  bundledCode: "#line 2 \"algorithm/longest_common_subsequence.hpp\"\n\n#include <string>\n\
    #include <vector>\n#include <algorithm>\n\nint longest_common_subsequence(const\
    \ std::string& s, const std::string t) {\n    int n = int(s.size()), m = int(t.size());\n\
    \    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));\n    for\
    \ (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n         \
    \   if (s[i] == t[j]) {\n                dp[i + 1][j + 1] = dp[i][j] + 1;\n  \
    \          } else {\n                dp[i + 1][j + 1] = std::max(dp[i + 1][j],\
    \ dp[i][j + 1]);\n            }\n        }\n    }\n    return dp[n][m];\n}\n\n\
    template <class T>\nint longest_common_subsequence(const std::vector<T>& s,\n\
    \                               const std::vector<T> t) {\n    int n = int(s.size()),\
    \ m = int(t.size());\n    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m\
    \ + 1));\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++)\
    \ {\n            if (s[i] == t[j]) {\n                dp[i + 1][j + 1] = dp[i][j]\
    \ + 1;\n            } else {\n                dp[i + 1][j + 1] = std::max(dp[i\
    \ + 1][j], dp[i][j + 1]);\n            }\n        }\n    }\n    return dp[n][m];\n\
    }\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n#include <algorithm>\n\
    \nint longest_common_subsequence(const std::string& s, const std::string t) {\n\
    \    int n = int(s.size()), m = int(t.size());\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1));\n    for (int i = 0; i < n; i++) {\n   \
    \     for (int j = 0; j < m; j++) {\n            if (s[i] == t[j]) {\n       \
    \         dp[i + 1][j + 1] = dp[i][j] + 1;\n            } else {\n           \
    \     dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);\n            }\n\
    \        }\n    }\n    return dp[n][m];\n}\n\ntemplate <class T>\nint longest_common_subsequence(const\
    \ std::vector<T>& s,\n                               const std::vector<T> t) {\n\
    \    int n = int(s.size()), m = int(t.size());\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1));\n    for (int i = 0; i < n; i++) {\n   \
    \     for (int j = 0; j < m; j++) {\n            if (s[i] == t[j]) {\n       \
    \         dp[i + 1][j + 1] = dp[i][j] + 1;\n            } else {\n           \
    \     dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);\n            }\n\
    \        }\n    }\n    return dp[n][m];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/longest_common_subsequence.hpp
  requiredBy: []
  timestamp: '2023-06-26 01:08:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/longest_common_subsequence.hpp
layout: document
redirect_from:
- /library/algorithm/longest_common_subsequence.hpp
- /library/algorithm/longest_common_subsequence.hpp.html
title: algorithm/longest_common_subsequence.hpp
---
