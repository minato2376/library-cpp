/**
 * sqrt(x) を超えない最大の整数を求める。
 * O(1)
 */
long long floor_sqrt(long long x) {
    assert(0 <= x);
    return floor(sqrt((long double)x));
}