/**
 * 値が lower 以上 upper 未満である長さ n の数列を全て生成する。
 * O(D**n * n)
 */
template <typename T>
vector<vector<T>> generate_random_sequence(int n, T upper, T lower = 0) {
    int D = upper - lower;
    int size = 1;
    for (int i = 0; i < n; i++) size *= D;
    vector<vector<T>> ret(size);
    for (int k = 0; k < size; k++) {
        vector<T> v(n);
        int x = k;
        for (int i = 0; i < n; i++) {
            v[i] = lower + x % D;
            x /= D;
        }
        reverse(v.begin(), v.end());
        ret[k] = v;
    }
    return ret;
}