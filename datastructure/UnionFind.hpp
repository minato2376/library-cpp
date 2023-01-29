#pragma once

/**
 * 高速、省メモリなシンプルな UnionFind を使いたい場合、atcoder::dsu を使う。
 */
struct UnionFind {
  private:
    int n, group_number;
    vector<int> parent_or_size, nex;

  public:
    UnionFind() : n(0), group_number(0) {
    }
    UnionFind(int n) : n(n), group_number(n), parent_or_size(n, -1), nex(n) {
        iota(nex.begin(), nex.end(), 0);
    }

    int size() const {
        return n;
    }

    /**
     * 連結成分の個数を取得する。
     */
    int count() const {
        return group_number;
    }

    bool merge(int x, int y) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        x = root_(x);
        y = root_(y);
        if (x == y) return false;
        if (parent_or_size[x] > parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        swap(nex[x], nex[y]);
        group_number--;
        return true;
    }

    /**
     * @param f void f(int parent, int child)
     * マージする際の処理を行う関数を渡す。
     */
    template <class F> bool merge(int x, int y, const F& f) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        x = root_(x);
        y = root_(y);
        if (x == y) return false;
        if (parent_or_size[x] > parent_or_size[y]) swap(x, y);
        f(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        swap(nex[x], nex[y]);
        group_number--;
        return true;
    }

    bool same(int x, int y) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        return root_(x) == root_(y);
    }

    int root(int x) {
        assert(0 <= x and x < n);
        return root_(x);
    }

    /**
     * 頂点 x の属する連結成分のサイズを返す。
     */
    int size(int x) {
        assert(0 <= x and x < n);
        return -parent_or_size[root_(x)];
    }

    /**
     * 頂点 x の属する連結成分の代表元を返す。
     * root(x) と同じ。
     */
    int operator[](int x) {
        assert(0 <= x and x < n);
        return root_(x);
    }

    vector<vector<int>> groups() {
        vector<int> leader_buf(n), group_size(n);
        for (int i = 0; i < n; i++) {
            leader_buf[i] = root(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(remove_if(result.begin(), result.end(),
                               [&](const vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

    /**
     * 頂点 x の属する連結成分の頂点番号のリストを返す。
     * O(size(x))
     */
    vector<int> group(int x) const {
        assert(0 <= x and x < n);
        vector<int> ret;
        int v = x;
        do {
            ret.emplace_back(v);
            v = nex[v];
        } while (v != x);
        return ret;
    }

  private:
    int root_(int x) {
        if (parent_or_size[x] < 0) return x;
        return parent_or_size[x] = root_(parent_or_size[x]);
    }
};