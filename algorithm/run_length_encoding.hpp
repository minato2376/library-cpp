template <class T>
vector<pair<T, int>> run_length_encoding(const vector<T>& v) {
    if (v.empty()) return {};
    int cnt = 1;
    vector<pair<T, int>> ret;
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i - 1] != v[i]) {
            ret.emplace_back(v[i - 1], cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    ret.emplace_back(v.back(), cnt);
    return ret;
}

vector<pair<char, int>> run_length_encoding(const string& s) {
    if (s.empty()) return {};
    int cnt = 1;
    vector<pair<char, int>> ret;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i]) {
            ret.emplace_back(s[i - 1], cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    ret.emplace_back(s.back(), cnt);
    return ret;
}