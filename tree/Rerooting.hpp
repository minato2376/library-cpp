#pragma once

/**
 * @brief 全方位木 DP
 * @param n int 頂点数
 * @param op (EdgeValue a, EdgeValue b) -> EdgeValue : dp の値の演算
 * @param vtoe (VertexValue a, auto(Edge) e) -> EdgeValue : 頂点の dp
 * の値をから辺の dp の値を計算する
 * @param etov (EdgeValue a, int v) -> VertexValue : 辺の dp の値から頂点の dp
 * の値を計算する
 * @param id EdgeValue 単位元
 */
template <class EdgeValue,
          class VertexValue,
          class Weight,
          class F,
          class G,
          class H>
struct Rerooting {
    struct Edge {
        int from;
        int to;
        Weight weight;
        Edge(int from, int to, const Weight& weight)
            : from(from), to(to), weight(weight) {
        }
    };
    int n;
    vector<vector<Edge>> g;
    vector<VertexValue> subdp, dp;
    F op;
    G vtoe;
    H etov;
    EdgeValue id;

    Rerooting() {
    }
    Rerooting(int n,
              const F& op,
              const G& vtoe,
              const H& etov,
              const EdgeValue& id)
        : n(n), g(n), subdp(n), dp(n), op(op), vtoe(vtoe), etov(etov), id(id) {
    }

    void add_edge(int u, int v, const Weight& weight = Weight()) {
        g[u].emplace_back(u, v, weight);
        g[v].emplace_back(v, u, weight);
    }

    void build() {
        dfs_sub(0, -1);
        dfs_all(0, -1, VertexValue());
        return;
    }

    VertexValue operator[](int i) const {
        return dp[i];
    }

#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, const Rerooting& r) {
        os << "\nsubdp = " << r.subdp;
        os << "\ndp = " << r.dp;
        return os;
    }
#endif

  private:
    void dfs_sub(int v, int pv) {
        EdgeValue merge_value = id;
        for (const Edge& edge : g[v]) {
            if (edge.to == pv) continue;
            dfs_sub(edge.to, v);
            merge_value = op(merge_value, vtoe(subdp[edge.to], edge));
        }
        subdp[v] = etov(merge_value, v);
        return;
    }

    void dfs_all(int v, int pv, const VertexValue& top) {
        dp[v] = calc_dp(v, pv, top);

        vector<EdgeValue> prefix_sum = get_prefix_sum(v, pv, top);
        EdgeValue merge_value = id;
        for (int i = int(g[v].size()) - 1; i >= 0; i--) {
            if (g[v][i].to != pv) {
                dfs_all(g[v][i].to, v, etov(op(merge_value, prefix_sum[i]), v));
                merge_value = op(merge_value, vtoe(subdp[g[v][i].to], g[v][i]));
            } else {
                merge_value = op(merge_value, vtoe(top, g[v][i]));
            }
        }
        return;
    }

    VertexValue calc_dp(int v, int pv, const VertexValue& top) const {
        EdgeValue merge_value = id;
        for (const Edge& edge : g[v]) {
            if (edge.to == pv) {
                merge_value = op(merge_value, vtoe(top, edge));
            } else {
                merge_value = op(merge_value, vtoe(subdp[edge.to], edge));
            }
        }
        return etov(merge_value, v);
    }

    vector<EdgeValue> get_prefix_sum(int v,
                                     int pv,
                                     const VertexValue& top) const {
        vector<EdgeValue> prefix_sum(g[v].size(), id);
        for (int i = 0; i < int(g[v].size()) - 1; i++) {
            if (g[v][i].to == pv) {
                prefix_sum[i + 1] = op(prefix_sum[i], vtoe(top, g[v][i]));
            } else {
                prefix_sum[i + 1] =
                    op(prefix_sum[i], vtoe(subdp[g[v][i].to], g[v][i]));
            }
        }
        return prefix_sum;
    }
};