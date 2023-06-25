---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: graph/StronglyConnectedComponents.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/StronglyConnectedComponents.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#line 1 \"other/template.hpp\"\
    \n// clang-format off\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    // clang-format on\n#line 2 \"graph/StronglyConnectedComponents.hpp\"\n\n#include\
    \ <atcoder/internal_scc>\n\nstruct StronglyConnectedComponents {\n    int n;\n\
    \    int group_num;\n    /**\n     * \u5143\u306E\u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u304C\u3069\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u6240\u5C5E\u3059\
    \u308B\u304B\u3092\u8868\u3059\u914D\u5217\n     */\n    vector<int> scc_ids;\n\
    \n    StronglyConnectedComponents() : n(0), internal(0) {\n    }\n    explicit\
    \ StronglyConnectedComponents(int n) : n(n), internal(n) {\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    void add_edge(int from, int to) {\n\
    \        assert(0 <= from && from < n);\n        assert(0 <= to && to < n);\n\
    \        internal.add_edge(from, to);\n        edges.emplace_back(from, to);\n\
    \    }\n\n    int build() {\n        tie(group_num, scc_ids) = internal.scc_ids();\n\
    \        return group_num;\n    }\n\n    vector<vector<int>> groups() const {\n\
    \        vector<vector<int>> groups(group_num);\n        vector<int> counts(group_num);\n\
    \        for (auto x : scc_ids) counts[x]++;\n        for (int i = 0; i < group_num;\
    \ i++) {\n            groups[i].reserve(counts[i]);\n        }\n        for (int\
    \ i = 0; i < n; i++) {\n            groups[scc_ids[i]].push_back(i);\n       \
    \ }\n        return groups;\n    }\n\n    vector<vector<int>> scc_graph() const\
    \ {\n        vector<int> counts(group_num);\n        vector<vector<int>> naive_scc_graph(group_num),\
    \ scc_graph(group_num);\n        for (auto [from, to] : edges) counts[scc_ids[from]]++;\n\
    \        for (int i = 0; i < group_num; i++) {\n            naive_scc_graph[i].reserve(counts[i]);\n\
    \            scc_graph[i].reserve(counts[i]);\n        }\n        for (auto [from,\
    \ to] : edges) {\n            naive_scc_graph[scc_ids[from]].push_back(scc_ids[to]);\n\
    \        }\n        vector<int> exists(group_num);\n        for (int from = 0;\
    \ from < group_num; from++) {\n            for (auto to : naive_scc_graph[from])\
    \ {\n                if (exists[to]) continue;\n                scc_graph[from].push_back(to);\n\
    \                exists[to] = 1;\n            }\n            for (auto to : scc_graph[from])\
    \ {\n                exists[to] = 0;\n            }\n        }\n        return\
    \ scc_graph;\n    }\n\n    int operator[](int i) const {\n        assert(0 <=\
    \ i && i < n);\n        return scc_ids[i];\n    }\n\n  private:\n    atcoder::internal::scc_graph\
    \ internal;\n    vector<pair<int, int>> edges;\n};\n#line 4 \"test/graph/StronglyConnectedComponents.test.cpp\"\
    \n\nint main() {\n    INT(N, M);\n    StronglyConnectedComponents SCC(N);\n  \
    \  rep(M) {\n        INT(a, b);\n        SCC.add_edge(a, b);\n    }\n    int K\
    \ = SCC.build();\n    print(K);\n    auto g = SCC.groups();\n    for (auto& v\
    \ : g) {\n        print(SZ(v), v);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"other/template.hpp\"\
    \n#include \"graph/StronglyConnectedComponents.hpp\"\n\nint main() {\n    INT(N,\
    \ M);\n    StronglyConnectedComponents SCC(N);\n    rep(M) {\n        INT(a, b);\n\
    \        SCC.add_edge(a, b);\n    }\n    int K = SCC.build();\n    print(K);\n\
    \    auto g = SCC.groups();\n    for (auto& v : g) {\n        print(SZ(v), v);\n\
    \    }\n}"
  dependsOn:
  - other/template.hpp
  - graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/graph/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2023-06-20 01:24:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/test/graph/StronglyConnectedComponents.test.cpp
- /verify/test/graph/StronglyConnectedComponents.test.cpp.html
title: test/graph/StronglyConnectedComponents.test.cpp
---
