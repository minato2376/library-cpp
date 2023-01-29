#pragma once

/**
 * f(T x) -> bool
 * f(ok) = true f(ng) = false
 */
template <class T, class F> T binary_search_(T ok, T ng, const F& f) {
    assert(ok != ng);
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
