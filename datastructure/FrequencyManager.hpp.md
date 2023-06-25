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
  bundledCode: "#line 2 \"datastructure/FrequencyManager.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nstruct FrequencyManager {\n    int n;\n    std::vector<int>\
    \ freq;\n    int distinct_count;\n\n    FrequencyManager() : n(0), distinct_count(0)\
    \ {\n    }\n    FrequencyManager(int n) : n(n), freq(n), distinct_count(0) {\n\
    \    }\n\n    int size() const {\n        return n;\n    }\n\n    /**\n     *\
    \ O(1)\n     */\n    int get_distinct_count() const {\n        return distinct_count;\n\
    \    }\n\n    /**\n     * O(1)\n     */\n    void add(int x) {\n        assert(0\
    \ <= x && x < n);\n        if (freq[x] == 0) distinct_count++;\n        freq[x]++;\n\
    \    }\n\n    /**\n     * O(1)\n     */\n    void erase(int x) {\n        assert(0\
    \ <= x && x < n);\n        assert(freq[x] > 0);\n        freq[x]--;\n        if\
    \ (freq[x] == 0) distinct_count--;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nstruct FrequencyManager\
    \ {\n    int n;\n    std::vector<int> freq;\n    int distinct_count;\n\n    FrequencyManager()\
    \ : n(0), distinct_count(0) {\n    }\n    FrequencyManager(int n) : n(n), freq(n),\
    \ distinct_count(0) {\n    }\n\n    int size() const {\n        return n;\n  \
    \  }\n\n    /**\n     * O(1)\n     */\n    int get_distinct_count() const {\n\
    \        return distinct_count;\n    }\n\n    /**\n     * O(1)\n     */\n    void\
    \ add(int x) {\n        assert(0 <= x && x < n);\n        if (freq[x] == 0) distinct_count++;\n\
    \        freq[x]++;\n    }\n\n    /**\n     * O(1)\n     */\n    void erase(int\
    \ x) {\n        assert(0 <= x && x < n);\n        assert(freq[x] > 0);\n     \
    \   freq[x]--;\n        if (freq[x] == 0) distinct_count--;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/FrequencyManager.hpp
  requiredBy: []
  timestamp: '2023-06-26 01:08:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/FrequencyManager.hpp
layout: document
redirect_from:
- /library/datastructure/FrequencyManager.hpp
- /library/datastructure/FrequencyManager.hpp.html
title: datastructure/FrequencyManager.hpp
---
