#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "other/template.hpp"
#include "math/floor_sqrt.hpp"

vec<ll> A = {1,
             2,
             3,
             4,
             8999999999999999999,
             9000000000000000000,
             8999999994000000000,
             8999999994000000001,
             8999999994000000002,
             8999999988000000003,
             8999999988000000004,
             8999999988000000005,
             8999999982000000008,
             8999999982000000009,
             8999999982000000010,
             8999999976000000015,
             8999999976000000016,
             8999999976000000017,
             8491099229177050083,
             8491099229177050084,
             8491099229177050085,
             8681616713998055555,
             8681616713998055556,
             8681616713998055557,
             8870082394394406024,
             8870082394394406025,
             8870082394394406026,
             8783796469688809023,
             8783796469688809024,
             8783796469688809025,
             8423372501986777343,
             8423372501986777344,
             8423372501986777345,
             8734980711058006083,
             8734980711058006084,
             8734980711058006085,
             8809989053821655183,
             8809989053821655184,
             8809989053821655185,
             8854489696895693763,
             8854489696895693764,
             8854489696895693765,
             8781633772865386800,
             8781633772865386801,
             8781633772865386802,
             8849280339176904003,
             8849280339176904004,
             8849280339176904005};
vec<ll> B = {
    1,          1,          1,          2,          2999999999, 3000000000,
    2999999998, 2999999999, 2999999999, 2999999997, 2999999998, 2999999998,
    2999999996, 2999999997, 2999999997, 2999999995, 2999999996, 2999999996,
    2913949077, 2913949078, 2913949078, 2946458333, 2946458334, 2946458334,
    2978268354, 2978268355, 2978268355, 2963747031, 2963747032, 2963747032,
    2902304687, 2902304688, 2902304688, 2955500077, 2955500078, 2955500078,
    2968162571, 2968162572, 2968162572, 2975649457, 2975649458, 2975649458,
    2963382150, 2963382151, 2963382151, 2974773997, 2974773998, 2974773998};
int main() {
    rep(i, SZ(A)) {
        assert(floor_sqrt(A[i]) == B[i]);
    }
    INT(X, Y);
    print(X + Y);
}