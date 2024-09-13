#pragma once

#include <cassert>
#include <limits>
#include <vector>

#include <atcoder/maxflow>

template <class Cap> struct ProjectSelectionProblem {
    struct Edge {
        int from, to;
        Cap cost;

        Edge(int from, int to, Cap cost) : from(from), to(to), cost(cost) {
        }
    };
    int n, mf_n, s, t;
    Cap base;
    std::vector<Edge> edges;
    atcoder::mf_graph<Cap> g;

    ProjectSelectionProblem() {
    }
    ProjectSelectionProblem(int n_)
        : n(n_), mf_n(n_ + 2), s(n_), t(n_ + 1), base(0) {
    }

    /**
     * 頂点 u が赤色かつ頂点 v が青色だとペナルティを受ける
     */
    void if_u_red_and_v_blue_then_penalty(int u, int v, Cap penalty) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && penalty >= 0);
        edges.emplace_back(u, v, penalty);
    }

    /**
     * 頂点 v が赤色になるとペナルティを受ける
     */
    void red_penalty(int v, Cap penalty) {
        assert(0 <= v && v < n && penalty >= 0);
        edges.emplace_back(v, t, penalty);
    }

    /**
     * 頂点 v が青色になるとペナルティを受ける
     */
    void blue_penalty(int v, Cap penalty) {
        assert(0 <= v && v < n && penalty >= 0);
        edges.emplace_back(s, v, penalty);
    }

    /**
     * 頂点 u と v の色が異なるとペナルティを受ける
     */
    void difference_penalty(int u, int v, Cap penalty) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && penalty >= 0);
        edges.emplace_back(u, v, penalty);
        edges.emplace_back(v, u, penalty);
    }

    /**
     * 頂点 u が赤色になると頂点 v も赤色になる
     */
    void if_u_red_then_v_red(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v);
        edges.emplace_back(u, v, std::numeric_limits<Cap>::max());
    }

    /**
     * 頂点 u が青色になると頂点 v も青色になる
     */
    void if_u_blue_then_v_blue(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v);
        edges.emplace_back(v, u, std::numeric_limits<Cap>::max());
    }

    /**
     * 頂点 v が赤色になる
     */
    void force_red(int v) {
        assert(0 <= v && v < n);
        edges.emplace_back(s, v, std::numeric_limits<Cap>::max());
    }

    /**
     * 頂点 v が青色になる
     */
    void force_blue(int v) {
        assert(0 <= v && v < n);
        edges.emplace_back(v, t, std::numeric_limits<Cap>::max());
    }

    /**
     * 頂点 u と v が同じ色になる
     */
    void force_same(int u, int v) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v);
        edges.emplace_back(u, v, std::numeric_limits<Cap>::max());
        edges.emplace_back(v, u, std::numeric_limits<Cap>::max());
    }

    /**
     * 頂点 v が赤色になると報酬を得る
     */
    void red_reward(int v, Cap reward) {
        assert(0 <= v && v < n && reward >= 0);
        base += reward;
        edges.emplace_back(s, v, reward);
    }

    /**
     * 頂点 v が青色になると報酬を得る
     */
    void blue_reward(int v, Cap reward) {
        assert(0 <= v && v < n && reward >= 0);
        base += reward;
        edges.emplace_back(v, t, reward);
    }

    /**
     * 頂点 u と v が同じ色になると報酬を得る
     */
    void same_reward(int u, int v, Cap reward) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && reward >= 0);
        base += reward;
        edges.emplace_back(u, v, reward);
        edges.emplace_back(v, u, reward);
    }

    /**
     * 赤色の頂点が存在するとペナルティを受ける
     */
    void any_red_peanlty(int u, int v, Cap penalty) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && penalty >= 0);
        edges.emplace_back(v, t, penalty);
        edges.emplace_back(u, v, penalty);
    }

    /**
     * 赤色の頂点が存在するとペナルティを受ける
     */
    void any_red_peanlty(const std::vector<int>& vs, Cap penalty) {
        int u = mf_n++;
        for (int v : vs) {
            assert(0 <= v && v < n);
            edges.emplace_back(v, u, std::numeric_limits<Cap>::max());
        }
        edges.emplace_back(u, t, penalty);
    }

    /**
     * 青色の頂点が存在するとペナルティを受ける
     */
    void any_blue_penalty(int u, int v, Cap penalty) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && penalty >= 0);
        edges.emplace_back(s, u, penalty);
        edges.emplace_back(u, v, penalty);
    }

    /**
     * 青色の頂点が存在するとペナルティを受ける
     */
    void any_blue_penalty(const std::vector<int>& vs, Cap penalty) {
        int u = mf_n++;
        for (int v : vs) {
            assert(0 <= v && v < n);
            edges.emplace_back(u, v, std::numeric_limits<Cap>::max());
        }
        edges.emplace_back(s, u, penalty);
    }

    /**
     * 頂点 u と v が赤色になると報酬を得る
     */
    void all_red_reward(int u, int v, Cap reward) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && reward >= 0);
        base += reward;
        edges.emplace_back(s, u, reward);
        edges.emplace_back(u, v, reward);
    }

    /**
     * すべての頂点が赤になると報酬を得る
     */
    void all_red_reward(const std::vector<int>& vs, Cap reward) {
        base += reward;
        int u = mf_n++;
        for (int v : vs) {
            assert(0 <= v && v < n);
            edges.emplace_back(u, v, std::numeric_limits<Cap>::max());
        }
        edges.emplace_back(s, u, reward);
    }

    /**
     * 頂点 u と v が青色になると報酬を得る
     */
    void all_blue_reward(int u, int v, Cap reward) {
        assert(0 <= u && u < n && 0 <= v && v < n && u != v && reward >= 0);
        base += reward;
        edges.emplace_back(v, t, reward);
        edges.emplace_back(u, v, reward);
    }

    /**
     * すべての頂点が青になると報酬を得る
     */
    void all_blue_reward(const std::vector<int>& vs, Cap reward) {
        base += reward;
        int u = mf_n++;
        for (int v : vs) {
            assert(0 <= v && v < n);
            edges.emplace_back(v, u, std::numeric_limits<Cap>::max());
        }
        edges.emplace_back(u, t, reward);
    }

    /**
     * 報酬の最大値を求める
     */
    Cap solve() {
        g = atcoder::mf_graph<Cap>(mf_n);
        for (const auto& [u, v, cost] : edges) {
            g.add_edge(u, v, cost);
        }
        return base - g.flow(s, t);
    }

    std::vector<bool> red_selection() {
        auto selection = g.min_cut(s);
        selection.resize(n);
        return selection;
    }
};