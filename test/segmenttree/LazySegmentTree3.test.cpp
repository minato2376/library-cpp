#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"
#include "other/template.hpp"
#include "segmenttree/LazySegmentTree.hpp"
int main() {
    INT(n, q);
    constexpr pii e = pii(0, 0);
    constexpr int id = numeric_limits<int>::max();
    auto seg = buildRangeSetRangeSum<int, int>(n, e, id);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            seg.apply(l, r + 1, x);
        } else {
            INT(l, r);
            print(seg.get(l, r + 1).first);
        }
    }
}