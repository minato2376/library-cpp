#define PROBLEM "https://yukicoder.me/problems/no/1469"
#include "other/template.hpp"
#include "algorithm/run_length_encoding.hpp"

int main() {
    STR(S);
    auto runs = run_length_encoding(S);
    string ans = "";
    for (auto [c, _] : runs) {
        ans += c;
    }
    print(ans);
}