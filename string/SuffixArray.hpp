#pragma once

#include <atcoder/string>
#include <string>
#include <vector>

template <class T> struct SuffixArray {
    T s;
    int n;
    std::vector<int> sa, sa_inv;
    SuffixArray() {
    }

    SuffixArray(const std::string& s)
        : s(s), n(int(s.size())), sa(), sa_inv(s.size()) {
        sa = atcoder::suffix_array(s);
        for (int i = 0; i < n; i++) {
            sa_inv[sa[i]] = i;
        }
    }

    template <class U>
    SuffixArray(const std::vector<U>& s)
        : s(s), n(int(s.size())), sa(), sa_inv(s.size()) {
        sa = atcoder::suffix_array(s);
        for (int i = 0; i < n; i++) {
            sa_inv[sa[i]] = i;
        }
    }

    SuffixArray(const std::vector<int>& s, int upper)
        : s(s), n(int(s.size())), sa(), sa_inv(s.size()) {
        sa = atcoder::suffix_array(s, upper);
        for (int i = 0; i < n; i++) {
            sa_inv[sa[i]] = i;
        }
    }

    int size() const {
        return n;
    }

    int operator[](int i) const {
        return sa[i];
    }

    int inv(int i) const {
        return sa_inv[i];
    }

    auto data(int i) const {
        return s[i];
    }

    /**
     * @brief
     * t 以上の s の suffix のうち、辞書順で最小のものの開始位置を返す
     * O(|t| log|s|)
     * @note
     * 戻り値はsa のインデックス
     * t 以上の suffix が存在しない場合は n を返す
     */
    int lower_bound(const T& t) const {
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (lexicomp_suffix_of_s_and_t(sa[m], t) ? l : r) = m;
        }
        return r;
    }

    /**
     * @brief
     * t より大きい s の suffix のうち、辞書順で最小のものの開始位置を返す
     * O(|t| log|s|)
     * @note
     * 戻り値はsa のインデックス
     * @note
     * t より大きい suffix が存在しない場合は n を返す
     */
    int upper_bound(T t) const {
        if (t.empty()) return 0;
        t.back()++;
        return lower_bound(t);
    }

    /**
     * @brief
     * s に含まれる t の出現回数を返す
     * O(|t| log|s|)
     */
    int count(T t) const {
        return upper_bound(t) - lower_bound(t);
    }

  private:
    /**
     * @brief
     * s の s_begin から始まる部分文字列と t が辞書順で比較されたとき、 s
     * の方が辞書順で小さいかどうかを返す
     */
    bool lexicomp_suffix_of_s_and_t(int s_begin, const T& t) const {
        return lexicographical_compare(s.begin() + s_begin, s.end(), t.begin(),
                                       t.end());
    }
};