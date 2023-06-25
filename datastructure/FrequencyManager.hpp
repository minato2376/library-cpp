#pragma once

#include <vector>
#include <cassert>

struct FrequencyManager {
    int n;
    std::vector<int> freq;
    int distinct_count;

    FrequencyManager() : n(0), distinct_count(0) {
    }
    FrequencyManager(int n) : n(n), freq(n), distinct_count(0) {
    }

    int size() const {
        return n;
    }

    /**
     * O(1)
     */
    int get_distinct_count() const {
        return distinct_count;
    }

    /**
     * O(1)
     */
    void add(int x) {
        assert(0 <= x && x < n);
        if (freq[x] == 0) distinct_count++;
        freq[x]++;
    }

    /**
     * O(1)
     */
    void erase(int x) {
        assert(0 <= x && x < n);
        assert(freq[x] > 0);
        freq[x]--;
        if (freq[x] == 0) distinct_count--;
    }
};