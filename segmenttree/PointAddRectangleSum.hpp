#pragma once
#include "datastructure/BinaryIndexedTree.hpp"

#include <vector>

template <class S, class T> struct PointAddRectangleSum {
    using P = pair<S, S>;
    int n, log, size, sz;
    std::vector<P> points;
    std::vector<S> xs, ls, rs, ys;
    std::vector<BinaryIndexedTree<T>> BITs;
    PointAddRectangleSum() {
    }

    void push_point(S x, S y) {
        points.emplace_back(x, y);
    }

    void build() {
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        xs.reserve(points.size());
        for (const auto& p : points) {
            xs.push_back(p.first);
        }
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        n = int(xs.size());

        log = 0;
        while ((1 << log) < n) log++;
        sz = 1 << log;
        BITs.resize(sz * 2);
        ls.resize(sz * 2);
        rs.resize(sz * 2);
        ys.reserve(points.size());
        int xs_index = 0;
        for (int i = 0; i < int(points.size()); i++) {
            if (i > 0 && points[i].first != points[i - 1].first) {
                rs[sz + xs_index] = int(ys.size());
                xs_index++;
            }
            if (i == 0 || points[i].first != points[i - 1].first) {
                ls[sz + xs_index] = int(ys.size());
            }
            ys.push_back(points[i].second);
        }
        rs[sz + n - 1] = int(ys.size());
        for (int i = n; i < sz; i++) {
            ls[sz + i] = int(ys.size());
            rs[sz + i] = int(ys.size());
        }
        for (int i = 0; i < n; i++) {
            BITs[sz + i] = BinaryIndexedTree<T>(rs[sz + i] - ls[sz + i]);
        }
        for (int i = sz - 1; i >= 1; i--) {
            ls[i] = int(ys.size());
            vector<int> vs;
            vs.reserve(rs[i * 2] - ls[i * 2] + rs[i * 2 + 1] - ls[i * 2 + 1]);
            merge(ys.begin() + ls[i * 2], ys.begin() + rs[i * 2],
                  ys.begin() + ls[i * 2 + 1], ys.begin() + rs[i * 2 + 1],
                  back_inserter(vs));
            vs.erase(unique(vs.begin(), vs.end()), vs.end());
            move(vs.begin(), vs.end(), back_inserter(ys));
            rs[i] = int(ys.size());
            BITs[i] = BinaryIndexedTree<T>(rs[i] - ls[i]);
        }
    }

    void add(S x, S y, T value) {
        int k = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        assert(k < n && xs[k] == x);
        k += sz;
        int l = get_y_index(y, k);
        assert(l < rs[k] - ls[k] && ys[ls[k] + l] == y);
        BITs[k].add(l, value);
        for (int i = 1; i <= log; i++) {
            int p = k >> i;
            int l = get_y_index(y, p);
            assert(l < rs[p] - ls[p] && ys[ls[p] + l] == y);
            BITs[p].add(l, value);
        }
    }

    T get(S xl, S xr, S yl, S yr) const {
        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
        l += sz;
        r += sz;
        T ret = 0;
        while (l < r) {
            if (l & 1) {
                int ll = get_y_index(yl, l);
                int rr = get_y_index(yr, l);
                ret += BITs[l].sum(ll, rr);
                l++;
            }
            if (r & 1) {
                r--;
                int ll = get_y_index(yl, r);
                int rr = get_y_index(yr, r);
                ret += BITs[r].sum(ll, rr);
            }
            l >>= 1;
            r >>= 1;
        }
        return ret;
    }

  private:
    int get_y_index(S y, int x_index) const {
        return lower_bound(ys.begin() + ls[x_index], ys.begin() + rs[x_index],
                           y) -
               (ys.begin() + ls[x_index]);
    }
};