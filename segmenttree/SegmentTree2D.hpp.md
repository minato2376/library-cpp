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
  bundledCode: "#line 2 \"segmenttree/SegmentTree2D.hpp\"\n\n#include <bit>\n#include\
    \ <atcoder/segtree>\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SegmentTree2D\
    \ {\n    int n, m, size, log;\n    std::vector<atcoder::segtree<S, op, e>> d;\n\
    \n    SegmentTree2D() {\n    }\n    SegmentTree2D(int n_, int m_)\n        : SegmentTree2D(\n\
    \              std::vector<std::vector<S>>(n_, std::vector<S>(m_, e()))) {\n \
    \   }\n    SegmentTree2D(const std::vector<std::vector<S>>& v)\n        : n(int(v.size())),\
    \ m(int(v[0].size())) {\n        size = std::bit_ceil((unsigned int)n);\n    \
    \    log = std::bit_width((unsigned int)size) - 1;\n        d.resize(2 * size);\n\
    \        for (int i = 0; i < n; i++)\n            d[size + i] = atcoder::segtree<S,\
    \ op, e>(v[i]);\n        for (int i = n; i < size; i++) {\n            d[size\
    \ + i] = atcoder::segtree<S, op, e>(m);\n        }\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            std::vector<S> tmp(m);\n            for (int\
    \ j = 0; j < m; j++) {\n                tmp[j] = op(d[i << 1 | 0].get(j), d[i\
    \ << 1 | 1].get(j));\n            }\n            d[i] = atcoder::segtree<S, op,\
    \ e>(tmp);\n        }\n    }\n\n    void set(int p, int q, S x) {\n        assert(0\
    \ <= p && p < n);\n        assert(0 <= q && q < m);\n        p += size;\n    \
    \    d[p].set(q, x);\n        for (int i = 1; i <= log; i++) {\n            int\
    \ x = p >> i;\n            d[x].set(q, op(d[x << 1 | 0].get(q), d[x << 1 | 1].get(q)));\n\
    \        }\n    }\n\n    S get(int p, int q) const {\n        assert(0 <= p &&\
    \ p < n);\n        assert(0 <= q && q < m);\n        return d[p + size].get(q);\n\
    \    }\n\n    S prod(int hl, int hr, int wl, int wr) const {\n        assert(0\
    \ <= hl && hl <= hr && hr <= n);\n        assert(0 <= wl && wl <= wr && wr <=\
    \ m);\n        S sml = e(), smr = e();\n        hl += size;\n        hr += size;\n\
    \        while (hl < hr) {\n            if (hl & 1) sml = op(sml, d[hl++].prod(wl,\
    \ wr));\n            if (hr & 1) smr = op(d[--hr].prod(wl, wr), smr);\n      \
    \      hl >>= 1;\n            hr >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() const {\n        return d[1].all_prod();\n    }\n};\n"
  code: "#pragma once\n\n#include <bit>\n#include <atcoder/segtree>\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct SegmentTree2D {\n    int n, m, size, log;\n\
    \    std::vector<atcoder::segtree<S, op, e>> d;\n\n    SegmentTree2D() {\n   \
    \ }\n    SegmentTree2D(int n_, int m_)\n        : SegmentTree2D(\n           \
    \   std::vector<std::vector<S>>(n_, std::vector<S>(m_, e()))) {\n    }\n    SegmentTree2D(const\
    \ std::vector<std::vector<S>>& v)\n        : n(int(v.size())), m(int(v[0].size()))\
    \ {\n        size = std::bit_ceil((unsigned int)n);\n        log = std::bit_width((unsigned\
    \ int)size) - 1;\n        d.resize(2 * size);\n        for (int i = 0; i < n;\
    \ i++)\n            d[size + i] = atcoder::segtree<S, op, e>(v[i]);\n        for\
    \ (int i = n; i < size; i++) {\n            d[size + i] = atcoder::segtree<S,\
    \ op, e>(m);\n        }\n        for (int i = size - 1; i >= 1; i--) {\n     \
    \       std::vector<S> tmp(m);\n            for (int j = 0; j < m; j++) {\n  \
    \              tmp[j] = op(d[i << 1 | 0].get(j), d[i << 1 | 1].get(j));\n    \
    \        }\n            d[i] = atcoder::segtree<S, op, e>(tmp);\n        }\n \
    \   }\n\n    void set(int p, int q, S x) {\n        assert(0 <= p && p < n);\n\
    \        assert(0 <= q && q < m);\n        p += size;\n        d[p].set(q, x);\n\
    \        for (int i = 1; i <= log; i++) {\n            int x = p >> i;\n     \
    \       d[x].set(q, op(d[x << 1 | 0].get(q), d[x << 1 | 1].get(q)));\n       \
    \ }\n    }\n\n    S get(int p, int q) const {\n        assert(0 <= p && p < n);\n\
    \        assert(0 <= q && q < m);\n        return d[p + size].get(q);\n    }\n\
    \n    S prod(int hl, int hr, int wl, int wr) const {\n        assert(0 <= hl &&\
    \ hl <= hr && hr <= n);\n        assert(0 <= wl && wl <= wr && wr <= m);\n   \
    \     S sml = e(), smr = e();\n        hl += size;\n        hr += size;\n    \
    \    while (hl < hr) {\n            if (hl & 1) sml = op(sml, d[hl++].prod(wl,\
    \ wr));\n            if (hr & 1) smr = op(d[--hr].prod(wl, wr), smr);\n      \
    \      hl >>= 1;\n            hr >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() const {\n        return d[1].all_prod();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segmenttree/SegmentTree2D.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segmenttree/SegmentTree2D.hpp
layout: document
redirect_from:
- /library/segmenttree/SegmentTree2D.hpp
- /library/segmenttree/SegmentTree2D.hpp.html
title: segmenttree/SegmentTree2D.hpp
---
