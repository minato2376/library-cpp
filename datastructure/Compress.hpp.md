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
  bundledCode: "#line 2 \"datastructure/Compress.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\ntemplate <class T> struct Compress {\n  public:\n    Compress()\
    \ {\n    }\n    Compress(const std::vector<T>& vs) {\n        add(vs);\n    }\n\
    \n    void add(const std::vector<T>& vs) {\n        std::copy(vs.begin(), vs.end(),\
    \ back_inserter(xs));\n    }\n    void add(const T& x) {\n        xs.emplace_back(x);\n\
    \    }\n\n    int build() {\n        std::sort(xs.begin(), xs.end());\n      \
    \  xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n        return int(xs.size());\n\
    \    }\n\n    int size() const {\n        return int(xs.size());\n    }\n\n  \
    \  std::vector<int> get(const std::vector<T>& vs) const {\n        std::vector<int>\
    \ ret;\n        ret.reserve(vs.size());\n        std::transform(\n           \
    \ vs.begin(), vs.end(), back_inserter(ret), [&](const T& e) {\n              \
    \  return std::lower_bound(xs.begin(), xs.end(), e) - xs.begin();\n          \
    \  });\n        return ret;\n    }\n\n    int get(const T& x) const {\n      \
    \  return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n \
    \   const T& operator[](int k) const {\n        return xs[k];\n    }\n\n  private:\n\
    \    std::vector<T> xs;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <class\
    \ T> struct Compress {\n  public:\n    Compress() {\n    }\n    Compress(const\
    \ std::vector<T>& vs) {\n        add(vs);\n    }\n\n    void add(const std::vector<T>&\
    \ vs) {\n        std::copy(vs.begin(), vs.end(), back_inserter(xs));\n    }\n\
    \    void add(const T& x) {\n        xs.emplace_back(x);\n    }\n\n    int build()\
    \ {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        return int(xs.size());\n    }\n\n    int size()\
    \ const {\n        return int(xs.size());\n    }\n\n    std::vector<int> get(const\
    \ std::vector<T>& vs) const {\n        std::vector<int> ret;\n        ret.reserve(vs.size());\n\
    \        std::transform(\n            vs.begin(), vs.end(), back_inserter(ret),\
    \ [&](const T& e) {\n                return std::lower_bound(xs.begin(), xs.end(),\
    \ e) - xs.begin();\n            });\n        return ret;\n    }\n\n    int get(const\
    \ T& x) const {\n        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \    }\n\n    const T& operator[](int k) const {\n        return xs[k];\n    }\n\
    \n  private:\n    std::vector<T> xs;\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/Compress.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/Compress.hpp
layout: document
redirect_from:
- /library/datastructure/Compress.hpp
- /library/datastructure/Compress.hpp.html
title: datastructure/Compress.hpp
---
