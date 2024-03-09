---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/ModInt61.hpp
    title: mod/ModInt61.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/RollingHash.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <chrono>\n#include <random>\n#include <vector>\n\n#line\
    \ 2 \"mod/ModInt61.hpp\"\n#include <ostream>\n\nstruct ModInt61 {\n    using ull\
    \ = unsigned long long;\n    static constexpr ull MD = (1ULL << 61) - 1;\n   \
    \ using M = ModInt61;\n    static constexpr ull get_mod() {\n        return MD;\n\
    \    }\n    ull v;\n    ModInt61(long long _v = 0) {\n        set_v(_v % MD +\
    \ MD);\n    }\n    M& set_v(ull _v) {\n        v = (_v < MD) ? _v : _v - MD;\n\
    \        return *this;\n    }\n    ull val() const {\n        return v;\n    }\n\
    \    explicit operator bool() const {\n        return v != 0;\n    }\n    M operator-()\
    \ const {\n        return M() - *this;\n    }\n    M operator+(const M& r) const\
    \ {\n        return M().set_v(v + r.v);\n    }\n    M operator-(const M& r) const\
    \ {\n        return M().set_v(v + MD - r.v);\n    }\n    M operator*(const M&\
    \ r) const {\n        __uint128_t z = __uint128_t(v) * r.v;\n        return M().set_v(ull((z\
    \ & ((1ULL << 61) - 1)) + (z >> 61)));\n    }\n    M operator/(const M& r) const\
    \ {\n        return *this * r.inv();\n    }\n    M& operator+=(const M& r) {\n\
    \        return *this = *this + r;\n    }\n    M& operator-=(const M& r) {\n \
    \       return *this = *this - r;\n    }\n    M& operator*=(const M& r) {\n  \
    \      return *this = *this * r;\n    }\n    M& operator/=(const M& r) {\n   \
    \     return *this = *this / r;\n    }\n    bool operator==(const M& r) const\
    \ {\n        return v == r.v;\n    }\n    M pow(long long n) const {\n       \
    \ M x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n \
    \           x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n\
    \    M inv() const {\n        return pow(MD - 2);\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const M& r) {\n        return os << r.v;\n    }\n\
    };\n#line 10 \"string/RollingHash.hpp\"\n\nstruct RollingHash {\n    using ull\
    \ = unsigned long long;\n\n  public:\n    static inline ull generate_base() {\n\
    \        std::mt19937_64 mt(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<ull> rand(0ULL, ModInt61::get_mod() - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash(int n, ull base) : n_(n),\
    \ power(n + 1, 1), base_(base) {\n        for (int i = 0; i < n; i++) {\n    \
    \        power[i + 1] = power[i] * base_;\n        }\n    }\n\n    int size()\
    \ const {\n        return n_ + 1;\n    }\n\n    ModInt61 operator[](int i) const\
    \ {\n        assert(0 <= i and i <= n_);\n        return power[i];\n    }\n\n\
    \    ModInt61 get_base() const {\n        return base_;\n    }\n\n    template\
    \ <class String, int base_num = 1>\n    std::vector<ModInt61> get_hash(const String&\
    \ s) const {\n        int n = int(s.size());\n        assert(n <= n_);\n     \
    \   std::vector<ModInt61> ret(n + 1);\n        for (int i = 0; i < n; i++) {\n\
    \            ret[i + 1] = ret[i] * base_ + s[i] + base_num;\n        }\n     \
    \   return ret;\n    }\n\n    // [l,r) (0-indexed)\n    ModInt61 getrange(const\
    \ std::vector<ModInt61>& hash, int l, int r) const {\n        if (l >= r) return\
    \ ModInt61(0);\n        assert(0 <= l and r <= n_);\n        return hash[r] -\
    \ hash[l] * power[r - l];\n    }\n\n    template <class String, int base_num =\
    \ 1>\n    ModInt61 getval(const String& s) const {\n        int n = int(s.size());\n\
    \        assert(n <= n_);\n        ModInt61 ret = 0;\n        for (int i = 0;\
    \ i < n; i++) {\n            ret = ret * base_ + s[i] + base_num;\n        }\n\
    \        return ret;\n    }\n\n    ModInt61 concat(ModInt61 hl, ModInt61 hr, int\
    \ rlen) const {\n        assert(rlen <= n_);\n        return hl * power[rlen]\
    \ + hr;\n    }\n\n    int LCP(const std::vector<ModInt61>& a,\n            const\
    \ std::vector<ModInt61>& b,\n            int l1,\n            int r1,\n      \
    \      int l2,\n            int r2) const {\n        assert(0 <= l1 and l1 < r1\
    \ and r1 <= int(a.size()));\n        assert(0 <= l2 and l2 < r2 and r2 <= int(b.size()));\n\
    \        int len = std::min(r1 - l1, r2 - l2);\n        int low = -1, high = len\
    \ + 1;\n        while (high - low > 1) {\n            int mid = (low + high) /\
    \ 2;\n            if (getrange(a, l1, l1 + mid) == getrange(b, l2, l2 + mid))\n\
    \                low = mid;\n            else\n                high = mid;\n \
    \       }\n        return low;\n    }\n\n  private:\n    int n_;\n    std::vector<ModInt61>\
    \ power;\n    ModInt61 base_;\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <chrono>\n\
    #include <random>\n#include <vector>\n\n#include \"mod/ModInt61.hpp\"\n\nstruct\
    \ RollingHash {\n    using ull = unsigned long long;\n\n  public:\n    static\
    \ inline ull generate_base() {\n        std::mt19937_64 mt(\n            std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \        std::uniform_int_distribution<ull> rand(0ULL, ModInt61::get_mod() - 1);\n\
    \        return rand(mt);\n    }\n\n    RollingHash(int n, ull base) : n_(n),\
    \ power(n + 1, 1), base_(base) {\n        for (int i = 0; i < n; i++) {\n    \
    \        power[i + 1] = power[i] * base_;\n        }\n    }\n\n    int size()\
    \ const {\n        return n_ + 1;\n    }\n\n    ModInt61 operator[](int i) const\
    \ {\n        assert(0 <= i and i <= n_);\n        return power[i];\n    }\n\n\
    \    ModInt61 get_base() const {\n        return base_;\n    }\n\n    template\
    \ <class String, int base_num = 1>\n    std::vector<ModInt61> get_hash(const String&\
    \ s) const {\n        int n = int(s.size());\n        assert(n <= n_);\n     \
    \   std::vector<ModInt61> ret(n + 1);\n        for (int i = 0; i < n; i++) {\n\
    \            ret[i + 1] = ret[i] * base_ + s[i] + base_num;\n        }\n     \
    \   return ret;\n    }\n\n    // [l,r) (0-indexed)\n    ModInt61 getrange(const\
    \ std::vector<ModInt61>& hash, int l, int r) const {\n        if (l >= r) return\
    \ ModInt61(0);\n        assert(0 <= l and r <= n_);\n        return hash[r] -\
    \ hash[l] * power[r - l];\n    }\n\n    template <class String, int base_num =\
    \ 1>\n    ModInt61 getval(const String& s) const {\n        int n = int(s.size());\n\
    \        assert(n <= n_);\n        ModInt61 ret = 0;\n        for (int i = 0;\
    \ i < n; i++) {\n            ret = ret * base_ + s[i] + base_num;\n        }\n\
    \        return ret;\n    }\n\n    ModInt61 concat(ModInt61 hl, ModInt61 hr, int\
    \ rlen) const {\n        assert(rlen <= n_);\n        return hl * power[rlen]\
    \ + hr;\n    }\n\n    int LCP(const std::vector<ModInt61>& a,\n            const\
    \ std::vector<ModInt61>& b,\n            int l1,\n            int r1,\n      \
    \      int l2,\n            int r2) const {\n        assert(0 <= l1 and l1 < r1\
    \ and r1 <= int(a.size()));\n        assert(0 <= l2 and l2 < r2 and r2 <= int(b.size()));\n\
    \        int len = std::min(r1 - l1, r2 - l2);\n        int low = -1, high = len\
    \ + 1;\n        while (high - low > 1) {\n            int mid = (low + high) /\
    \ 2;\n            if (getrange(a, l1, l1 + mid) == getrange(b, l2, l2 + mid))\n\
    \                low = mid;\n            else\n                high = mid;\n \
    \       }\n        return low;\n    }\n\n  private:\n    int n_;\n    std::vector<ModInt61>\
    \ power;\n    ModInt61 base_;\n};\n"
  dependsOn:
  - mod/ModInt61.hpp
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: string/RollingHash.hpp
---
