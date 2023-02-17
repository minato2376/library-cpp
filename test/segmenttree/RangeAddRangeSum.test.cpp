#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "other/template.hpp"
#include "segmenttree/RangeAddRangeSum.hpp"
int main() {
    INT(n, q);
    RangeAddRangeSum<ll> BIT(n);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            BIT.add(l - 1, r, x);
        } else {
            INT(l, r);
            print(BIT.sum(l - 1, r));
        }
    }
}