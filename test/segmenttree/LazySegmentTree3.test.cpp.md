---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: segmenttree/LazySegmentTree.hpp
    title: segmenttree/LazySegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"test/segmenttree/LazySegmentTree3.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#line 1 \"other/template.hpp\"\n// clang-format off\n#include <algorithm>\n\
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
    // clang-format on\n#line 2 \"segmenttree/LazySegmentTree.hpp\"\n\n#line 5 \"\
    segmenttree/LazySegmentTree.hpp\"\n\ntemplate <class T, class U, class F, class\
    \ G, class H> struct LazySegmentTree {\n  private:\n    F op;\n    G mapping;\n\
    \    H composition;\n    T e;\n    U id;\n    int _n, size, log;\n    std::vector<T>\
    \ node;\n    std::vector<U> lazy;\n\n  public:\n    LazySegmentTree() {\n    }\n\
    \    LazySegmentTree(const F& op,\n                    const G& mapping,\n   \
    \                 const H& composition,\n                    T e,\n          \
    \          U id,\n                    int n)\n        : LazySegmentTree(op,\n\
    \                          mapping,\n                          composition,\n\
    \                          e,\n                          id,\n               \
    \           std::vector<T>(n, e)) {\n    }\n    LazySegmentTree(const F& op,\n\
    \                    const G& mapping,\n                    const H& composition,\n\
    \                    T e,\n                    U id,\n                    const\
    \ std::vector<T>& v)\n        : op(op),\n          mapping(mapping),\n       \
    \   composition(composition),\n          e(e),\n          id(id),\n          _n(int(v.size())),\n\
    \          log(0) {\n        while ((1 << log) < _n) log++;\n        size = 1\
    \ << log;\n        node = std::vector<T>(2 * size, e);\n        lazy = std::vector<U>(size,\
    \ id);\n        for (int i = 0; i < _n; i++) node[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    void set(int p, T x) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        node[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    //\
    \ [l, r) (0-indexed)\n    T get(int l, int r) {\n        if (l >= r) return e;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push(r >> i);\n        }\n\n        T sml = e, smr =\
    \ e;\n        while (l < r) {\n            if (l & 1) sml = op(sml, node[l++]);\n\
    \            if (r & 1) smr = op(node[--r], smr);\n            l >>= 1;\n    \
    \        r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    T all_get()\
    \ const {\n        return node[1];\n    }\n\n    void apply(int p, U val) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        node[p] = val == id ? node[p] : mapping(node[p],\
    \ val);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n   \
    \ void apply(int l, int r, U val) {\n        if (l >= r) return;\n\n        l\
    \ += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--) {\n \
    \           if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int l2\
    \ = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ val);\n                if (r & 1) all_apply(--r, val);\n                l >>=\
    \ 1;\n                r >>= 1;\n            }\n            l = l2;\n         \
    \   r = r2;\n        }\n\n        for (int i = 1; i <= log; i++) {\n         \
    \   if (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i)\
    \ != r) update((r - 1) >> i);\n        }\n    }\n\n    template <typename C> int\
    \ max_right(int l, const C& check) {\n        assert(0 <= l && l <= _n);\n   \
    \     assert(check(e));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        T sm = e;\n   \
    \     do {\n            while (~l & 1) l >>= 1;\n            if (!check(op(sm,\
    \ node[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (check(op(sm, node[l])))\
    \ {\n                        sm = op(sm, node[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, node[l]);\n            l++;\n        }\
    \ while ((l & -l) != l);\n        return _n;\n    }\n\n    template <typename\
    \ C> int min_left(int r, const C& check) {\n        assert(0 <= r && r <= _n);\n\
    \        assert(check(e));\n        if (r == 0) return 0;\n        r += size;\n\
    \        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        T sm = e;\n\
    \        do {\n            r--;\n            while (r > 1 && (r & 1)) r >>= 1;\n\
    \            if (!check(op(node[r], sm))) {\n                while (r < size)\
    \ {\n                    push(r);\n                    r = (2 * r + 1);\n    \
    \                if (check(op(node[r], sm))) {\n                        sm = op(node[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(node[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n    T operator[](int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return node[p];\n    }\n#ifdef\
    \ MINATO_LOCAL\n    friend ostream& operator<<(ostream& os, LazySegmentTree r)\
    \ {\n        std::vector<T> v(r._n);\n        for (int i = 0; i < r._n; i++) {\n\
    \            v[i] = r[i];\n        }\n        os << v;\n        return os;\n \
    \   }\n#endif\n\n  private:\n    void update(int k) {\n        node[k] = op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n\n    void all_apply(int k, U val) {\n     \
    \   node[k] = val == id ? node[k] : mapping(node[k], val);\n        if (k < size)\
    \ lazy[k] = composition(lazy[k], val);\n    }\n\n    void push(int k) {\n    \
    \    if (lazy[k] == id) return;\n        all_apply(2 * k, lazy[k]);\n        all_apply(2\
    \ * k + 1, lazy[k]);\n        lazy[k] = id;\n    }\n};\n\n/**\n * \u533A\u9593\
    \u66F4\u65B0\u533A\u9593\u6700\u5C0F\u5024\n */\ntemplate <typename T>\nauto buildRangeSetRangeMin(const\
    \ std::vector<T>& v, T e, T id) {\n    auto f = [](T a, T b) { return min(a, b);\
    \ };\n    auto g = [](T a, T b) {\n        (void)a;\n        return b;\n    };\n\
    \    auto h = [](T a, T b) {\n        (void)a;\n        return b;\n    };\n  \
    \  LazySegmentTree seg(f, g, h, e, id, v);\n    return seg;\n}\n\ntemplate <typename\
    \ T> auto buildRangeSetRangeMin(int n, T e, T id) {\n    return buildRangeSetRangeMin<T>(std::vector<T>(n,\
    \ e), e, id);\n}\n\n/**\n * \u533A\u9593\u66F4\u65B0\u533A\u9593\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nauto buildRangeSetRangeMax(const std::vector<T>&\
    \ v, T e, T id) {\n    auto f = [](T a, T b) { return max(a, b); };\n    auto\
    \ g = [](T a, T b) {\n        (void)a;\n        return b;\n    };\n    auto h\
    \ = [](T a, T b) {\n        (void)a;\n        return b;\n    };\n    LazySegmentTree\
    \ seg(f, g, h, e, id, v);\n    return seg;\n}\n\ntemplate <typename T> auto buildRangeSetRangeMax(int\
    \ n, T e, T id) {\n    return buildRangeSetRangeMax<T>(std::vector<T>(n, e), e,\
    \ id);\n}\n\n/**\n * \u533A\u9593\u52A0\u7B97\u533A\u9593\u6700\u5C0F\u5024\n\
    \ */\ntemplate <typename T>\nauto buildRangeAddRangeMin(const std::vector<T>&\
    \ v, T e, T id) {\n    auto f = [](T a, T b) { return min(a, b); };\n    auto\
    \ g = [](T a, T b) { return a + b; };\n    auto h = [](T a, T b) { return a +\
    \ b; };\n    LazySegmentTree seg(f, g, h, e, id, v);\n    return seg;\n}\n\ntemplate\
    \ <typename T> auto buildRangeAddRangeMin(int n, T e, T id) {\n    return buildRangeAddRangeMin<T>(std::vector<T>(n,\
    \ e), e, id);\n}\n\n/**\n * \u533A\u9593\u52A0\u7B97\u533A\u9593\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nauto buildRangeAddRangeMax(const std::vector<T>&\
    \ v, T e, T id) {\n    auto f = [](T a, T b) { return max(a, b); };\n    auto\
    \ g = [](T a, T b) { return a + b; };\n    auto h = [](T a, T b) { return a +\
    \ b; };\n    LazySegmentTree seg(f, g, h, e, id, v);\n    return seg;\n}\n\ntemplate\
    \ <typename T> auto buildRangeAddRangeMax(int n, T e, T id) {\n    return buildRangeAddRangeMax<T>(std::vector<T>(n,\
    \ e), e, id);\n}\n\n/**\n * \u533A\u9593\u66F4\u65B0\u533A\u9593\u548C\n * @note\
    \ pair.first: \u533A\u9593\u548C, pair.second: \u533A\u9593\u306E\u9577\u3055\n\
    \ */\ntemplate <typename T, typename S>\nauto buildRangeSetRangeSum(const std::vector<T>&\
    \ v, pair<T, S> e, T id) {\n    using P = pair<T, S>;\n    auto f = [](P a, P\
    \ b) { return P(a.first + b.first, a.second + b.second); };\n    auto g = [](P\
    \ a, T b) { return P(b * a.second, a.second); };\n    auto h = [](T a, T b) {\n\
    \        (void)a;\n        return b;\n    };\n    std::vector<P> w(v.size());\n\
    \    for (size_t i = 0; i < v.size(); i++) {\n        w[i] = P(v[i], 1);\n   \
    \ }\n    LazySegmentTree seg(f, g, h, e, id, w);\n    return seg;\n}\n\ntemplate\
    \ <typename T, typename S>\nauto buildRangeSetRangeSum(int n, pair<T, S> e, T\
    \ id) {\n    return buildRangeSetRangeSum<T, S>(std::vector<T>(n), e, id);\n}\n\
    #line 5 \"test/segmenttree/LazySegmentTree3.test.cpp\"\nint main() {\n    INT(n,\
    \ q);\n    constexpr pii e = pii(0, 0);\n    constexpr int id = numeric_limits<int>::max();\n\
    \    auto seg = buildRangeSetRangeSum<int, int>(n, e, id);\n    rep(q) {\n   \
    \     INT(t);\n        if (t == 0) {\n            INT(l, r, x);\n            seg.apply(l,\
    \ r + 1, x);\n        } else {\n            INT(l, r);\n            print(seg.get(l,\
    \ r + 1).first);\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include \"other/template.hpp\"\n#include \"segmenttree/LazySegmentTree.hpp\"\
    \nint main() {\n    INT(n, q);\n    constexpr pii e = pii(0, 0);\n    constexpr\
    \ int id = numeric_limits<int>::max();\n    auto seg = buildRangeSetRangeSum<int,\
    \ int>(n, e, id);\n    rep(q) {\n        INT(t);\n        if (t == 0) {\n    \
    \        INT(l, r, x);\n            seg.apply(l, r + 1, x);\n        } else {\n\
    \            INT(l, r);\n            print(seg.get(l, r + 1).first);\n       \
    \ }\n    }\n}"
  dependsOn:
  - other/template.hpp
  - segmenttree/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/segmenttree/LazySegmentTree3.test.cpp
  requiredBy: []
  timestamp: '2023-06-26 01:08:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segmenttree/LazySegmentTree3.test.cpp
layout: document
redirect_from:
- /verify/test/segmenttree/LazySegmentTree3.test.cpp
- /verify/test/segmenttree/LazySegmentTree3.test.cpp.html
title: test/segmenttree/LazySegmentTree3.test.cpp
---
