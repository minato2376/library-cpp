#pragma once

#include <algorithm>
#include <cassert>
#include <bit>
#include <vector>

struct SegmentTreeInfo {
    using uint = unsigned int;
    int n, n_bit_ceil;

    SegmentTreeInfo(int n_) : n(n_), n_bit_ceil(std::bit_ceil((uint)n_)) {
    }

    int size() const {
        return n_bit_ceil * 2;
    }

    int node_index(int i) const {
        assert(0 <= i && i < n);
        return i + n_bit_ceil;
    }

    std::pair<int, int> index_to_range(int node_index) const {
        assert(1 <= node_index && node_index < n_bit_ceil * 2);
        int depth = topbit(node_index);
        int width = n_bit_ceil >> depth;
        return {node_index - (1 << depth), node_index + width - (1 << depth)};
    }

    std::vector<int> split_range(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        l += n_bit_ceil;
        r += n_bit_ceil;

        std::vector<int> L, R;
        while (l < r) {
            if (l & 1) L.push_back(l++);
            if (r & 1) R.push_back(--r);
            l >>= 1;
            r >>= 1;
        }
        L.reserve(L.size() + R.size());
        std::move(R.rbegin(), R.rend(), std::back_inserter(L));
        return L;
    }

    std::vector<int> coverings(int i) const {
        assert(0 <= i && i < n);
        i += n_bit_ceil;
        std::vector<int> coverings;
        coverings.reserve(topbit(i) + 1);
        while (i > 0) {
            coverings.push_back(i);
            i >>= 1;
        }
        return coverings;
    }

  private:
    int topbit(int x) const {
        return 31 - std::countr_zero((uint)x);
    }
};