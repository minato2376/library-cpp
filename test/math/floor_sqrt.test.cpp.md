---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor_sqrt.hpp
    title: math/floor_sqrt.hpp
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
  bundledCode: "#line 1 \"test/math/floor_sqrt.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"other/template.hpp\"\n// clang-format off\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing uint = unsigned int;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing i128 = __int128_t;\nusing ld = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<long long, long long>;\ntemplate\
    \ <class T> using maxheap = priority_queue<T>;\ntemplate <class T> using minheap\
    \ = priority_queue<T, vector<T>, greater<T>>;\ntemplate <class T> using vec =\
    \ vector<T>;\ntemplate <class T> using vvec = vector<vector<T>>;\n#define OVERLOAD_REP(_1,\
    \ _2, _3, name, ...) name\n#define REP0(n) for (auto minato = decay_t<decltype(n)>{};\
    \ minato < (n); ++minato)\n#define REP1(i, n) for (auto i = decay_t<decltype(n)>{};\
    \ (i) < (n); (i)++)\n#define REP2(i, l, r) for (auto i = (l); (i) < (r); (i)++)\n\
    #define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)\n#define\
    \ OVERLOAD_RREP(_1, _2, _3, name, ...) name\n#define RREP1(i, n) for (auto i =\
    \ (n) - 1; (i) >= decay_t<decltype(n)>{}; (i)--)\n#define RREP2(i, l, r) for (auto\
    \ i = (r) - 1; (i) >= (l); (i)--)\n#define rrep(...) OVERLOAD_RREP(__VA_ARGS__,\
    \ RREP2, RREP1)(__VA_ARGS__)\n#define all(x) begin(x), end(x)\ntemplate <class\
    \ Container> int SZ(const Container& v) { return int(v.size()); }\ntemplate <class\
    \ T> void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(), v.end()), v.end());\
    \ }\ntemplate <class T> T MAX(const vector<T>& v) { return *max_element(v.begin(),\
    \ v.end()); }\ntemplate <class T> T MIN(const vector<T>& v) { return *min_element(v.begin(),\
    \ v.end()); }\ntemplate <class T> T SUM(const vector<T>& v) { return accumulate(v.begin(),\
    \ v.end(), T(0)); }\ntemplate <class T> T ABS(T x) { return max(x, -x); }\ntemplate\
    \ <class T1, class T2> bool chmax(T1& a, T2 b) { if (a < b) { a = b; return true;\
    \ } return false; }\ntemplate <class T1, class T2> bool chmin(T1& a, T2 b) { if\
    \ (a > b) { a = b; return true; } return false; }\nint topbit(ull x) { return\
    \ x == 0 ? -1 : 63 - __builtin_clzll(x); }\nint botbit(ull x) { return x == 0\
    \ ? 64 : __builtin_ctzll(x); }\nint popcount(ull x) { return __builtin_popcountll(x);\
    \ }\nint kthbit(ull x, int k) { return (x >> k) & 1; }\nconstexpr long long TEN(int\
    \ x) { return x == 0 ? 1 : TEN(x - 1) * 10; }\ntemplate <typename S> void rearrange(const\
    \ vector<S>& id) { (void)id; }\ntemplate <typename S, typename T> void rearrange_exec(const\
    \ vector<S>& id, vector<T>& v) { vector<T> w(v.size()); for (size_t i = 0; i <\
    \ id.size(); i++) { w[i] = v[id[i]]; } v.swap(w); }\ntemplate <typename S, typename\
    \ Head, typename... Tail> void rearrange(const vector<S>& id, Head& a, Tail& ...tail)\
    \ { rearrange_exec(id, a); rearrange(id, tail...); }\nistream& operator>>(istream&\
    \ is, __int128_t& x) {\n    x = 0;\n    string s;\n    is >> s;\n    int n = int(s.size()),\
    \ it = 0;\n    if (s[0] == '-') it++;\n    for (; it < n; it++) x = (x * 10 +\
    \ s[it] - '0');\n    if (s[0] == '-') x = -x;\n    return is;\n}\nostream& operator<<(ostream&\
    \ os, __int128_t x) {\n    if (x == 0) return os << 0;\n    if (x < 0) os << '-',\
    \ x = -x;\n    deque<int> deq;\n    while (x) deq.emplace_front(x % 10), x /=\
    \ 10;\n    for (int e : deq) os << e;\n    return os;\n}\ntemplate <class T> vector<T>\
    \ &operator++(vector<T>& v) { for (auto& e : v) { e++; } return v;} \ntemplate\
    \ <class T> vector<T> operator++(vector<T>& v, int) { auto res = v; for (auto&\
    \ e : v) { e++; } return res; }\ntemplate <class T> vector<T> &operator--(vector<T>&\
    \ v) { for (auto& e : v) { e--; } return v; }\ntemplate <class T> vector<T> operator--(vector<T>&\
    \ v, int) { auto res = v; for (auto& e : v) { e--; } return res; }\ntemplate <class\
    \ T1, class T2> pair<T1, T2> operator-(const pair<T1, T2>& x) { return pair<T1,\
    \ T2>(-x.first, -x.second); }\ntemplate <class T1, class T2> pair<T1, T2> operator-(const\
    \ pair<T1, T2>& x, const pair<T1, T2>& y) { return pair<T1, T2>(x.first - y.first,\
    \ x.second - y.second); }\ntemplate <class T1, class T2> pair<T1, T2> operator+(const\
    \ pair<T1, T2>& x, const pair<T1, T2>& y) { return pair<T1, T2>(x.first + y.first,\
    \ x.second + y.second); }\ntemplate <class T1, class T2> pair<T1, T2> operator+=(pair<T1,\
    \ T2>& l, const pair<T1, T2>& r) { return l = l + r; }\ntemplate <class T1, class\
    \ T2> pair<T1, T2> operator-=(pair<T1, T2>& l, const pair<T1, T2>& r) { return\
    \ l = l - r; }\nconstexpr char ln = '\\n';\nconst string YESNO[2] = {\"NO\", \"\
    YES\"};\nconst string YesNo[2] = {\"No\", \"Yes\"};\nvoid YES(bool t = true) {\
    \ cout << YESNO[t] << \"\\n\"; }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool\
    \ t = true) { cout << YesNo[t] << \"\\n\"; }\nvoid No(bool t = 1) { Yes(!t); }\n\
    template <class T> void drop(T x) { cout << x << \"\\n\"; exit(0); }\n#define\
    \ INT(...)     \\\n    int __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n#define LL(...)\
    \     \\\n    ll __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n#define STR(...)      \
    \  \\\n    string __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n#define CHR(...)     \
    \ \\\n    char __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n#define LDB(...)        \
    \     \\\n    long double __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n#define VEC(type,\
    \ name, size) \\\n    vector<type> name(size);  \\\n    IN(name)\n#define VEC2(type,\
    \ name1, name2, size)     \\\n    vector<type> name1(size), name2(size); \\\n\
    \    for (int i = 0; i < size; i++) IN(name1[i], name2[i])\n#define VEC3(type,\
    \ name1, name2, name3, size)           \\\n    vector<type> name1(size), name2(size),\
    \ name3(size); \\\n    for (int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])\n\
    #define VEC4(type, name1, name2, name3, name4, size)                 \\\n    vector<type>\
    \ name1(size), name2(size), name3(size), name4(size); \\\n    for (int i = 0;\
    \ i < size; i++) IN(name1[i], name2[i], name3[i], name4[i]);\n#define VV(type,\
    \ name, N, M)                       \\\n    vector<vector<type>> name(N, vector<type>(M));\
    \ \\\n    IN(name)\ntemplate <class T> void scan(T& a) { cin >> a; }\ntemplate\
    \ <class T> void scan(vector<T>& a) { for (auto& i : a) scan(i); }\nvoid IN()\
    \ {}\ntemplate <class Head, class... Tail> void IN(Head& head, Tail&... tail)\
    \ { scan(head); IN(tail...); }\nvoid print() { cout << \"\\n\"; }\ntemplate <class\
    \ T> void print(const vector<T>& v) { for (auto it = v.begin(); it != v.end();\
    \ ++it) { if (it != v.begin()) { cout << \" \"; } cout << *it; } print(); }\n\
    template <class T, class... Args> void print(const T& x, const Args& ... args)\
    \ { cout << x; if (sizeof...(Args)) cout << \" \"; print(args...); }\n#ifdef MINATO_LOCAL\n\
    template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p)\
    \ { return os << \"(\" << p.first << \", \" << p.second << \")\"; }\ntemplate\
    \ <size_t N, class TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os; (void)_;\
    \ }\ntemplate <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream\
    \ &os, TUPLE t) { os << (N == 0 ? \"\" : \", \") << get<N>(t); debug_tuple<N +\
    \ 1, TUPLE, Args...>(os, t); }\ntemplate <class ...Args> ostream& operator<<(ostream&\
    \ os, tuple<Args...> t) { os << \"(\"; debug_tuple<0, tuple<Args...>, Args...>(os,\
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
    // clang-format on\n#line 1 \"math/floor_sqrt.hpp\"\n/**\n * sqrt(x) \u3092\u8D85\
    \u3048\u306A\u3044\u6700\u5927\u306E\u6574\u6570\u3092\u6C42\u3081\u308B\u3002\
    \n * O(1)\n */\nlong long floor_sqrt(long long x) {\n    assert(0 <= x);\n   \
    \ return floor(sqrt((long double)x));\n}\n#line 4 \"test/math/floor_sqrt.test.cpp\"\
    \n\nvec<ll> A = {1,\n             2,\n             3,\n             4,\n     \
    \        8999999999999999999,\n             9000000000000000000,\n           \
    \  8999999994000000000,\n             8999999994000000001,\n             8999999994000000002,\n\
    \             8999999988000000003,\n             8999999988000000004,\n      \
    \       8999999988000000005,\n             8999999982000000008,\n            \
    \ 8999999982000000009,\n             8999999982000000010,\n             8999999976000000015,\n\
    \             8999999976000000016,\n             8999999976000000017,\n      \
    \       8491099229177050083,\n             8491099229177050084,\n            \
    \ 8491099229177050085,\n             8681616713998055555,\n             8681616713998055556,\n\
    \             8681616713998055557,\n             8870082394394406024,\n      \
    \       8870082394394406025,\n             8870082394394406026,\n            \
    \ 8783796469688809023,\n             8783796469688809024,\n             8783796469688809025,\n\
    \             8423372501986777343,\n             8423372501986777344,\n      \
    \       8423372501986777345,\n             8734980711058006083,\n            \
    \ 8734980711058006084,\n             8734980711058006085,\n             8809989053821655183,\n\
    \             8809989053821655184,\n             8809989053821655185,\n      \
    \       8854489696895693763,\n             8854489696895693764,\n            \
    \ 8854489696895693765,\n             8781633772865386800,\n             8781633772865386801,\n\
    \             8781633772865386802,\n             8849280339176904003,\n      \
    \       8849280339176904004,\n             8849280339176904005};\nvec<ll> B =\
    \ {\n    1,          1,          1,          2,          2999999999, 3000000000,\n\
    \    2999999998, 2999999999, 2999999999, 2999999997, 2999999998, 2999999998,\n\
    \    2999999996, 2999999997, 2999999997, 2999999995, 2999999996, 2999999996,\n\
    \    2913949077, 2913949078, 2913949078, 2946458333, 2946458334, 2946458334,\n\
    \    2978268354, 2978268355, 2978268355, 2963747031, 2963747032, 2963747032,\n\
    \    2902304687, 2902304688, 2902304688, 2955500077, 2955500078, 2955500078,\n\
    \    2968162571, 2968162572, 2968162572, 2975649457, 2975649458, 2975649458,\n\
    \    2963382150, 2963382151, 2963382151, 2974773997, 2974773998, 2974773998};\n\
    int main() {\n    rep(i, SZ(A)) {\n        assert(floor_sqrt(A[i]) == B[i]);\n\
    \    }\n    INT(X, Y);\n    print(X + Y);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"other/template.hpp\"\
    \n#include \"math/floor_sqrt.hpp\"\n\nvec<ll> A = {1,\n             2,\n     \
    \        3,\n             4,\n             8999999999999999999,\n            \
    \ 9000000000000000000,\n             8999999994000000000,\n             8999999994000000001,\n\
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
    \      assert(floor_sqrt(A[i]) == B[i]);\n    }\n    INT(X, Y);\n    print(X +\
    \ Y);\n}"
  dependsOn:
  - other/template.hpp
  - math/floor_sqrt.hpp
  isVerificationFile: true
  path: test/math/floor_sqrt.test.cpp
  requiredBy: []
  timestamp: '2023-02-21 01:03:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/floor_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sqrt.test.cpp
- /verify/test/math/floor_sqrt.test.cpp.html
title: test/math/floor_sqrt.test.cpp
---