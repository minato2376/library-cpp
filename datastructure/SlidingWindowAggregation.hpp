#pragma once

#include <cassert>
#include <utility>
#include <vector>

template <class T, class F> struct SlidingWindowAggregation {
    F op;
    T e;
    std::vector<std::pair<T, T>> front, back;

    SlidingWindowAggregation(F op, T e) : op(op), e(e) {
    }

    void clear() {
        front.clear();
        back.clear();
    }

    void reserve(int n) {
        front.reserve(n);
        back.reserve(n);
    }

    bool empty() const {
        return front.empty() && back.empty();
    }

    int size() const {
        return front.size() + back.size();
    }

    T fold_all() const {
        T vf = front.empty() ? e : front.back().second;
        T vb = back.empty() ? e : back.back().second;
        return op(vf, vb);
    }

    void push(const T& val) {
        if (back.empty()) {
            back.emplace_back(val, val);
        } else {
            back.emplace_back(val, op(back.back().second, val));
        }
    }

    void pop() {
        assert(!empty());
        if (front.empty()) {
            front.emplace_back(back.back().first, back.back().first);
            back.pop_back();
            while (!back.empty()) {
                front.emplace_back(back.back().first,
                                   op(back.back().first, front.back().second));
                back.pop_back();
            }
        }
        front.pop_back();
    }
};