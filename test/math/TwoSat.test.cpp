#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "other/template.hpp"
#include "math/TwoSat.hpp"

int main() {
    STR(p, cnf);
    INT(N, M);
    TwoSat TS(N);
    rep(M) {
        INT(a, b, c);
        TS.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    if (!TS.satisfiable()) drop("s UNSATISFIABLE");
    print("s SATISFIABLE");
    auto answer = TS.answer();
    cout << "v ";
    rep(i, N) {
        cout << (answer[i] ? i + 1 : -(i + 1)) << " ";
    }
    cout << 0 << ln;
}
