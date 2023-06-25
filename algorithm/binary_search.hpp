#pragma once

#include <cassert>
#include <cmath>

namespace minato {
/**
 * f(T x) -> bool
 * f(ok) = true f(ng) = false
 */
template <class T, class F> T binary_search(T ok, T ng, const F& f) {
    assert(ok != ng);
    while (std::abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
}  // namespace minato
