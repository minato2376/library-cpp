#define PROBLEM "https://atcoder.jp/contests/abc284/tasks/abc284_d"
#include "math/floor_sqrt.hpp";
#include "other/template.hpp";

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        ll N;
        cin >> N;
        for (ll x = 2;; x++) {
            if (N % x == 0) {
                ll y = N / x;
                ll z = floor_sqrt(y);
                if (z * z == y) {
                    cout << z << " " << x << ln;
                } else {
                    y /= x;
                    cout << x << " " << y << ln;
                }
                break;
            }
        }
    }
}