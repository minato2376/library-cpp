#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "other/template.hpp"
#include "generator/generate_random_sequence.hpp"

void aplusb() {
    INT(A, B);
    print(A + B);
}

int main() {
    {
        auto value = generate_random_sequence(3, 4);
        vec<vec<int>> expected = {
            {0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 1, 0}, {0, 1, 1},
            {0, 1, 2}, {0, 1, 3}, {0, 2, 0}, {0, 2, 1}, {0, 2, 2}, {0, 2, 3},
            {0, 3, 0}, {0, 3, 1}, {0, 3, 2}, {0, 3, 3}, {1, 0, 0}, {1, 0, 1},
            {1, 0, 2}, {1, 0, 3}, {1, 1, 0}, {1, 1, 1}, {1, 1, 2}, {1, 1, 3},
            {1, 2, 0}, {1, 2, 1}, {1, 2, 2}, {1, 2, 3}, {1, 3, 0}, {1, 3, 1},
            {1, 3, 2}, {1, 3, 3}, {2, 0, 0}, {2, 0, 1}, {2, 0, 2}, {2, 0, 3},
            {2, 1, 0}, {2, 1, 1}, {2, 1, 2}, {2, 1, 3}, {2, 2, 0}, {2, 2, 1},
            {2, 2, 2}, {2, 2, 3}, {2, 3, 0}, {2, 3, 1}, {2, 3, 2}, {2, 3, 3},
            {3, 0, 0}, {3, 0, 1}, {3, 0, 2}, {3, 0, 3}, {3, 1, 0}, {3, 1, 1},
            {3, 1, 2}, {3, 1, 3}, {3, 2, 0}, {3, 2, 1}, {3, 2, 2}, {3, 2, 3},
            {3, 3, 0}, {3, 3, 1}, {3, 3, 2}, {3, 3, 3}};
        assert(value == expected);
    }
    {
        auto value = generate_random_sequence(1, 1);
        vec<vec<int>> expected = {{0}};
        assert(value == expected);
    }
    {
        auto value = generate_random_sequence(3, 7, 3);
        vec<vec<int>> expected = {
            {3, 3, 3}, {3, 3, 4}, {3, 3, 5}, {3, 3, 6}, {3, 4, 3}, {3, 4, 4},
            {3, 4, 5}, {3, 4, 6}, {3, 5, 3}, {3, 5, 4}, {3, 5, 5}, {3, 5, 6},
            {3, 6, 3}, {3, 6, 4}, {3, 6, 5}, {3, 6, 6}, {4, 3, 3}, {4, 3, 4},
            {4, 3, 5}, {4, 3, 6}, {4, 4, 3}, {4, 4, 4}, {4, 4, 5}, {4, 4, 6},
            {4, 5, 3}, {4, 5, 4}, {4, 5, 5}, {4, 5, 6}, {4, 6, 3}, {4, 6, 4},
            {4, 6, 5}, {4, 6, 6}, {5, 3, 3}, {5, 3, 4}, {5, 3, 5}, {5, 3, 6},
            {5, 4, 3}, {5, 4, 4}, {5, 4, 5}, {5, 4, 6}, {5, 5, 3}, {5, 5, 4},
            {5, 5, 5}, {5, 5, 6}, {5, 6, 3}, {5, 6, 4}, {5, 6, 5}, {5, 6, 6},
            {6, 3, 3}, {6, 3, 4}, {6, 3, 5}, {6, 3, 6}, {6, 4, 3}, {6, 4, 4},
            {6, 4, 5}, {6, 4, 6}, {6, 5, 3}, {6, 5, 4}, {6, 5, 5}, {6, 5, 6},
            {6, 6, 3}, {6, 6, 4}, {6, 6, 5}, {6, 6, 6}};
        assert(value == expected);
    }
    aplusb();
}