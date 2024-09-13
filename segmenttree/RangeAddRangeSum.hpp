#include "datastructure/BinaryIndexedTree.hpp"

template <typename T> struct RangeAddRangeSum {
    int n;
    BinaryIndexedTree<T> a, b;
    RangeAddRangeSum() {
    }
    RangeAddRangeSum(int n) : n(n), a(n + 1), b(n + 1) {
    }

    int size() const {
        return n;
    }

    // add x to [l, r)
    void add(int l, int r, T x) {
        if (l >= r) return;
        a.add(l, x);
        a.add(r, -x);
        b.add(l, x * (1 - l));
        b.add(r, x * (r - 1));
    }

    T sum(int i) const {
        return a.sum(i) * (i - 1) + b.sum(i);
    }

    // return sum of [l, r)
    T sum(int l, int r) const {
        return sum(r) - sum(l);
    }

#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, const RangeAddRangeSum& r) {
        vector<T> v(r.size());
        for (int i = 0; i < r.size(); i++) {
            v[i] = r.sum(i, i + 1);
        }
        os << v;
        return os;
    }
#endif
};