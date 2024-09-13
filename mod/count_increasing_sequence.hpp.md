---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/ModComb.hpp
    title: mod/ModComb.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/count_increasing_sequence.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"mod/ModComb.hpp\"\n\n#line\
    \ 5 \"mod/ModComb.hpp\"\n\ntemplate <class mint> struct ModComb {\n    static\
    \ int n;\n    static std::vector<mint> fac_, facinv_;\n\n    static void init(int\
    \ n_ = 1000000) {\n        n = n_;\n        fac_.resize(n + 1);\n        facinv_.resize(n\
    \ + 1);\n        fac_[0] = 1;\n        for (int i = 1; i <= n; i++) fac_[i] =\
    \ fac_[i - 1] * i;\n        facinv_[n] = mint(1) / fac_[n];\n        for (int\
    \ i = n; i >= 1; i--) facinv_[i - 1] = facinv_[i] * i;\n    }\n\n    static void\
    \ resize(int m) {\n        if (m <= n) return;\n        if (n == -1) {\n     \
    \       init(m);\n            return;\n        }\n        m = std::max(m, 2 *\
    \ n);\n        fac_.resize(m + 1);\n        facinv_.resize(m + 1);\n        for\
    \ (int i = n + 1; i <= m; i++) {\n            fac_[i] = fac_[i - 1] * i;\n   \
    \     }\n        facinv_[m] = mint(1) / fac_[m];\n        for (int i = m - 1;\
    \ i >= n; i--) {\n            facinv_[i] = facinv_[i + 1] * (i + 1);\n       \
    \ }\n        n = m;\n    }\n\n    static mint fac(int k) {\n        resize(k);\n\
    \        return fac_[k];\n    }\n    static mint facinv(int k) {\n        resize(k);\n\
    \        return facinv_[k];\n    }\n    static mint inv(int k) {\n        resize(k);\n\
    \        return facinv_[k] * fac_[k - 1];\n    }\n\n    static mint P(int n, int\
    \ k) {\n        if (k < 0 or k > n) return mint(0);\n        resize(n);\n    \
    \    return fac_[n] * facinv_[n - k];\n    }\n    static mint C(int n, int k)\
    \ {\n        if (k < 0 or k > n) return mint(0);\n        resize(n);\n       \
    \ return fac_[n] * facinv_[n - k] * facinv_[k];\n    }\n\n    /**\n     * @note\
    \ H(n, k) = (n \u500B \u306E\u30DC\u30FC\u30EB\u3092 k \u500B\u306E\u7BB1\u306B\
    \u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570)\n     * @note H(n, k) = C(n + k -\
    \ 1, n)\n     * @note H(n, k) = [x ^ n] (1 / (1 - x) ^ k)\n     */\n    static\
    \ mint H(int n, int k) {\n        if (n == 0 and k == 0) return mint(1);\n   \
    \     return C(n + k - 1, n);\n    }\n    static mint catalan(int n) {\n     \
    \   if (n == 0) return mint(1);\n        return C(2 * n, n) - C(2 * n, n - 1);\n\
    \    }\n};\n\ntemplate <class mint> int ModComb<mint>::n = -1;\ntemplate <class\
    \ mint> std::vector<mint> ModComb<mint>::fac_;\ntemplate <class mint> std::vector<mint>\
    \ ModComb<mint>::facinv_;\n#line 8 \"mod/count_increasing_sequence.hpp\"\n\ntemplate\
    \ <class mint, class FPS>\nFPS left_to_up(int Amax, int width, const FPS& left)\
    \ {\n    if (Amax == 0) return {left.freq(0)};\n    FPS X(Amax);\n    for (int\
    \ i = 0; i < Amax; i++) {\n        X[i] = left.freq(i) * ModComb<mint>::facinv(Amax\
    \ - 1 - i);\n    }\n    FPS Y(Amax + width - 1);\n    for (int i = 0; i < Amax\
    \ + width - 1; i++) {\n        Y[i] = ModComb<mint>::fac(i);\n    }\n    auto\
    \ Z = X * Y;\n\n    FPS ret(width);\n    for (int i = 0; i < width; i++) {\n \
    \       ret[i] = Z.freq(i + Amax - 1) * ModComb<mint>::facinv(i);\n    }\n\n \
    \   ret[0] += left.freq(Amax);\n    return ret;\n}\n\ntemplate <class mint, class\
    \ FPS>\nFPS left_to_right(int Amax, int width, const FPS& left) {\n    FPS X(Amax);\n\
    \    for (int i = 0; i < Amax; i++) X[i] = left.freq(i);\n    FPS Y(Amax);\n \
    \   for (int i = 0; i < Amax; i++)\n        Y[i] = ModComb<mint>::C(i + width\
    \ - 1, width - 1);\n    auto Z = X * Y;\n    if (int(Z.size()) > Amax) Z.resize(Amax);\n\
    \    return Z;\n}\n\ntemplate <class mint, class FPS>\nFPS down_to_up(int Amax,\
    \ int width, const FPS& down) {\n    if (Amax == 0) return down;\n    FPS Y(width);\n\
    \    for (int i = 0; i < width; i++) {\n        Y[i] = ModComb<mint>::C(i + Amax\
    \ - 1, Amax - 1);\n    }\n    auto Z = down * Y;\n    if (int(Z.size()) > width)\
    \ Z.resize(width);\n    return Z;\n}\n\ntemplate <class mint, class FPS>\nFPS\
    \ down_to_right(int Amax, int width, const FPS& down) {\n    FPS X(width);\n \
    \   for (int i = 0; i < width; i++) {\n        X[i] = down.freq(i) * ModComb<mint>::facinv(width\
    \ - 1 - i);\n    }\n    FPS Y(Amax + width - 1);\n    for (int i = 0; i < Amax\
    \ + width - 1; i++) {\n        Y[i] = ModComb<mint>::fac(i);\n    }\n    auto\
    \ Z = X * Y;\n\n    FPS ret(Amax);\n    for (int i = 0; i < Amax; i++) {\n   \
    \     ret[i] = Z.freq(i + width - 1) * ModComb<mint>::facinv(i);\n    }\n    return\
    \ ret;\n}\n\ntemplate <class mint, class FPS>\nFPS rec_count_increasing_sequence(const\
    \ std::vector<int>& A, const FPS& down) {\n    int n = A.size();\n    if (n ==\
    \ 1) {\n        FPS ret(A.front() + 1, down.freq(0));\n        return ret;\n \
    \   }\n    int m = n / 2;\n    FPS left_down(m);\n    for (int i = 0; i < m; i++)\
    \ left_down[i] = down.freq(i);\n    FPS right_down(n - m);\n    for (int i = 0;\
    \ i < n - m; i++) right_down[i] = down.freq(m + i);\n\n    FPS left = rec_count_increasing_sequence<mint,\
    \ FPS>(\n        std::vector<int>(A.begin(), A.begin() + m), left_down);\n\n \
    \   auto up1 = left_to_up<mint, FPS>(A[m - 1], n - m, left);\n    auto right1\
    \ = left_to_right<mint, FPS>(A[m - 1], n - m, left);\n    auto up2 = down_to_up<mint,\
    \ FPS>(A[m - 1], n - m, right_down);\n    auto right2 = down_to_right<mint, FPS>(A[m\
    \ - 1], n - m, right_down);\n\n    for (int i = 0; i < n - m; i++) right_down[i]\
    \ = up1.freq(i) + up2.freq(i);\n\n    std::vector<int> right_A(n - m);\n    for\
    \ (int i = 0; i < n - m; i++) right_A[i] = A[m + i] - A[m - 1];\n\n    auto right_result\
    \ =\n        rec_count_increasing_sequence<mint, FPS>(right_A, right_down);\n\n\
    \    FPS ret(A.back() + 1);\n    for (int i = 0; i < A[m - 1]; i++) {\n      \
    \  ret[i] = right1.freq(i) + right2.freq(i);\n    }\n    for (int i = A[m - 1];\
    \ i <= A.back(); i++) {\n        ret[i] = right_result.freq(i - A[m - 1]);\n \
    \   }\n\n    return ret;\n}\n\n/**\n * \u914D\u5217\u306E\u30B5\u30A4\u30BA\u3092\
    \ N , Amax = M \u3068\u3057\u3066\u3001\n * O((N + M) * log(N + M) ^ 2)\n */\n\
    template <class mint, class FPS>\nFPS count_increasing_sequence(const std::vector<int>&\
    \ A) {\n    assert(!A.empty());\n    assert(is_sorted(A.begin(), A.end()));\n\
    \    FPS down(1, mint(1));\n    return rec_count_increasing_sequence<mint, FPS>(A,\
    \ down);\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"mod/ModComb.hpp\"\n\ntemplate <class mint, class FPS>\nFPS left_to_up(int\
    \ Amax, int width, const FPS& left) {\n    if (Amax == 0) return {left.freq(0)};\n\
    \    FPS X(Amax);\n    for (int i = 0; i < Amax; i++) {\n        X[i] = left.freq(i)\
    \ * ModComb<mint>::facinv(Amax - 1 - i);\n    }\n    FPS Y(Amax + width - 1);\n\
    \    for (int i = 0; i < Amax + width - 1; i++) {\n        Y[i] = ModComb<mint>::fac(i);\n\
    \    }\n    auto Z = X * Y;\n\n    FPS ret(width);\n    for (int i = 0; i < width;\
    \ i++) {\n        ret[i] = Z.freq(i + Amax - 1) * ModComb<mint>::facinv(i);\n\
    \    }\n\n    ret[0] += left.freq(Amax);\n    return ret;\n}\n\ntemplate <class\
    \ mint, class FPS>\nFPS left_to_right(int Amax, int width, const FPS& left) {\n\
    \    FPS X(Amax);\n    for (int i = 0; i < Amax; i++) X[i] = left.freq(i);\n \
    \   FPS Y(Amax);\n    for (int i = 0; i < Amax; i++)\n        Y[i] = ModComb<mint>::C(i\
    \ + width - 1, width - 1);\n    auto Z = X * Y;\n    if (int(Z.size()) > Amax)\
    \ Z.resize(Amax);\n    return Z;\n}\n\ntemplate <class mint, class FPS>\nFPS down_to_up(int\
    \ Amax, int width, const FPS& down) {\n    if (Amax == 0) return down;\n    FPS\
    \ Y(width);\n    for (int i = 0; i < width; i++) {\n        Y[i] = ModComb<mint>::C(i\
    \ + Amax - 1, Amax - 1);\n    }\n    auto Z = down * Y;\n    if (int(Z.size())\
    \ > width) Z.resize(width);\n    return Z;\n}\n\ntemplate <class mint, class FPS>\n\
    FPS down_to_right(int Amax, int width, const FPS& down) {\n    FPS X(width);\n\
    \    for (int i = 0; i < width; i++) {\n        X[i] = down.freq(i) * ModComb<mint>::facinv(width\
    \ - 1 - i);\n    }\n    FPS Y(Amax + width - 1);\n    for (int i = 0; i < Amax\
    \ + width - 1; i++) {\n        Y[i] = ModComb<mint>::fac(i);\n    }\n    auto\
    \ Z = X * Y;\n\n    FPS ret(Amax);\n    for (int i = 0; i < Amax; i++) {\n   \
    \     ret[i] = Z.freq(i + width - 1) * ModComb<mint>::facinv(i);\n    }\n    return\
    \ ret;\n}\n\ntemplate <class mint, class FPS>\nFPS rec_count_increasing_sequence(const\
    \ std::vector<int>& A, const FPS& down) {\n    int n = A.size();\n    if (n ==\
    \ 1) {\n        FPS ret(A.front() + 1, down.freq(0));\n        return ret;\n \
    \   }\n    int m = n / 2;\n    FPS left_down(m);\n    for (int i = 0; i < m; i++)\
    \ left_down[i] = down.freq(i);\n    FPS right_down(n - m);\n    for (int i = 0;\
    \ i < n - m; i++) right_down[i] = down.freq(m + i);\n\n    FPS left = rec_count_increasing_sequence<mint,\
    \ FPS>(\n        std::vector<int>(A.begin(), A.begin() + m), left_down);\n\n \
    \   auto up1 = left_to_up<mint, FPS>(A[m - 1], n - m, left);\n    auto right1\
    \ = left_to_right<mint, FPS>(A[m - 1], n - m, left);\n    auto up2 = down_to_up<mint,\
    \ FPS>(A[m - 1], n - m, right_down);\n    auto right2 = down_to_right<mint, FPS>(A[m\
    \ - 1], n - m, right_down);\n\n    for (int i = 0; i < n - m; i++) right_down[i]\
    \ = up1.freq(i) + up2.freq(i);\n\n    std::vector<int> right_A(n - m);\n    for\
    \ (int i = 0; i < n - m; i++) right_A[i] = A[m + i] - A[m - 1];\n\n    auto right_result\
    \ =\n        rec_count_increasing_sequence<mint, FPS>(right_A, right_down);\n\n\
    \    FPS ret(A.back() + 1);\n    for (int i = 0; i < A[m - 1]; i++) {\n      \
    \  ret[i] = right1.freq(i) + right2.freq(i);\n    }\n    for (int i = A[m - 1];\
    \ i <= A.back(); i++) {\n        ret[i] = right_result.freq(i - A[m - 1]);\n \
    \   }\n\n    return ret;\n}\n\n/**\n * \u914D\u5217\u306E\u30B5\u30A4\u30BA\u3092\
    \ N , Amax = M \u3068\u3057\u3066\u3001\n * O((N + M) * log(N + M) ^ 2)\n */\n\
    template <class mint, class FPS>\nFPS count_increasing_sequence(const std::vector<int>&\
    \ A) {\n    assert(!A.empty());\n    assert(is_sorted(A.begin(), A.end()));\n\
    \    FPS down(1, mint(1));\n    return rec_count_increasing_sequence<mint, FPS>(A,\
    \ down);\n}"
  dependsOn:
  - mod/ModComb.hpp
  isVerificationFile: false
  path: mod/count_increasing_sequence.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/count_increasing_sequence.hpp
layout: document
redirect_from:
- /library/mod/count_increasing_sequence.hpp
- /library/mod/count_increasing_sequence.hpp.html
title: mod/count_increasing_sequence.hpp
---
