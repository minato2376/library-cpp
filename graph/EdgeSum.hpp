
struct EdgeSum {
    int n;
    vector<vector<pair<int, ll>>> g;
    vector<pair<int, ll>> linear_coeffs;
    vector<int> roots;
    vector<pair<ll, ll>> ranges;
    EdgeSum() {
    }
    EdgeSum(int n) : n(n), g(n), linear_coeffs(n) {
    }
    void add_edge(int u, int v, ll w) {
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    bool solve(ll l, ll r) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (linear_coeffs[i].first == 0) {
                linear_coeffs[i] = {1, 0};
                auto [value, x] = dfs(i);
            }
        }
        return ok;
    }

    // x + p == -x + q -> 2x = q - p
    pair<int, ll> dfs(int v) {
        auto [a, b] = linear_coeffs[v];
        for (auto [nv, w] : g[v]) {
            auto [na, nb] = linear_coeffs[nv];
            if (na == 0) {
                linear_coeffs[nv] = {a ^ 1, w - b};
                auto value = dfs(nv);
                if (value.first != 1) return value;
            } else {
                if (na == a) {
                    ll xx = w - b - nb;
                    if (na == -1) xx *= -1;
                    if (xx % 2 != 0) return {0, 0};
                    return {2, xx / 2};
                } else {
                    if (w - b != nb) return {0, 0};
                }
            }
        }
        return {1, 0};
    }
};