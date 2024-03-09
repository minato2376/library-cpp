---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/SquareMatrix.hpp\"\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate\
    \ <class T, int N> struct SquareMatrix {\n    using Mat = std::array<std::array<T,\
    \ N>, N>;\n\n    int n;\n    Mat A;\n\n    SquareMatrix() : SquareMatrix(N) {\n\
    \    }\n    SquareMatrix(int n_) : n(n_), A({}) {\n        assert(0 <= n and n\
    \ <= N);\n    }\n    SquareMatrix(int n_, std::vector<std::vector<T>> v) : n(n_)\
    \ {\n        assert(n == (int)v.size());\n        for (int i = 0; i < n; i++)\
    \ {\n            assert(n == (int)v[i].size());\n            for (int j = 0; j\
    \ < n; j++) {\n                A[i][j] = v[i][j];\n            }\n        }\n\
    \    }\n\n    int size() const {\n        return n;\n    }\n\n    const std::array<T,\
    \ N>& operator[](int i) const {\n        assert(i < n);\n        return A[i];\n\
    \    }\n    std::array<T, N>& operator[](int i) {\n        assert(i < n);\n  \
    \      return A[i];\n    }\n\n    static SquareMatrix mul_identity(int n_) {\n\
    \        SquareMatrix I(n_);\n        for (int i = 0; i < n_; i++) I[i][i] = 1;\n\
    \        return I;\n    }\n\n    SquareMatrix& operator+=(const SquareMatrix&\
    \ B) {\n        assert(B.size() == n);\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < n; j++) {\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    SquareMatrix& operator-=(const\
    \ SquareMatrix& B) {\n        assert(B.size() == n);\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < n; j++) {\n                (*this)[i][j]\
    \ -= B[i][j];\n            }\n        }\n        return *this;\n    }\n    SquareMatrix\
    \ operator*(const SquareMatrix& B) const {\n        assert(B.size() == n);\n \
    \       SquareMatrix C(n);\n        for (int i = 0; i < n; i++) {\n          \
    \  for (int k = 0; k < n; k++) {\n                for (int j = 0; j < n; j++)\
    \ {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n               \
    \ }\n            }\n        }\n        return C;\n    }\n\n    SquareMatrix operator^(long\
    \ long k) const {\n        assert(k >= 0);\n        SquareMatrix ret = mul_identity(n);\n\
    \        SquareMatrix A = *this;\n        while (k) {\n            if (k & 1)\
    \ ret = ret * A;\n            A = A * A;\n            k >>= 1;\n        }\n  \
    \      return ret;\n    }\n\n    SquareMatrix operator+(const SquareMatrix& B)\
    \ const {\n        return SquareMatrix(*this) += B;\n    }\n    SquareMatrix operator-(const\
    \ SquareMatrix& B) const {\n        return SquareMatrix(*this) -= B;\n    }\n\
    \    SquareMatrix& operator*=(const SquareMatrix& B) {\n        return *this =\
    \ *this * B;\n    }\n    SquareMatrix& operator^=(long long k) {\n        return\
    \ *this = *this ^ k;\n    }\n    bool operator==(const SquareMatrix& B) const\
    \ {\n        return n == B.size() && A == B.A;\n    }\n    bool operator!=(const\
    \ SquareMatrix& B) const {\n        return n != B.size() || A != B.A;\n    }\n\
    \n    T determinant() const {\n        SquareMatrix B = *this;\n        T ret\
    \ = 1;\n        for (int i = 0; i < n; i++) {\n            int idx = -1;\n   \
    \         for (int j = i; j < n; j++) {\n                if (B[j][i] != 0) idx\
    \ = j;\n            }\n            if (idx == -1) return T(0);\n            if\
    \ (i != idx) {\n                ret *= -1;\n                std::swap(B[i], B[idx]);\n\
    \            }\n            ret *= B[i][i];\n            T inv = T(1) / B[i][i];\n\
    \            for (int j = 0; j < n; j++) {\n                B[i][j] *= inv;\n\
    \            }\n            for (int j = i + 1; j < n; j++) {\n              \
    \  T a = B[j][i];\n                if (a == 0) continue;\n                for\
    \ (int k = 0; k < n; k++) {\n                    B[j][k] -= B[i][k] * a;\n   \
    \             }\n            }\n        }\n        return ret;\n    }\n\n#ifdef\
    \ MINATO_LOCAL\n    friend std::ostream& operator<<(std::ostream& os, const SquareMatrix&\
    \ r) {\n        os << \"\\n\";\n        os << \"{\\n\";\n        for (int i =\
    \ 0; i < r.size(); i++) {\n            os << \"  {\";\n            for (int j\
    \ = 0; j < r.size(); j++) {\n                if (j) os << \", \";\n          \
    \      os << r[i][j];\n            }\n            os << \"},\\n\";\n        }\n\
    \        os << \"}\\n\";\n        return os;\n    }\n#endif\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n\ntemplate <class T, int N> struct SquareMatrix\
    \ {\n    using Mat = std::array<std::array<T, N>, N>;\n\n    int n;\n    Mat A;\n\
    \n    SquareMatrix() : SquareMatrix(N) {\n    }\n    SquareMatrix(int n_) : n(n_),\
    \ A({}) {\n        assert(0 <= n and n <= N);\n    }\n    SquareMatrix(int n_,\
    \ std::vector<std::vector<T>> v) : n(n_) {\n        assert(n == (int)v.size());\n\
    \        for (int i = 0; i < n; i++) {\n            assert(n == (int)v[i].size());\n\
    \            for (int j = 0; j < n; j++) {\n                A[i][j] = v[i][j];\n\
    \            }\n        }\n    }\n\n    int size() const {\n        return n;\n\
    \    }\n\n    const std::array<T, N>& operator[](int i) const {\n        assert(i\
    \ < n);\n        return A[i];\n    }\n    std::array<T, N>& operator[](int i)\
    \ {\n        assert(i < n);\n        return A[i];\n    }\n\n    static SquareMatrix\
    \ mul_identity(int n_) {\n        SquareMatrix I(n_);\n        for (int i = 0;\
    \ i < n_; i++) I[i][i] = 1;\n        return I;\n    }\n\n    SquareMatrix& operator+=(const\
    \ SquareMatrix& B) {\n        assert(B.size() == n);\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = 0; j < n; j++) {\n                (*this)[i][j]\
    \ += B[i][j];\n            }\n        }\n        return *this;\n    }\n\n    SquareMatrix&\
    \ operator-=(const SquareMatrix& B) {\n        assert(B.size() == n);\n      \
    \  for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n\
    \                (*this)[i][j] -= B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n    SquareMatrix operator*(const SquareMatrix& B) const\
    \ {\n        assert(B.size() == n);\n        SquareMatrix C(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int k = 0; k < n; k++) {\n          \
    \      for (int j = 0; j < n; j++) {\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n                }\n            }\n        }\n        return C;\n\
    \    }\n\n    SquareMatrix operator^(long long k) const {\n        assert(k >=\
    \ 0);\n        SquareMatrix ret = mul_identity(n);\n        SquareMatrix A = *this;\n\
    \        while (k) {\n            if (k & 1) ret = ret * A;\n            A = A\
    \ * A;\n            k >>= 1;\n        }\n        return ret;\n    }\n\n    SquareMatrix\
    \ operator+(const SquareMatrix& B) const {\n        return SquareMatrix(*this)\
    \ += B;\n    }\n    SquareMatrix operator-(const SquareMatrix& B) const {\n  \
    \      return SquareMatrix(*this) -= B;\n    }\n    SquareMatrix& operator*=(const\
    \ SquareMatrix& B) {\n        return *this = *this * B;\n    }\n    SquareMatrix&\
    \ operator^=(long long k) {\n        return *this = *this ^ k;\n    }\n    bool\
    \ operator==(const SquareMatrix& B) const {\n        return n == B.size() && A\
    \ == B.A;\n    }\n    bool operator!=(const SquareMatrix& B) const {\n       \
    \ return n != B.size() || A != B.A;\n    }\n\n    T determinant() const {\n  \
    \      SquareMatrix B = *this;\n        T ret = 1;\n        for (int i = 0; i\
    \ < n; i++) {\n            int idx = -1;\n            for (int j = i; j < n; j++)\
    \ {\n                if (B[j][i] != 0) idx = j;\n            }\n            if\
    \ (idx == -1) return T(0);\n            if (i != idx) {\n                ret *=\
    \ -1;\n                std::swap(B[i], B[idx]);\n            }\n            ret\
    \ *= B[i][i];\n            T inv = T(1) / B[i][i];\n            for (int j = 0;\
    \ j < n; j++) {\n                B[i][j] *= inv;\n            }\n            for\
    \ (int j = i + 1; j < n; j++) {\n                T a = B[j][i];\n            \
    \    if (a == 0) continue;\n                for (int k = 0; k < n; k++) {\n  \
    \                  B[j][k] -= B[i][k] * a;\n                }\n            }\n\
    \        }\n        return ret;\n    }\n\n#ifdef MINATO_LOCAL\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SquareMatrix& r) {\n        os << \"\\n\"\
    ;\n        os << \"{\\n\";\n        for (int i = 0; i < r.size(); i++) {\n   \
    \         os << \"  {\";\n            for (int j = 0; j < r.size(); j++) {\n \
    \               if (j) os << \", \";\n                os << r[i][j];\n       \
    \     }\n            os << \"},\\n\";\n        }\n        os << \"}\\n\";\n  \
    \      return os;\n    }\n#endif\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/SquareMatrix.hpp
layout: document
redirect_from:
- /library/math/SquareMatrix.hpp
- /library/math/SquareMatrix.hpp.html
title: math/SquareMatrix.hpp
---
