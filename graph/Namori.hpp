#pragma once

#include <algorithm>
#include <queue>
#include <vector>

#include "datastructure/Csr.hpp"

struct Namori {
    int n;
    Csr<int> g, forests;
    std::vector<int> deg, types, roots;

    Namori() {
    }
    Namori(int n_) : n(n_), g(n_), forests(n_), deg(n_), types(n_) {
    }

    void add_edge(int u, int v) {
        g.add_edge(u, v);
        g.add_edge(v, u);
        deg[u]++;
        deg[v]++;
    }

    /**
     * roots は根の頂点番号が格納され、隣り合う頂点は元のグラフで隣接している
     */
    void build() {
        g.build();

        std::queue<int> que;
        for (int v = 0; v < n; v++) {
            if (deg[v] == 1) que.push(v);
        }

        std::vector<short> visited(n);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            visited[v] = true;
            for (int nv : g[v]) {
                if (visited[nv]) continue;
                forests.add_edge(nv, v);
                deg[nv]--;
                if (deg[nv] == 1) que.push(nv);
            }
        }

        forests.build();

        roots.reserve(std::count(visited.begin(), visited.end(), false));
        {
            int v = std::find(visited.begin(), visited.end(), false) -
                    visited.begin();
            while (!visited[v]) {
                visited[v] = true;
                roots.push_back(v);
                for (int nv : g[v]) {
                    if (!visited[nv]) {
                        v = nv;
                        break;
                    }
                }
            }
        }

        for (int r : roots) {
            que.push(r);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                types[v] = r;
                for (int nv : forests[v]) {
                    types[nv] = r;
                    que.push(nv);
                }
            }
        }
    }

    /**
     * v が属する根付き森の根を返す
     */
    int type(int v) const {
        return types[v];
    }
};