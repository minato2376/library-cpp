---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/SquareRootDecomposion.test.cpp
    title: test/algorithm/SquareRootDecomposion.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/algorithm/inversion_number.test.cpp
    title: test/algorithm/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/algorithm/run_length_encoding.test.cpp
    title: test/algorithm/run_length_encoding.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/datastructure/BinaryIndexedTree.test.cpp
    title: test/datastructure/BinaryIndexedTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/datastructure/RangeSet.test.cpp
    title: test/datastructure/RangeSet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/datastructure/SlidingWindowAggregation.test.cpp
    title: test/datastructure/SlidingWindowAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/datastructure/UnionFind.test.cpp
    title: test/datastructure/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/generator/generate_random_sequence.test.cpp
    title: test/generator/generate_random_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/StronglyConnectedComponents.test.cpp
    title: test/graph/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/TwoSat.test.cpp
    title: test/math/TwoSat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/floor_sqrt.test.cpp
    title: test/math/floor_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/totient.test.cpp
    title: test/math/totient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mod/ModInt.test.cpp
    title: test/mod/ModInt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/other/template.test.cpp
    title: test/other/template.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/DualSegmentTree.test.cpp
    title: test/segmenttree/DualSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/DualSegmentTree2.test.cpp
    title: test/segmenttree/DualSegmentTree2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/LazySegmentTree.test.cpp
    title: test/segmenttree/LazySegmentTree.test.cpp
  - icon: ':x:'
    path: test/segmenttree/LazySegmentTree2.test.cpp
    title: test/segmenttree/LazySegmentTree2.test.cpp
  - icon: ':x:'
    path: test/segmenttree/LazySegmentTree3.test.cpp
    title: test/segmenttree/LazySegmentTree3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/LazySegmentTree4.test.cpp
    title: test/segmenttree/LazySegmentTree4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/PointAddRectangleSum.test.cpp
    title: test/segmenttree/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/RangeAddRangeSum.test.cpp
    title: test/segmenttree/RangeAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmenttree/SegmentTree.test.cpp
    title: test/segmenttree/SegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/shortestpath/warshall_floyd.test.cpp
    title: test/shortestpath/warshall_floyd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rerooting.test.cpp
    title: test/tree/Rerooting.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/template.hpp\"\n// clang-format off\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <cmath>\n#include <complex>\n#include <deque>\n#include <forward_list>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n#include\
    \ <iostream>\n#include <limits>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\nusing namespace std;\nusing uint = unsigned int;\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing i128 = __int128_t;\nusing ld =\
    \ long double;\nusing pii = pair<int, int>;\nusing pll = pair<long long, long\
    \ long>;\ntemplate <class T> using maxheap = priority_queue<T>;\ntemplate <class\
    \ T> using minheap = priority_queue<T, vector<T>, greater<T>>;\ntemplate <class\
    \ T> using vec = vector<T>;\ntemplate <class T> using vvec = vector<vector<T>>;\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP0(n) for (auto minato\
    \ = decay_t<decltype(n)>{}; minato < (n); ++minato)\n#define REP1(i, n) for (auto\
    \ i = decay_t<decltype(n)>{}; (i) < (n); (i)++)\n#define REP2(i, l, r) for (auto\
    \ i = (l); (i) < (r); (i)++)\n#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2,\
    \ REP1, REP0)(__VA_ARGS__)\n#define OVERLOAD_RREP(_1, _2, _3, name, ...) name\n\
    #define RREP1(i, n) for (auto i = (n) - 1; (i) >= decay_t<decltype(n)>{}; (i)--)\n\
    #define RREP2(i, l, r) for (auto i = (r) - 1; (i) >= (l); (i)--)\n#define rrep(...)\
    \ OVERLOAD_RREP(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)\n#define ALL(x) begin(x),\
    \ end(x)\ntemplate <class Container> int SZ(const Container& v) { return int(v.size());\
    \ }\ntemplate <class T> void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(),\
    \ v.end()), v.end()); }\ntemplate <class T> T MAX(const vector<T>& v) { return\
    \ *max_element(v.begin(), v.end()); }\ntemplate <class T> T MIN(const vector<T>&\
    \ v) { return *min_element(v.begin(), v.end()); }\ntemplate <class T> T SUM(const\
    \ vector<T>& v) { return accumulate(v.begin(), v.end(), T(0)); }\ntemplate <class\
    \ T> T ABS(T x) { return max(x, -x); }\ntemplate <class T1, class T2> bool chmax(T1&\
    \ a, T2 b) { if (a < b) { a = b; return true; } return false; }\ntemplate <class\
    \ T1, class T2> bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true; } return\
    \ false; }\nint topbit(ull x) { return x == 0 ? -1 : 63 - __builtin_clzll(x);\
    \ }\nint botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x); }\nint popcount(ull\
    \ x) { return __builtin_popcountll(x); }\nint kthbit(ull x, int k) { return (x\
    \ >> k) & 1; }\nconstexpr long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1)\
    \ * 10; }\ntemplate <typename S> void rearrange(const vector<S>& id) { (void)id;\
    \ }\ntemplate <typename S, typename T> void rearrange_exec(const vector<S>& id,\
    \ vector<T>& v) { vector<T> w(v.size()); for (size_t i = 0; i < id.size(); i++)\
    \ { w[i] = v[id[i]]; } v.swap(w); }\ntemplate <typename S, typename Head, typename...\
    \ Tail> void rearrange(const vector<S>& id, Head& a, Tail& ...tail) { rearrange_exec(id,\
    \ a); rearrange(id, tail...); }\nistream& operator>>(istream& is, __int128_t&\
    \ x) {\n    x = 0;\n    string s;\n    is >> s;\n    int n = int(s.size()), it\
    \ = 0;\n    if (s[0] == '-') it++;\n    for (; it < n; it++) x = (x * 10 + s[it]\
    \ - '0');\n    if (s[0] == '-') x = -x;\n    return is;\n}\nostream& operator<<(ostream&\
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
    #else\n#define debug(...) (void(0))\n#endif\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\
    // clang-format on\n"
  code: "// clang-format off\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <cmath>\n#include <complex>\n\
    #include <deque>\n#include <forward_list>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <limits>\n#include\
    \ <list>\n#include <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\nusing namespace\
    \ std;\nusing uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing i128 = __int128_t;\nusing ld = long double;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<long long, long long>;\ntemplate <class T> using maxheap\
    \ = priority_queue<T>;\ntemplate <class T> using minheap = priority_queue<T, vector<T>,\
    \ greater<T>>;\ntemplate <class T> using vec = vector<T>;\ntemplate <class T>\
    \ using vvec = vector<vector<T>>;\n#define OVERLOAD_REP(_1, _2, _3, name, ...)\
    \ name\n#define REP0(n) for (auto minato = decay_t<decltype(n)>{}; minato < (n);\
    \ ++minato)\n#define REP1(i, n) for (auto i = decay_t<decltype(n)>{}; (i) < (n);\
    \ (i)++)\n#define REP2(i, l, r) for (auto i = (l); (i) < (r); (i)++)\n#define\
    \ rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)\n#define OVERLOAD_RREP(_1,\
    \ _2, _3, name, ...) name\n#define RREP1(i, n) for (auto i = (n) - 1; (i) >= decay_t<decltype(n)>{};\
    \ (i)--)\n#define RREP2(i, l, r) for (auto i = (r) - 1; (i) >= (l); (i)--)\n#define\
    \ rrep(...) OVERLOAD_RREP(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)\n#define ALL(x)\
    \ begin(x), end(x)\ntemplate <class Container> int SZ(const Container& v) { return\
    \ int(v.size()); }\ntemplate <class T> void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(),\
    \ v.end()), v.end()); }\ntemplate <class T> T MAX(const vector<T>& v) { return\
    \ *max_element(v.begin(), v.end()); }\ntemplate <class T> T MIN(const vector<T>&\
    \ v) { return *min_element(v.begin(), v.end()); }\ntemplate <class T> T SUM(const\
    \ vector<T>& v) { return accumulate(v.begin(), v.end(), T(0)); }\ntemplate <class\
    \ T> T ABS(T x) { return max(x, -x); }\ntemplate <class T1, class T2> bool chmax(T1&\
    \ a, T2 b) { if (a < b) { a = b; return true; } return false; }\ntemplate <class\
    \ T1, class T2> bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true; } return\
    \ false; }\nint topbit(ull x) { return x == 0 ? -1 : 63 - __builtin_clzll(x);\
    \ }\nint botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x); }\nint popcount(ull\
    \ x) { return __builtin_popcountll(x); }\nint kthbit(ull x, int k) { return (x\
    \ >> k) & 1; }\nconstexpr long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1)\
    \ * 10; }\ntemplate <typename S> void rearrange(const vector<S>& id) { (void)id;\
    \ }\ntemplate <typename S, typename T> void rearrange_exec(const vector<S>& id,\
    \ vector<T>& v) { vector<T> w(v.size()); for (size_t i = 0; i < id.size(); i++)\
    \ { w[i] = v[id[i]]; } v.swap(w); }\ntemplate <typename S, typename Head, typename...\
    \ Tail> void rearrange(const vector<S>& id, Head& a, Tail& ...tail) { rearrange_exec(id,\
    \ a); rearrange(id, tail...); }\nistream& operator>>(istream& is, __int128_t&\
    \ x) {\n    x = 0;\n    string s;\n    is >> s;\n    int n = int(s.size()), it\
    \ = 0;\n    if (s[0] == '-') it++;\n    for (; it < n; it++) x = (x * 10 + s[it]\
    \ - '0');\n    if (s[0] == '-') x = -x;\n    return is;\n}\nostream& operator<<(ostream&\
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
    #else\n#define debug(...) (void(0))\n#endif\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\
    // clang-format on"
  dependsOn: []
  isVerificationFile: false
  path: other/template.hpp
  requiredBy: []
  timestamp: '2023-06-20 01:24:59+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/datastructure/RangeSet.test.cpp
  - test/datastructure/SlidingWindowAggregation.test.cpp
  - test/datastructure/UnionFind.test.cpp
  - test/datastructure/BinaryIndexedTree.test.cpp
  - test/mod/ModInt.test.cpp
  - test/shortestpath/warshall_floyd.test.cpp
  - test/math/TwoSat.test.cpp
  - test/math/floor_sqrt.test.cpp
  - test/math/totient.test.cpp
  - test/algorithm/inversion_number.test.cpp
  - test/algorithm/SquareRootDecomposion.test.cpp
  - test/algorithm/run_length_encoding.test.cpp
  - test/graph/StronglyConnectedComponents.test.cpp
  - test/other/template.test.cpp
  - test/segmenttree/DualSegmentTree2.test.cpp
  - test/segmenttree/LazySegmentTree4.test.cpp
  - test/segmenttree/SegmentTree.test.cpp
  - test/segmenttree/DualSegmentTree.test.cpp
  - test/segmenttree/LazySegmentTree3.test.cpp
  - test/segmenttree/LazySegmentTree.test.cpp
  - test/segmenttree/PointAddRectangleSum.test.cpp
  - test/segmenttree/LazySegmentTree2.test.cpp
  - test/segmenttree/RangeAddRangeSum.test.cpp
  - test/tree/Rerooting.test.cpp
  - test/generator/generate_random_sequence.test.cpp
documentation_of: other/template.hpp
layout: document
redirect_from:
- /library/other/template.hpp
- /library/other/template.hpp.html
title: other/template.hpp
---
