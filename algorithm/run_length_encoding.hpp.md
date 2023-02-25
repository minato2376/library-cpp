---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/run_length_encoding.test.cpp
    title: test/algorithm/run_length_encoding.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/run_length_encoding.hpp\"\ntemplate <class T>\n\
    vector<pair<T, int>> run_length_encoding(const vector<T>& v) {\n    if (v.empty())\
    \ return {};\n    int cnt = 1;\n    vector<pair<T, int>> ret;\n    for (size_t\
    \ i = 1; i < v.size(); i++) {\n        if (v[i - 1] != v[i]) {\n            ret.emplace_back(v[i\
    \ - 1], cnt);\n            cnt = 1;\n        } else {\n            cnt++;\n  \
    \      }\n    }\n    ret.emplace_back(v.back(), cnt);\n    return ret;\n}\n\n\
    vector<pair<char, int>> run_length_encoding(const string& s) {\n    if (s.empty())\
    \ return {};\n    int cnt = 1;\n    vector<pair<char, int>> ret;\n    for (size_t\
    \ i = 1; i < s.size(); i++) {\n        if (s[i - 1] != s[i]) {\n            ret.emplace_back(s[i\
    \ - 1], cnt);\n            cnt = 1;\n        } else {\n            cnt++;\n  \
    \      }\n    }\n    ret.emplace_back(s.back(), cnt);\n    return ret;\n}\n"
  code: "template <class T>\nvector<pair<T, int>> run_length_encoding(const vector<T>&\
    \ v) {\n    if (v.empty()) return {};\n    int cnt = 1;\n    vector<pair<T, int>>\
    \ ret;\n    for (size_t i = 1; i < v.size(); i++) {\n        if (v[i - 1] != v[i])\
    \ {\n            ret.emplace_back(v[i - 1], cnt);\n            cnt = 1;\n    \
    \    } else {\n            cnt++;\n        }\n    }\n    ret.emplace_back(v.back(),\
    \ cnt);\n    return ret;\n}\n\nvector<pair<char, int>> run_length_encoding(const\
    \ string& s) {\n    if (s.empty()) return {};\n    int cnt = 1;\n    vector<pair<char,\
    \ int>> ret;\n    for (size_t i = 1; i < s.size(); i++) {\n        if (s[i - 1]\
    \ != s[i]) {\n            ret.emplace_back(s[i - 1], cnt);\n            cnt =\
    \ 1;\n        } else {\n            cnt++;\n        }\n    }\n    ret.emplace_back(s.back(),\
    \ cnt);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2023-02-26 03:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/run_length_encoding.test.cpp
documentation_of: algorithm/run_length_encoding.hpp
layout: document
redirect_from:
- /library/algorithm/run_length_encoding.hpp
- /library/algorithm/run_length_encoding.hpp.html
title: algorithm/run_length_encoding.hpp
---
