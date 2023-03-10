#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "other/template.hpp"
#include "mod/ModInt.hpp"

void aplusb() {
    INT(A, B);
    print(A + B);
}
using mint = ModInt<11>;

int main() {
    mint a = 10;
    mint b(3);

    // equal
    assert(a == 21);
    assert(a == -1);
    assert(-1 == a);

    // negative
    assert(-b == 8);

    // plus
    assert(a + b == 2);  // (10 + 3) mod 11
    assert(1 + a == 0);

    // minus
    assert(a - b == 7);  // (10 - 3) mod 11
    assert(b - a == 4);

    //++, --
    b++;
    assert(b == 4);
    b--;
    assert(b == 3);

    // mul
    assert(a * b == 8);  // (10 * 3) mod 11

    // inv
    assert(b.inv() == 4);  // (3 * 4) mod 11 == 1

    // div
    assert(a / b == 7);  // (10 * 4) mod 11

    // +=, -=, *=, /=
    a += b;
    assert(a == 2 && b == 3);
    a -= b;
    assert(a == 10 && b == 3);
    a *= b;
    assert(a == 8 && b == 3);
    a /= b;
    assert(a == 10 && b == 3);

    // pow
    assert(mint(2).pow(4) == 5);  // 16 mod 11

    // ^=
    mint c = 2;
    c ^= 4;
    assert(c == 5);
    c ^= -2;
    assert(c == 4);  // (4 * 25) mod 11 == 1

    // get mod
    assert(mint::mod() == 11 && a.mod() == 11);

    // mint(x) と書くとmodを取る操作が発生します((x % mod + mod) %
    // modをmodintに代入します) mint::raw(x)
    // はxをmodを取らずに代入するので高速です(もちろんxが[0,
    // mod)であることを利用者が保証しないといけません)
    assert(mint::raw(3) == 3);
    aplusb();
}