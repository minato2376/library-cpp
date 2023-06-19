#define PROBLEM "https://yukicoder.me/problems/no/1234"
#include "other/template.hpp"
#include "segmenttree/LazySegmentTree.hpp"

int main() {
    INT(N);
    VEC(ll, A, N);
    constexpr ll e = numeric_limits<ll>::max();
    constexpr ll id = 0;
    auto seg = buildRangeAddRangeMin<ll>(A, e, id);
    INT(Q);
    rep(Q) {
        LL(t, l, r, c);
        l--;
        if (t == 1) {
            seg.apply(l, r, c);
        } else {
            print(seg.get(l, r));
        }
    }
}