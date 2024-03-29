#pragma once

#include <cassert>
#include <vector>

template <class T, class U, class F, class G, class H> struct LazySegmentTree {
  private:
    F op;
    G mapping;
    H composition;
    T e;
    U id;
    int _n, size, log;
    std::vector<T> node;
    std::vector<U> lazy;

  public:
    LazySegmentTree() {
    }
    LazySegmentTree(const F& op,
                    const G& mapping,
                    const H& composition,
                    T e,
                    U id,
                    int n)
        : LazySegmentTree(op,
                          mapping,
                          composition,
                          e,
                          id,
                          std::vector<T>(n, e)) {
    }
    LazySegmentTree(const F& op,
                    const G& mapping,
                    const H& composition,
                    T e,
                    U id,
                    const std::vector<T>& v)
        : op(op),
          mapping(mapping),
          composition(composition),
          e(e),
          id(id),
          _n(int(v.size())),
          log(0) {
        while ((1 << log) < _n) log++;
        size = 1 << log;
        node = std::vector<T>(2 * size, e);
        lazy = std::vector<U>(size, id);
        for (int i = 0; i < _n; i++) node[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    // [l, r) (0-indexed)
    T get(int l, int r) {
        if (l >= r) return e;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        T sml = e, smr = e;
        while (l < r) {
            if (l & 1) sml = op(sml, node[l++]);
            if (r & 1) smr = op(node[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    T all_get() const {
        return node[1];
    }

    void apply(int p, U val) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p] = val == id ? node[p] : mapping(node[p], val);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, U val) {
        if (l >= r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, val);
                if (r & 1) all_apply(--r, val);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <typename C> int max_right(int l, const C& check) {
        assert(0 <= l && l <= _n);
        assert(check(e));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        T sm = e;
        do {
            while (~l & 1) l >>= 1;
            if (!check(op(sm, node[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (check(op(sm, node[l]))) {
                        sm = op(sm, node[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, node[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <typename C> int min_left(int r, const C& check) {
        assert(0 <= r && r <= _n);
        assert(check(e));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        T sm = e;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!check(op(node[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (check(op(node[r], sm))) {
                        sm = op(node[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(node[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    T operator[](int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return node[p];
    }
#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, LazySegmentTree r) {
        std::vector<T> v(r._n);
        for (int i = 0; i < r._n; i++) {
            v[i] = r[i];
        }
        os << v;
        return os;
    }
#endif

  private:
    void update(int k) {
        node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    void all_apply(int k, U val) {
        node[k] = val == id ? node[k] : mapping(node[k], val);
        if (k < size) lazy[k] = composition(lazy[k], val);
    }

    void push(int k) {
        if (lazy[k] == id) return;
        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);
        lazy[k] = id;
    }
};

/**
 * 区間更新区間最小値
 */
template <typename T>
auto buildRangeSetRangeMin(const std::vector<T>& v, T e, T id) {
    auto f = [](T a, T b) { return min(a, b); };
    auto g = [](T a, T b) {
        (void)a;
        return b;
    };
    auto h = [](T a, T b) {
        (void)a;
        return b;
    };
    LazySegmentTree seg(f, g, h, e, id, v);
    return seg;
}

template <typename T> auto buildRangeSetRangeMin(int n, T e, T id) {
    return buildRangeSetRangeMin<T>(std::vector<T>(n, e), e, id);
}

/**
 * 区間更新区間最大値
 */
template <typename T>
auto buildRangeSetRangeMax(const std::vector<T>& v, T e, T id) {
    auto f = [](T a, T b) { return max(a, b); };
    auto g = [](T a, T b) {
        (void)a;
        return b;
    };
    auto h = [](T a, T b) {
        (void)a;
        return b;
    };
    LazySegmentTree seg(f, g, h, e, id, v);
    return seg;
}

template <typename T> auto buildRangeSetRangeMax(int n, T e, T id) {
    return buildRangeSetRangeMax<T>(std::vector<T>(n, e), e, id);
}

/**
 * 区間加算区間最小値
 */
template <typename T>
auto buildRangeAddRangeMin(const std::vector<T>& v, T e, T id) {
    auto f = [](T a, T b) { return min(a, b); };
    auto g = [](T a, T b) { return a + b; };
    auto h = [](T a, T b) { return a + b; };
    LazySegmentTree seg(f, g, h, e, id, v);
    return seg;
}

template <typename T> auto buildRangeAddRangeMin(int n, T e, T id) {
    return buildRangeAddRangeMin<T>(std::vector<T>(n, e), e, id);
}

/**
 * 区間加算区間最大値
 */
template <typename T>
auto buildRangeAddRangeMax(const std::vector<T>& v, T e, T id) {
    auto f = [](T a, T b) { return max(a, b); };
    auto g = [](T a, T b) { return a + b; };
    auto h = [](T a, T b) { return a + b; };
    LazySegmentTree seg(f, g, h, e, id, v);
    return seg;
}

template <typename T> auto buildRangeAddRangeMax(int n, T e, T id) {
    return buildRangeAddRangeMax<T>(std::vector<T>(n, e), e, id);
}

/**
 * 区間更新区間和
 * @note pair.first: 区間和, pair.second: 区間の長さ
 */
template <typename T, typename S>
auto buildRangeSetRangeSum(const std::vector<T>& v, pair<T, S> e, T id) {
    using P = pair<T, S>;
    auto f = [](P a, P b) { return P(a.first + b.first, a.second + b.second); };
    auto g = [](P a, T b) { return P(b * a.second, a.second); };
    auto h = [](T a, T b) {
        (void)a;
        return b;
    };
    std::vector<P> w(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        w[i] = P(v[i], 1);
    }
    LazySegmentTree seg(f, g, h, e, id, w);
    return seg;
}

template <typename T, typename S>
auto buildRangeSetRangeSum(int n, pair<T, S> e, T id) {
    return buildRangeSetRangeSum<T, S>(std::vector<T>(n), e, id);
}