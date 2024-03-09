#pragma once

#include <istream>
#include <ostream>

using ll = long long;

struct Point {
    ll x, y;
    Point(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {
    }

    /**
     * +1 +1 | +1 +1
     * +1 +1 | +1 +1
     * +1 +1 0  0  0
     * -1 -1 | -1 -1
     * -1 -1 | -1 -1
     */
    int pos() const {
        if (y < 0) return -1;
        if (y == 0 and 0 <= x) return 0;
        return 1;
    }

    ll norm() const {
        return x * x + y * y;
    }

    Point operator+(const Point& r) const {
        return {x + r.x, y + r.y};
    }
    Point operator-(const Point& r) const {
        return {x - r.x, y - r.y};
    }
    Point operator*(const Point& r) const {
        return {x * r.x - y * r.y, x * r.y + y * r.x};
    }
    Point operator*(ll r) const {
        return {x * r, y * r};
    }
    Point& operator+=(const Point& r) {
        return *this = *this + r;
    }
    Point& operator-=(const Point& r) {
        return *this = *this - r;
    }
    Point& operator*=(const Point& r) {
        return *this = *this * r;
    }
    Point& operator*=(ll r) {
        return *this = *this * r;
    }
    bool operator==(const Point& r) const {
        return x == r.x && y == r.y;
    }
    bool operator!=(const Point& r) const {
        return x != r.x || y != r.y;
    }
    bool operator<(const Point& r) const {
        if (pos() != r.pos()) return pos() < r.pos();
        return y * r.x < x * r.y;
    }
    bool operator>(const Point& r) const {
        return r < *this;
    }
    bool operator<=(const Point& r) const {
        return !(r < *this);
    }
    bool operator>=(const Point& r) const {
        return !(*this < r);
    }

    friend std::istream& operator>>(std::istream& is, Point& r) {
        return is >> r.x >> r.y;
    }

#ifdef MINATO_LOCAL
    friend std::ostream& operator<<(std::ostream& os, const Point& r) {
        return os << "(" << r.x << ", " << r.y << ")";
    }
#endif
};

//ベクトル
using Vector = Point;

ll dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}
ll cross(const Vector& a, const Vector& b) {
    return a.x * b.y - a.y * b.x;
}
Vector rot90(const Vector& a) {
    return {-a.y, a.x};
}