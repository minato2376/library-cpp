#pragma once

#include <vector>

template <typename Int, Int INF>
void warshall_floyd(std::vector<std::vector<Int>>& G) {
    int N = G.size();

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (G[i][k] == INF) continue;
            for (int j = 0; j < N; j++) {
                if (G[k][j] == INF) continue;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    return;
}