---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: datastructure/BinaryIndexedTree.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: segmenttree/PointAddRectangleSum.hpp
    title: segmenttree/PointAddRectangleSum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/segmenttree/PointAddRectangleSum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n#line 1\
    \ \"other/template.hpp\"\n// clang-format off\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
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
    template <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p);\n\
    template <class ...Args> ostream& operator<<(ostream& os, tuple<Args...> t);\n\
    template <class T> ostream& operator<<(ostream& os, vector<T> v);\ntemplate <class\
    \ T, size_t N> ostream& operator<<(ostream& os, array<T, N> a);\ntemplate <class\
    \ T, size_t N> enable_if_t<!is_same_v<char, remove_cv_t<T>>, ostream>& operator<<(ostream&\
    \ os, T(&a)[N]);\ntemplate <class Key> ostream& operator<<(ostream& os, set<Key>\
    \ s);\ntemplate <class Key, class T> ostream& operator<<(ostream& os, map<Key,\
    \ T> mp);\ntemplate <class Key> ostream& operator<<(ostream& os, multiset<Key>\
    \ s);\ntemplate <class T> ostream& operator<<(ostream& os, queue<T> q);\ntemplate\
    \ <class T> ostream& operator<<(ostream& os, deque<T> q);\ntemplate <class T>\
    \ ostream& operator<<(ostream& os, priority_queue<T> q);\ntemplate <class T> ostream&\
    \ operator<<(ostream& os, priority_queue<T, vector<T>, greater<T>> q);\ntemplate\
    \ <class T1, class T2> ostream& operator<<(ostream& os, pair<T1, T2> p) { return\
    \ os << \"(\" << p.first << \", \" << p.second << \")\"; }\ntemplate <size_t N,\
    \ class TUPLE> void debug_tuple(ostream& os, TUPLE _) { (void)os; (void)_; }\n\
    template <size_t N, class TUPLE, class T, class ...Args> void debug_tuple(ostream\
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
    // clang-format on\n#line 2 \"datastructure/BinaryIndexedTree.hpp\"\n\ntemplate\
    \ <class T> struct BinaryIndexedTree {\n    int n;\n    vector<T> data;\n\n  \
    \  BinaryIndexedTree() {\n    }\n    BinaryIndexedTree(int n) : n(n), data(n +\
    \ 1, 0) {\n    }\n\n    int size() const {\n        return n;\n    }\n\n    /**\n\
    \     * (0-indexed)\n     * a[i] += x\n     */\n    void add(int i, T x) {\n \
    \       assert(0 <= i and i < n);\n        for (++i; i <= n; i += i & -i) data[i]\
    \ += x;\n    }\n\n    // [0,i) (0-indexed) a[0] + \u2026 + a[i-1]\n    T sum(int\
    \ i) const {\n        assert(0 <= i and i <= n);\n        T ret = 0;\n       \
    \ for (; i > 0; i -= i & -i) ret += data[i];\n        return ret;\n    }\n\n \
    \   /**\n     * [l, r) (0-indexed)\n     * @return a[l] + \u2026\u3000+ a[r-1]\n\
    \     */\n    T sum(int l, int r) const {\n        if (l >= r) return T(0);\n\
    \        return sum(r) - sum(l);\n    }\n\n    /**\n     * (0-indexed)\n     *\
    \ r = 0 or a[0] + a[1] + ... + a[r-1] < x\n     * r = n or a[0] + a[1] + ... +\
    \ a[r] >= x\n     * a[0] + a[1] + ... + a[r] >= x \u3068\u306A\u308B\u6700\u5C0F\
    \u306E r \u3092\u8FD4\u3059\u3002\n     */\n    int lower_bound(T x) const {\n\
    \        int k = 1;\n        int ret = 0;\n        while ((k << 1) <= n) k <<=\
    \ 1;\n        while (k > 0) {\n            if (ret + k <= n and data[ret + k]\
    \ < x) {\n                x -= data[ret + k];\n                ret += k;\n   \
    \         }\n            k >>= 1;\n        }\n        return ret;\n    }\n\n \
    \   int upper_bound(T x) const {\n        return lower_bound(x + 1);\n    }\n\n\
    #ifdef MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, const BinaryIndexedTree&\
    \ r) {\n        vector<T> v(r.size());\n        for (int i = 0; i < r.size();\
    \ i++) {\n            v[i] = r.sum(i, i + 1);\n        }\n        os << v;\n \
    \       return os;\n    }\n#endif\n};\n#line 3 \"segmenttree/PointAddRectangleSum.hpp\"\
    \n\n#line 5 \"segmenttree/PointAddRectangleSum.hpp\"\n\ntemplate <class S, class\
    \ T> struct PointAddRectangleSum {\n    using P = pair<S, S>;\n    int n, log,\
    \ size, sz;\n    std::vector<P> points;\n    std::vector<S> xs, ls, rs, ys;\n\
    \    std::vector<BinaryIndexedTree<T>> BITs;\n    PointAddRectangleSum() {\n \
    \   }\n\n    void push_point(S x, S y) {\n        points.emplace_back(x, y);\n\
    \    }\n\n    void build() {\n        sort(points.begin(), points.end());\n  \
    \      points.erase(unique(points.begin(), points.end()), points.end());\n   \
    \     xs.reserve(points.size());\n        for (const auto& p : points) {\n   \
    \         xs.push_back(p.first);\n        }\n        xs.erase(unique(xs.begin(),\
    \ xs.end()), xs.end());\n        n = int(xs.size());\n\n        log = 0;\n   \
    \     while ((1 << log) < n) log++;\n        sz = 1 << log;\n        BITs.resize(sz\
    \ * 2);\n        ls.resize(sz * 2);\n        rs.resize(sz * 2);\n        ys.reserve(points.size());\n\
    \        int xs_index = 0;\n        for (int i = 0; i < int(points.size()); i++)\
    \ {\n            if (i > 0 && points[i].first != points[i - 1].first) {\n    \
    \            rs[sz + xs_index] = int(ys.size());\n                xs_index++;\n\
    \            }\n            if (i == 0 || points[i].first != points[i - 1].first)\
    \ {\n                ls[sz + xs_index] = int(ys.size());\n            }\n    \
    \        ys.push_back(points[i].second);\n        }\n        rs[sz + n - 1] =\
    \ int(ys.size());\n        for (int i = n; i < sz; i++) {\n            ls[sz +\
    \ i] = int(ys.size());\n            rs[sz + i] = int(ys.size());\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            BITs[sz + i] = BinaryIndexedTree<T>(rs[sz\
    \ + i] - ls[sz + i]);\n        }\n        for (int i = sz - 1; i >= 1; i--) {\n\
    \            ls[i] = int(ys.size());\n            vector<int> vs;\n          \
    \  vs.reserve(rs[i * 2] - ls[i * 2] + rs[i * 2 + 1] - ls[i * 2 + 1]);\n      \
    \      merge(ys.begin() + ls[i * 2], ys.begin() + rs[i * 2],\n               \
    \   ys.begin() + ls[i * 2 + 1], ys.begin() + rs[i * 2 + 1],\n                \
    \  back_inserter(vs));\n            vs.erase(unique(vs.begin(), vs.end()), vs.end());\n\
    \            move(vs.begin(), vs.end(), back_inserter(ys));\n            rs[i]\
    \ = int(ys.size());\n            BITs[i] = BinaryIndexedTree<T>(rs[i] - ls[i]);\n\
    \        }\n    }\n\n    void add(S x, S y, T value) {\n        int k = lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n        assert(k < n && xs[k] == x);\n        k\
    \ += sz;\n        int l = get_y_index(y, k);\n        assert(l < rs[k] - ls[k]\
    \ && ys[ls[k] + l] == y);\n        BITs[k].add(l, value);\n        for (int i\
    \ = 1; i <= log; i++) {\n            int p = k >> i;\n            int l = get_y_index(y,\
    \ p);\n            assert(l < rs[p] - ls[p] && ys[ls[p] + l] == y);\n        \
    \    BITs[p].add(l, value);\n        }\n    }\n\n    T get(S xl, S xr, S yl, S\
    \ yr) const {\n        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n\
    \        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();\n       \
    \ l += sz;\n        r += sz;\n        T ret = 0;\n        while (l < r) {\n  \
    \          if (l & 1) {\n                int ll = get_y_index(yl, l);\n      \
    \          int rr = get_y_index(yr, l);\n                ret += BITs[l].sum(ll,\
    \ rr);\n                l++;\n            }\n            if (r & 1) {\n      \
    \          r--;\n                int ll = get_y_index(yl, r);\n              \
    \  int rr = get_y_index(yr, r);\n                ret += BITs[r].sum(ll, rr);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return ret;\n    }\n\n  private:\n    int get_y_index(S y, int x_index) const\
    \ {\n        return lower_bound(ys.begin() + ls[x_index], ys.begin() + rs[x_index],\n\
    \                           y) -\n               (ys.begin() + ls[x_index]);\n\
    \    }\n};\n#line 4 \"test/segmenttree/PointAddRectangleSum.test.cpp\"\n\nvoid\
    \ solve() {\n    INT(N, Q);\n    VEC3(int, X, Y, W, N);\n    vec<int> T(Q), A(Q),\
    \ B(Q), C(Q), D(Q);\n    rep(i, Q) {\n        cin >> T[i];\n        if (T[i] ==\
    \ 0) {\n            cin >> A[i] >> B[i] >> C[i];\n        } else {\n         \
    \   cin >> A[i] >> B[i] >> C[i] >> D[i];\n        }\n    }\n    PointAddRectangleSum<int,\
    \ ll> ps;\n    rep(i, N) {\n        ps.push_point(X[i], Y[i]);\n    }\n    rep(i,\
    \ Q) {\n        if (T[i] == 0) {\n            ps.push_point(A[i], B[i]);\n   \
    \     }\n    }\n    ps.build();\n    rep(i, N) {\n        ps.add(X[i], Y[i], W[i]);\n\
    \    }\n    rep(i, Q) {\n        if (T[i] == 0) {\n            ps.add(A[i], B[i],\
    \ C[i]);\n        } else {\n            print(ps.get(A[i], C[i], B[i], D[i]));\n\
    \        }\n    }\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cerr << fixed << setprecision(7);\n\
    \n    int T = 1;\n    // cin >> T;\n    for (int test_case = 1; test_case <= T;\
    \ test_case++) {\n        // debug(test_case);\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include \"other/template.hpp\"\n#include \"segmenttree/PointAddRectangleSum.hpp\"\
    \n\nvoid solve() {\n    INT(N, Q);\n    VEC3(int, X, Y, W, N);\n    vec<int> T(Q),\
    \ A(Q), B(Q), C(Q), D(Q);\n    rep(i, Q) {\n        cin >> T[i];\n        if (T[i]\
    \ == 0) {\n            cin >> A[i] >> B[i] >> C[i];\n        } else {\n      \
    \      cin >> A[i] >> B[i] >> C[i] >> D[i];\n        }\n    }\n    PointAddRectangleSum<int,\
    \ ll> ps;\n    rep(i, N) {\n        ps.push_point(X[i], Y[i]);\n    }\n    rep(i,\
    \ Q) {\n        if (T[i] == 0) {\n            ps.push_point(A[i], B[i]);\n   \
    \     }\n    }\n    ps.build();\n    rep(i, N) {\n        ps.add(X[i], Y[i], W[i]);\n\
    \    }\n    rep(i, Q) {\n        if (T[i] == 0) {\n            ps.add(A[i], B[i],\
    \ C[i]);\n        } else {\n            print(ps.get(A[i], C[i], B[i], D[i]));\n\
    \        }\n    }\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cerr << fixed << setprecision(7);\n\
    \n    int T = 1;\n    // cin >> T;\n    for (int test_case = 1; test_case <= T;\
    \ test_case++) {\n        // debug(test_case);\n        solve();\n    }\n}"
  dependsOn:
  - other/template.hpp
  - segmenttree/PointAddRectangleSum.hpp
  - datastructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/segmenttree/PointAddRectangleSum.test.cpp
  requiredBy: []
  timestamp: '2023-10-13 01:31:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segmenttree/PointAddRectangleSum.test.cpp
layout: document
redirect_from:
- /verify/test/segmenttree/PointAddRectangleSum.test.cpp
- /verify/test/segmenttree/PointAddRectangleSum.test.cpp.html
title: test/segmenttree/PointAddRectangleSum.test.cpp
---