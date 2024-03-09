#pragma once

#include <cassert>
#include <cstdint>
#include <optional>
#include <queue>
#include <vector>

#include "datastructure/Csr.hpp"

struct Centroid {
    using Res = std::pair<int, std::optional<int>>;
    int n;
    Csr<int> g;
    std::vector<int8_t> dead;

    Centroid() {
    }
    Centroid(int n_) : n(n_), g(n_), dead(n_) {
    }

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        g.add_edge(u, v);
        g.add_edge(v, u);
    }

    void build() {
        g.build();
    }

    Res find_centroids(int v) const {
        int all_sub = get_size(v);
        Res res(-1, std::nullopt);
        get_centroid(v, -1, all_sub, res);
        return res;
    }

    int find_centroid(int v) const {
        return find_centroids(v).first;
    }

    bool is_dead(int v) const {
        return dead[v];
    }

    void disable(int v) {
        dead[v] = true;
    }

    const auto operator[](int v) const {
        return g[v];
    }

  private:
    int get_size(int r) const {
        std::queue<std::pair<int, int>> que;
        que.emplace(r, -1);
        int res = 0;
        while (!que.empty()) {
            auto [v, pv] = que.front();
            que.pop();
            for (int nv : g[v]) {
                if (nv == pv || dead[nv]) continue;
                que.emplace(nv, v);
            }
            res++;
        }
        return res;
    }

    int get_centroid(int v, int pv, int all_sub, Res& res) const {
        int sub = 1;
        bool is_centroid = true;
        for (int nv : g[v]) {
            if (nv == pv || dead[nv]) continue;
            int tmp = get_centroid(nv, v, all_sub, res);
            if (tmp > all_sub / 2) is_centroid = false;
            sub += tmp;
        }
        if (all_sub - sub > all_sub / 2) is_centroid = false;
        if (is_centroid) {
            if (res.first == -1) {
                res.first = v;
            } else {
                res.second = v;
            }
        }
        return sub;
    }
};