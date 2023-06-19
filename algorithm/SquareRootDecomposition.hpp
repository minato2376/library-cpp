#pragma once

#include <cassert>
#include <optional>

template <int W> struct SquareRootDecomposition {
    struct Ranges {
        std::optional<pair<int, int>> left_overflow_range;
        std::optional<pair<int, int>> bucket_range;
        std::optional<pair<int, int>> right_overflow_range;
        Ranges()
            : left_overflow_range(nullopt),
              bucket_range(nullopt),
              right_overflow_range(nullopt) {
        }
    };

    int n;

    SquareRootDecomposition() {
    }
    SquareRootDecomposition(int n) : n(n) {
    }

    int bucket_size() const {
        return (n + W - 1) / W;
    }

    /**
     * @brief クエリの範囲を分割する
     * @param l 左端
     * @param r 右端
     * @return 分割された範囲
     * @note [l, r) の範囲を分割する
     */
    Ranges query(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        Ranges ret;
        int l_bucket_id = bucket_id(l);
        int r_bucket_id = bucket_id(r - 1);
        auto [l_bucket_l, l_bucket_r] = bucket_range(l_bucket_id);
        auto [r_bucket_l, r_bucket_r] = bucket_range(r_bucket_id);
        if (l_bucket_id == r_bucket_id) {
            if (l == l_bucket_l && r == r_bucket_r) {
                ret.bucket_range = {l_bucket_id, l_bucket_id + 1};
            } else {
                ret.left_overflow_range = {l, r};
            }
        } else {
            if (l_bucket_id + 1 < r_bucket_id) {
                ret.bucket_range = {l_bucket_id + 1, r_bucket_id};
            }
            if (l == l_bucket_l) {
                if (ret.bucket_range) {
                    ret.bucket_range->first--;
                } else {
                    ret.bucket_range = {l_bucket_id, l_bucket_id + 1};
                }
            } else {
                ret.left_overflow_range = {l, l_bucket_r};
            }
            if (r == r_bucket_r) {
                if (ret.bucket_range) {
                    ret.bucket_range->second++;
                } else {
                    ret.bucket_range = {r_bucket_id, r_bucket_id + 1};
                }
            } else {
                ret.right_overflow_range = {r_bucket_l, r};
            }
        }
        return ret;
    }

    /**
     * @brief インデックスが属するバケットを返す
     * @param i インデックス
     * @return バケットの番号
     * @note [0, n) の範囲のインデックス i が属するバケットの番号を返す
     */
    int bucket_id(int i) const {
        assert(0 <= i && i < n);
        return i / W;
    }

    /**
     * @brief バケットの範囲を返す
     * @param i バケットの番号
     * @return バケットの範囲
     * @note [l, r) の範囲を返す
     */
    pair<int, int> bucket_range(int i) const {
        assert(0 <= i && i < bucket_size());
        int l = i * W;
        int r = min((i + 1) * W, n);
        return {l, r};
    }
};