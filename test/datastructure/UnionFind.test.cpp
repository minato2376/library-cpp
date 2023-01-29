#define PROBLEM "https://yukicoder.me/problems/no/1054"
#include "other/template.hpp"
#include "datastructure/UnionFind.hpp"

void solve() {
    INT(N, Q);
    UnionFind uf(N);
    vec<ll> D(N);
    vec<ll> A(N);
    auto f = [&](int r, int c) {
        auto vs = uf.group(c);
        for (auto v : vs) {
            A[v] += D[c] - D[r];
        }
    };
    rep(Q) {
        INT(t, a, b);
        if (t == 1) {
            a--;
            b--;
            uf.merge(a, b, f);
        } else if (t == 2) {
            a--;
            D[uf.root(a)] += b;
        } else {
            a--;
            print(A[a] + D[uf.root(a)]);
        }
    }
}

int main() {
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
}