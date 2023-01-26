#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "other/template.hpp"
#include "datastructure/BinaryIndexedTree.hpp"

int main() {
    INT(N, Q);
    BinaryIndexedTree<ll> BIT(N);
    VEC(ll, A, N);
    rep(i, N) BIT.add(i, A[i]);
    rep(Q) {
        INT(T);
        if (T == 0) {
            LL(p, x);
            BIT.add(p, x);
        } else {
            INT(l, r);
            print(BIT.sum(l, r));
        }
    }
}