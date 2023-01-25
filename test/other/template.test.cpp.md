---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/other/template.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"other/template.hpp\"\n// clang-format off\n#ifndef MINATO_LOCAL\n\
    #pragma GCC optimize (\"Ofast\")\n#pragma GCC optimize (\"unroll-loops\")\n#endif\n\
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
    // clang-format on\n#line 3 \"test/other/template.test.cpp\"\n\nint main() {\n\
    \    int A, B;\n    cin >> A >> B;\n    cout << A + B << ln;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"other/template.hpp\"\
    \n\nint main() {\n    int A, B;\n    cin >> A >> B;\n    cout << A + B << ln;\n\
    }"
  dependsOn:
  - other/template.hpp
  isVerificationFile: true
  path: test/other/template.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 21:40:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/other/template.test.cpp
layout: document
redirect_from:
- /verify/test/other/template.test.cpp
- /verify/test/other/template.test.cpp.html
title: test/other/template.test.cpp
---
