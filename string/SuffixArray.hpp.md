---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/LCP_SegmentTree.hpp
    title: string/LCP_SegmentTree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/SuffixArray.hpp\"\n\n#include <atcoder/string>\n\
    #include <string>\n#include <vector>\n\ntemplate <class T> struct SuffixArray\
    \ {\n    T s;\n    int n;\n    std::vector<int> sa, sa_inv;\n    SuffixArray()\
    \ {\n    }\n\n    SuffixArray(const std::string& s)\n        : s(s), n(int(s.size())),\
    \ sa(), sa_inv(s.size()) {\n        sa = atcoder::suffix_array(s);\n        for\
    \ (int i = 0; i < n; i++) {\n            sa_inv[sa[i]] = i;\n        }\n    }\n\
    \n    template <class U>\n    SuffixArray(const std::vector<U>& s)\n        :\
    \ s(s), n(int(s.size())), sa(), sa_inv(s.size()) {\n        sa = atcoder::suffix_array(s);\n\
    \        for (int i = 0; i < n; i++) {\n            sa_inv[sa[i]] = i;\n     \
    \   }\n    }\n\n    SuffixArray(const std::vector<int>& s, int upper)\n      \
    \  : s(s), n(int(s.size())), sa(), sa_inv(s.size()) {\n        sa = atcoder::suffix_array(s,\
    \ upper);\n        for (int i = 0; i < n; i++) {\n            sa_inv[sa[i]] =\
    \ i;\n        }\n    }\n\n    int size() const {\n        return n;\n    }\n\n\
    \    int operator[](int i) const {\n        return sa[i];\n    }\n\n    int inv(int\
    \ i) const {\n        return sa_inv[i];\n    }\n\n    auto data(int i) const {\n\
    \        return s[i];\n    }\n\n    /**\n     * @brief\n     * t \u4EE5\u4E0A\u306E\
    \ s \u306E suffix \u306E\u3046\u3061\u3001\u8F9E\u66F8\u9806\u3067\u6700\u5C0F\
    \u306E\u3082\u306E\u306E\u958B\u59CB\u4F4D\u7F6E\u3092\u8FD4\u3059\n     * O(|t|\
    \ log|s|)\n     * @note\n     * \u623B\u308A\u5024\u306Fsa \u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n     * t \u4EE5\u4E0A\u306E suffix \u304C\u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306F n \u3092\u8FD4\u3059\n     */\n    int lower_bound(const\
    \ T& t) const {\n        int l = -1, r = n;\n        while (r - l > 1) {\n   \
    \         int m = (l + r) / 2;\n            (lexicomp_suffix_of_s_and_t(sa[m],\
    \ t) ? l : r) = m;\n        }\n        return r;\n    }\n\n    /**\n     * @brief\n\
    \     * t \u3088\u308A\u5927\u304D\u3044 s \u306E suffix \u306E\u3046\u3061\u3001\
    \u8F9E\u66F8\u9806\u3067\u6700\u5C0F\u306E\u3082\u306E\u306E\u958B\u59CB\u4F4D\
    \u7F6E\u3092\u8FD4\u3059\n     * O(|t| log|s|)\n     * @note\n     * \u623B\u308A\
    \u5024\u306Fsa \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @note\n    \
    \ * t \u3088\u308A\u5927\u304D\u3044 suffix \u304C\u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F n \u3092\u8FD4\u3059\n     */\n    int upper_bound(T t) const\
    \ {\n        if (t.empty()) return 0;\n        t.back()++;\n        return lower_bound(t);\n\
    \    }\n\n    /**\n     * @brief\n     * s \u306B\u542B\u307E\u308C\u308B t \u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n     * O(|t| log|s|)\n     */\n  \
    \  int count(T t) const {\n        return upper_bound(t) - lower_bound(t);\n \
    \   }\n\n  private:\n    /**\n     * @brief\n     * s \u306E s_begin \u304B\u3089\
    \u59CB\u307E\u308B\u90E8\u5206\u6587\u5B57\u5217\u3068 t \u304C\u8F9E\u66F8\u9806\
    \u3067\u6BD4\u8F03\u3055\u308C\u305F\u3068\u304D\u3001 s\n     * \u306E\u65B9\u304C\
    \u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u304B\u3069\u3046\u304B\u3092\u8FD4\
    \u3059\n     */\n    bool lexicomp_suffix_of_s_and_t(int s_begin, const T& t)\
    \ const {\n        return lexicographical_compare(s.begin() + s_begin, s.end(),\
    \ t.begin(),\n                                       t.end());\n    }\n};\n"
  code: "#pragma once\n\n#include <atcoder/string>\n#include <string>\n#include <vector>\n\
    \ntemplate <class T> struct SuffixArray {\n    T s;\n    int n;\n    std::vector<int>\
    \ sa, sa_inv;\n    SuffixArray() {\n    }\n\n    SuffixArray(const std::string&\
    \ s)\n        : s(s), n(int(s.size())), sa(), sa_inv(s.size()) {\n        sa =\
    \ atcoder::suffix_array(s);\n        for (int i = 0; i < n; i++) {\n         \
    \   sa_inv[sa[i]] = i;\n        }\n    }\n\n    template <class U>\n    SuffixArray(const\
    \ std::vector<U>& s)\n        : s(s), n(int(s.size())), sa(), sa_inv(s.size())\
    \ {\n        sa = atcoder::suffix_array(s);\n        for (int i = 0; i < n; i++)\
    \ {\n            sa_inv[sa[i]] = i;\n        }\n    }\n\n    SuffixArray(const\
    \ std::vector<int>& s, int upper)\n        : s(s), n(int(s.size())), sa(), sa_inv(s.size())\
    \ {\n        sa = atcoder::suffix_array(s, upper);\n        for (int i = 0; i\
    \ < n; i++) {\n            sa_inv[sa[i]] = i;\n        }\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int operator[](int i) const {\n   \
    \     return sa[i];\n    }\n\n    int inv(int i) const {\n        return sa_inv[i];\n\
    \    }\n\n    auto data(int i) const {\n        return s[i];\n    }\n\n    /**\n\
    \     * @brief\n     * t \u4EE5\u4E0A\u306E s \u306E suffix \u306E\u3046\u3061\
    \u3001\u8F9E\u66F8\u9806\u3067\u6700\u5C0F\u306E\u3082\u306E\u306E\u958B\u59CB\
    \u4F4D\u7F6E\u3092\u8FD4\u3059\n     * O(|t| log|s|)\n     * @note\n     * \u623B\
    \u308A\u5024\u306Fsa \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * t \u4EE5\
    \u4E0A\u306E suffix \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F n \u3092\
    \u8FD4\u3059\n     */\n    int lower_bound(const T& t) const {\n        int l\
    \ = -1, r = n;\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            (lexicomp_suffix_of_s_and_t(sa[m], t) ? l : r) = m;\n        }\n\
    \        return r;\n    }\n\n    /**\n     * @brief\n     * t \u3088\u308A\u5927\
    \u304D\u3044 s \u306E suffix \u306E\u3046\u3061\u3001\u8F9E\u66F8\u9806\u3067\u6700\
    \u5C0F\u306E\u3082\u306E\u306E\u958B\u59CB\u4F4D\u7F6E\u3092\u8FD4\u3059\n   \
    \  * O(|t| log|s|)\n     * @note\n     * \u623B\u308A\u5024\u306Fsa \u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @note\n     * t \u3088\u308A\u5927\u304D\
    \u3044 suffix \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F n \u3092\u8FD4\
    \u3059\n     */\n    int upper_bound(T t) const {\n        if (t.empty()) return\
    \ 0;\n        t.back()++;\n        return lower_bound(t);\n    }\n\n    /**\n\
    \     * @brief\n     * s \u306B\u542B\u307E\u308C\u308B t \u306E\u51FA\u73FE\u56DE\
    \u6570\u3092\u8FD4\u3059\n     * O(|t| log|s|)\n     */\n    int count(T t) const\
    \ {\n        return upper_bound(t) - lower_bound(t);\n    }\n\n  private:\n  \
    \  /**\n     * @brief\n     * s \u306E s_begin \u304B\u3089\u59CB\u307E\u308B\u90E8\
    \u5206\u6587\u5B57\u5217\u3068 t \u304C\u8F9E\u66F8\u9806\u3067\u6BD4\u8F03\u3055\
    \u308C\u305F\u3068\u304D\u3001 s\n     * \u306E\u65B9\u304C\u8F9E\u66F8\u9806\u3067\
    \u5C0F\u3055\u3044\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool\
    \ lexicomp_suffix_of_s_and_t(int s_begin, const T& t) const {\n        return\
    \ lexicographical_compare(s.begin() + s_begin, s.end(), t.begin(),\n         \
    \                              t.end());\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/SuffixArray.hpp
  requiredBy:
  - string/LCP_SegmentTree.hpp
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/SuffixArray.hpp
layout: document
redirect_from:
- /library/string/SuffixArray.hpp
- /library/string/SuffixArray.hpp.html
title: string/SuffixArray.hpp
---
