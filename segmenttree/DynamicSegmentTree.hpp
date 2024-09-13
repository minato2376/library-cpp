#pragma once

#include <cassert>
#include <vector>

template <class T, class F, int B> struct DynamicSegmentTree {
    using ll = long long;
    struct Node {
        T value;
        int parent = -1, left = -1, right = -1;
        Node() {
        }
        Node(T value, int parent) : value(value), parent(parent) {
        }
    };
    F op;
    T e;
    std::vector<Node> nodes;

    DynamicSegmentTree() {
    }
    DynamicSegmentTree(F op, T e) : op(op), e(e), nodes(1, Node(e, -1)) {
    }

    void set(ll p, T x) {
        assert(0 <= p && p < (1LL << B));
        int idx = 0;
        for (int b = B - 1; b >= 0; b--) {
            if (p >> b & 1) {
                if (nodes[idx].right == -1) {
                    nodes[idx].right = nodes.size();
                    nodes.emplace_back(e, idx);
                }
                idx = nodes[idx].right;
            } else {
                if (nodes[idx].left == -1) {
                    nodes[idx].left = nodes.size();
                    nodes.emplace_back(e, idx);
                }
                idx = nodes[idx].left;
            }
        }
        nodes[idx].value = x;
        for (int b = 0; b < B; b++) {
            idx = nodes[idx].parent;
            update(idx);
        }
    }

    T get(ll p) const {
        assert(0 <= p && p < (1LL << B));
        int idx = 0;
        for (int b = B - 1; b >= 0; b--) {
            if (p >> b & 1) {
                if (nodes[idx].right == -1) {
                    return e;
                }
                idx = nodes[idx].right;
            } else {
                if (nodes[idx].left == -1) {
                    return e;
                }
                idx = nodes[idx].left;
            }
        }
        return nodes[idx].value;
    }

    T prod(ll l, ll r) const {
        assert(0 <= l && l <= r && r <= (1LL << B));
        return inner_prod(l, r, 0, 0, (1LL << B));
    }

    T all_prod() const {
        return nodes[0].value;
    }

  private:
    void update(int idx) {
        T vl = nodes[idx].left == -1 ? e : nodes[nodes[idx].left].value;
        T vr = nodes[idx].right == -1 ? e : nodes[nodes[idx].right].value;
        nodes[idx].value = op(vl, vr);
    }

    T inner_prod(ll l, ll r, int idx, ll tl, ll tr) const {
        if (r <= tl || tr <= l) {
            return e;
        }
        if (idx == -1) {
            return e;
        }
        if (l <= tl && tr <= r) {
            return nodes[idx].value;
        }
        ll tm = (tl + tr) / 2;
        return op(inner_prod(l, r, nodes[idx].left, tl, tm),
                  inner_prod(l, r, nodes[idx].right, tm, tr));
    }
};