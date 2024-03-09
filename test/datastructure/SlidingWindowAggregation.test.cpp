#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include "other/template.hpp"
#include "datastructure/SlidingWindowAggregation.hpp"

int main() {
    INT(N);
    VEC(ll, A, N);
    auto f = [](ll a, ll b) { return gcd(a, b); };
    constexpr ll e = 0;
    SlidingWindowAggregation swag(f, e);
    int r = 0;
    ll ans = 0;
    rep(l, N) {
        while (r < N && f(swag.fold_all(), A[r]) != 1) {
            swag.push(A[r]);
            r++;
        }
        ans += N - r;
        if (l == r)
            r++;
        else
            swag.pop();
    }
    print(ans);
}