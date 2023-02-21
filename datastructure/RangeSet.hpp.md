---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/RangeSet.test.cpp
    title: test/datastructure/RangeSet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/RangeSet.hpp\"\ntemplate <typename T> struct\
    \ RangeSet : set<pair<T, T>> {\n    T insert_range(T l, T r) {\n        assert(l\
    \ < r);\n        T increased_length = 0;\n        auto it = this->lower_bound(make_pair(l,\
    \ r));\n        while (it != this->end() && it->first <= r) {\n            r =\
    \ max(r, it->second);\n            increased_length -= it->second - it->first;\n\
    \            it = this->erase(it);\n        }\n        if (it != this->begin()\
    \ && prev(it)->second >= l) {\n            it = prev(it);\n            l = min(l,\
    \ it->first);\n            r = max(r, it->second);\n            increased_length\
    \ -= it->second - it->first;\n            it = this->erase(it);\n        }\n \
    \       increased_length += r - l;\n        this->emplace_hint(it, make_pair(l,\
    \ r));\n        return increased_length;\n    }\n\n    T insert_point(T x) {\n\
    \        return insert_range(x, x + 1);\n    }\n\n    T erase_range(T l, T r)\
    \ {\n        assert(l < r);\n        T decreased_length = r - l - insert_range(l,\
    \ r);\n        auto it =\n            prev(this->upper_bound(make_pair(l, numeric_limits<T>::max())));\n\
    \        auto [new_l, new_r] = *it;\n        if (new_l < l) this->emplace_hint(it,\
    \ make_pair(new_l, l));\n        it = this->erase(it);\n        if (new_r > r)\
    \ this->emplace_hint(it, make_pair(r, new_r));\n        return decreased_length;\n\
    \    }\n\n    T erase_point(T x) {\n        return erase_range(x, x + 1);\n  \
    \  }\n\n    auto contains_range(T l, T r) const {\n        assert(l < r);\n  \
    \      auto it = this->upper_bound(make_pair(l, numeric_limits<T>::max()));\n\
    \        if (it == this->begin()) return this->end();\n        it = prev(it);\n\
    \        return (it->first <= l && r <= it->second ? it : this->end());\n    }\n\
    \n    auto contains_point(T x) const {\n        return contains_range(x, x + 1);\n\
    \    }\n\n    T mex() const {\n        assert(this->empty() || this->begin()->first\
    \ >= 0);\n        if (this->empty()) return 0;\n        return this->begin()->first\
    \ == 0 ? this->begin()->second : 0;\n    }\n\n#ifdef MINATO_LOCAL\n    friend\
    \ ostream& operator<<(ostream& os, RangeSet r) {\n        for (auto it = r.begin();\
    \ it != r.end(); it = next(it)) {\n            if (it != r.begin()) os << \",\
    \ \";\n            os << *it;\n        }\n        return os;\n    }\n#endif\n\
    };\n"
  code: "template <typename T> struct RangeSet : set<pair<T, T>> {\n    T insert_range(T\
    \ l, T r) {\n        assert(l < r);\n        T increased_length = 0;\n       \
    \ auto it = this->lower_bound(make_pair(l, r));\n        while (it != this->end()\
    \ && it->first <= r) {\n            r = max(r, it->second);\n            increased_length\
    \ -= it->second - it->first;\n            it = this->erase(it);\n        }\n \
    \       if (it != this->begin() && prev(it)->second >= l) {\n            it =\
    \ prev(it);\n            l = min(l, it->first);\n            r = max(r, it->second);\n\
    \            increased_length -= it->second - it->first;\n            it = this->erase(it);\n\
    \        }\n        increased_length += r - l;\n        this->emplace_hint(it,\
    \ make_pair(l, r));\n        return increased_length;\n    }\n\n    T insert_point(T\
    \ x) {\n        return insert_range(x, x + 1);\n    }\n\n    T erase_range(T l,\
    \ T r) {\n        assert(l < r);\n        T decreased_length = r - l - insert_range(l,\
    \ r);\n        auto it =\n            prev(this->upper_bound(make_pair(l, numeric_limits<T>::max())));\n\
    \        auto [new_l, new_r] = *it;\n        if (new_l < l) this->emplace_hint(it,\
    \ make_pair(new_l, l));\n        it = this->erase(it);\n        if (new_r > r)\
    \ this->emplace_hint(it, make_pair(r, new_r));\n        return decreased_length;\n\
    \    }\n\n    T erase_point(T x) {\n        return erase_range(x, x + 1);\n  \
    \  }\n\n    auto contains_range(T l, T r) const {\n        assert(l < r);\n  \
    \      auto it = this->upper_bound(make_pair(l, numeric_limits<T>::max()));\n\
    \        if (it == this->begin()) return this->end();\n        it = prev(it);\n\
    \        return (it->first <= l && r <= it->second ? it : this->end());\n    }\n\
    \n    auto contains_point(T x) const {\n        return contains_range(x, x + 1);\n\
    \    }\n\n    T mex() const {\n        assert(this->empty() || this->begin()->first\
    \ >= 0);\n        if (this->empty()) return 0;\n        return this->begin()->first\
    \ == 0 ? this->begin()->second : 0;\n    }\n\n#ifdef MINATO_LOCAL\n    friend\
    \ ostream& operator<<(ostream& os, RangeSet r) {\n        for (auto it = r.begin();\
    \ it != r.end(); it = next(it)) {\n            if (it != r.begin()) os << \",\
    \ \";\n            os << *it;\n        }\n        return os;\n    }\n#endif\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/RangeSet.hpp
  requiredBy: []
  timestamp: '2023-02-22 03:55:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/RangeSet.test.cpp
documentation_of: datastructure/RangeSet.hpp
layout: document
redirect_from:
- /library/datastructure/RangeSet.hpp
- /library/datastructure/RangeSet.hpp.html
title: datastructure/RangeSet.hpp
---
