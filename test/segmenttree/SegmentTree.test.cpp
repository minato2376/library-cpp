#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "other/template.hpp"
#include "segmenttree/SegmentTree.hpp"
int main() {
    INT(n, q);
    vec<int> A(n, numeric_limits<int>::max());
    auto seg = buildPointSetRangeMin<int, numeric_limits<int>::max()>(A);
    rep(q) {
        INT(com, x, y);
        if (com == 0) {
            seg.set(x, y);
        } else {
            print(seg.get(x, y + 1));
        }
    }
}