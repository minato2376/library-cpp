#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "other/template.hpp"
#include "segmenttree/DualSegmentTree.hpp"
int main() {
    INT(n, q);
    auto g = [](int a, int b) {
        (void)a;
        return b;
    };
    auto h = [](int a, int b) {
        (void)a;
        return b;
    };
    const int id = numeric_limits<int>::max();
    vec<int> A(n, numeric_limits<int>::max());
    DualSegmentTree seg(g, h, id, A);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            seg.apply(l, r + 1, x);
        } else {
            INT(i);
            print(seg[i]);
        }
    }
}