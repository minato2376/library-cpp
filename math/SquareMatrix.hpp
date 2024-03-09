#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

template <class T, int N> struct SquareMatrix {
    using Mat = std::array<std::array<T, N>, N>;

    int n;
    Mat A;

    SquareMatrix() : SquareMatrix(N) {
    }
    SquareMatrix(int n_) : n(n_), A({}) {
        assert(0 <= n and n <= N);
    }
    SquareMatrix(int n_, std::vector<std::vector<T>> v) : n(n_) {
        assert(n == (int)v.size());
        for (int i = 0; i < n; i++) {
            assert(n == (int)v[i].size());
            for (int j = 0; j < n; j++) {
                A[i][j] = v[i][j];
            }
        }
    }

    int size() const {
        return n;
    }

    const std::array<T, N>& operator[](int i) const {
        assert(i < n);
        return A[i];
    }
    std::array<T, N>& operator[](int i) {
        assert(i < n);
        return A[i];
    }

    static SquareMatrix mul_identity(int n_) {
        SquareMatrix I(n_);
        for (int i = 0; i < n_; i++) I[i][i] = 1;
        return I;
    }

    SquareMatrix& operator+=(const SquareMatrix& B) {
        assert(B.size() == n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix& operator-=(const SquareMatrix& B) {
        assert(B.size() == n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }
    SquareMatrix operator*(const SquareMatrix& B) const {
        assert(B.size() == n);
        SquareMatrix C(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    SquareMatrix operator^(long long k) const {
        assert(k >= 0);
        SquareMatrix ret = mul_identity(n);
        SquareMatrix A = *this;
        while (k) {
            if (k & 1) ret = ret * A;
            A = A * A;
            k >>= 1;
        }
        return ret;
    }

    SquareMatrix operator+(const SquareMatrix& B) const {
        return SquareMatrix(*this) += B;
    }
    SquareMatrix operator-(const SquareMatrix& B) const {
        return SquareMatrix(*this) -= B;
    }
    SquareMatrix& operator*=(const SquareMatrix& B) {
        return *this = *this * B;
    }
    SquareMatrix& operator^=(long long k) {
        return *this = *this ^ k;
    }
    bool operator==(const SquareMatrix& B) const {
        return n == B.size() && A == B.A;
    }
    bool operator!=(const SquareMatrix& B) const {
        return n != B.size() || A != B.A;
    }

    T determinant() const {
        SquareMatrix B = *this;
        T ret = 1;
        for (int i = 0; i < n; i++) {
            int idx = -1;
            for (int j = i; j < n; j++) {
                if (B[j][i] != 0) idx = j;
            }
            if (idx == -1) return T(0);
            if (i != idx) {
                ret *= -1;
                std::swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T inv = T(1) / B[i][i];
            for (int j = 0; j < n; j++) {
                B[i][j] *= inv;
            }
            for (int j = i + 1; j < n; j++) {
                T a = B[j][i];
                if (a == 0) continue;
                for (int k = 0; k < n; k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return ret;
    }

#ifdef MINATO_LOCAL
    friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& r) {
        os << "\n";
        os << "{\n";
        for (int i = 0; i < r.size(); i++) {
            os << "  {";
            for (int j = 0; j < r.size(); j++) {
                if (j) os << ", ";
                os << r[i][j];
            }
            os << "},\n";
        }
        os << "}\n";
        return os;
    }
#endif
};