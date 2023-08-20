#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "other/template.hpp"
#include "datastructure/BinaryTrie.hpp"

int main() {
    auto f = [](int a, int b) { return a + b; };
    constexpr int e = 0;
    BinaryTrie<int, int, 30, decltype(f)> trie(f, e);

    INT(Q);
    rep(Q) {
        INT(t, x);
        if (t == 0) {
            trie.insert(x, 1);
        } else if (t == 1) {
            if (trie.find(x) == -1) continue;
            trie.erase(x);
        } else {
            print(trie.min_element(x));
        }
    }
}