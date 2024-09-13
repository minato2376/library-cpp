---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryTrie.hpp
    title: datastructure/BinaryTrie.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/datastructure/BinaryTrie.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 1 \"other/template.hpp\"\
    \n// clang-format off\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <complex>\n#include <deque>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
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
    // clang-format on\n#line 2 \"datastructure/BinaryTrie.hpp\"\n\n#line 6 \"datastructure/BinaryTrie.hpp\"\
    \n\ntemplate <class Key, class T, int B, class F> struct BinaryTrie {\n    struct\
    \ Node {\n        int parent;\n        std::array<int, 2> child;\n        T value;\n\
    \        Node(int parent, T value) : parent(parent), value(value) {\n        \
    \    child[0] = child[1] = -1;\n        }\n    };\n\n    F op;\n    T e;\n   \
    \ std::vector<Node> nodes;\n\n    BinaryTrie(const F& op, T e) : op(op), e(e),\
    \ nodes(1, Node(-1, e)) {\n    }\n\n    int create_node(int parent, T value) {\n\
    \        int ret = int(nodes.size());\n        nodes.emplace_back(parent, value);\n\
    \        return ret;\n    }\n\n    void insert(Key key, T value) {\n        int\
    \ cur = 0;\n\n        for (int i = B - 1; i >= 0; i--) {\n            int b =\
    \ kthbit(key, i);\n            if (nodes[cur].child[b] == -1) {\n            \
    \    nodes[cur].child[b] = create_node(cur, e);\n            }\n            cur\
    \ = nodes[cur].child[b];\n        }\n\n        nodes[cur].value = value;\n   \
    \     for (int i = 0; i < B; i++) {\n            cur = nodes[cur].parent;\n  \
    \          nodes[cur].value = op(\n                nodes[cur].child[0] == -1 ?\
    \ e\n                                          : nodes[nodes[cur].child[0]].value,\n\
    \                nodes[cur].child[1] == -1 ? e\n                             \
    \             : nodes[nodes[cur].child[1]].value);\n        }\n    }\n\n    void\
    \ erase(Key key) {\n        int cur = 0;\n\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            int b = kthbit(key, i);\n            assert(nodes[cur].child[b]\
    \ != -1);\n            cur = nodes[cur].child[b];\n        }\n\n        for (int\
    \ i = 0; i < B; i++) {\n            cur = nodes[cur].parent;\n            int\
    \ b = kthbit(key, i);\n            nodes[cur].child[b] = -1;\n            if (nodes[cur].child[1\
    \ ^ b] != -1) {\n                nodes[cur].value = op(nodes[cur].child[0] ==\
    \ -1\n                                          ? e\n                        \
    \                  : nodes[nodes[cur].child[0]].value,\n                     \
    \                 nodes[cur].child[1] == -1\n                                \
    \          ? e\n                                          : nodes[nodes[cur].child[1]].value);\n\
    \                break;\n            }\n        }\n    }\n\n    int find(Key key)\
    \ const {\n        int cur = 0;\n        for (int i = B - 1; i >= 0; i--) {\n\
    \            int b = kthbit(key, i);\n            if (nodes[cur].child[b] == -1)\
    \ {\n                return -1;\n            }\n            cur = nodes[cur].child[b];\n\
    \        }\n\n        return cur;\n    }\n\n    /**\n     * key \u304B\u3089\u306A\
    \u308B\u96C6\u5408\u306B\u5024 x \u3067 xor \u3057\u305F\u3068\u304D\u306E\u6700\
    \u5C0F\u5024\u3092\u6C42\u3081\u308B\n     * \u6700\u5C0F\u5024\u306F xor \u3057\
    \u305F\u3042\u3068\u306E\u5024\n     * O(B)\n     */\n    Key min_element(Key\
    \ x = 0) const {\n        int cur = 0;\n\n        Key ret = 0;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            int b = kthbit(x, i);\n            if\
    \ (nodes[cur].child[b] == -1) {\n                ret ^= 1 << i;\n            \
    \    cur = nodes[cur].child[1 ^ b];\n            } else {\n                cur\
    \ = nodes[cur].child[b];\n            }\n        }\n        return ret;\n    }\n\
    \n    Key max_element(Key x = 0) const {\n        int cur = 0;\n\n        Key\
    \ ret = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            int b = kthbit(x,\
    \ i);\n            if (nodes[cur].child[1 ^ b] == -1) {\n                cur =\
    \ nodes[cur].child[b];\n            } else {\n                ret ^= 1 << i;\n\
    \                cur = nodes[cur].child[1 ^ b];\n            }\n        }\n  \
    \      return ret;\n    }\n\n    int kthbit(Key key, int k) const {\n        return\
    \ (key >> k) & 1;\n    }\n};\n#line 4 \"test/datastructure/BinaryTrie.test.cpp\"\
    \n\nint main() {\n    auto f = [](int a, int b) { return a + b; };\n    constexpr\
    \ int e = 0;\n    BinaryTrie<int, int, 30, decltype(f)> trie(f, e);\n\n    INT(Q);\n\
    \    rep(Q) {\n        INT(t, x);\n        if (t == 0) {\n            trie.insert(x,\
    \ 1);\n        } else if (t == 1) {\n            if (trie.find(x) == -1) continue;\n\
    \            trie.erase(x);\n        } else {\n            print(trie.min_element(x));\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"other/template.hpp\"\n#include \"datastructure/BinaryTrie.hpp\"\n\nint main()\
    \ {\n    auto f = [](int a, int b) { return a + b; };\n    constexpr int e = 0;\n\
    \    BinaryTrie<int, int, 30, decltype(f)> trie(f, e);\n\n    INT(Q);\n    rep(Q)\
    \ {\n        INT(t, x);\n        if (t == 0) {\n            trie.insert(x, 1);\n\
    \        } else if (t == 1) {\n            if (trie.find(x) == -1) continue;\n\
    \            trie.erase(x);\n        } else {\n            print(trie.min_element(x));\n\
    \        }\n    }\n}"
  dependsOn:
  - other/template.hpp
  - datastructure/BinaryTrie.hpp
  isVerificationFile: true
  path: test/datastructure/BinaryTrie.test.cpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/BinaryTrie.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/BinaryTrie.test.cpp
- /verify/test/datastructure/BinaryTrie.test.cpp.html
title: test/datastructure/BinaryTrie.test.cpp
---
