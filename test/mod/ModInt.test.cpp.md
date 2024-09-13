---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/ModInt.hpp
    title: mod/ModInt.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: other/type_traits.hpp
    title: other/type_traits.hpp
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
  bundledCode: "#line 1 \"test/mod/ModInt.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"other/template.hpp\"\n// clang-format off\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <deque>\n#include\
    \ <forward_list>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\nusing uint = unsigned\
    \ int;\nusing ll = long long;\nusing ull = unsigned long long;\nusing i128 = __int128_t;\n\
    using ld = long double;\nusing pii = pair<int, int>;\nusing pll = pair<long long,\
    \ long long>;\ntemplate <class T> using maxheap = priority_queue<T>;\ntemplate\
    \ <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;\ntemplate\
    \ <class T> using vec = vector<T>;\ntemplate <class T> using vvec = vector<vector<T>>;\n\
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
    \ T> T ABS(T x) { return max(x, -x); }\ntemplate <class T> constexpr T POW(T x,\
    \ ull n) { T ret = 1; while (n > 0) { if (n & 1) ret *= x; x *= x; n >>= 1; }\
    \ return ret; }\ntemplate <class T> constexpr T POW(T x, ull n, T mod) { T ret\
    \ = 1; while (n > 0) { if (n & 1) ret = ret * x % mod; x = x * x % mod; n >>=\
    \ 1; } return ret; }\nconstexpr long long floor_div(long long n, long long d)\
    \ { return n / d - ((n ^ d) < 0 && n % d); }\ntemplate <class T1, class T2> bool\
    \ chmax(T1& a, T2 b) { if (a < b) { a = b; return true; } return false; }\ntemplate\
    \ <class T1, class T2> bool chmin(T1& a, T2 b) { if (a > b) { a = b; return true;\
    \ } return false; }\nint topbit(ull x) { return x == 0 ? -1 : 63 - __builtin_clzll(x);\
    \ }\nint botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x); }\nint popcount(ull\
    \ x) { return __builtin_popcountll(x); }\nint kthbit(ull x, int k) { return (x\
    \ >> k) & 1; }\nint popparity(ull x) { return __builtin_parityll(x); }\nint parity_sign(ull\
    \ x) { return (x & 1) ? -1 : 1; }\nconstexpr long long TEN(int x) { return x ==\
    \ 0 ? 1 : TEN(x - 1) * 10; }\ntemplate <typename S> void rearrange(const vector<S>&\
    \ id) { (void)id; }\ntemplate <typename S, typename T> void rearrange_exec(const\
    \ vector<S>& id, vector<T>& v) { vector<T> w(v.size()); for (size_t i = 0; i <\
    \ id.size(); i++) { w[i] = v[id[i]]; } v.swap(w); }\ntemplate <typename S, typename\
    \ Head, typename... Tail> void rearrange(const vector<S>& id, Head& a, Tail& ...tail)\
    \ { rearrange_exec(id, a); rearrange(id, tail...); }\ntemplate <class T>\nvector<vector<T>>\
    \ rot90(const vector<vector<T>>& v) {\n    int n = v.size(), m = v[0].size();\n\
    \    vector<vector<T>> ret(m, vector<T>(n));\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j = 0; j < m; j++) {\n            ret[m - 1 - j][i] = v[i][j];\n\
    \        }\n    }\n    return ret;\n}\nistream& operator>>(istream& is, __int128_t&\
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
    \ { scan(head); IN(tail...); }\nstd::vector<std::vector<int>> read_graph(int N,\
    \ int M) {\n    std::vector<std::vector<int>> g(N);\n    for (int i = 0; i < M;\
    \ i++) {\n        int a, b;\n        cin >> a >> b;\n        a--, b--;\n     \
    \   g[a].emplace_back(b);\n        g[b].emplace_back(a);\n    }\n    return g;\n\
    }\nstd::vector<std::vector<int>> read_tree(int N) { return read_graph(N, N - 1);\
    \ }\nvoid print() { cout << \"\\n\"; }\ntemplate <class T> void print(const vector<T>&\
    \ v) { for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) {\
    \ cout << \" \"; } cout << *it; } print(); }\ntemplate <class T, class... Args>\
    \ void print(const T& x, const Args& ... args) { cout << x; if (sizeof...(Args))\
    \ cout << \" \"; print(args...); }\n#ifdef MINATO_LOCAL\ntemplate <class T1, class\
    \ T2> ostream& operator<<(ostream& os, pair<T1, T2> p);\ntemplate <class ...Args>\
    \ ostream& operator<<(ostream& os, tuple<Args...> t);\ntemplate <class T> ostream&\
    \ operator<<(ostream& os, vector<T> v);\ntemplate <class T, size_t N> ostream&\
    \ operator<<(ostream& os, array<T, N> a);\ntemplate <class T, size_t N> enable_if_t<!is_same_v<char,\
    \ remove_cv_t<T>>, ostream>& operator<<(ostream& os, T(&a)[N]);\ntemplate <class\
    \ Key> ostream& operator<<(ostream& os, set<Key> s);\ntemplate <class Key, class\
    \ T> ostream& operator<<(ostream& os, map<Key, T> mp);\ntemplate <class Key> ostream&\
    \ operator<<(ostream& os, multiset<Key> s);\ntemplate <class T> ostream& operator<<(ostream&\
    \ os, queue<T> q);\ntemplate <class T> ostream& operator<<(ostream& os, deque<T>\
    \ q);\ntemplate <class T> ostream& operator<<(ostream& os, priority_queue<T> q);\n\
    template <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>,\
    \ greater<T>> q);\ntemplate <class T1, class T2> ostream& operator<<(ostream&\
    \ os, pair<T1, T2> p) { return os << \"(\" << p.first << \", \" << p.second <<\
    \ \")\"; }\ntemplate <size_t N, class TUPLE> void debug_tuple(ostream& os, TUPLE\
    \ _) { (void)os; (void)_; }\ntemplate <size_t N, class TUPLE, class T, class ...Args>\
    \ void debug_tuple(ostream &os, TUPLE t) { os << (N == 0 ? \"\" : \", \") << get<N>(t);\
    \ debug_tuple<N + 1, TUPLE, Args...>(os, t); }\ntemplate <class ...Args> ostream&\
    \ operator<<(ostream& os, tuple<Args...> t) { os << \"(\"; debug_tuple<0, tuple<Args...>,\
    \ Args...>(os, t); return os << \")\"; }\nstring debug_delim(int& i) { return\
    \ i++ == 0 ? \"\" : \", \"; }\n#define debug_embrace(x) { int i = 0; os << \"\
    {\";  { x } return os << \"}\"; }\ntemplate <class T> ostream& operator<<(ostream&\
    \ os, vector<T> v) { debug_embrace( for (T e : v) { os << debug_delim(i) << e;\
    \ } ) }\ntemplate <class T, size_t N> ostream& operator<<(ostream& os, array<T,\
    \ N> a) { debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }\ntemplate\
    \ <class T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>&\
    \ operator<<(ostream& os, T(&a)[N]) { debug_embrace( for (T e : a) { os << debug_delim(i)\
    \ << e; } ) }\ntemplate <class Key> ostream& operator<<(ostream& os, set<Key>\
    \ s) { debug_embrace( for (Key e : s) { os << debug_delim(i) << e; }) }\ntemplate\
    \ <class Key, class T> ostream& operator<<(ostream& os, map<Key, T> mp) { debug_embrace(\
    \ for (auto e : mp) { os << debug_delim(i) << e; }) }\ntemplate <class Key> ostream&\
    \ operator<<(ostream& os, multiset<Key> s) { debug_embrace( for (Key e : s) {\
    \ os << debug_delim(i) << e; }) }\ntemplate <class T> ostream& operator<<(ostream&\
    \ os, queue<T> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i)\
    \ << q.front(); } ) }\ntemplate <class T> ostream& operator<<(ostream& os, deque<T>\
    \ q) { debug_embrace( for (T e : q) { os << debug_delim(i) << e; } ) }\ntemplate\
    \ <class T> ostream& operator<<(ostream& os, priority_queue<T> q) { debug_embrace(\
    \ for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }\ntemplate\
    \ <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>>\
    \ q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top();\
    \ } ) }\nvoid debug_out() { cerr << endl; }\ntemplate <class T, class... Args>\
    \ void debug_out(const T& x, const Args& ... args) { cerr << \" \" << x; debug_out(args...);\
    \ }\n#define debug(...) cerr << __LINE__ << \" : [\" << #__VA_ARGS__ << \"] =\"\
    , debug_out(__VA_ARGS__)\nvoid debug_table(const std::vector<std::vector<int>>&\
    \ table) {\n    for (const auto& row : table) {\n        for (const auto& cell\
    \ : row) {\n            cerr << cell << \"\\t\";\n        }\n        cerr << endl;\n\
    \    }\n}\n#else\n#define debug(...) (void(0))\nvoid debug_table(const std::vector<std::vector<int>>&\
    \ table) { (void)table; }\n#endif\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\
    // clang-format on\n#line 2 \"mod/ModInt.hpp\"\n\n#line 2 \"other/type_traits.hpp\"\
    \n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n#line 4 \"mod/ModInt.hpp\"\n\n#line 6 \"mod/ModInt.hpp\"\
    \n\ntemplate <int m> struct ModInt {\n  public:\n    static constexpr int mod()\
    \ {\n        return m;\n    }\n    static ModInt raw(int v) {\n        ModInt\
    \ x;\n        x._v = v;\n        return x;\n    }\n\n    ModInt() : _v(0) {\n\
    \    }\n\n    template <class T, internal::is_signed_int_t<T>* = nullptr> ModInt(T\
    \ v) {\n        long long x = (long long)(v % (long long)(umod()));\n        if\
    \ (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n    template <class\
    \ T, internal::is_unsigned_int_t<T>* = nullptr> ModInt(T v) {\n        _v = (unsigned\
    \ int)(v % umod());\n    }\n\n    unsigned int val() const {\n        return _v;\n\
    \    }\n\n    ModInt& operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    ModInt& operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    ModInt\
    \ operator++(int) {\n        ModInt result = *this;\n        ++*this;\n      \
    \  return result;\n    }\n    ModInt operator--(int) {\n        ModInt result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    ModInt& operator+=(const\
    \ ModInt& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    ModInt& operator-=(const ModInt& rhs) {\n \
    \       _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return\
    \ *this;\n    }\n    ModInt& operator*=(const ModInt& rhs) {\n        unsigned\
    \ long long z = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n\
    \        return *this;\n    }\n    ModInt& operator^=(long long n) {\n       \
    \ ModInt x = *this;\n        *this = 1;\n        if (n < 0) x = x.inv(), n = -n;\n\
    \        while (n) {\n            if (n & 1) *this *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return *this;\n    }\n    ModInt& operator/=(const\
    \ ModInt& rhs) {\n        return *this = *this * rhs.inv();\n    }\n\n    ModInt\
    \ operator+() const {\n        return *this;\n    }\n    ModInt operator-() const\
    \ {\n        return ModInt() - *this;\n    }\n    explicit operator bool() const\
    \ {\n        return _v != 0;\n    }\n\n    ModInt pow(long long n) const {\n \
    \       ModInt r = *this;\n        r ^= n;\n        return r;\n    }\n    ModInt\
    \ inv() const {\n        int a = _v, b = umod(), y = 1, z = 0, t;\n        for\
    \ (;;) {\n            t = a / b;\n            a -= t * b;\n            if (a ==\
    \ 0) {\n                assert(b == 1 || b == -1);\n                return ModInt(b\
    \ * z);\n            }\n            y -= t * z;\n            t = b / a;\n    \
    \        b -= t * a;\n            if (b == 0) {\n                assert(a == 1\
    \ || a == -1);\n                return ModInt(a * y);\n            }\n       \
    \     z -= t * y;\n        }\n    }\n\n    friend ModInt operator+(const ModInt&\
    \ lhs, const ModInt& rhs) {\n        return ModInt(lhs) += rhs;\n    }\n    friend\
    \ ModInt operator-(const ModInt& lhs, const ModInt& rhs) {\n        return ModInt(lhs)\
    \ -= rhs;\n    }\n    friend ModInt operator*(const ModInt& lhs, const ModInt&\
    \ rhs) {\n        return ModInt(lhs) *= rhs;\n    }\n    friend ModInt operator/(const\
    \ ModInt& lhs, const ModInt& rhs) {\n        return ModInt(lhs) /= rhs;\n    }\n\
    \    friend ModInt operator^(const ModInt& lhs, long long rhs) {\n        return\
    \ ModInt(lhs) ^= rhs;\n    }\n    friend bool operator==(const ModInt& lhs, const\
    \ ModInt& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ ModInt& lhs, const ModInt& rhs) {\n        return lhs._v != rhs._v;\n    }\n\
    \    friend ModInt operator+(long long lhs, const ModInt& rhs) {\n        return\
    \ (ModInt(lhs) += rhs);\n    }\n    friend ModInt operator-(long long lhs, const\
    \ ModInt& rhs) {\n        return (ModInt(lhs) -= rhs);\n    }\n    friend ModInt\
    \ operator*(long long lhs, const ModInt& rhs) {\n        return (ModInt(lhs) *=\
    \ rhs);\n    }\n    friend ostream& operator<<(ostream& os, const ModInt& M) {\n\
    \        return os << M._v;\n    }\n    friend istream& operator>>(istream& is,\
    \ ModInt& M) {\n        long long x;\n        is >> x;\n        M = x;\n     \
    \   return is;\n    }\n\n  private:\n    unsigned int _v;\n    static constexpr\
    \ unsigned int umod() {\n        return m;\n    }\n};\n#line 4 \"test/mod/ModInt.test.cpp\"\
    \n\nvoid aplusb() {\n    INT(A, B);\n    print(A + B);\n}\nusing mint = ModInt<11>;\n\
    \nint main() {\n    mint a = 10;\n    mint b(3);\n\n    // equal\n    assert(a\
    \ == 21);\n    assert(a == -1);\n    assert(-1 == a);\n\n    // negative\n   \
    \ assert(-b == 8);\n\n    // plus\n    assert(a + b == 2);  // (10 + 3) mod 11\n\
    \    assert(1 + a == 0);\n\n    // minus\n    assert(a - b == 7);  // (10 - 3)\
    \ mod 11\n    assert(b - a == 4);\n\n    //++, --\n    b++;\n    assert(b == 4);\n\
    \    b--;\n    assert(b == 3);\n\n    // mul\n    assert(a * b == 8);  // (10\
    \ * 3) mod 11\n\n    // inv\n    assert(b.inv() == 4);  // (3 * 4) mod 11 == 1\n\
    \n    // div\n    assert(a / b == 7);  // (10 * 4) mod 11\n\n    // +=, -=, *=,\
    \ /=\n    a += b;\n    assert(a == 2 && b == 3);\n    a -= b;\n    assert(a ==\
    \ 10 && b == 3);\n    a *= b;\n    assert(a == 8 && b == 3);\n    a /= b;\n  \
    \  assert(a == 10 && b == 3);\n\n    // pow\n    assert(mint(2).pow(4) == 5);\
    \  // 16 mod 11\n\n    // ^=\n    mint c = 2;\n    c ^= 4;\n    assert(c == 5);\n\
    \    c ^= -2;\n    assert(c == 4);  // (4 * 25) mod 11 == 1\n\n    // get mod\n\
    \    assert(mint::mod() == 11 && a.mod() == 11);\n\n    // mint(x) \u3068\u66F8\
    \u304F\u3068mod\u3092\u53D6\u308B\u64CD\u4F5C\u304C\u767A\u751F\u3057\u307E\u3059\
    ((x % mod + mod) %\n    // mod\u3092modint\u306B\u4EE3\u5165\u3057\u307E\u3059\
    ) mint::raw(x)\n    // \u306Fx\u3092mod\u3092\u53D6\u3089\u305A\u306B\u4EE3\u5165\
    \u3059\u308B\u306E\u3067\u9AD8\u901F\u3067\u3059(\u3082\u3061\u308D\u3093x\u304C\
    [0,\n    // mod)\u3067\u3042\u308B\u3053\u3068\u3092\u5229\u7528\u8005\u304C\u4FDD\
    \u8A3C\u3057\u306A\u3044\u3068\u3044\u3051\u307E\u305B\u3093)\n    assert(mint::raw(3)\
    \ == 3);\n    aplusb();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"other/template.hpp\"\
    \n#include \"mod/ModInt.hpp\"\n\nvoid aplusb() {\n    INT(A, B);\n    print(A\
    \ + B);\n}\nusing mint = ModInt<11>;\n\nint main() {\n    mint a = 10;\n    mint\
    \ b(3);\n\n    // equal\n    assert(a == 21);\n    assert(a == -1);\n    assert(-1\
    \ == a);\n\n    // negative\n    assert(-b == 8);\n\n    // plus\n    assert(a\
    \ + b == 2);  // (10 + 3) mod 11\n    assert(1 + a == 0);\n\n    // minus\n  \
    \  assert(a - b == 7);  // (10 - 3) mod 11\n    assert(b - a == 4);\n\n    //++,\
    \ --\n    b++;\n    assert(b == 4);\n    b--;\n    assert(b == 3);\n\n    // mul\n\
    \    assert(a * b == 8);  // (10 * 3) mod 11\n\n    // inv\n    assert(b.inv()\
    \ == 4);  // (3 * 4) mod 11 == 1\n\n    // div\n    assert(a / b == 7);  // (10\
    \ * 4) mod 11\n\n    // +=, -=, *=, /=\n    a += b;\n    assert(a == 2 && b ==\
    \ 3);\n    a -= b;\n    assert(a == 10 && b == 3);\n    a *= b;\n    assert(a\
    \ == 8 && b == 3);\n    a /= b;\n    assert(a == 10 && b == 3);\n\n    // pow\n\
    \    assert(mint(2).pow(4) == 5);  // 16 mod 11\n\n    // ^=\n    mint c = 2;\n\
    \    c ^= 4;\n    assert(c == 5);\n    c ^= -2;\n    assert(c == 4);  // (4 *\
    \ 25) mod 11 == 1\n\n    // get mod\n    assert(mint::mod() == 11 && a.mod() ==\
    \ 11);\n\n    // mint(x) \u3068\u66F8\u304F\u3068mod\u3092\u53D6\u308B\u64CD\u4F5C\
    \u304C\u767A\u751F\u3057\u307E\u3059((x % mod + mod) %\n    // mod\u3092modint\u306B\
    \u4EE3\u5165\u3057\u307E\u3059) mint::raw(x)\n    // \u306Fx\u3092mod\u3092\u53D6\
    \u3089\u305A\u306B\u4EE3\u5165\u3059\u308B\u306E\u3067\u9AD8\u901F\u3067\u3059\
    (\u3082\u3061\u308D\u3093x\u304C[0,\n    // mod)\u3067\u3042\u308B\u3053\u3068\
    \u3092\u5229\u7528\u8005\u304C\u4FDD\u8A3C\u3057\u306A\u3044\u3068\u3044\u3051\
    \u307E\u305B\u3093)\n    assert(mint::raw(3) == 3);\n    aplusb();\n}"
  dependsOn:
  - other/template.hpp
  - mod/ModInt.hpp
  - other/type_traits.hpp
  isVerificationFile: true
  path: test/mod/ModInt.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mod/ModInt.test.cpp
layout: document
redirect_from:
- /verify/test/mod/ModInt.test.cpp
- /verify/test/mod/ModInt.test.cpp.html
title: test/mod/ModInt.test.cpp
---
