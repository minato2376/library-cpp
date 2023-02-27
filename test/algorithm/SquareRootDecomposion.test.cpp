#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3170"
#include "other/template.hpp"
#include "algorithm/SquareRootDecomposition.hpp"

int main() {
    constexpr ll INF = TEN(18);
    INT(N, Q);
    VEC(ll, A, N);

    SquareRootDecomposition<64> decomp(N);
    auto B = A;
    vec<ll> add(decomp.bucket_size(), 0);
    vec<ll> mn(decomp.bucket_size(), -INF);
    vec<ll> mx(decomp.bucket_size(), INF);
    // 足したあと切り詰める
    auto upd = [&](int k) {
        auto [l, r] = decomp.bucket_range(k);
        rep(i, l, r) A[i] += add[k];
        add[k] = 0;
        rep(i, l, r) A[i] = clamp(A[i], mn[k], mx[k]);
        rep(i, l, r) B[i] = A[i];
        sort(B.begin() + l, B.begin() + r);
        mn[k] = -INF;
        mx[k] = INF;
    };
    auto lazy = [&](int k, int t, ll x) {
        if (t == 1) {
            chmin(mn[k], x);
            chmin(mx[k], x);
        } else if (t == 2) {
            chmax(mn[k], x);
            chmax(mx[k], x);
        } else {
            add[k] += x;
            mn[k] += x;
            mx[k] += x;
        }
    };
    rep(i, decomp.bucket_size()) upd(i);
    rep(Q) {
        INT(t);
        if (t == 1) {
            LL(l, r, x);
            l--;
            auto ranges = decomp.query(l, r);
            if (ranges.left_overflow_range) {
                auto [p, q] = ranges.left_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) chmin(A[j], x);
                upd(decomp.bucket_id(p));
            }
            if (ranges.bucket_range) {
                auto [p, q] = ranges.bucket_range.value();
                rep(j, p, q) {
                    lazy(j, t, x);
                }
            }
            if (ranges.right_overflow_range) {
                auto [p, q] = ranges.right_overflow_range.value();
                debug(p, q);
                upd(decomp.bucket_id(p));
                rep(j, p, q) chmin(A[j], x);
                upd(decomp.bucket_id(p));
            }
        } else if (t == 2) {
            LL(l, r, x);
            l--;
            auto ranges = decomp.query(l, r);
            if (ranges.left_overflow_range) {
                auto [p, q] = ranges.left_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) chmax(A[j], x);
                upd(decomp.bucket_id(p));
            }
            if (ranges.bucket_range) {
                auto [p, q] = ranges.bucket_range.value();
                rep(j, p, q) {
                    lazy(j, t, x);
                }
            }
            if (ranges.right_overflow_range) {
                auto [p, q] = ranges.right_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) chmax(A[j], x);
                upd(decomp.bucket_id(p));
            }

        } else if (t == 3) {
            LL(l, r, x);
            l--;
            auto ranges = decomp.query(l, r);
            if (ranges.left_overflow_range) {
                auto [p, q] = ranges.left_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) A[j] += x;
                upd(decomp.bucket_id(p));
            }
            if (ranges.bucket_range) {
                auto [p, q] = ranges.bucket_range.value();
                rep(j, p, q) {
                    lazy(j, t, x);
                }
            }
            if (ranges.right_overflow_range) {
                auto [p, q] = ranges.right_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) A[j] += x;
                upd(decomp.bucket_id(p));
            }

        } else {
            LL(l, r, x, y);
            l--;
            auto ranges = decomp.query(l, r);
            int ans = 0;
            if (ranges.left_overflow_range) {
                auto [p, q] = ranges.left_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) {
                    if (x <= A[j] && A[j] <= y) ans++;
                }
            }
            if (ranges.bucket_range) {
                auto [p, q] = ranges.bucket_range.value();
                rep(j, p, q) {
                    if (mn[j] > y || mx[j] < x) continue;
                    auto [a, b] = decomp.bucket_range(j);
                    int lb =
                        lower_bound(B.begin() + a, B.begin() + b, x - add[j]) -
                        B.begin();
                    int ub =
                        upper_bound(B.begin() + a, B.begin() + b, y - add[j]) -
                        B.begin();
                    if (mn[j] >= x) lb = a;
                    if (mx[j] <= y) ub = b;
                    ans += ub - lb;
                }
            }
            if (ranges.right_overflow_range) {
                auto [p, q] = ranges.right_overflow_range.value();
                upd(decomp.bucket_id(p));
                rep(j, p, q) {
                    if (x <= A[j] && A[j] <= y) ans++;
                }
            }
            print(ans);
        }
    }
}