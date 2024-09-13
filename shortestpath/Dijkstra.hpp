#pragma once

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

template <class T, bool RESTORE = false> struct Dijkstra {
  public:
    struct edge {
        int from, to, idx;
        T cost;
    };

    Dijkstra() {
    }
    Dijkstra(int n_) : Dijkstra(n_, std::numeric_limits<T>::max() / 2) {
    }
    Dijkstra(int n_, T INF_) : n(n_), INF(INF_), g(n_) {
    }

    int size() const {
        return n;
    }

    int add_edge(int u, int v, T cost) {
        assert(0 <= v and v < n);
        assert(0 <= cost);

        int m = int(edges.size());
        g[u].push_back(edge{u, v, m, cost});
        edges.push_back(edge{u, v, m, cost});
        return m;
    }

    void shortest_path(const std::vector<int>& vs = {0}) {
        dist.assign(n, INF);
        if (RESTORE) from.assign(n, -1);
        std::priority_queue<vertex> pq;
        for (int v : vs) {
            dist[v] = 0;
            pq.push(vertex{v, 0});
        }

        while (!pq.empty()) {
            vertex v = pq.top();
            pq.pop();
            if (v.dist > dist[v.idx]) continue;
            for (const edge& e : g[v.idx]) {
                if (dist[e.to] > v.dist + e.cost) {
                    dist[e.to] = v.dist + e.cost;
                    if (RESTORE) from[e.to] = e.idx;
                    pq.push(vertex{e.to, dist[e.to]});
                }
            }
        }
    }

    T operator[](int v) const {
        return dist[v];
    }

    std::vector<edge> restore(int t) const {
        static_assert(RESTORE);
        std::vector<edge> ret;
        while (~from[t]) {
            int idx = from[t];
            ret.push_back(edges[idx]);
            t = edges[idx].from;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

  private:
    int n;
    T INF;
    std::vector<std::vector<edge>> g;
    std::vector<T> dist;
    std::vector<int> from;
    std::vector<edge> edges;
    struct vertex {
        int idx;
        T dist;
        bool operator<(const vertex& o) const {
            return dist > o.dist;
        }
    };
};