#pragma once

#include <algorithm>
#include <vector>

template <class T> struct Compress {
  public:
    Compress() {
    }
    Compress(const std::vector<T>& vs) {
        add(vs);
    }

    void add(const std::vector<T>& vs) {
        std::copy(vs.begin(), vs.end(), back_inserter(xs));
    }
    void add(const T& x) {
        xs.emplace_back(x);
    }

    int build() {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        return int(xs.size());
    }

    int size() const {
        return int(xs.size());
    }

    std::vector<int> get(const std::vector<T>& vs) const {
        std::vector<int> ret;
        ret.reserve(vs.size());
        std::transform(
            vs.begin(), vs.end(), back_inserter(ret), [&](const T& e) {
                return std::lower_bound(xs.begin(), xs.end(), e) - xs.begin();
            });
        return ret;
    }

    int get(const T& x) const {
        return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }

    const T& operator[](int k) const {
        return xs[k];
    }

  private:
    std::vector<T> xs;
};