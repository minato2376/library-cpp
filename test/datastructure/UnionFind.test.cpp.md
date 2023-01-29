---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.hpp
    title: datastructure/UnionFind.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/1054
    links:
    - https://yukicoder.me/problems/no/1054
  bundledCode: "#line 1 \"test/datastructure/UnionFind.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1054\"\n#line 1 \"other/template.hpp\"\n\
    // clang-format off\n#include <bits/stdc++.h>\nusing namespace std;\nusing uint\
    \ = unsigned int;\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ ld = long double;\nusing pii = pair<int, int>;\nusing pll = pair<long long,\
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
    \ OVERLOAD_RREP(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)\n#define all(x) begin(x),\
    \ end(x)\ntemplate <class Container> int SZ(const Container& v) { return int(v.size());\
    \ }\ntemplate <class T> void UNIQUE(vector<T>& v) { v.erase(unique(v.begin(),\
    \ v.end()), v.end()); }\ntemplate <class T> T MAX(const vector<T>& v) { return\
    \ *max_element(v.begin(), v.end()); }\ntemplate <class T> T MIN(const vector<T>&\
    \ v) { return *min_element(v.begin(), v.end()); }\ntemplate <class T> T SUM(const\
    \ vector<T>& v) { return *accumulate(v.begin(), v.end(), T(0)); }\ntemplate <class\
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
    // clang-format on\n#line 2 \"datastructure/UnionFind.hpp\"\n\n/**\n * \u9AD8\u901F\
    \u3001\u7701\u30E1\u30E2\u30EA\u306A\u30B7\u30F3\u30D7\u30EB\u306A UnionFind \u3092\
    \u4F7F\u3044\u305F\u3044\u5834\u5408\u3001atcoder::dsu \u3092\u4F7F\u3046\u3002\
    \n */\nstruct UnionFind {\n  private:\n    int n, group_number;\n    vector<int>\
    \ parent_or_size, nex;\n\n  public:\n    UnionFind() : n(0), group_number(0) {\n\
    \    }\n    UnionFind(int n) : n(n), group_number(n), parent_or_size(n, -1), nex(n)\
    \ {\n        iota(nex.begin(), nex.end(), 0);\n    }\n\n    int size() const {\n\
    \        return n;\n    }\n\n    /**\n     * \u9023\u7D50\u6210\u5206\u306E\u500B\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\u3002\n     */\n    int count() const {\n\
    \        return group_number;\n    }\n\n    bool merge(int x, int y) {\n     \
    \   assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n        x =\
    \ root_(x);\n        y = root_(y);\n        if (x == y) return false;\n      \
    \  if (parent_or_size[x] > parent_or_size[y]) swap(x, y);\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        swap(nex[x],\
    \ nex[y]);\n        group_number--;\n        return true;\n    }\n\n    /**\n\
    \     * @param f void f(int parent, int child)\n     * \u30DE\u30FC\u30B8\u3059\
    \u308B\u969B\u306E\u51E6\u7406\u3092\u884C\u3046\u95A2\u6570\u3092\u6E21\u3059\
    \u3002\n     */\n    template <class F> bool merge(int x, int y, const F& f) {\n\
    \        assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n      \
    \  x = root_(x);\n        y = root_(y);\n        if (x == y) return false;\n \
    \       if (parent_or_size[x] > parent_or_size[y]) swap(x, y);\n        f(x, y);\n\
    \        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y] =\
    \ x;\n        swap(nex[x], nex[y]);\n        group_number--;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) {\n        assert(0 <= x and x < n);\n \
    \       assert(0 <= y and y < n);\n        return root_(x) == root_(y);\n    }\n\
    \n    int root(int x) {\n        assert(0 <= x and x < n);\n        return root_(x);\n\
    \    }\n\n    /**\n     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\u3002\n     */\n    int size(int\
    \ x) {\n        assert(0 <= x and x < n);\n        return -parent_or_size[root_(x)];\n\
    \    }\n\n    /**\n     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u3002\n     * root(x) \u3068\u540C\
    \u3058\u3002\n     */\n    int operator[](int x) {\n        assert(0 <= x and\
    \ x < n);\n        return root_(x);\n    }\n\n    vector<vector<int>> groups()\
    \ {\n        vector<int> leader_buf(n), group_size(n);\n        for (int i = 0;\
    \ i < n; i++) {\n            leader_buf[i] = root(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        vector<vector<int>> result(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            result[i].reserve(group_size[i]);\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(remove_if(result.begin(), result.end(),\n   \
    \                            [&](const vector<int>& v) { return v.empty(); }),\n\
    \                     result.end());\n        return result;\n    }\n\n    /**\n\
    \     * \u9802\u70B9 x \u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u9802\
    \u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\n     * O(size(x))\n\
    \     */\n    vector<int> group(int x) const {\n        assert(0 <= x and x <\
    \ n);\n        vector<int> ret;\n        int v = x;\n        do {\n          \
    \  ret.emplace_back(v);\n            v = nex[v];\n        } while (v != x);\n\
    \        return ret;\n    }\n\n  private:\n    int root_(int x) {\n        if\
    \ (parent_or_size[x] < 0) return x;\n        return parent_or_size[x] = root_(parent_or_size[x]);\n\
    \    }\n};\n#line 4 \"test/datastructure/UnionFind.test.cpp\"\n\nvoid solve()\
    \ {\n    INT(N, Q);\n    UnionFind uf(N);\n    vec<ll> D(N);\n    vec<ll> A(N);\n\
    \    auto f = [&](int r, int c) {\n        auto vs = uf.group(c);\n        for\
    \ (auto v : vs) {\n            A[v] += D[c] - D[r];\n        }\n    };\n    rep(Q)\
    \ {\n        INT(t, a, b);\n        if (t == 1) {\n            a--;\n        \
    \    b--;\n            uf.merge(a, b, f);\n        } else if (t == 2) {\n    \
    \        a--;\n            D[uf.root(a)] += b;\n        } else {\n           \
    \ a--;\n            print(A[a] + D[uf.root(a)]);\n        }\n    }\n}\n\nint main()\
    \ {\n    int T = 1;\n    // cin >> T;\n    for (int i = 0; i < T; i++) {\n   \
    \     solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1054\"\n#include \"other/template.hpp\"\
    \n#include \"datastructure/UnionFind.hpp\"\n\nvoid solve() {\n    INT(N, Q);\n\
    \    UnionFind uf(N);\n    vec<ll> D(N);\n    vec<ll> A(N);\n    auto f = [&](int\
    \ r, int c) {\n        auto vs = uf.group(c);\n        for (auto v : vs) {\n \
    \           A[v] += D[c] - D[r];\n        }\n    };\n    rep(Q) {\n        INT(t,\
    \ a, b);\n        if (t == 1) {\n            a--;\n            b--;\n        \
    \    uf.merge(a, b, f);\n        } else if (t == 2) {\n            a--;\n    \
    \        D[uf.root(a)] += b;\n        } else {\n            a--;\n           \
    \ print(A[a] + D[uf.root(a)]);\n        }\n    }\n}\n\nint main() {\n    int T\
    \ = 1;\n    // cin >> T;\n    for (int i = 0; i < T; i++) {\n        solve();\n\
    \    }\n}"
  dependsOn:
  - other/template.hpp
  - datastructure/UnionFind.hpp
  isVerificationFile: true
  path: test/datastructure/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 01:33:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/UnionFind.test.cpp
- /verify/test/datastructure/UnionFind.test.cpp.html
title: test/datastructure/UnionFind.test.cpp
---
