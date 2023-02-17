---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: segmenttree/DualSegmentTree.hpp
    title: segmenttree/DualSegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/segmenttree/DualSegmentTree.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#line 1 \"other/template.hpp\"\n// clang-format off\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing uint = unsigned int;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<long long, long long>;\ntemplate <class T> using maxheap = priority_queue<T>;\n\
    template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;\n\
    template <class T> using vec = vector<T>;\ntemplate <class T> using vvec = vector<vector<T>>;\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP0(n) for (auto minato\
    \ = decay_t<decltype(n)>{}; minato < (n); ++minato)\n#define REP1(i, n) for (auto\
    \ i = decay_t<decltype(n)>{}; (i) < (n); (i)++)\n#define REP2(i, l, r) for (auto\
    \ i = (l); (i) < (r); (i)++)\n#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2,\
    \ REP1, REP0)(__VA_ARGS__)\n#define OVERLOAD_RREP(_1, _2, _3, name, ...) name\n\
    #define RREP1(i, n) for (auto i = (n) - 1; (i) >= decay_t<decltype(n)>{}; (i)--)\n\
    #define RREP2(i, l, r) for (auto i = (r) - 1; (i) >= (l); (i)--)\n#define rrep(...)\
    \ OVERLOAD_RREP(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)\n#define all(x) begin(x),\
    \ end(x)\ntemplate <class Container> int SZ(const Container& v) { return int(v.size());\
    \ }\ntemplate <class T> void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(),\
    \ v.end()), v.end()); }\ntemplate <class T> T MAX(const vector<T>& v) { return\
    \ *max_element(v.begin(), v.end()); }\ntemplate <class T> T MIN(const vector<T>&\
    \ v) { return *min_element(v.begin(), v.end()); }\ntemplate <class T> T SUM(const\
    \ vector<T>& v) { return accumulate(v.begin(), v.end(), T(0)); }\ntemplate <class\
    \ T1, class T2> bool chmax(T1& a, T2 b) { if (a < b) { a = b; return true; } return\
    \ false; }\ntemplate <class T1, class T2> bool chmin(T1& a, T2 b) { if (a > b)\
    \ { a = b; return true; } return false; }\nint topbit(ull x) { return x == 0 ?\
    \ -1 : 63 - __builtin_clzll(x); }\nint botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x);\
    \ }\nint popcount(ull x) { return __builtin_popcountll(x); }\nint kthbit(ull x,\
    \ int k) { return (x >> k) & 1; }\nconstexpr long long TEN(int x) { return x ==\
    \ 0 ? 1 : TEN(x - 1) * 10; }\ntemplate <typename S> void rearrange(const vector<S>&\
    \ id) {}\ntemplate <typename S, typename T> void rearrange_exec(const vector<S>&\
    \ id, vector<T>& v) { vector<T> w(v.size()); for (size_t i = 0; i < id.size();\
    \ i++) { w[i] = v[id[i]]; } v.swap(w); }\ntemplate <typename S, typename Head,\
    \ typename... Tail> void rearrange(const vector<S>& id, Head& a, Tail& ...tail)\
    \ { rearrange_exec(id, a); rearrange(id, tail...); }\nconstexpr char ln = '\\\
    n';\nconst string YESNO[2] = {\"NO\", \"YES\"};\nconst string YesNo[2] = {\"No\"\
    , \"Yes\"};\nvoid YES(bool t = true) { cout << YESNO[t] << \"\\n\"; }\nvoid Yes(bool\
    \ t = true) { cout << YesNo[t] << \"\\n\"; }\ntemplate <class T> void drop(T x)\
    \ { cout << x << \"\\n\"; exit(0); }\n#define INT(...)     \\\n    int __VA_ARGS__;\
    \ \\\n    IN(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n  \
    \  IN(__VA_ARGS__)\n#define STR(...)        \\\n    string __VA_ARGS__; \\\n \
    \   IN(__VA_ARGS__)\n#define CHR(...)      \\\n    char __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n\
    #define LDB(...)             \\\n    long double __VA_ARGS__; \\\n    IN(__VA_ARGS__)\n\
    #define VEC(type, name, size) \\\n    vector<type> name(size);  \\\n    IN(name)\n\
    #define VEC2(type, name1, name2, size)     \\\n    vector<type> name1(size), name2(size);\
    \ \\\n    for (int i = 0; i < size; i++) IN(name1[i], name2[i])\n#define VEC3(type,\
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
    // clang-format on\n#line 1 \"segmenttree/DualSegmentTree.hpp\"\ntemplate <class\
    \ T, class U, class G, class H> struct DualSegmentTree {\n  private:\n    G mapping;\n\
    \    H composition;\n    U id;\n    int _n, size, log;\n    vector<T> node;\n\
    \    vector<U> lazy;\n\n  public:\n    DualSegmentTree() {\n    }\n    DualSegmentTree(const\
    \ G& mapping,\n                    const H& composition,\n                   \
    \ U id,\n                    const vector<T>& v)\n        : mapping(mapping),\n\
    \          composition(composition),\n          id(id),\n          _n(int(v.size())),\n\
    \          log(0) {\n        while ((1 << log) < _n) log++;\n        size = 1\
    \ << log;\n        node.resize(size);\n        for (int i = 0; i < _n; i++) node[i]\
    \ = v[i];\n        lazy = vector<U>(size, id);\n    }\n\n    void set(int p, T\
    \ x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        node[p - size] = x;\n    }\n\n\
    \    void apply(int p, U val) {\n        assert(0 <= p && p < _n);\n        p\
    \ += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        node[p\
    \ - size] =\n            val == id ? node[p - size] : mapping(node[p - size],\
    \ val);\n    }\n\n    void apply(int l, int r, U val) {\n        if (l >= r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, val);\n                if (r & 1) all_apply(--r, val);\n\
    \                l >>= 1;\n                r >>= 1;\n            }\n         \
    \   l = l2;\n            r = r2;\n        }\n    }\n\n    T operator[](int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return node[p - size];\n    }\n\n\
    \  private:\n    void all_apply(int k, U val) {\n        if (k >= size)\n    \
    \        node[k - size] =\n                val == id ? node[k - size] : mapping(node[k\
    \ - size], val);\n        else\n            lazy[k] = composition(lazy[k], val);\n\
    \    }\n\n    void push(int k) {\n        if (lazy[k] == id) return;\n       \
    \ all_apply(2 * k, lazy[k]);\n        all_apply(2 * k + 1, lazy[k]);\n       \
    \ lazy[k] = id;\n    }\n};\n#line 5 \"test/segmenttree/DualSegmentTree.test.cpp\"\
    \nint main() {\n    INT(n, q);\n    auto g = [](int a, int b) {\n        (void)a;\n\
    \        return b;\n    };\n    auto h = [](int a, int b) {\n        (void)a;\n\
    \        return b;\n    };\n    const int id = numeric_limits<int>::max();\n \
    \   vec<int> A(n, numeric_limits<int>::max());\n    DualSegmentTree seg(g, h,\
    \ id, A);\n    rep(q) {\n        INT(t);\n        if (t == 0) {\n            INT(l,\
    \ r, x);\n            seg.apply(l, r + 1, x);\n        } else {\n            INT(i);\n\
    \            print(seg[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include \"other/template.hpp\"\n#include \"segmenttree/DualSegmentTree.hpp\"\
    \nint main() {\n    INT(n, q);\n    auto g = [](int a, int b) {\n        (void)a;\n\
    \        return b;\n    };\n    auto h = [](int a, int b) {\n        (void)a;\n\
    \        return b;\n    };\n    const int id = numeric_limits<int>::max();\n \
    \   vec<int> A(n, numeric_limits<int>::max());\n    DualSegmentTree seg(g, h,\
    \ id, A);\n    rep(q) {\n        INT(t);\n        if (t == 0) {\n            INT(l,\
    \ r, x);\n            seg.apply(l, r + 1, x);\n        } else {\n            INT(i);\n\
    \            print(seg[i]);\n        }\n    }\n}"
  dependsOn:
  - other/template.hpp
  - segmenttree/DualSegmentTree.hpp
  isVerificationFile: true
  path: test/segmenttree/DualSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2023-02-18 02:43:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segmenttree/DualSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/segmenttree/DualSegmentTree.test.cpp
- /verify/test/segmenttree/DualSegmentTree.test.cpp.html
title: test/segmenttree/DualSegmentTree.test.cpp
---
