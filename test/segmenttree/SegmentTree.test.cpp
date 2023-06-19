#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "other/template.hpp"
#include "segmenttree/SegmentTree.hpp"

void solve() {
    constexpr int e = numeric_limits<int>::max();
    INT(n, q);
    vec<int> A(n, e);

    auto seg = buildPointSetRangeMin<int>(A, e);
    rep(q) {
        INT(com, x, y);
        if (com == 0) {
            seg.set(x, y);
        } else {
            print(seg.get(x, y + 1));
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