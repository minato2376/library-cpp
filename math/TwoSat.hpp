#pragma once
#include <atcoder/twosat>

struct TwoSat : public atcoder::two_sat {
    TwoSat() : two_sat() {
    }
    TwoSat(int n) : two_sat(n) {
    }

    /**
     * x => y
     */
    void add_if(int x, int y) {
        add_clause(y, true, x, false);
    }

    void set_true(int x) {
        add_clause(x, true, x, true);
    }

    void set_false(int x) {
        add_clause(x, false, x, false);
    }
};