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
  bundledCode: "#line 2 \"segmenttree/SegmentTreeInfo.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <bit>\n#include <vector>\n\nstruct SegmentTreeInfo\
    \ {\n    using uint = unsigned int;\n    int n, n_bit_ceil;\n\n    SegmentTreeInfo(int\
    \ n_) : n(n_), n_bit_ceil(std::bit_ceil((uint)n_)) {\n    }\n\n    int size()\
    \ const {\n        return n_bit_ceil * 2;\n    }\n\n    int node_index(int i)\
    \ const {\n        assert(0 <= i && i < n);\n        return i + n_bit_ceil;\n\
    \    }\n\n    std::pair<int, int> index_to_range(int node_index) const {\n   \
    \     assert(1 <= node_index && node_index < n_bit_ceil * 2);\n        int depth\
    \ = topbit(node_index);\n        int width = n_bit_ceil >> depth;\n        return\
    \ {node_index - (1 << depth), node_index + width - (1 << depth)};\n    }\n\n \
    \   std::vector<int> split_range(int l, int r) const {\n        assert(0 <= l\
    \ && l < r && r <= n);\n        l += n_bit_ceil;\n        r += n_bit_ceil;\n\n\
    \        std::vector<int> L, R;\n        while (l < r) {\n            if (l &\
    \ 1) L.push_back(l++);\n            if (r & 1) R.push_back(--r);\n           \
    \ l >>= 1;\n            r >>= 1;\n        }\n        L.reserve(L.size() + R.size());\n\
    \        std::move(R.rbegin(), R.rend(), std::back_inserter(L));\n        return\
    \ L;\n    }\n\n    std::vector<int> coverings(int i) const {\n        assert(0\
    \ <= i && i < n);\n        i += n_bit_ceil;\n        std::vector<int> coverings;\n\
    \        coverings.reserve(topbit(i) + 1);\n        while (i > 0) {\n        \
    \    coverings.push_back(i);\n            i >>= 1;\n        }\n        return\
    \ coverings;\n    }\n\n  private:\n    int topbit(int x) const {\n        return\
    \ 31 - std::countl_zero((uint)x);\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <bit>\n\
    #include <vector>\n\nstruct SegmentTreeInfo {\n    using uint = unsigned int;\n\
    \    int n, n_bit_ceil;\n\n    SegmentTreeInfo(int n_) : n(n_), n_bit_ceil(std::bit_ceil((uint)n_))\
    \ {\n    }\n\n    int size() const {\n        return n_bit_ceil * 2;\n    }\n\n\
    \    int node_index(int i) const {\n        assert(0 <= i && i < n);\n       \
    \ return i + n_bit_ceil;\n    }\n\n    std::pair<int, int> index_to_range(int\
    \ node_index) const {\n        assert(1 <= node_index && node_index < n_bit_ceil\
    \ * 2);\n        int depth = topbit(node_index);\n        int width = n_bit_ceil\
    \ >> depth;\n        return {node_index - (1 << depth), node_index + width - (1\
    \ << depth)};\n    }\n\n    std::vector<int> split_range(int l, int r) const {\n\
    \        assert(0 <= l && l < r && r <= n);\n        l += n_bit_ceil;\n      \
    \  r += n_bit_ceil;\n\n        std::vector<int> L, R;\n        while (l < r) {\n\
    \            if (l & 1) L.push_back(l++);\n            if (r & 1) R.push_back(--r);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        L.reserve(L.size()\
    \ + R.size());\n        std::move(R.rbegin(), R.rend(), std::back_inserter(L));\n\
    \        return L;\n    }\n\n    std::vector<int> coverings(int i) const {\n \
    \       assert(0 <= i && i < n);\n        i += n_bit_ceil;\n        std::vector<int>\
    \ coverings;\n        coverings.reserve(topbit(i) + 1);\n        while (i > 0)\
    \ {\n            coverings.push_back(i);\n            i >>= 1;\n        }\n  \
    \      return coverings;\n    }\n\n  private:\n    int topbit(int x) const {\n\
    \        return 31 - std::countl_zero((uint)x);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/SegmentTreeInfo.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segmenttree/SegmentTreeInfo.hpp
layout: document
redirect_from:
- /library/segmenttree/SegmentTreeInfo.hpp
- /library/segmenttree/SegmentTreeInfo.hpp.html
title: segmenttree/SegmentTreeInfo.hpp
---
