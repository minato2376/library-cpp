#pragma once

#include <atcoder/internal_scc>
#include <cassert>
#include <utility>
#include <vector>

struct StronglyConnectedComponents {
    int n;
    int group_num;
    /**
     * 元のグラフの頂点がどの強連結成分に所属するかを表す配列
     */
    std::vector<int> scc_ids;

    StronglyConnectedComponents() : n(0), internal(0) {
    }
    explicit StronglyConnectedComponents(int n) : n(n), internal(n) {
    }

    int size() const {
        return n;
    }

    void add_edge(int from, int to) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
        edges.emplace_back(from, to);
    }

    int build() {
        tie(group_num, scc_ids) = internal.scc_ids();
        return group_num;
    }

    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> groups(group_num);
        std::vector<int> counts(group_num);
        for (auto x : scc_ids) counts[x]++;
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < n; i++) {
            groups[scc_ids[i]].push_back(i);
        }
        return groups;
    }

    std::vector<std::vector<int>> scc_graph() const {
        std::vector<int> counts(group_num);
        std::vector<std::vector<int>> naive_scc_graph(group_num),
            scc_graph(group_num);
        for (auto [from, to] : edges) counts[scc_ids[from]]++;
        for (int i = 0; i < group_num; i++) {
            naive_scc_graph[i].reserve(counts[i]);
            scc_graph[i].reserve(counts[i]);
        }
        for (auto [from, to] : edges) {
            naive_scc_graph[scc_ids[from]].push_back(scc_ids[to]);
        }
        std::vector<int> exists(group_num);
        for (int from = 0; from < group_num; from++) {
            for (auto to : naive_scc_graph[from]) {
                if (from == to) continue;
                if (exists[to]) continue;
                scc_graph[from].push_back(to);
                exists[to] = 1;
            }
            for (auto to : scc_graph[from]) {
                exists[to] = 0;
            }
        }
        return scc_graph;
    }

    int operator[](int i) const {
        assert(0 <= i && i < n);
        return scc_ids[i];
    }

  private:
    atcoder::internal::scc_graph internal;
    std::vector<std::pair<int, int>> edges;
};