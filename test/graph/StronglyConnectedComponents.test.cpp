#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "other/template.hpp"
#include "graph/StronglyConnectedComponents.hpp"

int main() {
    INT(N, M);
    StronglyConnectedComponents SCC(N);
    rep(M) {
        INT(a, b);
        SCC.add_edge(a, b);
    }
    int K = SCC.build();
    print(K);
    auto g = SCC.groups();
    for (auto& v : g) {
        print(SZ(v), v);
    }
}