#pragma once

#include <cassert>
#include <functional>
#include <queue>
#include <vector>

template <class T,
          class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type>>
struct ErasablePriorityQueue {
    std::priority_queue<T, Container, Compare> pq, erased;

    int size() const {
        return pq.size() - erased.size();
    }

    bool empty() const {
        return size() == 0;
    }

    void push(T x) {
        pq.push(x);
    }

    void erase(T x) {
        erased.push(x);
        assert(erased.size() <= pq.size());
    }

    T top() {
        assert(!empty());
        update();
        return pq.top();
    }

  private:
    void update() {
        while (!erased.empty() && pq.top() == erased.top()) {
            pq.pop();
            erased.pop();
        }
    }
};