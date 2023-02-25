---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/TwoSat.test.cpp
    title: test/math/TwoSat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/TwoSat.hpp\"\n#include <atcoder/twosat>\n\nstruct TwoSat\
    \ : atcoder::two_sat {\n    TwoSat() : two_sat() {\n    }\n    TwoSat(int n) :\
    \ two_sat(n) {\n    }\n\n    /**\n     * x => y\n     */\n    void add_if(int\
    \ x, int y) {\n        add_clause(x, false, y, true);\n    }\n\n    /**\n    \
    \ * x \u304B\u3064 y \u304C\u507D\n     */\n    void add_nand(int x, int y) {\n\
    \        add_clause(x, false, y, false);\n    }\n\n    void set_true(int x) {\n\
    \        add_clause(x, true, x, true);\n    }\n\n    void set_false(int x) {\n\
    \        add_clause(x, false, x, false);\n    }\n};\n"
  code: "#pragma once\n#include <atcoder/twosat>\n\nstruct TwoSat : atcoder::two_sat\
    \ {\n    TwoSat() : two_sat() {\n    }\n    TwoSat(int n) : two_sat(n) {\n   \
    \ }\n\n    /**\n     * x => y\n     */\n    void add_if(int x, int y) {\n    \
    \    add_clause(x, false, y, true);\n    }\n\n    /**\n     * x \u304B\u3064 y\
    \ \u304C\u507D\n     */\n    void add_nand(int x, int y) {\n        add_clause(x,\
    \ false, y, false);\n    }\n\n    void set_true(int x) {\n        add_clause(x,\
    \ true, x, true);\n    }\n\n    void set_false(int x) {\n        add_clause(x,\
    \ false, x, false);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/TwoSat.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:14:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/TwoSat.test.cpp
documentation_of: math/TwoSat.hpp
layout: document
redirect_from:
- /library/math/TwoSat.hpp
- /library/math/TwoSat.hpp.html
title: math/TwoSat.hpp
---
