---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/SquareRootDecomposion.test.cpp
    title: test/algorithm/SquareRootDecomposion.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3092\u5206\u5272\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"algorithm/SquareRootDecomposition.hpp\"\n\ntemplate <int\
    \ W> struct SquareRootDecomposition {\n    struct Ranges {\n        optional<pair<int,\
    \ int>> left_overflow_range;\n        optional<pair<int, int>> bucket_range;\n\
    \        optional<pair<int, int>> right_overflow_range;\n        Ranges()\n  \
    \          : left_overflow_range(nullopt),\n              bucket_range(nullopt),\n\
    \              right_overflow_range(nullopt) {\n        }\n    };\n\n    int n;\n\
    \n    SquareRootDecomposition() {\n    }\n    SquareRootDecomposition(int n) :\
    \ n(n) {\n    }\n\n    int bucket_size() const {\n        return (n + W - 1) /\
    \ W;\n    }\n\n    /**\n     * @brief \u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3092\
    \u5206\u5272\u3059\u308B\n     * @param l \u5DE6\u7AEF\n     * @param r \u53F3\
    \u7AEF\n     * @return \u5206\u5272\u3055\u308C\u305F\u7BC4\u56F2\n     * @note\
    \ [l, r) \u306E\u7BC4\u56F2\u3092\u5206\u5272\u3059\u308B\n     */\n    Ranges\
    \ query(int l, int r) const {\n        assert(0 <= l && l < r && r <= n);\n  \
    \      Ranges ret;\n        int l_bucket_id = bucket_id(l);\n        int r_bucket_id\
    \ = bucket_id(r - 1);\n        auto [l_bucket_l, l_bucket_r] = bucket_range(l_bucket_id);\n\
    \        auto [r_bucket_l, r_bucket_r] = bucket_range(r_bucket_id);\n        if\
    \ (l_bucket_id == r_bucket_id) {\n            if (l == l_bucket_l && r == r_bucket_r)\
    \ {\n                ret.bucket_range = {l_bucket_id, l_bucket_id + 1};\n    \
    \        } else {\n                ret.left_overflow_range = {l, r};\n       \
    \     }\n        } else {\n            if (l_bucket_id + 1 < r_bucket_id) {\n\
    \                ret.bucket_range = {l_bucket_id + 1, r_bucket_id};\n        \
    \    }\n            if (l == l_bucket_l) {\n                if (ret.bucket_range)\
    \ {\n                    ret.bucket_range->first--;\n                } else {\n\
    \                    ret.bucket_range = {l_bucket_id, l_bucket_id + 1};\n    \
    \            }\n            } else {\n                ret.left_overflow_range\
    \ = {l, l_bucket_r};\n            }\n            if (r == r_bucket_r) {\n    \
    \            if (ret.bucket_range) {\n                    ret.bucket_range->second++;\n\
    \                } else {\n                    ret.bucket_range = {r_bucket_id,\
    \ r_bucket_id + 1};\n                }\n            } else {\n               \
    \ ret.right_overflow_range = {r_bucket_l, r};\n            }\n        }\n    \
    \    return ret;\n    }\n\n    /**\n     * @brief \u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u304C\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\u3092\u8FD4\u3059\n   \
    \  * @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return \u30D0\u30B1\
    \u30C3\u30C8\u306E\u756A\u53F7\n     * @note [0, n) \u306E\u7BC4\u56F2\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9 i \u304C\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\
    \u306E\u756A\u53F7\u3092\u8FD4\u3059\n     */\n    int bucket_id(int i) const\
    \ {\n        assert(0 <= i && i < n);\n        return i / W;\n    }\n\n    /**\n\
    \     * @brief \u30D0\u30B1\u30C3\u30C8\u306E\u7BC4\u56F2\u3092\u8FD4\u3059\n\
    \     * @param i \u30D0\u30B1\u30C3\u30C8\u306E\u756A\u53F7\n     * @return \u30D0\
    \u30B1\u30C3\u30C8\u306E\u7BC4\u56F2\n     * @note [l, r) \u306E\u7BC4\u56F2\u3092\
    \u8FD4\u3059\n     */\n    pair<int, int> bucket_range(int i) const {\n      \
    \  assert(0 <= i && i < bucket_size());\n        int l = i * W;\n        int r\
    \ = min((i + 1) * W, n);\n        return {l, r};\n    }\n};\n"
  code: "#pragma once\n\ntemplate <int W> struct SquareRootDecomposition {\n    struct\
    \ Ranges {\n        optional<pair<int, int>> left_overflow_range;\n        optional<pair<int,\
    \ int>> bucket_range;\n        optional<pair<int, int>> right_overflow_range;\n\
    \        Ranges()\n            : left_overflow_range(nullopt),\n             \
    \ bucket_range(nullopt),\n              right_overflow_range(nullopt) {\n    \
    \    }\n    };\n\n    int n;\n\n    SquareRootDecomposition() {\n    }\n    SquareRootDecomposition(int\
    \ n) : n(n) {\n    }\n\n    int bucket_size() const {\n        return (n + W -\
    \ 1) / W;\n    }\n\n    /**\n     * @brief \u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\
    \u3092\u5206\u5272\u3059\u308B\n     * @param l \u5DE6\u7AEF\n     * @param r\
    \ \u53F3\u7AEF\n     * @return \u5206\u5272\u3055\u308C\u305F\u7BC4\u56F2\n  \
    \   * @note [l, r) \u306E\u7BC4\u56F2\u3092\u5206\u5272\u3059\u308B\n     */\n\
    \    Ranges query(int l, int r) const {\n        assert(0 <= l && l < r && r <=\
    \ n);\n        Ranges ret;\n        int l_bucket_id = bucket_id(l);\n        int\
    \ r_bucket_id = bucket_id(r - 1);\n        auto [l_bucket_l, l_bucket_r] = bucket_range(l_bucket_id);\n\
    \        auto [r_bucket_l, r_bucket_r] = bucket_range(r_bucket_id);\n        if\
    \ (l_bucket_id == r_bucket_id) {\n            if (l == l_bucket_l && r == r_bucket_r)\
    \ {\n                ret.bucket_range = {l_bucket_id, l_bucket_id + 1};\n    \
    \        } else {\n                ret.left_overflow_range = {l, r};\n       \
    \     }\n        } else {\n            if (l_bucket_id + 1 < r_bucket_id) {\n\
    \                ret.bucket_range = {l_bucket_id + 1, r_bucket_id};\n        \
    \    }\n            if (l == l_bucket_l) {\n                if (ret.bucket_range)\
    \ {\n                    ret.bucket_range->first--;\n                } else {\n\
    \                    ret.bucket_range = {l_bucket_id, l_bucket_id + 1};\n    \
    \            }\n            } else {\n                ret.left_overflow_range\
    \ = {l, l_bucket_r};\n            }\n            if (r == r_bucket_r) {\n    \
    \            if (ret.bucket_range) {\n                    ret.bucket_range->second++;\n\
    \                } else {\n                    ret.bucket_range = {r_bucket_id,\
    \ r_bucket_id + 1};\n                }\n            } else {\n               \
    \ ret.right_overflow_range = {r_bucket_l, r};\n            }\n        }\n    \
    \    return ret;\n    }\n\n    /**\n     * @brief \u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u304C\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\u3092\u8FD4\u3059\n   \
    \  * @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return \u30D0\u30B1\
    \u30C3\u30C8\u306E\u756A\u53F7\n     * @note [0, n) \u306E\u7BC4\u56F2\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9 i \u304C\u5C5E\u3059\u308B\u30D0\u30B1\u30C3\u30C8\
    \u306E\u756A\u53F7\u3092\u8FD4\u3059\n     */\n    int bucket_id(int i) const\
    \ {\n        assert(0 <= i && i < n);\n        return i / W;\n    }\n\n    /**\n\
    \     * @brief \u30D0\u30B1\u30C3\u30C8\u306E\u7BC4\u56F2\u3092\u8FD4\u3059\n\
    \     * @param i \u30D0\u30B1\u30C3\u30C8\u306E\u756A\u53F7\n     * @return \u30D0\
    \u30B1\u30C3\u30C8\u306E\u7BC4\u56F2\n     * @note [l, r) \u306E\u7BC4\u56F2\u3092\
    \u8FD4\u3059\n     */\n    pair<int, int> bucket_range(int i) const {\n      \
    \  assert(0 <= i && i < bucket_size());\n        int l = i * W;\n        int r\
    \ = min((i + 1) * W, n);\n        return {l, r};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/SquareRootDecomposition.hpp
  requiredBy: []
  timestamp: '2023-02-27 18:25:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/SquareRootDecomposion.test.cpp
documentation_of: algorithm/SquareRootDecomposition.hpp
layout: document
redirect_from:
- /library/algorithm/SquareRootDecomposition.hpp
- /library/algorithm/SquareRootDecomposition.hpp.html
title: "\u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3092\u5206\u5272\u3059\u308B"
---
