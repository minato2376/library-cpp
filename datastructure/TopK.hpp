#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>

template <class Key,
          class T,
          int K,
          T (*op)(T, T),
          bool (*comp)(std::pair<Key, T>, std::pair<Key, T>),
          std::pair<Key, T> (*e)()>
struct TopK {
    using P = std::pair<Key, T>;
    std::array<P, K> data;

    TopK() {
        std::fill(data.begin(), data.end(), e());
    }
    TopK(std::vector<P> v) {
        std::fill(data.begin(), data.end(), e());
        for (int i = 0; i < int(v.size()); i++) {
            data[i] = v[i];
        }
    }

    void push(P x) {
        std::array<P, K + 1> buf = {};
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