---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/FormalPowerSeriesNTTFriendly.hpp
    title: mod/FormalPowerSeriesNTTFriendly.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"test/mod/inv_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\n#line\
    \ 1 \"other/template.hpp\"\n// clang-format off\n#include <algorithm>\n#include\
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
    \ T> T ABS(T x) { return max(x, -x); }\nlong long floor_div(long long n, long\
    \ long d) { return n / d - ((n ^ d) < 0 && n % d); }\ntemplate <class T1, class\
    \ T2> bool chmax(T1& a, T2 b) { if (a < b) { a = b; return true; } return false;\
    \ }\ntemplate <class T1, class T2> bool chmin(T1& a, T2 b) { if (a > b) { a =\
    \ b; return true; } return false; }\nint topbit(ull x) { return x == 0 ? -1 :\
    \ 63 - __builtin_clzll(x); }\nint botbit(ull x) { return x == 0 ? 64 : __builtin_ctzll(x);\
    \ }\nint popcount(ull x) { return __builtin_popcountll(x); }\nint kthbit(ull x,\
    \ int k) { return (x >> k) & 1; }\nconstexpr long long TEN(int x) { return x ==\
    \ 0 ? 1 : TEN(x - 1) * 10; }\ntemplate <typename S> void rearrange(const vector<S>&\
    \ id) { (void)id; }\ntemplate <typename S, typename T> void rearrange_exec(const\
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
    , debug_out(__VA_ARGS__)\n#else\n#define debug(...) (void(0))\n#endif\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\
    // clang-format on\n#line 2 \"mod/FormalPowerSeriesNTTFriendly.hpp\"\n\n#line\
    \ 8 \"mod/FormalPowerSeriesNTTFriendly.hpp\"\n\n#include <atcoder/convolution>\n\
    \ntemplate <typename M, int SPARSE = 10>\nstruct FormalPowerSeriesNTTFriendly\
    \ : std::vector<M> {\n    using std::vector<M>::vector;\n    using FPS = FormalPowerSeriesNTTFriendly;\n\
    \n    FPS static read(int n) {\n        FPS ret(n);\n        for (int i = 0; i\
    \ < n; i++) {\n            long long x;\n            std::cin >> x;\n        \
    \    ret[i] = x;\n        }\n        return ret;\n    }\n\n    M freq(int p) const\
    \ {\n        return p < (int)this->size() ? (*this)[p] : M(0);\n    }\n\n    void\
    \ shrink() {\n        while (!this->empty() and this->back().val() == 0) this->pop_back();\n\
    \    }\n\n    FPS pre(int le) const {\n        return FPS(this->begin(),\n   \
    \                this->begin() + std::min((int)this->size(), le));\n    }\n\n\
    \    FPS rev() const {\n        FPS ret(*this);\n        std::reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    int count_nonzero() const {\n\
    \        return std::count_if(this->begin(), this->end(),\n                  \
    \           [](M x) { return x.val() != 0; });\n    }\n\n    std::vector<std::pair<int,\
    \ M>> get_sparse() const {\n        std::vector<std::pair<int, M>> ret;\n    \
    \    for (size_t i = 0; i < this->size(); i++) {\n            if ((*this)[i].val()\
    \ != 0) ret.emplace_back(i, (*this)[i]);\n        }\n        return ret;\n   \
    \ }\n\n    FPS operator>>(int s) const {\n        if ((int)this->size() <= s)\
    \ return {};\n        return FPS(this->begin() + s, this->end());\n    }\n\n \
    \   FPS operator<<(int s) const {\n        if (this->empty()) return {};\n   \
    \     FPS ret(*this);\n        ret.insert(ret.begin(), s, M(0));\n        return\
    \ ret;\n    }\n\n    FPS& operator+=(const FPS& r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (size_t i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];\n        shrink();\n        return *this;\n    }\n\n    FPS& operator+=(const\
    \ M& v) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] +=\
    \ v;\n        shrink();\n        return *this;\n    }\n\n    FPS& operator-=(const\
    \ FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < int(r.size()); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator-=(const M& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator*=(const FPS& r) {\n       \
    \ const int z = r.count_nonzero();\n        if (z == 0) {\n            this->clear();\n\
    \            return *this;\n        }\n        if (z <= SPARSE) {\n          \
    \  auto sparse = r.get_sparse();\n            return *this *= sparse;\n      \
    \  }\n        auto res = atcoder::convolution(*this, r);\n        return *this\
    \ = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const M& v) {\n  \
    \      for (auto& x : (*this)) x *= v;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS& operator*=(const std::vector<std::pair<int, M>>& r) {\n   \
    \     assert(!r.empty());\n        const int m = r.back().first;\n        FPS\
    \ ret(this->size() + m);\n        for (int i = 0; i < (int)this->size(); i++)\
    \ {\n            for (const auto& [j, c] : r) {\n                ret[i + j] +=\
    \ (*this)[i] * c;\n            }\n        }\n        ret.shrink();\n        return\
    \ *this = ret;\n    }\n\n    FPS& operator/=(const FPS& r) {\n        if (this->size()\
    \ < r.size()) {\n            this->clear();\n            return *this;\n     \
    \   }\n        const int z = r.count_nonzero();\n        assert(z != 0);\n   \
    \     if (z <= SPARSE) {\n            auto sparse = r.get_sparse();\n        \
    \    return *this /= sparse;\n        }\n        int n = this->size() - r.size()\
    \ + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS& operator/=(const M& v) {\n        assert(v.val() != 0);\n \
    \       auto vinv = v.inv();\n        for (auto& x : (*this)) x *= vinv;\n   \
    \     return *this;\n    }\n\n    FPS& operator/=(const std::vector<std::pair<int,\
    \ M>>& r) {\n        assert(!r.empty());\n        auto [j0, c0] = r.front();\n\
    \        assert(j0 == 0 && c0.val() != 0);\n        auto ic = c0.inv();\n    \
    \    FPS ret(this->size());\n        for (int i = 0; i < (int)this->size(); i++)\
    \ {\n            for (const auto& [j, c] : r) {\n                if (j >= 1 &&\
    \ j <= i) {\n                    ret[i] -= ret[i - j] * c;\n                }\n\
    \            }\n            ret[i] += (*this)[i];\n            ret[i] *= ic;\n\
    \        }\n        ret.shrink();\n        return *this = ret;\n    }\n\n    FPS&\
    \ operator%=(const FPS& r) {\n        *this -= *this / r * r;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS operator+(const FPS& r) const {\n   \
    \     return FPS(*this) += r;\n    }\n\n    FPS operator+(const M& v) const {\n\
    \        return FPS(*this) += v;\n    }\n\n    FPS operator-(const FPS& r) const\
    \ {\n        return FPS(*this) -= r;\n    }\n\n    FPS operator-(const M& v) const\
    \ {\n        return FPS(*this) -= v;\n    }\n\n    FPS operator*(const FPS& r)\
    \ const {\n        return FPS(*this) *= r;\n    }\n\n    FPS operator*(const M&\
    \ v) const {\n        return FPS(*this) *= v;\n    }\n\n    FPS operator/(const\
    \ FPS& r) const {\n        return FPS(*this) /= r;\n    }\n\n    FPS operator%(const\
    \ FPS& r) const {\n        return FPS(*this) %= r;\n    }\n\n    FPS operator-()\
    \ const {\n        FPS ret = *this;\n        for (auto& v : ret) v = -v;\n   \
    \     return ret;\n    }\n\n    FPS differential() const {\n        const int\
    \ n = (int)this->size();\n        FPS ret(std::max(0, n - 1));\n        for (int\
    \ i = 1; i < n; i++) ret[i - 1] = (*this)[i] * M(i);\n        return ret;\n  \
    \  }\n\n    FPS integral() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(n + 1);\n        ret[0] = M(0);\n        if (n > 0) ret[1] =\
    \ M(1);\n        auto mod = M::mod();\n        for (int i = 2; i <= n; i++) ret[i]\
    \ = -ret[mod % i] * (mod / i);\n        for (int i = 0; i < n; i++) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n\n    FPS inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != M(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        FPS ret{(*this)[0].inv()};\n       \
    \ ret.reserve(deg);\n        for (int d = 1; d < deg; d <<= 1) {\n           \
    \ FPS f(d << 1), g(d << 1);\n            std::copy(this->begin(), this->begin()\
    \ + std::min(n, d << 1),\n                      f.begin());\n            std::copy(ret.begin(),\
    \ ret.end(), g.begin());\n            atcoder::internal::butterfly(f);\n     \
    \       atcoder::internal::butterfly(g);\n            for (int i = 0; i < (d <<\
    \ 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n \
    \           std::fill(f.begin(), f.begin() + d, M(0));\n            atcoder::internal::butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            M iz = M(d << 1).inv();\n            iz *= -iz;\n            for\
    \ (int i = d; i < std::min(d << 1, deg); i++)\n                ret.push_back(f[i]\
    \ * iz);\n        }\n        return ret.pre(deg);\n    }\n\n    FPS log(int deg\
    \ = -1) const {\n        assert((*this)[0] == M(1));\n        if (deg == -1) deg\
    \ = (int)this->size();\n        return (differential() * inv(deg)).pre(deg - 1).integral();\n\
    \    }\n\n    FPS sqrt(const std::function<M(M)>& get_sqrt, int deg = -1) const\
    \ {\n        const int n = this->size();\n        if (deg == -1) deg = n;\n  \
    \      if (this->empty()) return FPS(deg, 0);\n        if ((*this)[0] == M(0))\
    \ {\n            for (int i = 1; i < n; i++) {\n                if ((*this)[i]\
    \ != M(0)) {\n                    if (i & 1) return {};\n                    if\
    \ (deg - i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(get_sqrt,\
    \ deg - i / 2);\n                    if (ret.empty()) return {};\n           \
    \         ret = ret << (i / 2);\n                    if ((int)ret.size() < deg)\
    \ ret.resize(deg, M(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, M(0));\n        }\n        auto sqrtf0\
    \ = M(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0 != (*this)[0]) return\
    \ {};\n        FPS ret{sqrtf0};\n        M inv2 = M(2).inv();\n        for (int\
    \ i = 1; i < deg; i <<= 1)\n            ret = (ret + pre(i << 1) * ret.inv(i <<\
    \ 1)) * inv2;\n        return ret.pre(deg);\n    }\n\n    FPS exp(int deg = -1)\
    \ const {\n        assert(this->empty() or (*this)[0] == M(0));\n        if (this->size()\
    \ <= 1) return {M(1)};\n        if (deg == -1) deg = (int)this->size();\n    \
    \    FPS inv;\n        inv.reserve(deg + 1);\n        inv.push_back(M(0));\n \
    \       inv.push_back(M(1));\n        auto inplace_integral = [&](FPS& F) -> void\
    \ {\n            const int n = (int)F.size();\n            auto mod = M::mod();\n\
    \            while ((int)inv.size() <= n) {\n                int i = inv.size();\n\
    \                inv.push_back(-inv[mod % i] * (mod / i));\n            }\n  \
    \          F.insert(F.begin(), M(0));\n            for (int i = 1; i <= n; i++)\
    \ F[i] *= inv[i];\n        };\n        auto inplace_differential = [](FPS& F)\
    \ -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
    \            for (size_t i = 0; i < F.size(); i++) F[i] *= M(i + 1);\n       \
    \ };\n        FPS f{1, (*this)[1]}, g{M(1)}, g_fft{M(1), M(1)};\n        for (int\
    \ m = 2; m < deg; m <<= 1) {\n            const M iz1 = M(m).inv(), iz2 = M(m\
    \ << 1).inv();\n            auto f_fft = f;\n            f_fft.resize(m << 1);\n\
    \            atcoder::internal::butterfly(f_fft);\n            {\n           \
    \     FPS _g(m);\n                for (int i = 0; i < m; i++) _g[i] = f_fft[i]\
    \ * g_fft[i];\n                atcoder::internal::butterfly_inv(_g);\n       \
    \         std::fill(_g.begin(), _g.begin() + (m >> 1), M(0));\n              \
    \  atcoder::internal::butterfly(_g);\n                for (int i = 0; i < m; i++)\
    \ _g[i] *= -g_fft[i] * iz1 * iz1;\n                atcoder::internal::butterfly_inv(_g);\n\
    \                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());\n\n     \
    \           g_fft = g;\n                g_fft.resize(m << 1);\n              \
    \  atcoder::internal::butterfly(g_fft);\n            }\n            FPS x(this->begin(),\n\
    \                  this->begin() + std::min((int)this->size(), m));\n        \
    \    {\n                x.resize(m);\n                inplace_differential(x);\n\
    \                x.push_back(M(0));\n                atcoder::internal::butterfly(x);\n\
    \            }\n            {\n                for (int i = 0; i < m; i++) x[i]\
    \ *= f_fft[i] * iz1;\n                atcoder::internal::butterfly_inv(x);\n \
    \           }\n            {\n                x -= f.differential();\n       \
    \         x.resize(m << 1);\n                for (int i = 0; i < m - 1; i++) x[m\
    \ + i] = x[i], x[i] = M(0);\n                atcoder::internal::butterfly(x);\n\
    \                for (int i = 0; i < (m << 1); i++) x[i] *= g_fft[i] * iz2;\n\
    \                atcoder::internal::butterfly_inv(x);\n            }\n       \
    \     {\n                x.pop_back();\n                inplace_integral(x);\n\
    \                for (int i = m; i < std::min((int)this->size(), m << 1); i++)\n\
    \                    x[i] += (*this)[i];\n                std::fill(x.begin(),\
    \ x.begin() + m, M(0));\n            }\n            {\n                atcoder::internal::butterfly(x);\n\
    \                for (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;\n\
    \                atcoder::internal::butterfly_inv(x);\n                f.insert(f.end(),\
    \ x.begin() + m, x.end());\n            }\n        }\n        return FPS{f.begin(),\
    \ f.begin() + deg};\n    }\n\n    FPS pow(int64_t k, int deg = -1) const {\n \
    \       const int n = (int)this->size();\n        if (deg == -1) deg = n;\n  \
    \      if (k == 0) {\n            auto res = FPS(deg, M(0));\n            res[0]\
    \ = M(1);\n            return res;\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if ((*this)[i] != M(0)) {\n                if (i >= (deg\
    \ + k - 1) / k) return FPS(deg, M(0));\n                M rev = (*this)[i].inv();\n\
    \                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg) *\n  \
    \                        ((*this)[i].pow(k));\n                ret = (ret << (i\
    \ * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ M(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, M(0));\n    }\n\n    M eval(M x) const {\n        M ret = 0, w = 1;\n\
    \        for (const auto& v : *this) ret += w * v, w *= x;\n        return ret;\n\
    \    }\n};\n\ntemplate <class M, int SPARSE>\nvoid print(const FormalPowerSeriesNTTFriendly<M,\
    \ SPARSE>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n        if (i) std::cout\
    \ << \" \";\n        std::cout << v[i].val();\n    }\n    cout << \"\\n\";\n}\n\
    #line 4 \"test/mod/inv_of_formal_power_series.test.cpp\"\nusing namespace atcoder;\n\
    using mint = modint998244353;\nusing FPS = FormalPowerSeriesNTTFriendly<mint>;\n\
    void solve() {\n    INT(N);\n    auto F = FPS::read(N);\n\n    auto ans = F.inv(N);\n\
    \    print(ans);\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cerr << fixed << setprecision(7);\n\
    \n    int T = 1;\n    // cin >> T;\n    for (int test_case = 1; test_case <= T;\
    \ test_case++) {\n        // debug(test_case);\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n#include \"other/template.hpp\"\n#include \"mod/FormalPowerSeriesNTTFriendly.hpp\"\
    \nusing namespace atcoder;\nusing mint = modint998244353;\nusing FPS = FormalPowerSeriesNTTFriendly<mint>;\n\
    void solve() {\n    INT(N);\n    auto F = FPS::read(N);\n\n    auto ans = F.inv(N);\n\
    \    print(ans);\n}\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(20);\n    cerr << fixed << setprecision(7);\n\
    \n    int T = 1;\n    // cin >> T;\n    for (int test_case = 1; test_case <= T;\
    \ test_case++) {\n        // debug(test_case);\n        solve();\n    }\n}"
  dependsOn:
  - other/template.hpp
  - mod/FormalPowerSeriesNTTFriendly.hpp
  isVerificationFile: true
  path: test/mod/inv_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mod/inv_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/mod/inv_of_formal_power_series.test.cpp
- /verify/test/mod/inv_of_formal_power_series.test.cpp.html
title: test/mod/inv_of_formal_power_series.test.cpp
---
