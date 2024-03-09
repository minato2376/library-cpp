#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "other/template.hpp"
#include "mod/FormalPowerSeriesNTTFriendly.hpp"
using namespace atcoder;
using mint = modint998244353;
using FPS = FormalPowerSeriesNTTFriendly<mint>;
void solve() {
    INT(N);
    auto F = FPS::read(N);

    auto ans = F.inv(N);
    print(ans);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(7);

    int T = 1;
    // cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        // debug(test_case);
        solve();
    }
}