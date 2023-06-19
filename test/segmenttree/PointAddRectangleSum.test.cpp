#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "other/template.hpp"
#include "segmenttree/PointAddRectangleSum.hpp"

void solve() {
    INT(N, Q);
    VEC3(int, X, Y, W, N);
    vec<int> T(Q), A(Q), B(Q), C(Q), D(Q);
    rep(i, Q) {
        cin >> T[i];
        if (T[i] == 0) {
            cin >> A[i] >> B[i] >> C[i];
        } else {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }
    }
    PointAddRectangleSum<int, ll> ps;
    rep(i, N) {
        ps.push_point(X[i], Y[i]);
    }
    rep(i, Q) {
        if (T[i] == 0) {
            ps.push_point(A[i], B[i]);
        }
    }
    ps.build();
    rep(i, N) {
        ps.add(X[i], Y[i], W[i]);
    }
    rep(i, Q) {
        if (T[i] == 0) {
            ps.add(A[i], B[i], C[i]);
        } else {
            print(ps.get(A[i], C[i], B[i], D[i]));
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(7);

    int T = 1;
    // cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        // debug(test_case);
        solve();
    }
}