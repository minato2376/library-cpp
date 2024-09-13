#pragma once

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

template <int B> struct Mo {
  public:
    Mo() {
    }
    Mo(int n) : n_(n) {
    }
    Mo(int n, int q) : n_(n) {
        L.reserve(q);
        R.reserve(q);
    }

    // (0-indexed) [l, r)
    void add(int l, int r) {
        assert(0 <= l && l < r && r <= n_);
        L.push_back(l);
        R.push_back(r);
    }

    template <class AL, class AR, class EL, class ER, class C>
    void build(const AL& add_left,
               const AR& add_right,
               const EL& erase_left,
               const ER& erase_right,
               const C& calc) const {
        int q = int(L.size());
        std::vector<int> ord(q);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(), [&](int i, int j) {
            int a = L[i] / B, b = L[j] / B;
            if (a != b) return a < b;
            return (a & 1) ? R[i] > R[j] : R[i] < R[j];
        });

        int l = 0, r = 0;
        for (int idx : ord) {
            while (l > L[idx]) add_left(--l);
            while (r < R[idx]) add_right(r++);
            while (l < L[idx]) erase_left(l++);
            while (r > R[idx]) erase_right(--r);
            calc(idx);
        }
    }

  private:
    int n_;
    std::vector<int> L, R;
};