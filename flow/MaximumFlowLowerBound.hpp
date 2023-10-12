#pragma once

#include <atcoder/maxflow>
#include <cassert>
#include <limits>
#include <optional>
#include <utility>
#include <vector>

template <typename Cap> struct MaximumFlowLowerBound {
    struct Edge {
        int from, to;
        Cap lower, upper, flow;
    };
    int n;
    atcoder::mf_graph<Cap> g;
    int S, T;
    Cap lower_bound_sum;
    std::vector<std::pair<int, int>> edge_ids;

    MaximumFlowLowerBound() : MaximumFlowLowerBound(0) {
    }

    MaximumFlowLowerBound(int n)
        : n(n), g(n + 2), S(n), T(n + 1), lower_bound_sum(0) {
    }

    int add_edge(int from, int to, Cap lower, Cap upper) {
        assert(lower <= upper);
        int from_to = g.add_edge(from, to, upper - lower);
        int s_to = g.add_edge(S, to, lower);
        g.add_edge(from, T, lower);
        lower_bound_sum += lower;
        int m = int(edge_ids.size());
        edge_ids.emplace_back(from_to, s_to);
        return m;
    }

    bool can_flow(int s, int t) {
        assert(s != t);
        g.add_edge(t, s, std::numeric_limits<Cap>::max());
        Cap lower_bound_flow = g.flow(S, T);
        return lower_bound_flow == lower_bound_sum;
    }

    std::optional<Cap> flow(int s, int t) {
        assert(s != t);
        Cap max_flow = 0;
        max_flow += g.flow(S, T);
        max_flow += g.flow(S, t);
        max_flow += g.flow(s, T);
        max_flow += g.flow(s, t);
        auto edges = g.edges();
        for (const auto& edge : edges) {
            if (edge.from == S || edge.to == T) {
                if (edge.flow != edge.cap) return std::nullopt;
            }
        }
        return max_flow;
    }

    Edge get_edge(int i) {
        assert(0 <= i && i < int(edge_ids.size()));
        auto [from_to, s_to] = edge_ids[i];
        auto from_to_edge = g.get_edge(from_to);
        auto s_to_edge = g.get_edge(s_to);
        int from = from_to_edge.from;
        int to = from_to_edge.to;
        Cap lower = s_to_edge.cap;
        Cap upper = lower + from_to_edge.cap;
        Cap flow = from_to_edge.flow + lower;
        return Edge{from, to, lower, upper, flow};
    }

    std::vector<Edge> get_edges() {
        std::vector<Edge> edges;
        edges.reserve(edge_ids.size());
        for (int i = 0; i < int(edge_ids.size()); i++) {
            edges.push_back(get_edge(i));
        }
        return edges;
    }
};