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
  bundledCode: "#line 2 \"math/TwoSat.hpp\"\n#include <atcoder/twosat>\n\nstruct TwoSat\
    \ : public atcoder::two_sat {\n    TwoSat() : two_sat() {\n    }\n    TwoSat(int\
    \ n) : two_sat(n) {\n    }\n\n    /**\n     * x => y\n     */\n    void add_if(int\
    \ x, int y) {\n        add_clause(y, true, x, false);\n    }\n\n    void set_true(int\
    \ x) {\n        add_clause(x, true, x, true);\n    }\n\n    void set_false(int\
    \ x) {\n        add_clause(x, false, x, false);\n    }\n};\n"
  code: "#pragma once\n#include <atcoder/twosat>\n\nstruct TwoSat : public atcoder::two_sat\
    \ {\n    TwoSat() : two_sat() {\n    }\n    TwoSat(int n) : two_sat(n) {\n   \
    \ }\n\n    /**\n     * x => y\n     */\n    void add_if(int x, int y) {\n    \
    \    add_clause(y, true, x, false);\n    }\n\n    void set_true(int x) {\n   \
    \     add_clause(x, true, x, true);\n    }\n\n    void set_false(int x) {\n  \
    \      add_clause(x, false, x, false);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/TwoSat.hpp
  requiredBy: []
  timestamp: '2023-01-27 12:58:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/TwoSat.hpp
layout: document
redirect_from:
- /library/math/TwoSat.hpp
- /library/math/TwoSat.hpp.html
title: math/TwoSat.hpp
---
