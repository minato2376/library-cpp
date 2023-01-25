---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../math/floor_sqrt.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../math/floor_sqrt.hpp\"\
    ;\n#include \"../other/template.hpp\";\n\nvec<ll> A = {1,\n             2,\n \
    \            3,\n             4,\n             8999999999999999999,\n        \
    \     9000000000000000000,\n             8999999994000000000,\n             8999999994000000001,\n\
    \             8999999994000000002,\n             8999999988000000003,\n      \
    \       8999999988000000004,\n             8999999988000000005,\n            \
    \ 8999999982000000008,\n             8999999982000000009,\n             8999999982000000010,\n\
    \             8999999976000000015,\n             8999999976000000016,\n      \
    \       8999999976000000017,\n             8491099229177050083,\n            \
    \ 8491099229177050084,\n             8491099229177050085,\n             8681616713998055555,\n\
    \             8681616713998055556,\n             8681616713998055557,\n      \
    \       8870082394394406024,\n             8870082394394406025,\n            \
    \ 8870082394394406026,\n             8783796469688809023,\n             8783796469688809024,\n\
    \             8783796469688809025,\n             8423372501986777343,\n      \
    \       8423372501986777344,\n             8423372501986777345,\n            \
    \ 8734980711058006083,\n             8734980711058006084,\n             8734980711058006085,\n\
    \             8809989053821655183,\n             8809989053821655184,\n      \
    \       8809989053821655185,\n             8854489696895693763,\n            \
    \ 8854489696895693764,\n             8854489696895693765,\n             8781633772865386800,\n\
    \             8781633772865386801,\n             8781633772865386802,\n      \
    \       8849280339176904003,\n             8849280339176904004,\n            \
    \ 8849280339176904005};\nvec<ll> B = {\n    1,          1,          1,       \
    \   2,          2999999999, 3000000000,\n    2999999998, 2999999999, 2999999999,\
    \ 2999999997, 2999999998, 2999999998,\n    2999999996, 2999999997, 2999999997,\
    \ 2999999995, 2999999996, 2999999996,\n    2913949077, 2913949078, 2913949078,\
    \ 2946458333, 2946458334, 2946458334,\n    2978268354, 2978268355, 2978268355,\
    \ 2963747031, 2963747032, 2963747032,\n    2902304687, 2902304688, 2902304688,\
    \ 2955500077, 2955500078, 2955500078,\n    2968162571, 2968162572, 2968162572,\
    \ 2975649457, 2975649458, 2975649458,\n    2963382150, 2963382151, 2963382151,\
    \ 2974773997, 2974773998, 2974773998};\nint main() {\n    rep(i, SZ(A)) {\n  \
    \      assert(floor_sqrt(A[i]) == B[i]);\n    }\n    int A, B;\n    cin >> A >>\
    \ B;\n    cout << A + B << ln;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/math/floor_sqrt.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/floor_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sqrt.test.cpp
- /verify/test/math/floor_sqrt.test.cpp.html
title: test/math/floor_sqrt.test.cpp
---
