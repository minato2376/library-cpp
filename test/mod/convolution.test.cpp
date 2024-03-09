#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "other/template.hpp"
#include "mod/FormalPowerSeriesNTTFriendly.hpp"
using namespace atcoder;
using mint = modint998244353;
using FPS = FormalPowerSeriesNTTFriendly<mint>;
void solve() {
    INT(N, M);
    auto F = FPS::read(N);
    auto G = FPS::read(M);

    auto H = F * G;
    H.resize(N + M - 1);
    print(H);
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