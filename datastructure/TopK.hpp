#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

template <class S, int K, bool (*comp)(S, S), S (*e)()> struct TopK {
    std::array<S, K> data;

    TopK() {
        std::fill(data.begin(), data.end(), e());
    }
    TopK(std::vector<S> v) {
        assert(int(v.size()) <= K);
        std::fill(data.begin(), data.end(), e());
        for (int i = 0; i < int(v.size()); i++) {
            data[i] = v[i];
        }
    }

    void push(S x) {
        for (int i = 0; i < K; i++) {
            if (comp(x, data[i])) {
                swap(x, data[i]);
            }
        }
    }

    const S& operator[](int i) const {
        assert(0 <= i && i < K);
        return data[i];
    }

    void merge(const TopK& rhs) {
        std::array<S, K> new_data;
        int l = 0, r = 0;
        for (int i = 0; i < K; i++) {
            if (comp(data[l], rhs[r])) {
                new_data[i] = data[l++];
            } else {
                new_data[i] = rhs[r++];
            }
        }
        data = new_data;
    }

#ifdef MINATO_LOCAL
    friend ostream& operator<<(ostream& os, TopK r) {
        os << r.data;
        return os;
    }
#endif
};