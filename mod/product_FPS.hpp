#pragma once

#include <queue>
#include <vector>
template <class FPS> FPS product_FPS(const std::vector<FPS>& fpss) {
    if (fpss.empty()) return FPS(1);
    auto comp = [&](const FPS& a, const FPS& b) { return a.size() > b.size(); };
    std::priority_queue<FPS, std::vector<FPS>, decltype(comp)> pq(comp, fpss);

    while (pq.size() > 1) {
        FPS a = pq.top();
        pq.pop();
        FPS b = pq.top();
        pq.pop();
        pq.push(a * b);
    }
    return pq.top();
}