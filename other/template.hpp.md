---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/floor_sqrt.test.cpp
    title: test/math/floor_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "other/template.hpp"

    // clang-format off

    #ifndef MINATO_LOCAL

    #pragma GCC optimize ("Ofast")

    #pragma GCC optimize ("unroll-loops")

    #endif

    #include <bits/stdc++.h>

    using namespace std;

    using uint = unsigned int;

    using ll = long long;

    using ull = unsigned long long;

    using pii = pair<int, int>;

    using pll = pair<long long, long long>;

    template <class T> using vec = vector<T>;

    template <class T> using vvec = vector<vector<T>>;

    #define rep(i, n) for (int i = 0; i < (n); i++)

    #define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)

    #define all(x) begin(x), end(x)

    constexpr char ln = ''\n'';

    template <class Container> inline int SZ(const Container& v) { return int(v.size());
    }

    template <class T> inline void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(),
    v.end()), v.end()); }

    template <class T1, class T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a
    = b; return true; } return false; }

    template <class T1, class T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a
    = b; return true; } return false; }

    inline int topbit(ull x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }

    inline int botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x); }

    inline int popcount(ull x) { return __builtin_popcountll(x); }

    inline int kthbit(ull x, int k) { return (x >> k) & 1; }

    inline constexpr long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }

    const string YESNO[2] = {"NO", "YES"};

    const string YesNo[2] = {"No", "Yes"};

    inline void YES(bool t = true) { cout << YESNO[t] << "\n"; }

    inline void Yes(bool t = true) { cout << YesNo[t] << "\n"; }

    template <class T> inline void drop(T x) { cout << x << "\n"; exit(0); }

    inline void print() { cout << "\n"; }

    template <class T> inline void print(const vector<T>& v) { for (auto it = v.begin();
    it != v.end(); ++it) { if (it != v.begin()) { cout << " "; } cout << *it; } print();
    }

    template <class T, class... Args> inline void print(const T& x, const Args& ...
    args) { cout << x << " "; print(args...); }

    #ifdef MINATO_LOCAL

    template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p)
    { return os << "(" << p.first << ", " << p.second << ")"; }

    template <size_t N, class TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os;
    (void)_; }

    template <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream
    &os, TUPLE t) { os << (N == 0 ? "" : ", ") << get<N>(t); debug_tuple<N + 1, TUPLE,
    Args...>(os, t); }

    template <class ...Args> ostream& operator<<(ostream& os, tuple<Args...> t) {
    os << "("; debug_tuple<0, tuple<Args...>, Args...>(os, t); return os << ")"; }

    string debug_delim(int& i) { return i++ == 0 ? "" : ", "; }

    #define debug_embrace(x) { int i = 0; os << "{";  { x } return os << "}"; }

    template <class T> ostream& operator<<(ostream& os, vector<T> v) { debug_embrace(
    for (T e : v) { os << debug_delim(i) << e; } ) }

    template <class T, size_t N> ostream& operator<<(ostream& os, array<T, N> a) {
    debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }

    template <class T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>&
    operator<<(ostream& os, T(&a)[N]) { debug_embrace( for (T e : a) { os << debug_delim(i)
    << e; } ) }

    template <class Key> ostream& operator<<(ostream& os, set<Key> s) { debug_embrace(
    for (Key e : s) { os << debug_delim(i) << e; }) }

    template <class Key, class T> ostream& operator<<(ostream& os, map<Key, T> mp)
    { debug_embrace( for (auto e : mp) { os << debug_delim(i) << e; }) }

    template <class Key> ostream& operator<<(ostream& os, multiset<Key> s) { debug_embrace(
    for (Key e : s) { os << debug_delim(i) << e; }) }

    template <class T> ostream& operator<<(ostream& os, queue<T> q) { debug_embrace(
    for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.front(); } ) }

    template <class T> ostream& operator<<(ostream& os, deque<T> q) { debug_embrace(
    for (T e : q) { os << debug_delim(i) << e; } ) }

    template <class T> ostream& operator<<(ostream& os, priority_queue<T> q) { debug_embrace(
    for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }

    template <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>,
    greater<T>> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i)
    << q.top(); } ) }

    void debug_out() { cerr << endl; }

    template <class T, class... Args> void debug_out(const T& x, const Args& ... args)
    { cerr << " " << x; debug_out(args...); }

    #define debug(...) cerr << __LINE__ << " : [" << #__VA_ARGS__ << "] =", debug_out(__VA_ARGS__)

    #else

    #define debug(...) (void(0))

    #endif

    struct fast_ios { fast_ios() { cin.tie(nullptr); ios::sync_with_stdio(false);
    cout << fixed << setprecision(20); cerr << fixed << setprecision(7); }; } fast_ios_;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // clang-format on

    '
  code: '// clang-format off

    #ifndef MINATO_LOCAL

    #pragma GCC optimize ("Ofast")

    #pragma GCC optimize ("unroll-loops")

    #endif

    #include <bits/stdc++.h>

    using namespace std;

    using uint = unsigned int;

    using ll = long long;

    using ull = unsigned long long;

    using pii = pair<int, int>;

    using pll = pair<long long, long long>;

    template <class T> using vec = vector<T>;

    template <class T> using vvec = vector<vector<T>>;

    #define rep(i, n) for (int i = 0; i < (n); i++)

    #define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)

    #define all(x) begin(x), end(x)

    constexpr char ln = ''\n'';

    template <class Container> inline int SZ(const Container& v) { return int(v.size());
    }

    template <class T> inline void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(),
    v.end()), v.end()); }

    template <class T1, class T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a
    = b; return true; } return false; }

    template <class T1, class T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a
    = b; return true; } return false; }

    inline int topbit(ull x) { return x == 0 ? -1 : 63 - __builtin_clzll(x); }

    inline int botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x); }

    inline int popcount(ull x) { return __builtin_popcountll(x); }

    inline int kthbit(ull x, int k) { return (x >> k) & 1; }

    inline constexpr long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }

    const string YESNO[2] = {"NO", "YES"};

    const string YesNo[2] = {"No", "Yes"};

    inline void YES(bool t = true) { cout << YESNO[t] << "\n"; }

    inline void Yes(bool t = true) { cout << YesNo[t] << "\n"; }

    template <class T> inline void drop(T x) { cout << x << "\n"; exit(0); }

    inline void print() { cout << "\n"; }

    template <class T> inline void print(const vector<T>& v) { for (auto it = v.begin();
    it != v.end(); ++it) { if (it != v.begin()) { cout << " "; } cout << *it; } print();
    }

    template <class T, class... Args> inline void print(const T& x, const Args& ...
    args) { cout << x << " "; print(args...); }

    #ifdef MINATO_LOCAL

    template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p)
    { return os << "(" << p.first << ", " << p.second << ")"; }

    template <size_t N, class TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os;
    (void)_; }

    template <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream
    &os, TUPLE t) { os << (N == 0 ? "" : ", ") << get<N>(t); debug_tuple<N + 1, TUPLE,
    Args...>(os, t); }

    template <class ...Args> ostream& operator<<(ostream& os, tuple<Args...> t) {
    os << "("; debug_tuple<0, tuple<Args...>, Args...>(os, t); return os << ")"; }

    string debug_delim(int& i) { return i++ == 0 ? "" : ", "; }

    #define debug_embrace(x) { int i = 0; os << "{";  { x } return os << "}"; }

    template <class T> ostream& operator<<(ostream& os, vector<T> v) { debug_embrace(
    for (T e : v) { os << debug_delim(i) << e; } ) }

    template <class T, size_t N> ostream& operator<<(ostream& os, array<T, N> a) {
    debug_embrace( for (T e : a) { os << debug_delim(i) << e; } ) }

    template <class T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>&
    operator<<(ostream& os, T(&a)[N]) { debug_embrace( for (T e : a) { os << debug_delim(i)
    << e; } ) }

    template <class Key> ostream& operator<<(ostream& os, set<Key> s) { debug_embrace(
    for (Key e : s) { os << debug_delim(i) << e; }) }

    template <class Key, class T> ostream& operator<<(ostream& os, map<Key, T> mp)
    { debug_embrace( for (auto e : mp) { os << debug_delim(i) << e; }) }

    template <class Key> ostream& operator<<(ostream& os, multiset<Key> s) { debug_embrace(
    for (Key e : s) { os << debug_delim(i) << e; }) }

    template <class T> ostream& operator<<(ostream& os, queue<T> q) { debug_embrace(
    for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.front(); } ) }

    template <class T> ostream& operator<<(ostream& os, deque<T> q) { debug_embrace(
    for (T e : q) { os << debug_delim(i) << e; } ) }

    template <class T> ostream& operator<<(ostream& os, priority_queue<T> q) { debug_embrace(
    for (; !q.empty(); q.pop()) { os << debug_delim(i) << q.top(); } ) }

    template <class T> ostream& operator<<(ostream& os, priority_queue<T, vector<T>,
    greater<T>> q) { debug_embrace( for (; !q.empty(); q.pop()) { os << debug_delim(i)
    << q.top(); } ) }

    void debug_out() { cerr << endl; }

    template <class T, class... Args> void debug_out(const T& x, const Args& ... args)
    { cerr << " " << x; debug_out(args...); }

    #define debug(...) cerr << __LINE__ << " : [" << #__VA_ARGS__ << "] =", debug_out(__VA_ARGS__)

    #else

    #define debug(...) (void(0))

    #endif

    struct fast_ios { fast_ios() { cin.tie(nullptr); ios::sync_with_stdio(false);
    cout << fixed << setprecision(20); cerr << fixed << setprecision(7); }; } fast_ios_;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // clang-format on

    '
  dependsOn: []
  isVerificationFile: false
  path: other/template.hpp
  requiredBy: []
  timestamp: '2023-01-25 18:02:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/template.test.cpp
  - test/math/floor_sqrt.test.cpp
documentation_of: other/template.hpp
layout: document
redirect_from:
- /library/other/template.hpp
- /library/other/template.hpp.html
title: other/template.hpp
---
