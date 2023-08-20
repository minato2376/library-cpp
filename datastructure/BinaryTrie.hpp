#pragma once

#include <array>
#include <cassert>
#include <vector>

template <class Key, class T, int B, class F> struct BinaryTrie {
    struct Node {
        int parent;
        std::array<int, 2> child;
        T value;
        Node(int parent, T value) : parent(parent), value(value) {
            child[0] = child[1] = -1;
        }
    };

    F op;
    T e;
    vector<Node> nodes;

    BinaryTrie(const F& op, T e) : op(op), e(e), nodes(1, Node(-1, e)) {
    }

    int create_node(int parent, T value) {
        int ret = int(nodes.size());
        nodes.emplace_back(parent, value);
        return ret;
    }

    void insert(Key key, T value) {
        int cur = 0;

        for (int i = B - 1; i >= 0; i--) {
            int b = kthbit(key, i);
            if (nodes[cur].child[b] == -1) {
                nodes[cur].child[b] = create_node(cur, e);
            }
            cur = nodes[cur].child[b];
        }

        nodes[cur].value = value;
        for (int i = 0; i < B; i++) {
            cur = nodes[cur].parent;
            nodes[cur].value = op(
                nodes[cur].child[0] == -1 ? e
                                          : nodes[nodes[cur].child[0]].value,
                nodes[cur].child[1] == -1 ? e
                                          : nodes[nodes[cur].child[1]].value);
        }
    }

    void erase(Key key) {
        int cur = 0;

        for (int i = B - 1; i >= 0; i--) {
            int b = kthbit(key, i);
            assert(nodes[cur].child[b] != -1);
            cur = nodes[cur].child[b];
        }

        for (int i = 0; i < B; i++) {
            cur = nodes[cur].parent;
            int b = kthbit(key, i);
            nodes[cur].child[b] = -1;
            if (nodes[cur].child[1 ^ b] != -1) {
                nodes[cur].value = op(nodes[cur].child[0] == -1
                                          ? e
                                          : nodes[nodes[cur].child[0]].value,
                                      nodes[cur].child[1] == -1
                                          ? e
                                          : nodes[nodes[cur].child[1]].value);
                break;
            }
        }
    }

    int find(Key key) const {
        int cur = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = kthbit(key, i);
            if (nodes[cur].child[b] == -1) {
                return -1;
            }
            cur = nodes[cur].child[b];
        }

        return cur;
    }

    /**
     * key からなる集合に値 x で xor したときの最小値を求める
     * 最小値は xor したあとの値
     * O(B)
     */
    Key min_element(Key x = 0) const {
        int cur = 0;

        Key ret = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = kthbit(x, i);
            if (nodes[cur].child[b] == -1) {
                ret ^= 1 << i;
                cur = nodes[cur].child[1 ^ b];
            } else {
                cur = nodes[cur].child[b];
            }
        }
        return ret;
    }

    Key max_element(Key x = 0) const {
        int cur = 0;

        Key ret = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = kthbit(x, i);
            if (nodes[cur].child[1 ^ b] == -1) {
                cur = nodes[cur].child[b];
            } else {
                ret ^= 1 << i;
                cur = nodes[cur].child[1 ^ b];
            }
        }
        return ret;
    }

    int kthbit(Key key, int k) const {
        return (key >> k) & 1;
    }
};