#pragma once

#include <map>
#include <queue>
#include <vector>

/**
 * @brief AhoCorasick
 * @note 全ノードは追加した文字列の prefix に対応する
 * @note link は suffix link で、その node に対応する文字列の最長の suffix
 * に対応する node にリンクする
 * @note link は v より頂点番号は小さいとは限らないが、深さは必ず小さい
 */
template <typename Char> struct AhoCorasick {
    struct Node {
        std::map<Char, int> next;
        int link;
        Node() : link(-1) {
        }
    };

    static constexpr int root = 0;
    std::vector<Node> nodes;

    AhoCorasick() : nodes(1) {
    }

    const Node& operator[](int v) const {
        return nodes[v];
    }

    Node& operator[](int v) {
        return nodes[v];
    }

    int size() const {
        return nodes.size();
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

    /**
     * 頂点 v に相当する文字列に対して文字 c を追加した文字列と最も suffix
     * が一致する頂点を返す
     * @note 最悪 v
     * の深さだけかかるが、返す頂点の深さはその分だけ減っていることに注意する
     */
    int process(int v, Char c) {
        while (v != -1 && find_char(c, v) == -1) v = nodes[v].link;
        return v == -1 ? root : find_char(c, v);
    }

    void build() {
        std::queue<int> que;
        que.push(root);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (const auto& [c, nv] : nodes[v].next) {
                nodes[nv].link = process(nodes[v].link, c);
                que.push(nv);
            }
        }
    }

    /**
     * 各頂点に対応する文字列に対して文字 transition[i] を追加したときの
     * 遷移先の頂点を格納したテーブルを返す
     */
    template <typename String>
    std::vector<std::vector<int>> transition_table(const String& transition) {
        std::map<Char, int> char_to_index;
        int M = 0;
        for (const auto& c : transition) {
            char_to_index[c] = M++;
        }
        std::vector<std::vector<int>> table(size(), std::vector<int>(M));
        std::queue<int> que;
        que.push(root);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (v != root) {
                for (int i = 0; i < M; i++) {
                    table[v][i] = table[nodes[v].link][i];
                }
            }
            for (const auto& [c, nv] : nodes[v].next) {
                table[v][char_to_index[c]] = nv;
                que.push(nv);
            }
        }
        return table;
    }

    /**
     * 禁止文字列に対応する頂点を渡すと、各頂点に対応する文字列が禁止文字列を
     * suffix に持つかどうかを格納したテーブルを返す
     */
    std::vector<short> banned_table(const std::vector<int>& banned) {
        std::vector<short> table(size());
        for (auto v : banned) {
            table[v] = true;
        }
        std::queue<int> que;
        que.push(root);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (v != root) table[v] |= table[nodes[v].link];
            for (const auto& [c, nv] : nodes[v].next) {
                que.push(nv);
            }
        }
        return table;
    }
};
