#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

struct RangeUnionFind {
    struct Node {
        int l, r;
    };
    int n, group_number;
    std::vector<int> parent_or_size;
    std::vector<Node> nodes;

    RangeUnionFind() {
    }
    RangeUnionFind(int n_) : n(n_), group_number(n_), parent_or_size(n_, -1) {
        nodes.resize(n);
        for (int i = 0; i < n; i++) {
            nodes[i] = {i, i};
        }
    }

    int size() const {
        return n;
    }

    int group_count() const {
        return group_number;
    }

    std::pair<int, int> range(int x) {
        return {nodes[root(x)].l, nodes[root(x)].r};
    }

    bool prev_merge(int x) {
        assert(prev_root(x) != -1);
        return merge(x, prev_root(x));
    }

    bool next_merge(int x) {
        assert(next_root(x) != -1);
        return merge(x, next_root(x));
    }

    int root(int x) {
        if (parent_or_size[x] < 0) return x;
        return parent_or_size[x] = root(parent_or_size[x]);
    }

    int prev_root(int x) {
        if (nodes[x].l == 0) return -1;
        return root(nodes[x].l - 1);
    }

    int next_root(int x) {
        if (nodes[x].r == n - 1) return -1;
        return root(nodes[x].r + 1);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (parent_or_size[x] > parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        nodes[x].r = std::max(nodes[x].r, nodes[y].r);
        nodes[x].l = std::min(nodes[x].l, nodes[y].l);
        return true;
    }
};