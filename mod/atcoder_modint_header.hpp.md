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
  bundledCode: "#line 2 \"mod/atcoder_modint_header.hpp\"\n\n#include <istream>\n\
    #include <ostream>\n\n#include <atcoder/modint>\n\ntemplate <int M>\nstd::istream&\
    \ operator>>(std::istream& is, atcoder::static_modint<M>& m) {\n    long long\
    \ x;\n    is >> x;\n    m = x;\n    return is;\n}\ntemplate <int M>\nstd::ostream&\
    \ operator<<(std::ostream& os, const atcoder::static_modint<M>& m) {\n    return\
    \ os << m.val();\n}\n"
  code: "#pragma once\n\n#include <istream>\n#include <ostream>\n\n#include <atcoder/modint>\n\
    \ntemplate <int M>\nstd::istream& operator>>(std::istream& is, atcoder::static_modint<M>&\
    \ m) {\n    long long x;\n    is >> x;\n    m = x;\n    return is;\n}\ntemplate\
    \ <int M>\nstd::ostream& operator<<(std::ostream& os, const atcoder::static_modint<M>&\
    \ m) {\n    return os << m.val();\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/atcoder_modint_header.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/atcoder_modint_header.hpp
layout: document
redirect_from:
- /library/mod/atcoder_modint_header.hpp
- /library/mod/atcoder_modint_header.hpp.html
title: mod/atcoder_modint_header.hpp
---
