#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"
#include "other/template.hpp"
#include "math/totient.hpp"

int main() {
    INT(N);
    print(totient(N));
}