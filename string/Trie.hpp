#pragma once

#include <map>
#include <vector>

/**
 * @brief Trie
 * 全ノードは追加した文字列の prefix に対応する
 */
template <typename Char> struct Trie {
    struct Node {
        std::map<Char, int> next;
        Node() {
        }
    };

    static constexpr int root = 0;
    std::vector<Node> nodes;

    Trie() : nodes(1) {
    }

    int size() const {
        return nodes.size();
    }

    const Node& operator[](int v) const {
        return nodes[v];
    }

    Node& operator[](int v) {
        return nodes[v];
    }

    /**
     * 頂点 v から c を辿った先の頂点を返す
     * 存在しない場合は -1 を返す
     */
    int find_char(Char c, int v = root) {
        return nodes[v].next.contains(c) ? nodes[v].next[c] : -1;
    }

    /**
     * 文字列 s （の終端）に対応する頂点を返す
     * 存在しない場合は -1 を返す
     */
    template <typename String> int find_string(const String& s) {
        int v = 0;
        for (const auto& c : s) {
            v = find_char(c, v);
            if (v == -1) break;
        }
        return v;
    }

    /**
     * 頂点 v から c を辿った先の頂点を返す
     * 存在しない場合は新たに頂点を作成して返す
     */
    int add_char(Char c, int v = root) {
        int nv = find_char(c, v);
        if (nv == -1) {
            nv = nodes.size();
            nodes.emplace_back();
            nodes[v].next[c] = nv;
        }
        return nv;
    }

    /**
     * 文字列 s を追加する
     * 文字列 s の終端に対応する頂点を返す
     */
    template <typename String> int add_string(const String& s) {
        int v = 0;
        for (const auto& c : s) {
            v = add_char(c, v);
        }
        return v;
    }
};