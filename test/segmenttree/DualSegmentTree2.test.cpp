#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include "other/template.hpp"
#include "segmenttree/DualSegmentTree.hpp"
int main() {
    INT(n, q);
    auto g = [](int a, int b) { return a + b; };
    auto h = [](int a, int b) { return a + b; };
    const int id = 0;
    DualSegmentTree seg(g, h, id, vec<int>(n));
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            seg.apply(l - 1, r, x);
        } else {
            INT(i);
            print(seg[i - 1]);
        }
    }
}