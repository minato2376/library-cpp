#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include "other/template.hpp"
#include "algorithm/inversion_number.hpp"

int main() {
    INT(N);
    VEC(int, A, N);
    print(inversion_number(A));
}