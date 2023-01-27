#pragma once
#include "datastructure/BinaryIndexedTree.hpp"

template <class T> long long inversion_number(const vector<T>& v) {
    int n = int(v.size());
    vector<T> com = v;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    int m = int(com.size());

    BinaryIndexedTree<int> BIT(m);
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(com.begin(), com.end(), v[i]) - com.begin();
        ret += BIT.sum(k + 1, m);
        BIT.add(k, 1);
    }

    return ret;
}