---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/floor_sqrt.hpp
    title: math/floor_sqrt.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/floor_sqrt.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"math/floor_sqrt.hpp\"\n/**\n * sqrt(x) \u3092\u8D85\u3048\u306A\u3044\
    \u6700\u5927\u306E\u6574\u6570\u3092\u6C42\u3081\u308B\u3002\n * O(1)\n */\nlong\
    \ long floor_sqrt(long long x) {\n    return floor(sqrt((long double)x));\n}\n\
    #line 1 \"other/template.hpp\"\n// clang-format off\n#ifndef MINATO_LOCAL\n#pragma\
    \ GCC optimize (\"Ofast\")\n#pragma GCC optimize (\"unroll-loops\")\n#endif\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing uint = unsigned int;\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing pii = pair<int, int>;\n\
    using pll = pair<long long, long long>;\ntemplate <class T> using vec = vector<T>;\n\
    template <class T> using vvec = vector<vector<T>>;\n#define rep(i, n) for (int\
    \ i = 0; i < (n); i++)\n#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)\n\
    #define all(x) begin(x), end(x)\nconstexpr char ln = '\\n';\ntemplate <class Container>\
    \ inline int SZ(const Container& v) { return int(v.size()); }\ntemplate <class\
    \ T> inline void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(), v.end()), v.end());\
    \ }\ntemplate <class T1, class T2> inline bool chmax(T1& a, T2 b) { if (a < b)\
    \ { a = b; return true; } return false; }\ntemplate <class T1, class T2> inline\
    \ bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true; } return false; }\n\
    inline int topbit(ull x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }\ninline\
    \ int botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x); }\ninline int popcount(ull\
    \ x) { return __builtin_popcountll(x); }\ninline int kthbit(ull x, int k) { return\
    \ (x >> k) & 1; }\ninline constexpr long long TEN(int x) { return x == 0 ? 1 :\
    \ TEN(x - 1) * 10; }\nconst string YESNO[2] = {\"NO\", \"YES\"};\nconst string\
    \ YesNo[2] = {\"No\", \"Yes\"};\ninline void YES(bool t = true) { cout << YESNO[t]\
    \ << \"\\n\"; }\ninline void Yes(bool t = true) { cout << YesNo[t] << \"\\n\"\
    ; }\ntemplate <class T> inline void drop(T x) { cout << x << \"\\n\"; exit(0);\
    \ }\ninline void print() { cout << \"\\n\"; }\ntemplate <class T> inline void\
    \ print(const vector<T>& v) { for (auto it = v.begin(); it != v.end(); ++it) {\
    \ if (it != v.begin()) { cout << \" \"; } cout << *it; } print(); }\ntemplate\
    \ <class T, class... Args> inline void print(const T& x, const Args& ... args)\
    \ { cout << x << \" \"; print(args...); }\n#ifdef MINATO_LOCAL\ntemplate <class\
    \ T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p) { return os <<\
    \ \"(\" << p.first << \", \" << p.second << \")\"; }\ntemplate <size_t N, class\
    \ TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os; (void)_; }\ntemplate\
    \ <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream &os,\
    \ TUPLE t) { os << (N == 0 ? \"\" : \", \") << get<N>(t); debug_tuple<N + 1, TUPLE,\
    \ Args...>(os, t); }\ntemplate <class ...Args> ostream& operator<<(ostream& os,\
    \ tuple<Args...> t) { os << \"(\"; debug_tuple<0, tuple<Args...>, Args...>(os,\
    \ t); return os << \")\"; }\nstring debug_delim(int& i) { return i++ == 0 ? \"\
    \" : \", \"; }\n#define debug_embrace(x) { int i = 0; os << \"{\";  { x } return\
    \ os << \"}\"; }\ntemplate <class T> ostream& operator<<(ostream& os, vector<T>\
    \ v) { debug_embrace( for (T e : v) { os << debug_delim(i) << e; } ) }\ntemplate\
    \ <class T, size_t N> ostream& operator<<(ostream& os, array<T, N> a) { debug_embrace(\
    \ for (T e : a) { os << debug_delim(i) << e; } ) }\ntemplate <class T, size_t\
    \ N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>& operator<<(ostream&\
    \ os, T(&a)[N]) { debug_embrace( for (T e : a) { os << debug_delim(i) << e; }\
    \ ) }\ntemplate <class Key> ostream& operator<<(ostream& os, set<Key> s) { debug_embrace(\
    \ for (Key e : s) { os << debug_delim(i) << e; }) }\ntemplate <class Key, class\
    \ T> ostream& operator<<(ostream& os, map<Key, T> mp) { debug_embrace( for (auto\
    \ e : mp) { os << debug_delim(i) << e; }) }\ntemplate <class Key> ostream& operator<<(ostream&\
    \ os, multiset<Key> s) { debug_embrace( for (Key e : s) { os << debug_delim(i)\
    \ << e; }) }\ntemplate <class T> ostream& operator<<(ostream& os, queue<T> q)\
    \ { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.front();\
    \ } ) }\ntemplate <class T> ostream& operator<<(ostream& os, deque<T> q) { debug_embrace(\
    \ for (T e : q) { os << debug_delim(i) << e; } ) }\ntemplate <class T> ostream&\
    \ operator<<(ostream& os, priority_queue<T> q) { debug_embrace( for (; !q.empty();\
    \ q.pop()) { os << debug_delim(i) << q.top(); } ) }\ntemplate <class T> ostream&\
    \ operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>> q) { debug_embrace(\
    \ for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <class T, class... Args> void debug_out(const T&\
    \ x, const Args& ... args) { cerr << \" \" << x; debug_out(args...); }\n#define\
    \ debug(...) cerr << __LINE__ << \" : [\" << #__VA_ARGS__ << \"] =\", debug_out(__VA_ARGS__)\n\
    #else\n#define debug(...) (void(0))\n#endif\nstruct fast_ios { fast_ios() { cin.tie(nullptr);\
    \ ios::sync_with_stdio(false); cout << fixed << setprecision(20); cerr << fixed\
    \ << setprecision(7); }; } fast_ios_;\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\
    // clang-format on\n#line 4 \"test/math/floor_sqrt.test.cpp\"\n\nvec<ll> A = {1,\n\
    \             2,\n             3,\n             4,\n             8999999999999999999,\n\
    \             9000000000000000000,\n             8999999994000000000,\n      \
    \       8999999994000000001,\n             8999999994000000002,\n            \
    \ 8999999988000000003,\n             8999999988000000004,\n             8999999988000000005,\n\
    \             8999999982000000008,\n             8999999982000000009,\n      \
    \       8999999982000000010,\n             8999999976000000015,\n            \
    \ 8999999976000000016,\n             8999999976000000017,\n             8491099229177050083,\n\
    \             8491099229177050084,\n             8491099229177050085,\n      \
    \       8681616713998055555,\n             8681616713998055556,\n            \
    \ 8681616713998055557,\n             8870082394394406024,\n             8870082394394406025,\n\
    \             8870082394394406026,\n             8783796469688809023,\n      \
    \       8783796469688809024,\n             8783796469688809025,\n            \
    \ 8423372501986777343,\n             8423372501986777344,\n             8423372501986777345,\n\
    \             8734980711058006083,\n             8734980711058006084,\n      \
    \       8734980711058006085,\n             8809989053821655183,\n            \
    \ 8809989053821655184,\n             8809989053821655185,\n             8854489696895693763,\n\
    \             8854489696895693764,\n             8854489696895693765,\n      \
    \       8781633772865386800,\n             8781633772865386801,\n            \
    \ 8781633772865386802,\n             8849280339176904003,\n             8849280339176904004,\n\
    \             8849280339176904005};\nvec<ll> B = {\n    1,          1,       \
    \   1,          2,          2999999999, 3000000000,\n    2999999998, 2999999999,\
    \ 2999999999, 2999999997, 2999999998, 2999999998,\n    2999999996, 2999999997,\
    \ 2999999997, 2999999995, 2999999996, 2999999996,\n    2913949077, 2913949078,\
    \ 2913949078, 2946458333, 2946458334, 2946458334,\n    2978268354, 2978268355,\
    \ 2978268355, 2963747031, 2963747032, 2963747032,\n    2902304687, 2902304688,\
    \ 2902304688, 2955500077, 2955500078, 2955500078,\n    2968162571, 2968162572,\
    \ 2968162572, 2975649457, 2975649458, 2975649458,\n    2963382150, 2963382151,\
    \ 2963382151, 2974773997, 2974773998, 2974773998};\nint main() {\n    rep(i, SZ(A))\
    \ {\n        assert(floor_sqrt(A[i]) == B[i]);\n    }\n    int A, B;\n    cin\
    \ >> A >> B;\n    cout << A + B << ln;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"math/floor_sqrt.hpp\"\
    ;\n#include \"other/template.hpp\";\n\nvec<ll> A = {1,\n             2,\n    \
    \         3,\n             4,\n             8999999999999999999,\n           \
    \  9000000000000000000,\n             8999999994000000000,\n             8999999994000000001,\n\
    \             8999999994000000002,\n             8999999988000000003,\n      \
    \       8999999988000000004,\n             8999999988000000005,\n            \
    \ 8999999982000000008,\n             8999999982000000009,\n             8999999982000000010,\n\
    \             8999999976000000015,\n             8999999976000000016,\n      \
    \       8999999976000000017,\n             8491099229177050083,\n            \
    \ 8491099229177050084,\n             8491099229177050085,\n             8681616713998055555,\n\
    \             8681616713998055556,\n             8681616713998055557,\n      \
    \       8870082394394406024,\n             8870082394394406025,\n            \
    \ 8870082394394406026,\n             8783796469688809023,\n             8783796469688809024,\n\
    \             8783796469688809025,\n             8423372501986777343,\n      \
    \       8423372501986777344,\n             8423372501986777345,\n            \
    \ 8734980711058006083,\n             8734980711058006084,\n             8734980711058006085,\n\
    \             8809989053821655183,\n             8809989053821655184,\n      \
    \       8809989053821655185,\n             8854489696895693763,\n            \
    \ 8854489696895693764,\n             8854489696895693765,\n             8781633772865386800,\n\
    \             8781633772865386801,\n             8781633772865386802,\n      \
    \       8849280339176904003,\n             8849280339176904004,\n            \
    \ 8849280339176904005};\nvec<ll> B = {\n    1,          1,          1,       \
    \   2,          2999999999, 3000000000,\n    2999999998, 2999999999, 2999999999,\
    \ 2999999997, 2999999998, 2999999998,\n    2999999996, 2999999997, 2999999997,\
    \ 2999999995, 2999999996, 2999999996,\n    2913949077, 2913949078, 2913949078,\
    \ 2946458333, 2946458334, 2946458334,\n    2978268354, 2978268355, 2978268355,\
    \ 2963747031, 2963747032, 2963747032,\n    2902304687, 2902304688, 2902304688,\
    \ 2955500077, 2955500078, 2955500078,\n    2968162571, 2968162572, 2968162572,\
    \ 2975649457, 2975649458, 2975649458,\n    2963382150, 2963382151, 2963382151,\
    \ 2974773997, 2974773998, 2974773998};\nint main() {\n    rep(i, SZ(A)) {\n  \
    \      assert(floor_sqrt(A[i]) == B[i]);\n    }\n    int A, B;\n    cin >> A >>\
    \ B;\n    cout << A + B << ln;\n}"
  dependsOn:
  - math/floor_sqrt.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/math/floor_sqrt.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 21:23:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/floor_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sqrt.test.cpp
- /verify/test/math/floor_sqrt.test.cpp.html
title: test/math/floor_sqrt.test.cpp
---
