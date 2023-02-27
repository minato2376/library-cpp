---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/SquareRootDecomposition.hpp
    title: "\u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3092\u5206\u5272\u3059\u308B"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3170
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3170
  bundledCode: "#line 1 \"test/algorithm/SquareRootDecomposion.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3170\"\n\
    #line 1 \"other/template.hpp\"\n// clang-format off\n#include <bits/stdc++.h>\n\
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
    // clang-format on\n#line 2 \"algorithm/SquareRootDecomposition.hpp\"\n\ntemplate\
    \ <int W> struct SquareRootDecomposition {\n    struct Ranges {\n        optional<pair<int,\
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
    \ = min((i + 1) * W, n);\n        return {l, r};\n    }\n};\n#line 4 \"test/algorithm/SquareRootDecomposion.test.cpp\"\
    \n\nint main() {\n    constexpr ll INF = TEN(18);\n    INT(N, Q);\n    VEC(ll,\
    \ A, N);\n\n    SquareRootDecomposition<64> decomp(N);\n    auto B = A;\n    vec<ll>\
    \ add(decomp.bucket_size(), 0);\n    vec<ll> mn(decomp.bucket_size(), -INF);\n\
    \    vec<ll> mx(decomp.bucket_size(), INF);\n    // \u8DB3\u3057\u305F\u3042\u3068\
    \u5207\u308A\u8A70\u3081\u308B\n    auto upd = [&](int k) {\n        auto [l,\
    \ r] = decomp.bucket_range(k);\n        rep(i, l, r) A[i] += add[k];\n       \
    \ add[k] = 0;\n        rep(i, l, r) A[i] = clamp(A[i], mn[k], mx[k]);\n      \
    \  rep(i, l, r) B[i] = A[i];\n        sort(B.begin() + l, B.begin() + r);\n  \
    \      mn[k] = -INF;\n        mx[k] = INF;\n    };\n    auto lazy = [&](int k,\
    \ int t, ll x) {\n        if (t == 1) {\n            chmin(mn[k], x);\n      \
    \      chmin(mx[k], x);\n        } else if (t == 2) {\n            chmax(mn[k],\
    \ x);\n            chmax(mx[k], x);\n        } else {\n            add[k] += x;\n\
    \            mn[k] += x;\n            mx[k] += x;\n        }\n    };\n    rep(i,\
    \ decomp.bucket_size()) upd(i);\n    rep(Q) {\n        INT(t);\n        if (t\
    \ == 1) {\n            LL(l, r, x);\n            l--;\n            auto ranges\
    \ = decomp.query(l, r);\n            if (ranges.left_overflow_range) {\n     \
    \           auto [p, q] = ranges.left_overflow_range.value();\n              \
    \  upd(decomp.bucket_id(p));\n                rep(j, p, q) chmin(A[j], x);\n \
    \               upd(decomp.bucket_id(p));\n            }\n            if (ranges.bucket_range)\
    \ {\n                auto [p, q] = ranges.bucket_range.value();\n            \
    \    rep(j, p, q) {\n                    lazy(j, t, x);\n                }\n \
    \           }\n            if (ranges.right_overflow_range) {\n              \
    \  auto [p, q] = ranges.right_overflow_range.value();\n                debug(p,\
    \ q);\n                upd(decomp.bucket_id(p));\n                rep(j, p, q)\
    \ chmin(A[j], x);\n                upd(decomp.bucket_id(p));\n            }\n\
    \        } else if (t == 2) {\n            LL(l, r, x);\n            l--;\n  \
    \          auto ranges = decomp.query(l, r);\n            if (ranges.left_overflow_range)\
    \ {\n                auto [p, q] = ranges.left_overflow_range.value();\n     \
    \           upd(decomp.bucket_id(p));\n                rep(j, p, q) chmax(A[j],\
    \ x);\n                upd(decomp.bucket_id(p));\n            }\n            if\
    \ (ranges.bucket_range) {\n                auto [p, q] = ranges.bucket_range.value();\n\
    \                rep(j, p, q) {\n                    lazy(j, t, x);\n        \
    \        }\n            }\n            if (ranges.right_overflow_range) {\n  \
    \              auto [p, q] = ranges.right_overflow_range.value();\n          \
    \      upd(decomp.bucket_id(p));\n                rep(j, p, q) chmax(A[j], x);\n\
    \                upd(decomp.bucket_id(p));\n            }\n\n        } else if\
    \ (t == 3) {\n            LL(l, r, x);\n            l--;\n            auto ranges\
    \ = decomp.query(l, r);\n            if (ranges.left_overflow_range) {\n     \
    \           auto [p, q] = ranges.left_overflow_range.value();\n              \
    \  upd(decomp.bucket_id(p));\n                rep(j, p, q) A[j] += x;\n      \
    \          upd(decomp.bucket_id(p));\n            }\n            if (ranges.bucket_range)\
    \ {\n                auto [p, q] = ranges.bucket_range.value();\n            \
    \    rep(j, p, q) {\n                    lazy(j, t, x);\n                }\n \
    \           }\n            if (ranges.right_overflow_range) {\n              \
    \  auto [p, q] = ranges.right_overflow_range.value();\n                upd(decomp.bucket_id(p));\n\
    \                rep(j, p, q) A[j] += x;\n                upd(decomp.bucket_id(p));\n\
    \            }\n\n        } else {\n            LL(l, r, x, y);\n            l--;\n\
    \            auto ranges = decomp.query(l, r);\n            int ans = 0;\n   \
    \         if (ranges.left_overflow_range) {\n                auto [p, q] = ranges.left_overflow_range.value();\n\
    \                upd(decomp.bucket_id(p));\n                rep(j, p, q) {\n \
    \                   if (x <= A[j] && A[j] <= y) ans++;\n                }\n  \
    \          }\n            if (ranges.bucket_range) {\n                auto [p,\
    \ q] = ranges.bucket_range.value();\n                rep(j, p, q) {\n        \
    \            if (mn[j] > y || mx[j] < x) continue;\n                    auto [a,\
    \ b] = decomp.bucket_range(j);\n                    int lb =\n               \
    \         lower_bound(B.begin() + a, B.begin() + b, x - add[j]) -\n          \
    \              B.begin();\n                    int ub =\n                    \
    \    upper_bound(B.begin() + a, B.begin() + b, y - add[j]) -\n               \
    \         B.begin();\n                    if (mn[j] >= x) lb = a;\n          \
    \          if (mx[j] <= y) ub = b;\n                    ans += ub - lb;\n    \
    \            }\n            }\n            if (ranges.right_overflow_range) {\n\
    \                auto [p, q] = ranges.right_overflow_range.value();\n        \
    \        upd(decomp.bucket_id(p));\n                rep(j, p, q) {\n         \
    \           if (x <= A[j] && A[j] <= y) ans++;\n                }\n          \
    \  }\n            print(ans);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3170\"\
    \n#include \"other/template.hpp\"\n#include \"algorithm/SquareRootDecomposition.hpp\"\
    \n\nint main() {\n    constexpr ll INF = TEN(18);\n    INT(N, Q);\n    VEC(ll,\
    \ A, N);\n\n    SquareRootDecomposition<64> decomp(N);\n    auto B = A;\n    vec<ll>\
    \ add(decomp.bucket_size(), 0);\n    vec<ll> mn(decomp.bucket_size(), -INF);\n\
    \    vec<ll> mx(decomp.bucket_size(), INF);\n    // \u8DB3\u3057\u305F\u3042\u3068\
    \u5207\u308A\u8A70\u3081\u308B\n    auto upd = [&](int k) {\n        auto [l,\
    \ r] = decomp.bucket_range(k);\n        rep(i, l, r) A[i] += add[k];\n       \
    \ add[k] = 0;\n        rep(i, l, r) A[i] = clamp(A[i], mn[k], mx[k]);\n      \
    \  rep(i, l, r) B[i] = A[i];\n        sort(B.begin() + l, B.begin() + r);\n  \
    \      mn[k] = -INF;\n        mx[k] = INF;\n    };\n    auto lazy = [&](int k,\
    \ int t, ll x) {\n        if (t == 1) {\n            chmin(mn[k], x);\n      \
    \      chmin(mx[k], x);\n        } else if (t == 2) {\n            chmax(mn[k],\
    \ x);\n            chmax(mx[k], x);\n        } else {\n            add[k] += x;\n\
    \            mn[k] += x;\n            mx[k] += x;\n        }\n    };\n    rep(i,\
    \ decomp.bucket_size()) upd(i);\n    rep(Q) {\n        INT(t);\n        if (t\
    \ == 1) {\n            LL(l, r, x);\n            l--;\n            auto ranges\
    \ = decomp.query(l, r);\n            if (ranges.left_overflow_range) {\n     \
    \           auto [p, q] = ranges.left_overflow_range.value();\n              \
    \  upd(decomp.bucket_id(p));\n                rep(j, p, q) chmin(A[j], x);\n \
    \               upd(decomp.bucket_id(p));\n            }\n            if (ranges.bucket_range)\
    \ {\n                auto [p, q] = ranges.bucket_range.value();\n            \
    \    rep(j, p, q) {\n                    lazy(j, t, x);\n                }\n \
    \           }\n            if (ranges.right_overflow_range) {\n              \
    \  auto [p, q] = ranges.right_overflow_range.value();\n                debug(p,\
    \ q);\n                upd(decomp.bucket_id(p));\n                rep(j, p, q)\
    \ chmin(A[j], x);\n                upd(decomp.bucket_id(p));\n            }\n\
    \        } else if (t == 2) {\n            LL(l, r, x);\n            l--;\n  \
    \          auto ranges = decomp.query(l, r);\n            if (ranges.left_overflow_range)\
    \ {\n                auto [p, q] = ranges.left_overflow_range.value();\n     \
    \           upd(decomp.bucket_id(p));\n                rep(j, p, q) chmax(A[j],\
    \ x);\n                upd(decomp.bucket_id(p));\n            }\n            if\
    \ (ranges.bucket_range) {\n                auto [p, q] = ranges.bucket_range.value();\n\
    \                rep(j, p, q) {\n                    lazy(j, t, x);\n        \
    \        }\n            }\n            if (ranges.right_overflow_range) {\n  \
    \              auto [p, q] = ranges.right_overflow_range.value();\n          \
    \      upd(decomp.bucket_id(p));\n                rep(j, p, q) chmax(A[j], x);\n\
    \                upd(decomp.bucket_id(p));\n            }\n\n        } else if\
    \ (t == 3) {\n            LL(l, r, x);\n            l--;\n            auto ranges\
    \ = decomp.query(l, r);\n            if (ranges.left_overflow_range) {\n     \
    \           auto [p, q] = ranges.left_overflow_range.value();\n              \
    \  upd(decomp.bucket_id(p));\n                rep(j, p, q) A[j] += x;\n      \
    \          upd(decomp.bucket_id(p));\n            }\n            if (ranges.bucket_range)\
    \ {\n                auto [p, q] = ranges.bucket_range.value();\n            \
    \    rep(j, p, q) {\n                    lazy(j, t, x);\n                }\n \
    \           }\n            if (ranges.right_overflow_range) {\n              \
    \  auto [p, q] = ranges.right_overflow_range.value();\n                upd(decomp.bucket_id(p));\n\
    \                rep(j, p, q) A[j] += x;\n                upd(decomp.bucket_id(p));\n\
    \            }\n\n        } else {\n            LL(l, r, x, y);\n            l--;\n\
    \            auto ranges = decomp.query(l, r);\n            int ans = 0;\n   \
    \         if (ranges.left_overflow_range) {\n                auto [p, q] = ranges.left_overflow_range.value();\n\
    \                upd(decomp.bucket_id(p));\n                rep(j, p, q) {\n \
    \                   if (x <= A[j] && A[j] <= y) ans++;\n                }\n  \
    \          }\n            if (ranges.bucket_range) {\n                auto [p,\
    \ q] = ranges.bucket_range.value();\n                rep(j, p, q) {\n        \
    \            if (mn[j] > y || mx[j] < x) continue;\n                    auto [a,\
    \ b] = decomp.bucket_range(j);\n                    int lb =\n               \
    \         lower_bound(B.begin() + a, B.begin() + b, x - add[j]) -\n          \
    \              B.begin();\n                    int ub =\n                    \
    \    upper_bound(B.begin() + a, B.begin() + b, y - add[j]) -\n               \
    \         B.begin();\n                    if (mn[j] >= x) lb = a;\n          \
    \          if (mx[j] <= y) ub = b;\n                    ans += ub - lb;\n    \
    \            }\n            }\n            if (ranges.right_overflow_range) {\n\
    \                auto [p, q] = ranges.right_overflow_range.value();\n        \
    \        upd(decomp.bucket_id(p));\n                rep(j, p, q) {\n         \
    \           if (x <= A[j] && A[j] <= y) ans++;\n                }\n          \
    \  }\n            print(ans);\n        }\n    }\n}"
  dependsOn:
  - other/template.hpp
  - algorithm/SquareRootDecomposition.hpp
  isVerificationFile: true
  path: test/algorithm/SquareRootDecomposion.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 18:25:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/SquareRootDecomposion.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/SquareRootDecomposion.test.cpp
- /verify/test/algorithm/SquareRootDecomposion.test.cpp.html
title: test/algorithm/SquareRootDecomposion.test.cpp
---
