---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/HeavyLightDecomposition.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n/**\n *   HeavyLightDecomposition\n *\
    \   \u69CB\u7BC9 O(n) \u7A7A\u9593 O(n)\n *\n *   \u9802\u70B9 v \u306E\u60C5\u5831\
    \u306F HLD[v] \u306B\u6301\u305F\u305B\u308B\u3002\n *   \u8FBA uv \u306E\u60C5\
    \u5831\u306F dep[u] < dep[v] \u3068\u3057\u3066 HLD[v] \u306B\u6301\u305F\u305B\
    \u308B\u3002\n *   \uFF08\u3064\u307E\u308A\u6DF1\u3044\u65B9,\u5B50\u306E\u9802\
    \u70B9\u306B\u5BFE\u5FDC\u3055\u305B\u308B\uFF09\n *   \u3044\u305A\u308C\u306B\
    \u305B\u3088\u30C7\u30FC\u30BF\u69CB\u9020\u306F n \u9802\u70B9\u5206\u69CB\u7BC9\
    \u3059\u308B\u3002\n */\nstruct HeavyLightDecomposition {\n    std::vector<std::vector<int>>\
    \ g;\n\n    /**\n     *  n \u9802\u70B9 0 \u8FBA\u306E\u7121\u5411\u30B0\u30E9\
    \u30D5\u3092\u4F5C\u308B\u3002\n     *  O(n)\n     */\n    HeavyLightDecomposition(int\
    \ n_)\n        : g(n_),\n          n(n_),\n          vid(n_),\n          head(n_),\n\
    \          sub(n_, 1),\n          par(n_, -1),\n          dep(n_),\n         \
    \ inv(n_),\n          types(n_) {\n    }\n\n    /**\n     * \u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int size() const {\n     \
    \   return n;\n    }\n\n    /**\n     * \u9802\u70B9 u \u3068 v \u3092\u7D50\u3076\
    \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n     * O(1)\n     */\n\
    \    void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n\n    /**\n     * \u6839\u96C6\u5408\u3092\u6839\u3068\u3057\u305F\u6709\
    \u5411\u68EE\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * O(n)\n     */\n    void\
    \ build(const std::vector<int>& rs = {0}) {\n        int pos = 0;\n        for\
    \ (int r : rs) {\n            dfs_sz(r);\n            head[r] = r;\n         \
    \   dfs_hld(r, r, pos);\n        }\n    }\n\n    /**\n     * \u30AA\u30A4\u30E9\
    \u30FC\u30C4\u30A2\u30FC\u3092\u884C\u3063\u305F\u3042\u3068\u306E v \u306E\u9802\
    \u70B9\u756A\u53F7\u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int operator[](int\
    \ v) const {\n        return vid[v];\n    }\n\n    /**\n     * v \u306E\u6DF1\u3055\
    \u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int depth(int v) const {\n\
    \        return dep[v];\n    }\n\n    /**\n     * v \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\u3002\n     * O(1)\n\
    \     */\n    int subtree_size(int v) const {\n        return sub[v];\n    }\n\
    \n    /**\n     * v \u306E\u89AA\u3092\u8FD4\u3059\u3002\n     * v \u304C\u6839\
    \u306E\u3068\u304D\u3001-1 \u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n  \
    \  int parent(int v) const {\n        return par[v];\n    }\n\n    /**\n     *\
    \ v \u306E\u6839\u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int type(int\
    \ v) const {\n        return types[v];\n    }\n\n    /**\n     * v \u304B\u3089\
    \ k \u56DE\u89AA\u3092\u8FBF\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\u3002\n\
    \     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u3001-1 \u3092\u8FD4\u3059\u3002\
    \n     * O(log(n))\n     */\n    int kth_ancestor(int v, int k) const {\n    \
    \    if (dep[v] < k or k < 0) return -1;\n        while (true) {\n           \
    \ if (dep[v] - dep[head[v]] + 1 <= k) {\n                k -= dep[v] - dep[head[v]]\
    \ + 1;\n                v = par[head[v]];\n            } else {\n            \
    \    return inv[vid[v] - k];\n            }\n        }\n    }\n\n    /**\n   \
    \  * v \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C d \u306E\u7269\u3092\u8FD4\u3059\
    \u3002\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -1 \u3092\u8FD4\u3059\
    \u3002\n     * O(log(n))\n     */\n    int level_ancestor(int v, int d) const\
    \ {\n        return kth_ancestor(v, dep[v] - d);\n    }\n\n    /**\n     * u \u3068\
    \ v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u3092\u8FD4\u3059\u3002\n     *\
    \ u \u3068 v \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\
    \u308B\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     * O(log(n))\n     */\n  \
    \  int lca(int u, int v) const {\n        if (types[u] != types[v]) return -1;\n\
    \        while (true) {\n            comparator_in(u, v);\n            if (head[u]\
    \ == head[v]) return u;\n            v = par[head[v]];\n        }\n    }\n\n \
    \   /**\n     * uv \u30D1\u30B9\u306E\u9577\u3055\u3092\u8FD4\u3059\u3002\n  \
    \   * u \u3068 v \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\
    \u308B\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     * O(log(n))\n     */\n  \
    \  int distance(int u, int v) const {\n        if (types[u] != types[v]) return\
    \ -1;\n        int w = lca(u, v);\n        return distance(u, v, w);\n    }\n\n\
    \    /**\n     * w \u304C u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u3067\u3042\u308B\u3068\u304D\u306E uv \u30D1\u30B9\u306E\u9577\u3055\u3092\u8FD4\
    \u3059\u3002\n     * w \u304C u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u3067\u3042\u308B\u3053\u3068\u306F\u547C\u3073\u51FA\u3057\u5074\u304C\u4FDD\
    \u8A3C\u3059\u308B\u3002\n     * O(1)\n     */\n    int distance(int u, int v,\
    \ int w) const {\n        return dep[u] + dep[v] - 2 * dep[w];\n    }\n\n    /**\n\
    \     * \u8FBA uv \u3092\u5207\u3063\u305F\u3068\u304D\u306B\u3067\u304D\u308B\
    \ 2 \u3064\u306E\u6728\u306E\u3046\u3061\u3001\n     * u \u3092\u542B\u3080\u65B9\
    \u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\u3002\n     * uv \u8FBA\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     * O(1)\n\
    \     */\n    int cut_size(int u, int v) const {\n        if (par[u] == v) return\
    \ sub[u];\n        if (par[v] == u) return n - sub[v];\n        return -1;\n \
    \   }\n\n    /**\n     * uv \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3067\u3001u\
    \ \u304B\u3089\u306E\u8DDD\u96E2\u304C d \u3067\u3042\u308B\u3082\u306E\u3092\u8FD4\
    \u3059\u3002\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -1 \u3092\u8FD4\
    \u3059\u3002\n     * O(log(n))\n     */\n    int jump(int u, int v, int d) const\
    \ {\n        if (types[u] != types[v]) return -1;\n        int w = lca(u, v);\n\
    \        int L = distance(u, v, w);\n        if (L < d) return -1;\n        if\
    \ (d <= distance(u, w, w)) return kth_ancestor(u, d);\n        return kth_ancestor(v,\
    \ L - d);\n    }\n\n    /**\n     * uv \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3067\
    \u3001u \u304B\u3089\u8DDD\u96E2 1 \u3067\u3042\u308B\u3082\u306E\u3092\u8FD4\u3059\
    \u3002\n     * u == v \u306E\u3068\u304D -1 \u3092\u8FD4\u3059\u3002\n     * O(log(n))\n\
    \     */\n    int step(int u, int v) const {\n        return jump(u, v, 1);\n\
    \    }\n\n    /**\n     * u, v, w \u307E\u3067\u306E\u30D1\u30B9\u304C\u8FBA\u3092\
    \u5171\u6709\u3057\u306A\u3044\u3088\u3046\u306A\u552F\u4E00\u306E\u9802\u70B9\
    \u3092\u8FD4\u3059\u3002\n     * u, v, w \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\
    \u5206\u306B\u5C5E\u3059\u308B\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     *\
    \ O(log(n))\n     */\n    int meet(int u, int v, int w) const {\n        if (types[u]\
    \ != types[v] || types[u] != types[w]) return -1;\n        comparator_in(u, v);\n\
    \        comparator_in(v, w);\n        comparator_in(u, v);\n        int a = lca(u,\
    \ v);\n        int b = lca(v, w);\n        if (dep[a] < dep[b]) return b;\n  \
    \      return a;\n    }\n\n    /**\n     * uv \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\
    \uFF08\u7AEF\u70B9\u542B\u3080\uFF09\u3092\u305D\u306E\u9806\u306B\u8FD4\u3059\
    \u3002\n     * u \u3068 v \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u306B\
    \u5C5E\u3059\u308B\u5834\u5408\u7A7A\u306E\u914D\u5217\u3092\u8FD4\u3059\u3002\
    \n     * O(n)\n     */\n    std::vector<int> path(int u, int v) const {\n    \
    \    if (types[u] != types[v]) return {};\n        int w = lca(u, v);\n      \
    \  int L = distance(u, v, w);\n        std::vector<int> ret(L + 1);\n        int\
    \ it = 0;\n        while (u != w) {\n            ret[it++] = u;\n            u\
    \ = par[u];\n        }\n        it = L;\n        while (v != w) {\n          \
    \  ret[it--] = v;\n            v = par[v];\n        }\n        ret[it] = w;\n\
    \        return ret;\n    }\n\n    /**\n     * uv \u30D1\u30B9\u3092\u8907\u6570\
    \u306E\u533A\u9593\u3068\u3057\u3066\u53D6\u5F97\u3057\u3001\u64CD\u4F5C\u3059\
    \u308B\u3002\n     * \u533A\u9593\u306E\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3059\
    \u308B\u3068\u304D\u306F\u53EF\u63DB\u3067\u3042\u308B\u3053\u3068\u304C\u6C42\
    \u3081\u3089\u308C\u308B\u3002\n     * F f \u306F\u533A\u9593 [l,r) \u3092\u5F15\
    \u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n     * auto f=[&](int l, int r) {\n\
    \     *     //\u533A\u9593[l,r)\u306B\u5BFE\u3059\u308B\u51E6\u7406\n     * };\n\
    \     * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\
    \u91CF\u3092 O(X) \u3068\u3057\u3066 O(Xlog(n))\n     */\n    template <class\
    \ F> void path_query_vertex(int u, int v, const F& f) const {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        while (true) {\n\
    \            comparator_in(u, v);\n            f(max(vid[head[v]], vid[u]), vid[v]\
    \ + 1);\n            if (head[u] != head[v])\n                v = par[head[v]];\n\
    \            else\n                break;\n        }\n    }\n\n    /**\n     *\
    \ uv \u30D1\u30B9\u3092\u8907\u6570\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\u5F97\
    \u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * \u533A\u9593\u306E\u8981\u7D20\
    \u3092\u30DE\u30FC\u30B8\u3059\u308B\u3068\u304D\u306F\u53EF\u63DB\u3067\u3042\
    \u308B\u3053\u3068\u304C\u6C42\u3081\u3089\u308C\u308B\u3002\n     * F f \u306F\
    \u533A\u9593 [l,r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n  \
    \   * auto f=[&](int l, int r) {\n     *     //\u533A\u9593[l,r)\u306B\u5BFE\u3059\
    \u308B\u51E6\u7406\n     * };\n     * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\
    \u64CD\u4F5C\u306E\u8A08\u7B97\u91CF\u3092 O(X) \u3068\u3057\u3066 O(Xlog(n))\n\
    \     */\n    template <class F> void path_query_edge(int u, int v, const F& f)\
    \ const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        while (true) {\n            comparator_in(u, v);\n            if (head[u]\
    \ != head[v]) {\n                f(vid[head[v]], vid[v] + 1);\n              \
    \  v = par[head[v]];\n            } else {\n                if (u != v) f(vid[u]\
    \ + 1, vid[v] + 1);\n                break;\n            }\n        }\n    }\n\
    \n    /**\n     * v \u3092\u6839\u3068\u3057\u305F\u90E8\u5206\u6728\u3092\u4E00\
    \u3064\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\u5F97\u3057\u3001\u64CD\u4F5C\
    \u3059\u308B\u3002\n     * F f \u306F\u533A\u9593 [l,r) \u3092\u5F15\u6570\u306B\
    \u3068\u308B\u95A2\u6570\u3002\n     * auto f=[&](int l, int r) {\n     *    \
    \ //\u533A\u9593 [l, r) \u306B\u5BFE\u3059\u308B\u51E6\u7406\n     * };\n    \
    \ * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\u91CF\
    \u3092 O(X) \u3068\u3057\u3066 O(X)\n     */\n    template <class F> void subtree_query_vertex(int\
    \ v, const F& f) const {\n        assert(0 <= v and v < n);\n        f(vid[v],\
    \ vid[v] + sub[v]);\n    }\n\n    /**\n     * v \u3092\u6839\u3068\u3057\u305F\
    \u90E8\u5206\u6728\u3092\u4E00\u3064\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\
    \u5F97\u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * F f \u306F\u533A\u9593\
    \ [l, r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n     * auto f=[&](int\
    \ l, int r) {\n     *     //\u533A\u9593 [l, r) \u306B\u5BFE\u3059\u308B\u51E6\
    \u7406\n     * };\n     * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\
    \u306E\u8A08\u7B97\u91CF\u3092 O(X) \u3068\u3057\u3066 O(X)\n     */\n    template\
    \ <class F> void subtree_query_edge(int v, const F& f) const {\n        assert(0\
    \ <= v and v < n);\n        f(vid[v] + 1, vid[v] + sub[v]);\n    }\n\n    /**\n\
    \     * uv \u30D1\u30B9\u3092\u8907\u6570\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\
    \u5F97\u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * \u30E2\u30CE\u30A4\u30C9\
    \u304C\u975E\u53EF\u63DB\u3067\u3082\u52D5\u304F\u3002\n     * F f \u306F\u533A\
    \u9593 [l,r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n     * auto\
    \ f=[&](int l, int r) {\n     *     if (l < r) {\n     *         //\u5DE6\u304B\
    \u3089\u53F3\u306B\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3057\u305F\u3068\u304D\
    \u306E\u7A4D\u3092\u53D6\u5F97\n     *         return get(l,r)\n     *     } else\
    \ {\n     *         //\u53F3\u304B\u3089\u5DE6\u306B\u8981\u7D20\u3092\u30DE\u30FC\
    \u30B8\u3057\u305F\u3068\u304D\u306E\u7A4D\u3092\u53D6\u5F97\n     *         return\
    \ get(r,l)\n     *     }\n     * };\n     * M op \u306F\u30DE\u30FC\u30B8\u3059\
    \u308B\u95A2\u6570\n     * T e \u306F\u5358\u4F4D\u5143\n     * \u4E00\u3064\u306E\
    \u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\u91CF\u3092 O(X) \u3068\
    \u3057\u3066 O(Xlog(n))\n     */\n    template <class T, class F, class M>\n \
    \   T noncommutative_query_vertex(int u, int v, T e, const F& f, const M& op)\n\
    \        const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and\
    \ v < n);\n        int w = lca(u, v);\n        T resl = e, resr = e;\n       \
    \ while (true) {\n            resl = op(resl, f(vid[u] + 1, max(vid[head[u]],\
    \ vid[w])));\n            if (head[w] != head[u])\n                u = par[head[u]];\n\
    \            else\n                break;\n        }\n        while (true) {\n\
    \            if (head[w] != head[v]) {\n                resr = op(f(vid[head[v]],\
    \ vid[v] + 1), resr);\n                v = par[head[v]];\n            } else {\n\
    \                if (w != v) resr = op(f(vid[w] + 1, vid[v] + 1), resr);\n   \
    \             break;\n            }\n        }\n        return op(resl, resr);\n\
    \    }\n\n    /**\n     * uv \u30D1\u30B9\u3092\u8907\u6570\u306E\u533A\u9593\u3068\
    \u3057\u3066\u53D6\u5F97\u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * \u30E2\
    \u30CE\u30A4\u30C9\u304C\u975E\u53EF\u63DB\u3067\u3082\u52D5\u304F\u3002\n   \
    \  * F f \u306F\u533A\u9593 [l,r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\
    \u3002\n     * auto f=[&](int l, int r) {\n     *     if (l < r) {\n     *   \
    \      //\u5DE6\u304B\u3089\u53F3\u306B\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3057\
    \u305F\u3068\u304D\u306E\u7A4D\u3092\u53D6\u5F97\n     *         return get(l,r)\n\
    \     *     } else {\n     *         //\u53F3\u304B\u3089\u5DE6\u306B\u8981\u7D20\
    \u3092\u30DE\u30FC\u30B8\u3057\u305F\u3068\u304D\u306E\u7A4D\u3092\u53D6\u5F97\
    \n     *         return get(r,l)\n     *     }\n     * };\n     * M op \u306F\u30DE\
    \u30FC\u30B8\u3059\u308B\u95A2\u6570\n     * T e \u306F\u5358\u4F4D\u5143\n  \
    \   * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\
    \u91CF\u3092 O(X) \u3068\u3057\u3066 O(Xlog(n))\n     */\n    template <class\
    \ T, class F, class M>\n    T noncommutative_query_edge(int u, int v, T e, const\
    \ F& f, const M& op)\n        const {\n        assert(0 <= u and u < n);\n   \
    \     assert(0 <= v and v < n);\n        int w = lca(u, v);\n        T resl =\
    \ e, resr = e;\n        while (true) {\n            if (head[w] != head[u]) {\n\
    \                resl = op(resl, f(vid[u] + 1, vid[head[u]]));\n             \
    \   u = par[head[u]];\n            } else {\n                if (w != u) resl\
    \ = op(resl, f(vid[u] + 1, vid[w] + 1));\n                break;\n           \
    \ }\n        }\n        while (true) {\n            if (head[w] != head[v]) {\n\
    \                resr = op(f(vid[head[v]], vid[v] + 1), resr);\n             \
    \   v = par[head[v]];\n            } else {\n                if (w != v) resr\
    \ = op(f(vid[w] + 1, vid[v] + 1), resr);\n                break;\n           \
    \ }\n        }\n        return op(resl, resr);\n    }\n\n    int n;\n    std::vector<int>\
    \ vid, head, sub, par, dep, inv, types;\n\n    void dfs_sz(int v) {\n        std::vector<int>&\
    \ es = g[v];\n        if (~par[v]) es.erase(std::find(es.begin(), es.end(), par[v]));\n\
    \n        for (int& u : es) {\n            par[u] = v;\n            dep[u] = dep[v]\
    \ + 1;\n            dfs_sz(u);\n            sub[v] += sub[u];\n            if\
    \ (sub[u] > sub[es[0]]) std::swap(u, es[0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ v, int c, int& pos) {\n        vid[v] = pos++;\n        inv[vid[v]] = v;\n \
    \       types[v] = c;\n        for (int u : g[v]) {\n            head[u] = (u\
    \ == g[v][0] ? head[v] : u);\n            dfs_hld(u, c, pos);\n        }\n   \
    \ }\n\n    void comparator_in(int& u, int& v) const {\n        if (vid[u] > vid[v])\
    \ std::swap(u, v);\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n/**\n *   HeavyLightDecomposition\n *   \u69CB\u7BC9 O(n) \u7A7A\u9593 O(n)\n\
    \ *\n *   \u9802\u70B9 v \u306E\u60C5\u5831\u306F HLD[v] \u306B\u6301\u305F\u305B\
    \u308B\u3002\n *   \u8FBA uv \u306E\u60C5\u5831\u306F dep[u] < dep[v] \u3068\u3057\
    \u3066 HLD[v] \u306B\u6301\u305F\u305B\u308B\u3002\n *   \uFF08\u3064\u307E\u308A\
    \u6DF1\u3044\u65B9,\u5B50\u306E\u9802\u70B9\u306B\u5BFE\u5FDC\u3055\u305B\u308B\
    \uFF09\n *   \u3044\u305A\u308C\u306B\u305B\u3088\u30C7\u30FC\u30BF\u69CB\u9020\
    \u306F n \u9802\u70B9\u5206\u69CB\u7BC9\u3059\u308B\u3002\n */\nstruct HeavyLightDecomposition\
    \ {\n    std::vector<std::vector<int>> g;\n\n    /**\n     *  n \u9802\u70B9 0\
    \ \u8FBA\u306E\u7121\u5411\u30B0\u30E9\u30D5\u3092\u4F5C\u308B\u3002\n     * \
    \ O(n)\n     */\n    HeavyLightDecomposition(int n_)\n        : g(n_),\n     \
    \     n(n_),\n          vid(n_),\n          head(n_),\n          sub(n_, 1),\n\
    \          par(n_, -1),\n          dep(n_),\n          inv(n_),\n          types(n_)\
    \ {\n    }\n\n    /**\n     * \u9802\u70B9\u6570\u3092\u8FD4\u3059\u3002\n   \
    \  * O(1)\n     */\n    int size() const {\n        return n;\n    }\n\n    /**\n\
    \     * \u9802\u70B9 u \u3068 v \u3092\u7D50\u3076\u7121\u5411\u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\u3002\n     * O(1)\n     */\n    void add_edge(int u, int v)\
    \ {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n    }\n\n \
    \   /**\n     * \u6839\u96C6\u5408\u3092\u6839\u3068\u3057\u305F\u6709\u5411\u68EE\
    \u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * O(n)\n     */\n    void build(const\
    \ std::vector<int>& rs = {0}) {\n        int pos = 0;\n        for (int r : rs)\
    \ {\n            dfs_sz(r);\n            head[r] = r;\n            dfs_hld(r,\
    \ r, pos);\n        }\n    }\n\n    /**\n     * \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\u3092\u884C\u3063\u305F\u3042\u3068\u306E v \u306E\u9802\u70B9\u756A\
    \u53F7\u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int operator[](int v)\
    \ const {\n        return vid[v];\n    }\n\n    /**\n     * v \u306E\u6DF1\u3055\
    \u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int depth(int v) const {\n\
    \        return dep[v];\n    }\n\n    /**\n     * v \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\u3002\n     * O(1)\n\
    \     */\n    int subtree_size(int v) const {\n        return sub[v];\n    }\n\
    \n    /**\n     * v \u306E\u89AA\u3092\u8FD4\u3059\u3002\n     * v \u304C\u6839\
    \u306E\u3068\u304D\u3001-1 \u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n  \
    \  int parent(int v) const {\n        return par[v];\n    }\n\n    /**\n     *\
    \ v \u306E\u6839\u3092\u8FD4\u3059\u3002\n     * O(1)\n     */\n    int type(int\
    \ v) const {\n        return types[v];\n    }\n\n    /**\n     * v \u304B\u3089\
    \ k \u56DE\u89AA\u3092\u8FBF\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\u3002\n\
    \     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u3001-1 \u3092\u8FD4\u3059\u3002\
    \n     * O(log(n))\n     */\n    int kth_ancestor(int v, int k) const {\n    \
    \    if (dep[v] < k or k < 0) return -1;\n        while (true) {\n           \
    \ if (dep[v] - dep[head[v]] + 1 <= k) {\n                k -= dep[v] - dep[head[v]]\
    \ + 1;\n                v = par[head[v]];\n            } else {\n            \
    \    return inv[vid[v] - k];\n            }\n        }\n    }\n\n    /**\n   \
    \  * v \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C d \u306E\u7269\u3092\u8FD4\u3059\
    \u3002\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -1 \u3092\u8FD4\u3059\
    \u3002\n     * O(log(n))\n     */\n    int level_ancestor(int v, int d) const\
    \ {\n        return kth_ancestor(v, dep[v] - d);\n    }\n\n    /**\n     * u \u3068\
    \ v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u3092\u8FD4\u3059\u3002\n     *\
    \ u \u3068 v \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\
    \u308B\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     * O(log(n))\n     */\n  \
    \  int lca(int u, int v) const {\n        if (types[u] != types[v]) return -1;\n\
    \        while (true) {\n            comparator_in(u, v);\n            if (head[u]\
    \ == head[v]) return u;\n            v = par[head[v]];\n        }\n    }\n\n \
    \   /**\n     * uv \u30D1\u30B9\u306E\u9577\u3055\u3092\u8FD4\u3059\u3002\n  \
    \   * u \u3068 v \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\
    \u308B\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     * O(log(n))\n     */\n  \
    \  int distance(int u, int v) const {\n        if (types[u] != types[v]) return\
    \ -1;\n        int w = lca(u, v);\n        return distance(u, v, w);\n    }\n\n\
    \    /**\n     * w \u304C u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u3067\u3042\u308B\u3068\u304D\u306E uv \u30D1\u30B9\u306E\u9577\u3055\u3092\u8FD4\
    \u3059\u3002\n     * w \u304C u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \u3067\u3042\u308B\u3053\u3068\u306F\u547C\u3073\u51FA\u3057\u5074\u304C\u4FDD\
    \u8A3C\u3059\u308B\u3002\n     * O(1)\n     */\n    int distance(int u, int v,\
    \ int w) const {\n        return dep[u] + dep[v] - 2 * dep[w];\n    }\n\n    /**\n\
    \     * \u8FBA uv \u3092\u5207\u3063\u305F\u3068\u304D\u306B\u3067\u304D\u308B\
    \ 2 \u3064\u306E\u6728\u306E\u3046\u3061\u3001\n     * u \u3092\u542B\u3080\u65B9\
    \u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\u3002\n     * uv \u8FBA\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     * O(1)\n\
    \     */\n    int cut_size(int u, int v) const {\n        if (par[u] == v) return\
    \ sub[u];\n        if (par[v] == u) return n - sub[v];\n        return -1;\n \
    \   }\n\n    /**\n     * uv \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3067\u3001u\
    \ \u304B\u3089\u306E\u8DDD\u96E2\u304C d \u3067\u3042\u308B\u3082\u306E\u3092\u8FD4\
    \u3059\u3002\n     * \u5B58\u5728\u3057\u306A\u3044\u5834\u5408 -1 \u3092\u8FD4\
    \u3059\u3002\n     * O(log(n))\n     */\n    int jump(int u, int v, int d) const\
    \ {\n        if (types[u] != types[v]) return -1;\n        int w = lca(u, v);\n\
    \        int L = distance(u, v, w);\n        if (L < d) return -1;\n        if\
    \ (d <= distance(u, w, w)) return kth_ancestor(u, d);\n        return kth_ancestor(v,\
    \ L - d);\n    }\n\n    /**\n     * uv \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3067\
    \u3001u \u304B\u3089\u8DDD\u96E2 1 \u3067\u3042\u308B\u3082\u306E\u3092\u8FD4\u3059\
    \u3002\n     * u == v \u306E\u3068\u304D -1 \u3092\u8FD4\u3059\u3002\n     * O(log(n))\n\
    \     */\n    int step(int u, int v) const {\n        return jump(u, v, 1);\n\
    \    }\n\n    /**\n     * u, v, w \u307E\u3067\u306E\u30D1\u30B9\u304C\u8FBA\u3092\
    \u5171\u6709\u3057\u306A\u3044\u3088\u3046\u306A\u552F\u4E00\u306E\u9802\u70B9\
    \u3092\u8FD4\u3059\u3002\n     * u, v, w \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\
    \u5206\u306B\u5C5E\u3059\u308B\u5834\u5408 -1 \u3092\u8FD4\u3059\u3002\n     *\
    \ O(log(n))\n     */\n    int meet(int u, int v, int w) const {\n        if (types[u]\
    \ != types[v] || types[u] != types[w]) return -1;\n        comparator_in(u, v);\n\
    \        comparator_in(v, w);\n        comparator_in(u, v);\n        int a = lca(u,\
    \ v);\n        int b = lca(v, w);\n        if (dep[a] < dep[b]) return b;\n  \
    \      return a;\n    }\n\n    /**\n     * uv \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\
    \uFF08\u7AEF\u70B9\u542B\u3080\uFF09\u3092\u305D\u306E\u9806\u306B\u8FD4\u3059\
    \u3002\n     * u \u3068 v \u304C\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u306B\
    \u5C5E\u3059\u308B\u5834\u5408\u7A7A\u306E\u914D\u5217\u3092\u8FD4\u3059\u3002\
    \n     * O(n)\n     */\n    std::vector<int> path(int u, int v) const {\n    \
    \    if (types[u] != types[v]) return {};\n        int w = lca(u, v);\n      \
    \  int L = distance(u, v, w);\n        std::vector<int> ret(L + 1);\n        int\
    \ it = 0;\n        while (u != w) {\n            ret[it++] = u;\n            u\
    \ = par[u];\n        }\n        it = L;\n        while (v != w) {\n          \
    \  ret[it--] = v;\n            v = par[v];\n        }\n        ret[it] = w;\n\
    \        return ret;\n    }\n\n    /**\n     * uv \u30D1\u30B9\u3092\u8907\u6570\
    \u306E\u533A\u9593\u3068\u3057\u3066\u53D6\u5F97\u3057\u3001\u64CD\u4F5C\u3059\
    \u308B\u3002\n     * \u533A\u9593\u306E\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3059\
    \u308B\u3068\u304D\u306F\u53EF\u63DB\u3067\u3042\u308B\u3053\u3068\u304C\u6C42\
    \u3081\u3089\u308C\u308B\u3002\n     * F f \u306F\u533A\u9593 [l,r) \u3092\u5F15\
    \u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n     * auto f=[&](int l, int r) {\n\
    \     *     //\u533A\u9593[l,r)\u306B\u5BFE\u3059\u308B\u51E6\u7406\n     * };\n\
    \     * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\
    \u91CF\u3092 O(X) \u3068\u3057\u3066 O(Xlog(n))\n     */\n    template <class\
    \ F> void path_query_vertex(int u, int v, const F& f) const {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        while (true) {\n\
    \            comparator_in(u, v);\n            f(max(vid[head[v]], vid[u]), vid[v]\
    \ + 1);\n            if (head[u] != head[v])\n                v = par[head[v]];\n\
    \            else\n                break;\n        }\n    }\n\n    /**\n     *\
    \ uv \u30D1\u30B9\u3092\u8907\u6570\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\u5F97\
    \u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * \u533A\u9593\u306E\u8981\u7D20\
    \u3092\u30DE\u30FC\u30B8\u3059\u308B\u3068\u304D\u306F\u53EF\u63DB\u3067\u3042\
    \u308B\u3053\u3068\u304C\u6C42\u3081\u3089\u308C\u308B\u3002\n     * F f \u306F\
    \u533A\u9593 [l,r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n  \
    \   * auto f=[&](int l, int r) {\n     *     //\u533A\u9593[l,r)\u306B\u5BFE\u3059\
    \u308B\u51E6\u7406\n     * };\n     * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\
    \u64CD\u4F5C\u306E\u8A08\u7B97\u91CF\u3092 O(X) \u3068\u3057\u3066 O(Xlog(n))\n\
    \     */\n    template <class F> void path_query_edge(int u, int v, const F& f)\
    \ const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        while (true) {\n            comparator_in(u, v);\n            if (head[u]\
    \ != head[v]) {\n                f(vid[head[v]], vid[v] + 1);\n              \
    \  v = par[head[v]];\n            } else {\n                if (u != v) f(vid[u]\
    \ + 1, vid[v] + 1);\n                break;\n            }\n        }\n    }\n\
    \n    /**\n     * v \u3092\u6839\u3068\u3057\u305F\u90E8\u5206\u6728\u3092\u4E00\
    \u3064\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\u5F97\u3057\u3001\u64CD\u4F5C\
    \u3059\u308B\u3002\n     * F f \u306F\u533A\u9593 [l,r) \u3092\u5F15\u6570\u306B\
    \u3068\u308B\u95A2\u6570\u3002\n     * auto f=[&](int l, int r) {\n     *    \
    \ //\u533A\u9593 [l, r) \u306B\u5BFE\u3059\u308B\u51E6\u7406\n     * };\n    \
    \ * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\u91CF\
    \u3092 O(X) \u3068\u3057\u3066 O(X)\n     */\n    template <class F> void subtree_query_vertex(int\
    \ v, const F& f) const {\n        assert(0 <= v and v < n);\n        f(vid[v],\
    \ vid[v] + sub[v]);\n    }\n\n    /**\n     * v \u3092\u6839\u3068\u3057\u305F\
    \u90E8\u5206\u6728\u3092\u4E00\u3064\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\
    \u5F97\u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * F f \u306F\u533A\u9593\
    \ [l, r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n     * auto f=[&](int\
    \ l, int r) {\n     *     //\u533A\u9593 [l, r) \u306B\u5BFE\u3059\u308B\u51E6\
    \u7406\n     * };\n     * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\
    \u306E\u8A08\u7B97\u91CF\u3092 O(X) \u3068\u3057\u3066 O(X)\n     */\n    template\
    \ <class F> void subtree_query_edge(int v, const F& f) const {\n        assert(0\
    \ <= v and v < n);\n        f(vid[v] + 1, vid[v] + sub[v]);\n    }\n\n    /**\n\
    \     * uv \u30D1\u30B9\u3092\u8907\u6570\u306E\u533A\u9593\u3068\u3057\u3066\u53D6\
    \u5F97\u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * \u30E2\u30CE\u30A4\u30C9\
    \u304C\u975E\u53EF\u63DB\u3067\u3082\u52D5\u304F\u3002\n     * F f \u306F\u533A\
    \u9593 [l,r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\u3002\n     * auto\
    \ f=[&](int l, int r) {\n     *     if (l < r) {\n     *         //\u5DE6\u304B\
    \u3089\u53F3\u306B\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3057\u305F\u3068\u304D\
    \u306E\u7A4D\u3092\u53D6\u5F97\n     *         return get(l,r)\n     *     } else\
    \ {\n     *         //\u53F3\u304B\u3089\u5DE6\u306B\u8981\u7D20\u3092\u30DE\u30FC\
    \u30B8\u3057\u305F\u3068\u304D\u306E\u7A4D\u3092\u53D6\u5F97\n     *         return\
    \ get(r,l)\n     *     }\n     * };\n     * M op \u306F\u30DE\u30FC\u30B8\u3059\
    \u308B\u95A2\u6570\n     * T e \u306F\u5358\u4F4D\u5143\n     * \u4E00\u3064\u306E\
    \u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\u91CF\u3092 O(X) \u3068\
    \u3057\u3066 O(Xlog(n))\n     */\n    template <class T, class F, class M>\n \
    \   T noncommutative_query_vertex(int u, int v, T e, const F& f, const M& op)\n\
    \        const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and\
    \ v < n);\n        int w = lca(u, v);\n        T resl = e, resr = e;\n       \
    \ while (true) {\n            resl = op(resl, f(vid[u] + 1, max(vid[head[u]],\
    \ vid[w])));\n            if (head[w] != head[u])\n                u = par[head[u]];\n\
    \            else\n                break;\n        }\n        while (true) {\n\
    \            if (head[w] != head[v]) {\n                resr = op(f(vid[head[v]],\
    \ vid[v] + 1), resr);\n                v = par[head[v]];\n            } else {\n\
    \                if (w != v) resr = op(f(vid[w] + 1, vid[v] + 1), resr);\n   \
    \             break;\n            }\n        }\n        return op(resl, resr);\n\
    \    }\n\n    /**\n     * uv \u30D1\u30B9\u3092\u8907\u6570\u306E\u533A\u9593\u3068\
    \u3057\u3066\u53D6\u5F97\u3057\u3001\u64CD\u4F5C\u3059\u308B\u3002\n     * \u30E2\
    \u30CE\u30A4\u30C9\u304C\u975E\u53EF\u63DB\u3067\u3082\u52D5\u304F\u3002\n   \
    \  * F f \u306F\u533A\u9593 [l,r) \u3092\u5F15\u6570\u306B\u3068\u308B\u95A2\u6570\
    \u3002\n     * auto f=[&](int l, int r) {\n     *     if (l < r) {\n     *   \
    \      //\u5DE6\u304B\u3089\u53F3\u306B\u8981\u7D20\u3092\u30DE\u30FC\u30B8\u3057\
    \u305F\u3068\u304D\u306E\u7A4D\u3092\u53D6\u5F97\n     *         return get(l,r)\n\
    \     *     } else {\n     *         //\u53F3\u304B\u3089\u5DE6\u306B\u8981\u7D20\
    \u3092\u30DE\u30FC\u30B8\u3057\u305F\u3068\u304D\u306E\u7A4D\u3092\u53D6\u5F97\
    \n     *         return get(r,l)\n     *     }\n     * };\n     * M op \u306F\u30DE\
    \u30FC\u30B8\u3059\u308B\u95A2\u6570\n     * T e \u306F\u5358\u4F4D\u5143\n  \
    \   * \u4E00\u3064\u306E\u533A\u9593\u3078\u306E\u64CD\u4F5C\u306E\u8A08\u7B97\
    \u91CF\u3092 O(X) \u3068\u3057\u3066 O(Xlog(n))\n     */\n    template <class\
    \ T, class F, class M>\n    T noncommutative_query_edge(int u, int v, T e, const\
    \ F& f, const M& op)\n        const {\n        assert(0 <= u and u < n);\n   \
    \     assert(0 <= v and v < n);\n        int w = lca(u, v);\n        T resl =\
    \ e, resr = e;\n        while (true) {\n            if (head[w] != head[u]) {\n\
    \                resl = op(resl, f(vid[u] + 1, vid[head[u]]));\n             \
    \   u = par[head[u]];\n            } else {\n                if (w != u) resl\
    \ = op(resl, f(vid[u] + 1, vid[w] + 1));\n                break;\n           \
    \ }\n        }\n        while (true) {\n            if (head[w] != head[v]) {\n\
    \                resr = op(f(vid[head[v]], vid[v] + 1), resr);\n             \
    \   v = par[head[v]];\n            } else {\n                if (w != v) resr\
    \ = op(f(vid[w] + 1, vid[v] + 1), resr);\n                break;\n           \
    \ }\n        }\n        return op(resl, resr);\n    }\n\n    int n;\n    std::vector<int>\
    \ vid, head, sub, par, dep, inv, types;\n\n    void dfs_sz(int v) {\n        std::vector<int>&\
    \ es = g[v];\n        if (~par[v]) es.erase(std::find(es.begin(), es.end(), par[v]));\n\
    \n        for (int& u : es) {\n            par[u] = v;\n            dep[u] = dep[v]\
    \ + 1;\n            dfs_sz(u);\n            sub[v] += sub[u];\n            if\
    \ (sub[u] > sub[es[0]]) std::swap(u, es[0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ v, int c, int& pos) {\n        vid[v] = pos++;\n        inv[vid[v]] = v;\n \
    \       types[v] = c;\n        for (int u : g[v]) {\n            head[u] = (u\
    \ == g[v][0] ? head[v] : u);\n            dfs_hld(u, c, pos);\n        }\n   \
    \ }\n\n    void comparator_in(int& u, int& v) const {\n        if (vid[u] > vid[v])\
    \ std::swap(u, v);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/tree/HeavyLightDecomposition.hpp
- /library/tree/HeavyLightDecomposition.hpp.html
title: tree/HeavyLightDecomposition.hpp
---
