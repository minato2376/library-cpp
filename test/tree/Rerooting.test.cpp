#define PROBLEM "https://yukicoder.me/problems/no/1333"
#include "other/template.hpp"
#include "tree/Rerooting.hpp"
#include "mod/ModInt.hpp"
using mint = ModInt<1000000007>;
using Tu = tuple<mint, mint, mint>;

int main() {
    INT(N);
    auto op = [](Tu a, Tu b) {
        auto [a0, a1, a2] = a;
        auto [b0, b1, b2] = b;
        return Tu(a0 + b0, a1 + b1, a2 + b2);
    };
    auto etov = [](Tu a, auto e) {
        auto [a0, a1, a2] = a;
        return Tu(a0 + a1 * e.weight * 2 + e.weight * e.weight * a2,
                  a1 + e.weight * a2, a2);
    };
    auto vtoe = [](Tu a, int v) {
        (void)v;
        auto [a0, a1, a2] = a;
        return Tu(a0, a1, a2 + 1);
    };
    const Tu e = Tu(0, 0, 0);
    Rerooting<Tu, Tu, mint, decltype(op), decltype(etov), decltype(vtoe)> r(
        N, op, etov, vtoe, e);
    rep(N - 1) {
        INT(a, b, c);
        a--;
        b--;
        r.add_edge(a, b, c);
    }
    r.build();
    mint ans = 0;
    rep(i, N) {
        ans += get<0>(r[i]);
    }
    ans /= 2;
    print(ans);
}