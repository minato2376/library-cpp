#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "other/template.hpp"
#include "segmenttree/LazySegmentTree.hpp"
int main() {
    INT(n, q);
    auto seg = buildRangeAddRangeMin<int, numeric_limits<int>::max()>(n);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            seg.apply(l, r + 1, x);
        } else {
            INT(l, r);
            print(seg.get(l, r + 1));
        }
    }
}