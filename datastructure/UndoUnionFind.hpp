#pragma once

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

struct UndoUnionFind {
  private:
    struct History {
        int v, prev;
        History() {
        }
        History(int v, int prev) : v(v), prev(prev) {
        }
    };
    int n, group_number;
    std::vector<int> parent_or_size, nex;
    std::vector<History> histories;

  public:
    UndoUnionFind() : n(0), group_number(0) {
    }
    UndoUnionFind(int n)
        : n(n), group_number(n), parent_or_size(n, -1), nex(n) {
        std::iota(nex.begin(), nex.end(), 0);
    }

    int size() const {
        return n;
    }

    int count() const {
        return group_number;
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        histories.emplace_back(x, parent_or_size[x]);
        histories.emplace_back(y, parent_or_size[y]);
        if (x == y) return false;
        if (parent_or_size[x] > parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        std::swap(nex[x], nex[y]);
        group_number--;
        return true;
    }

    template <class F> bool merge(int x, int y, const F& f) {
        x = root(x);
        y = root(y);
        histories.emplace_back(x, parent_or_size[x]);
        histories.emplace_back(y, parent_or_size[y]);
        if (x == y) return false;
        if (parent_or_size[x] > parent_or_size[y]) std::swap(x, y);
        f(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        std::swap(nex[x], nex[y]);
        group_number--;
        return true;
    }

    /**
     * O(log n)
     */
    bool same(int x, int y) const {
        return root(x) == root(y);
    }

    /**
     * O(log n)
     */
    int size(int x) const {
        return -parent_or_size[root(x)];
    }

    /**
     * O(log n)
     */
    int root(int x) const {
        if (parent_or_size[x] < 0) return x;
        return root(parent_or_size[x]);
    }

    /**
     * 頂点 x の属する連結成分の代表元を返す。
     * root(x) と同じ。
     */
    int operator[](int x) {
        return root(x);
    }

    /**
     * O(n)
     */
    std::vector<std::vector<int>> groups() const {
        std::vector<int> leader_buf(n, -1), group_size(n);
        auto dfs = [&](auto self, int v) -> int {
            if (leader_buf[v] != -1) return leader_buf[v];
            if (parent_or_size[v] < 0) return leader_buf[v] = v;
            return leader_buf[v] = self(self, parent_or_size[v]);
        };
        for (int i = 0; i < n; i++) {
            if (leader_buf[i] == -1) dfs(dfs, i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

    /**
     * 頂点 x の属する連結成分の頂点番号のリストを返す。
     * O(size(x))
     */
    std::vector<int> group(int x) const {
        std::vector<int> ret;
        ret.reserve(size(x));
        int v = x;
        do {
            ret.push_back(v);
            v = nex[v];
        } while (v != x);
        return ret;
    }

    bool undo() {
        auto [x, prev_x] = histories.back();
        histories.pop_back();
        auto [y, prev_y] = histories.back();
        histories.pop_back();
        if (x == y) return false;
        group_number++;
        std::swap(nex[x], nex[y]);
        parent_or_size[x] = prev_x;
        parent_or_size[y] = prev_y;
        return true;
    }

    void snapshot() {
        while (!histories.empty()) histories.pop_back();
    }

    void rollback() {
        while (!histories.empty()) undo();
    }
};