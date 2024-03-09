#pragma once

#include <istream>
#include <ostream>

#include <atcoder/modint>

template <int M>
std::istream& operator>>(std::istream& is, atcoder::static_modint<M>& m) {
    long long x;
    is >> x;
    m = x;
    return is;
}
template <int M>
std::ostream& operator<<(std::ostream& os, const atcoder::static_modint<M>& m) {
    return os << m.val();
}