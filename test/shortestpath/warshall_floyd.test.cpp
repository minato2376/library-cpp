#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "other/template.hpp"
#include "shortestpath/warshall_floyd.hpp"

int main() {
    constexpr int INF = numeric_limits<int>::max();
    INT(V, E);
    vvec<int> dist(V, vec<int>(V, INF));
    rep(i, V) dist[i][i] = 0;
    rep(E) {
        INT(s, t, d);
        chmin(dist[s][t], d);
    }
    warshall_floyd<int, INF>(dist);
    rep(i, V) if (dist[i][i] < 0) drop("NEGATIVE CYCLE");
    rep(i, V) {
        rep(j, V) {
            if (j) cout << " ";
            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];
        }
        cout << ln;
    }
}