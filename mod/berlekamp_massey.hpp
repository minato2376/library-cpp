#pragma once

#include <vector>

template <class mint>
std::vector<mint> berlekamp_massey(const std::vector<mint>& s) {
    const int N = (int)s.size();
    std::vector<mint> b, c;
    b.reserve(N + 1);
    c.reserve(N + 1);
    b.push_back(mint(1));
    c.push_back(mint(1));
    mint y = mint(1);
    for (int ed = 1; ed <= N; ed++) {
        int l = int(c.size()), m = int(b.size());
        mint x = 0;
        for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
        b.emplace_back(mint(0));
        m++;
        if (x == mint(0)) continue;
        mint freq = x / y;
        if (l < m) {
            auto tmp = c;
            c.insert(c.begin(), m - l, mint(0));
            for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
            b = tmp;
            y = x;
        } else {
            for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
        }
    }
    reverse(c.begin(), c.end());
    return c;
}