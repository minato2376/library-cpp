#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include "other/template.hpp"
#include "segmenttree/LazySegmentTree.hpp"
int main() {
    INT(n, q);
    constexpr int e = numeric_limits<int>::max();
    constexpr int id = 0;
    auto seg = buildRangeAddRangeMin<int>(vec<int>(n), e, id);
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