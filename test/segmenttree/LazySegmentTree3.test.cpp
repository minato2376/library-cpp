#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"
#include "other/template.hpp"
#include "segmenttree/LazySegmentTree.hpp"
int main() {
    INT(n, q);
    auto seg = buildRangeSetRangeSum<int>(n, numeric_limits<int>::max());
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