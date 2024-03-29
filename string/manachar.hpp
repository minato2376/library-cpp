#pragma once

#include <string>
#include <vector>

std::vector<int> manachar(const std::string& s) {
    int n = s.size();
    std::vector<int> res(n);
    for (int i = 0, j = 0; i < n;) {
        while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;
        res[i] = j;
        int k = 1;
        while (i - k >= 0 and i + k < n and k + res[i - k] < j) {
            res[i + k] = res[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    return res;
}

template <typename T> std::vector<int> manachar(const std::vector<T>& s) {
    int n = s.size();
    std::vector<int> res(n);
    for (int i = 0, j = 0;;) {
        while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;
        res[i] = j;
        int k = 1;
        while (i - k >= 0 and i + k < n and k + res[i - k] < j) {
            res[i + k] = res[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    return res;
}