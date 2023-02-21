#define PROBLEM "https://yukicoder.me/problems/no/674"
#include "other/template.hpp"
#include "datastructure/RangeSet.hpp"

int main() {
    LL(D, Q);
    RangeSet<ll> dic;
    ll ans = 0;
    rep(Q) {
        LL(a, b);
        dic.insert_range(a, b + 1);
        auto it = dic.contains_range(a, b + 1);
        chmax(ans, it->second - it->first);
        print(ans);
    }
}