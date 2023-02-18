template <class T, class U, class G, class H> struct DualSegmentTree {
  private:
    G mapping;
    H composition;
    U id;
    int _n, size_, log;
    vector<T> node;
    vector<U> lazy;

  public:
    DualSegmentTree() {
    }
    DualSegmentTree(const G& mapping,
                    const H& composition,
                    U id,
                    const vector<T>& v)
        : mapping(mapping),
          composition(composition),
          id(id),
          _n(int(v.size())),
          log(0) {
        while ((1 << log) < _n) log++;
        size_ = 1 << log;
        node.resize(size_);
        for (int i = 0; i < _n; i++) node[i] = v[i];
        lazy = vector<U>(size_, id);
    }

    int size() const {
        return _n;
    }

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size_;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p - size_] = x;
    }

    void apply(int p, U val) {
        assert(0 <= p && p < _n);
        p += size_;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p - size_] =
            val == id ? node[p - size_] : mapping(node[p - size_], val);
    }

    void apply(int l, int r, U val) {
        if (l >= r) return;

        l += size_;
        r += size_;

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
    }

    T operator[](int p) {
        assert(0 <= p && p < _n);
        p += size_;
        for (int i = log; i >= 1; i--) push(p >> i);
        return node[p - size_];
    }

#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, DualSegmentTree r) {
        vector<T> v(r.size());
        for (int i = 0; i < r.size(); i++) {
            v[i] = r[i];
        }
        os << v;
        return os;
    }
#endif

  private:
    void all_apply(int k, U val) {
        if (k >= size_)
            node[k - size_] =
                val == id ? node[k - size_] : mapping(node[k - size_], val);
        else
            lazy[k] = composition(lazy[k], val);
    }

    void push(int k) {
        if (lazy[k] == id) return;
        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);
        lazy[k] = id;
    }
};