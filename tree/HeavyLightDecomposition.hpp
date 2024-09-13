#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

/**
 *   HeavyLightDecomposition
 *   構築 O(n) 空間 O(n)
 *
 *   頂点 v の情報は HLD[v] に持たせる。
 *   辺 uv の情報は dep[u] < dep[v] として HLD[v] に持たせる。
 *   （つまり深い方,子の頂点に対応させる）
 *   いずれにせよデータ構造は n 頂点分構築する。
 */
struct HeavyLightDecomposition {
    std::vector<std::vector<int>> g;

    /**
     *  n 頂点 0 辺の無向グラフを作る。
     *  O(n)
     */
    HeavyLightDecomposition(int n_)
        : g(n_),
          n(n_),
          vid(n_),
          head(n_),
          sub(n_, 1),
          par(n_, -1),
          dep(n_),
          inv(n_),
          types(n_) {
    }

    /**
     * 頂点数を返す。
     * O(1)
     */
    int size() const {
        return n;
    }

    /**
     * 頂点 u と v を結ぶ無向辺を追加する。
     * O(1)
     */
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    /**
     * 根集合を根とした有向森を構築する。
     * O(n)
     */
    void build(const std::vector<int>& rs = {0}) {
        int pos = 0;
        for (int r : rs) {
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, r, pos);
        }
    }

    /**
     * オイラーツアーを行ったあとの v の頂点番号を返す。
     * O(1)
     */
    int operator[](int v) const {
        return vid[v];
    }

    /**
     * v の深さを返す。
     * O(1)
     */
    int depth(int v) const {
        return dep[v];
    }

    /**
     * v を根とする部分木の頂点数を返す。
     * O(1)
     */
    int subtree_size(int v) const {
        return sub[v];
    }

    /**
     * v の親を返す。
     * v が根のとき、-1 を返す。
     * O(1)
     */
    int parent(int v) const {
        return par[v];
    }

    /**
     * v の根を返す。
     * O(1)
     */
    int type(int v) const {
        return types[v];
    }

    /**
     * v から k 回親を辿った頂点を返す。
     * 存在しない場合、-1 を返す。
     * O(log(n))
     */
    int kth_ancestor(int v, int k) const {
        if (dep[v] < k or k < 0) return -1;
        while (true) {
            if (dep[v] - dep[head[v]] + 1 <= k) {
                k -= dep[v] - dep[head[v]] + 1;
                v = par[head[v]];
            } else {
                return inv[vid[v] - k];
            }
        }
    }

    /**
     * v の祖先で深さが d の物を返す。
     * 存在しない場合 -1 を返す。
     * O(log(n))
     */
    int level_ancestor(int v, int d) const {
        return kth_ancestor(v, dep[v] - d);
    }

    /**
     * u と v の最小共通祖先を返す。
     * u と v が異なる連結成分に属する場合 -1 を返す。
     * O(log(n))
     */
    int lca(int u, int v) const {
        if (types[u] != types[v]) return -1;
        while (true) {
            comparator_in(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    /**
     * uv パスの長さを返す。
     * u と v が異なる連結成分に属する場合 -1 を返す。
     * O(log(n))
     */
    int distance(int u, int v) const {
        if (types[u] != types[v]) return -1;
        int w = lca(u, v);
        return distance(u, v, w);
    }

    /**
     * w が u と v の最小共通祖先であるときの uv パスの長さを返す。
     * w が u と v の最小共通祖先であることは呼び出し側が保証する。
     * O(1)
     */
    int distance(int u, int v, int w) const {
        return dep[u] + dep[v] - 2 * dep[w];
    }

    /**
     * 辺 uv を切ったときにできる 2 つの木のうち、
     * u を含む方の頂点数を返す。
     * uv 辺が存在しない場合 -1 を返す。
     * O(1)
     */
    int cut_size(int u, int v) const {
        if (par[u] == v) return sub[u];
        if (par[v] == u) return n - sub[v];
        return -1;
    }

    /**
     * uv パス上の頂点で、u からの距離が d であるものを返す。
     * 存在しない場合 -1 を返す。
     * O(log(n))
     */
    int jump(int u, int v, int d) const {
        if (types[u] != types[v]) return -1;
        int w = lca(u, v);
        int L = distance(u, v, w);
        if (L < d) return -1;
        if (d <= distance(u, w, w)) return kth_ancestor(u, d);
        return kth_ancestor(v, L - d);
    }

    /**
     * uv パス上の頂点で、u から距離 1 であるものを返す。
     * u == v のとき -1 を返す。
     * O(log(n))
     */
    int step(int u, int v) const {
        return jump(u, v, 1);
    }

    /**
     * u, v, w までのパスが辺を共有しないような唯一の頂点を返す。
     * u, v, w が異なる連結成分に属する場合 -1 を返す。
     * O(log(n))
     */
    int meet(int u, int v, int w) const {
        if (types[u] != types[v] || types[u] != types[w]) return -1;
        comparator_in(u, v);
        comparator_in(v, w);
        comparator_in(u, v);
        int a = lca(u, v);
        int b = lca(v, w);
        if (dep[a] < dep[b]) return b;
        return a;
    }

    /**
     * uv パス上の頂点（端点含む）をその順に返す。
     * u と v が異なる連結成分に属する場合空の配列を返す。
     * O(n)
     */
    std::vector<int> path(int u, int v) const {
        if (types[u] != types[v]) return {};
        int w = lca(u, v);
        int L = distance(u, v, w);
        std::vector<int> ret(L + 1);
        int it = 0;
        while (u != w) {
            ret[it++] = u;
            u = par[u];
        }
        it = L;
        while (v != w) {
            ret[it--] = v;
            v = par[v];
        }
        ret[it] = w;
        return ret;
    }

    /**
     * uv パスを複数の区間として取得し、操作する。
     * 区間の要素をマージするときは可換であることが求められる。
     * F f は区間 [l,r) を引数にとる関数。
     * auto f=[&](int l, int r) {
     *     //区間[l,r)に対する処理
     * };
     * 一つの区間への操作の計算量を O(X) として O(Xlog(n))
     */
    template <class F> void path_query_vertex(int u, int v, const F& f) const {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        while (true) {
            comparator_in(u, v);
            f(max(vid[head[v]], vid[u]), vid[v] + 1);
            if (head[u] != head[v])
                v = par[head[v]];
            else
                break;
        }
    }

    /**
     * uv パスを複数の区間として取得し、操作する。
     * 区間の要素をマージするときは可換であることが求められる。
     * F f は区間 [l,r) を引数にとる関数。
     * auto f=[&](int l, int r) {
     *     //区間[l,r)に対する処理
     * };
     * 一つの区間への操作の計算量を O(X) として O(Xlog(n))
     */
    template <class F> void path_query_edge(int u, int v, const F& f) const {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        while (true) {
            comparator_in(u, v);
            if (head[u] != head[v]) {
                f(vid[head[v]], vid[v] + 1);
                v = par[head[v]];
            } else {
                if (u != v) f(vid[u] + 1, vid[v] + 1);
                break;
            }
        }
    }

    /**
     * v を根とした部分木を一つの区間として取得し、操作する。
     * F f は区間 [l,r) を引数にとる関数。
     * auto f=[&](int l, int r) {
     *     //区間 [l, r) に対する処理
     * };
     * 一つの区間への操作の計算量を O(X) として O(X)
     */
    template <class F> void subtree_query_vertex(int v, const F& f) const {
        assert(0 <= v and v < n);
        f(vid[v], vid[v] + sub[v]);
    }

    /**
     * v を根とした部分木を一つの区間として取得し、操作する。
     * F f は区間 [l, r) を引数にとる関数。
     * auto f=[&](int l, int r) {
     *     //区間 [l, r) に対する処理
     * };
     * 一つの区間への操作の計算量を O(X) として O(X)
     */
    template <class F> void subtree_query_edge(int v, const F& f) const {
        assert(0 <= v and v < n);
        f(vid[v] + 1, vid[v] + sub[v]);
    }

    /**
     * uv パスを複数の区間として取得し、操作する。
     * モノイドが非可換でも動く。
     * F f は区間 [l,r) を引数にとる関数。
     * auto f=[&](int l, int r) {
     *     if (l < r) {
     *         //左から右に要素をマージしたときの積を取得
     *         return get(l,r)
     *     } else {
     *         //右から左に要素をマージしたときの積を取得
     *         return get(r,l)
     *     }
     * };
     * M op はマージする関数
     * T e は単位元
     * 一つの区間への操作の計算量を O(X) として O(Xlog(n))
     */
    template <class T, class F, class M>
    T noncommutative_query_vertex(int u, int v, T e, const F& f, const M& op)
        const {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        int w = lca(u, v);
        T resl = e, resr = e;
        while (true) {
            resl = op(resl, f(vid[u] + 1, max(vid[head[u]], vid[w])));
            if (head[w] != head[u])
                u = par[head[u]];
            else
                break;
        }
        while (true) {
            if (head[w] != head[v]) {
                resr = op(f(vid[head[v]], vid[v] + 1), resr);
                v = par[head[v]];
            } else {
                if (w != v) resr = op(f(vid[w] + 1, vid[v] + 1), resr);
                break;
            }
        }
        return op(resl, resr);
    }

    /**
     * uv パスを複数の区間として取得し、操作する。
     * モノイドが非可換でも動く。
     * F f は区間 [l,r) を引数にとる関数。
     * auto f=[&](int l, int r) {
     *     if (l < r) {
     *         //左から右に要素をマージしたときの積を取得
     *         return get(l,r)
     *     } else {
     *         //右から左に要素をマージしたときの積を取得
     *         return get(r,l)
     *     }
     * };
     * M op はマージする関数
     * T e は単位元
     * 一つの区間への操作の計算量を O(X) として O(Xlog(n))
     */
    template <class T, class F, class M>
    T noncommutative_query_edge(int u, int v, T e, const F& f, const M& op)
        const {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        int w = lca(u, v);
        T resl = e, resr = e;
        while (true) {
            if (head[w] != head[u]) {
                resl = op(resl, f(vid[u] + 1, vid[head[u]]));
                u = par[head[u]];
            } else {
                if (w != u) resl = op(resl, f(vid[u] + 1, vid[w] + 1));
                break;
            }
        }
        while (true) {
            if (head[w] != head[v]) {
                resr = op(f(vid[head[v]], vid[v] + 1), resr);
                v = par[head[v]];
            } else {
                if (w != v) resr = op(f(vid[w] + 1, vid[v] + 1), resr);
                break;
            }
        }
        return op(resl, resr);
    }

    int n;
    std::vector<int> vid, head, sub, par, dep, inv, types;

    void dfs_sz(int v) {
        std::vector<int>& es = g[v];
        if (~par[v]) es.erase(std::find(es.begin(), es.end(), par[v]));

        for (int& u : es) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[es[0]]) std::swap(u, es[0]);
        }
    }

    void dfs_hld(int v, int c, int& pos) {
        vid[v] = pos++;
        inv[vid[v]] = v;
        types[v] = c;
        for (int u : g[v]) {
            head[u] = (u == g[v][0] ? head[v] : u);
            dfs_hld(u, c, pos);
        }
    }

    void comparator_in(int& u, int& v) const {
        if (vid[u] > vid[v]) std::swap(u, v);
    }
};
