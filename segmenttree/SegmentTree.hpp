#pragma once

template <class T, class F> struct SegmentTree {
  private:
    F op;
    T e;
    int _n, size, log;
    vector<T> node;

  public:
    SegmentTree() {
    }
    SegmentTree(const F& op, T e, int n) : SegmentTree(op, e, vector<T>(n, e)) {
    }
    SegmentTree(const F& op, T e, const vector<T>& v)
        : op(op), e(e), _n(int(v.size())), log(0) {
        while ((1 << log) < _n) log++;
        size = 1 << log;
        node = vector<T>(2 * size, e);
        for (int i = 0; i < _n; i++) node[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    // (0-indexed)
    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size;
        node[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    // [l, r) (0-indexed)
    T get(int l, int r) {
        if (l >= r) return e;
        T resl = e, resr = e;
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) resl = op(resl, node[l++]);
            l >>= 1;
            if (r & 1) resr = op(node[--r], resr);
            r >>= 1;
        }
        return op(resl, resr);
    }

    T all_get() {
        return node[1];
    }

    template <class C> int max_right(int l, const C& check) {
        assert(0 <= l && l <= _n);
        assert(check(e));
        if (l == _n) return _n;
        l += size;
        T sm = e;
        do {
            while (~l & 1) l >>= 1;
            if (!check(op(sm, node[l]))) {
                while (l < size) {
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

    template <class C> int min_left(int r, const C& check) {
        assert(0 <= r && r <= _n);
        assert(check(e));
        if (r == 0) return 0;
        r += size;
        T sm = e;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!check(op(node[r], sm))) {
                while (r < size) {
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
        return node[p + size];
    }

  private:
    void update(int k) {
        node[k] = op(node[2 * k], node[2 * k + 1]);
    }
};