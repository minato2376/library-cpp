#pragma once
#include <atcoder/twosat>

struct TwoSat : atcoder::two_sat {
    TwoSat() : two_sat() {
    }
    TwoSat(int n) : two_sat(n) {
    }

    /**
     * x => y
     */
    void add_if(int x, int y) {
        add_clause(x, false, y, true);
    }

    /**
     * x かつ y が偽
     */
    void add_nand(int x, int y) {
        add_clause(x, false, y, false);
    }

    void set_true(int x) {
        add_clause(x, true, x, true);
    }

    void set_false(int x) {
        add_clause(x, false, x, false);
    }
};