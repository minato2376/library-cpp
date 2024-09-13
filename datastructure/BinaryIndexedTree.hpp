#pragma once

#include <cassert>
#include <vector>

template <class T> struct BinaryIndexedTree {
    int n;
    std::vector<T> data;

    BinaryIndexedTree() {
    }
    BinaryIndexedTree(int n_) : n(n_), data(n + 1, 0) {
    }

    int size() const {
        return n;
    }

    /**
     * (0-indexed)
     * a[i] += x
     */
    void add(int i, T x) {
        assert(0 <= i and i < n);
        for (++i; i <= n; i += i & -i) data[i] += x;
    }

    // [0,i) (0-indexed) a[0] + … + a[i-1]
    T sum(int i) const {
        assert(0 <= i and i <= n);
        T ret = 0;
        for (; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    /**
     * [l, r) (0-indexed)
     * @return a[l] + …　+ a[r-1]
     */
    T sum(int l, int r) const {
        if (l >= r) return T(0);
        return sum(r) - sum(l);
    }

    /**
     * (0-indexed)
     * r = 0 or a[0] + a[1] + ... + a[r-1] < x
     * r = n or a[0] + a[1] + ... + a[r] >= x
     * a[0] + a[1] + ... + a[r] >= x となる最小の r を返す。
     */
    int lower_bound(T x) const {
        int k = 1;
        int ret = 0;
        while ((k << 1) <= n) k <<= 1;
        while (k > 0) {
            if (ret + k <= n and data[ret + k] < x) {
                x -= data[ret + k];
                ret += k;
            }
            k >>= 1;
        }
        return ret;
    }

    int upper_bound(T x) const {
        return lower_bound(x + 1);
    }

#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, const BinaryIndexedTree& r) {
        std::vector<T> v(r.size());
        for (int i = 0; i < r.size(); i++) {
            v[i] = r.sum(i, i + 1);
        }
        os << v;
        return os;
    }
#endif
};
