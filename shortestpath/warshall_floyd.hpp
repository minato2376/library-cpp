#pragma once

#include <vector>

template <typename Int>
std::vector<std::vector<Int>> warshall_floyd(
    const std::vector<std::vector<Int>>& G,
    Int INF) {
    int N = G.size();
    auto dist = G;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < N; j++) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}