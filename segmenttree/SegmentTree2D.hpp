#pragma once

#include <bit>
#include <atcoder/segtree>

template <class S, S (*op)(S, S), S (*e)()> struct SegmentTree2D {
    int n, m, size, log;
    std::vector<atcoder::segtree<S, op, e>> d;

    SegmentTree2D() {
    }
    SegmentTree2D(int n_, int m_)
        : SegmentTree2D(
              std::vector<std::vector<S>>(n_, std::vector<S>(m_, e()))) {
    }
    SegmentTree2D(const std::vector<std::vector<S>>& v)
        : n(int(v.size())), m(int(v[0].size())) {
        size = std::bit_ceil((unsigned int)n);
        log = std::bit_width((unsigned int)size) - 1;
        d.resize(2 * size);
        for (int i = 0; i < n; i++)
            d[size + i] = atcoder::segtree<S, op, e>(v[i]);
        for (int i = n; i < size; i++) {
            d[size + i] = atcoder::segtree<S, op, e>(m);
        }
        for (int i = size - 1; i >= 1; i--) {
            std::vector<S> tmp(m);
            for (int j = 0; j < m; j++) {
                tmp[j] = op(d[i << 1 | 0].get(j), d[i << 1 | 1].get(j));
            }
            d[i] = atcoder::segtree<S, op, e>(tmp);
        }
    }

    void set(int p, int q, S x) {
        assert(0 <= p && p < n);
        assert(0 <= q && q < m);
        p += size;
        d[p].set(q, x);
        for (int i = 1; i <= log; i++) {
            int x = p >> i;
            d[x].set(q, op(d[x << 1 | 0].get(q), d[x << 1 | 1].get(q)));
        }
    }

    S get(int p, int q) const {
        assert(0 <= p && p < n);
        assert(0 <= q && q < m);
        return d[p + size].get(q);
    }

    S prod(int hl, int hr, int wl, int wr) const {
        assert(0 <= hl && hl <= hr && hr <= n);
        assert(0 <= wl && wl <= wr && wr <= m);
        S sml = e(), smr = e();
        hl += size;
        hr += size;
        while (hl < hr) {
            if (hl & 1) sml = op(sml, d[hl++].prod(wl, wr));
            if (hr & 1) smr = op(d[--hr].prod(wl, wr), smr);
            hl >>= 1;
            hr >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const {
        return d[1].all_prod();
    }
};