#pragma once

#include <queue>
#include <vector>

std::vector<int> bfs(const std::vector<std::vector<int>>& G,
                     const std::vector<int>& starts = {0}) {
    std::vector<int> ret(G.size(), -1);
    std::queue<int> que;
    for (int s : starts) {
        ret[s] = 0;
        que.push(s);
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int nv : G[v]) {
            if (~ret[nv]) continue;
            ret[nv] = ret[v] + 1;
            que.push(nv);
        }
    }
    return ret;
}
