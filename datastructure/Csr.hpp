#pragma once

#include <algorithm>
#include <ranges>
#include <utility>
#include <vector>

template <class E> struct Csr {
    int n;
    std::vector<int> start;
    std::vector<E> elist;
    std::vector<std::pair<int, E>> edges;

    Csr() {
    }
    Csr(int n_) : n(n_), start(n_ + 1) {
    }

    void add_edge(int from, E value) {
        assert(0 <= from && from < n);
        edges.emplace_back(from, value);
    }

    void build() {
        for (const auto& e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        elist.resize(edges.size());
        auto counter = start;
        for (auto& e : edges) {
            elist[counter[e.first]++] = std::move(e.second);
        }
    }

    const auto operator[](int idx) const {
        return std::ranges::subrange(elist.begin() + start[idx],
                                     elist.begin() + start[idx + 1]);
    }
};
