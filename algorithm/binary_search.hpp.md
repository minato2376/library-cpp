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
  bundledCode: "#line 2 \"algorithm/binary_search.hpp\"\n\n#include <cassert>\n#include\
    \ <cmath>\n\nnamespace minato {\n/**\n * f(T x) -> bool\n * f(ok) = true f(ng)\
    \ = false\n */\ntemplate <class T, class F> T binary_search(T ok, T ng, const\
    \ F& f) {\n    assert(ok != ng);\n    while (std::abs(ok - ng) > 1) {\n      \
    \  T mid = (ok + ng) / 2;\n        (f(mid) ? ok : ng) = mid;\n    }\n    return\
    \ ok;\n}\n}  // namespace minato\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cmath>\n\nnamespace minato\
    \ {\n/**\n * f(T x) -> bool\n * f(ok) = true f(ng) = false\n */\ntemplate <class\
    \ T, class F> T binary_search(T ok, T ng, const F& f) {\n    assert(ok != ng);\n\
    \    while (std::abs(ok - ng) > 1) {\n        T mid = (ok + ng) / 2;\n       \
    \ (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n}  // namespace minato\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/binary_search.hpp
  requiredBy: []
  timestamp: '2023-06-26 01:08:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/binary_search.hpp
layout: document
redirect_from:
- /library/algorithm/binary_search.hpp
- /library/algorithm/binary_search.hpp.html
title: algorithm/binary_search.hpp
---
