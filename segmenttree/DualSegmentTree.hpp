template <class T, class U, class G, class H> struct DualSegmentTree {
  private:
    G mapping;
    H composition;
    U id;
    int _n, size, log;
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
        size = 1 << log;
        node.resize(size);
        for (int i = 0; i < _n; i++) node[i] = v[i];
        lazy = vector<U>(size, id);
    }

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p - size] = x;
    }

    void apply(int p, U val) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        node[p - size] =
            val == id ? node[p - size] : mapping(node[p - size], val);
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
    }

    T operator[](int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return node[p - size];
    }

  private:
    void all_apply(int k, U val) {
        if (k >= size)
            node[k - size] =
                val == id ? node[k - size] : mapping(node[k - size], val);
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