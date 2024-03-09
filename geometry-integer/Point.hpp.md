---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry-integer/ccw.hpp
    title: geometry-integer/ccw.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry-integer/Point.hpp\"\n\n#include <istream>\n#include\
    \ <ostream>\n\nusing ll = long long;\n\nstruct Point {\n    ll x, y;\n    Point(ll\
    \ x_ = 0, ll y_ = 0) : x(x_), y(y_) {\n    }\n\n    /**\n     * +1 +1 | +1 +1\n\
    \     * +1 +1 | +1 +1\n     * +1 +1 0  0  0\n     * -1 -1 | -1 -1\n     * -1 -1\
    \ | -1 -1\n     */\n    int pos() const {\n        if (y < 0) return -1;\n   \
    \     if (y == 0 and 0 <= x) return 0;\n        return 1;\n    }\n\n    ll norm()\
    \ const {\n        return x * x + y * y;\n    }\n\n    Point operator+(const Point&\
    \ r) const {\n        return {x + r.x, y + r.y};\n    }\n    Point operator-(const\
    \ Point& r) const {\n        return {x - r.x, y - r.y};\n    }\n    Point operator*(const\
    \ Point& r) const {\n        return {x * r.x - y * r.y, x * r.y + y * r.x};\n\
    \    }\n    Point operator*(ll r) const {\n        return {x * r, y * r};\n  \
    \  }\n    Point& operator+=(const Point& r) {\n        return *this = *this +\
    \ r;\n    }\n    Point& operator-=(const Point& r) {\n        return *this = *this\
    \ - r;\n    }\n    Point& operator*=(const Point& r) {\n        return *this =\
    \ *this * r;\n    }\n    Point& operator*=(ll r) {\n        return *this = *this\
    \ * r;\n    }\n    bool operator==(const Point& r) const {\n        return x ==\
    \ r.x && y == r.y;\n    }\n    bool operator!=(const Point& r) const {\n     \
    \   return x != r.x || y != r.y;\n    }\n    bool operator<(const Point& r) const\
    \ {\n        if (pos() != r.pos()) return pos() < r.pos();\n        return y *\
    \ r.x < x * r.y;\n    }\n    bool operator>(const Point& r) const {\n        return\
    \ r < *this;\n    }\n    bool operator<=(const Point& r) const {\n        return\
    \ !(r < *this);\n    }\n    bool operator>=(const Point& r) const {\n        return\
    \ !(*this < r);\n    }\n\n    friend std::istream& operator>>(std::istream& is,\
    \ Point& r) {\n        return is >> r.x >> r.y;\n    }\n\n#ifdef MINATO_LOCAL\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Point& r) {\n   \
    \     return os << \"(\" << r.x << \", \" << r.y << \")\";\n    }\n#endif\n};\n\
    \n//\u30D9\u30AF\u30C8\u30EB\nusing Vector = Point;\n\nll dot(const Vector& a,\
    \ const Vector& b) {\n    return a.x * b.x + a.y * b.y;\n}\nll cross(const Vector&\
    \ a, const Vector& b) {\n    return a.x * b.y - a.y * b.x;\n}\nVector rot90(const\
    \ Vector& a) {\n    return {-a.y, a.x};\n}\n"
  code: "#pragma once\n\n#include <istream>\n#include <ostream>\n\nusing ll = long\
    \ long;\n\nstruct Point {\n    ll x, y;\n    Point(ll x_ = 0, ll y_ = 0) : x(x_),\
    \ y(y_) {\n    }\n\n    /**\n     * +1 +1 | +1 +1\n     * +1 +1 | +1 +1\n    \
    \ * +1 +1 0  0  0\n     * -1 -1 | -1 -1\n     * -1 -1 | -1 -1\n     */\n    int\
    \ pos() const {\n        if (y < 0) return -1;\n        if (y == 0 and 0 <= x)\
    \ return 0;\n        return 1;\n    }\n\n    ll norm() const {\n        return\
    \ x * x + y * y;\n    }\n\n    Point operator+(const Point& r) const {\n     \
    \   return {x + r.x, y + r.y};\n    }\n    Point operator-(const Point& r) const\
    \ {\n        return {x - r.x, y - r.y};\n    }\n    Point operator*(const Point&\
    \ r) const {\n        return {x * r.x - y * r.y, x * r.y + y * r.x};\n    }\n\
    \    Point operator*(ll r) const {\n        return {x * r, y * r};\n    }\n  \
    \  Point& operator+=(const Point& r) {\n        return *this = *this + r;\n  \
    \  }\n    Point& operator-=(const Point& r) {\n        return *this = *this -\
    \ r;\n    }\n    Point& operator*=(const Point& r) {\n        return *this = *this\
    \ * r;\n    }\n    Point& operator*=(ll r) {\n        return *this = *this * r;\n\
    \    }\n    bool operator==(const Point& r) const {\n        return x == r.x &&\
    \ y == r.y;\n    }\n    bool operator!=(const Point& r) const {\n        return\
    \ x != r.x || y != r.y;\n    }\n    bool operator<(const Point& r) const {\n \
    \       if (pos() != r.pos()) return pos() < r.pos();\n        return y * r.x\
    \ < x * r.y;\n    }\n    bool operator>(const Point& r) const {\n        return\
    \ r < *this;\n    }\n    bool operator<=(const Point& r) const {\n        return\
    \ !(r < *this);\n    }\n    bool operator>=(const Point& r) const {\n        return\
    \ !(*this < r);\n    }\n\n    friend std::istream& operator>>(std::istream& is,\
    \ Point& r) {\n        return is >> r.x >> r.y;\n    }\n\n#ifdef MINATO_LOCAL\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Point& r) {\n   \
    \     return os << \"(\" << r.x << \", \" << r.y << \")\";\n    }\n#endif\n};\n\
    \n//\u30D9\u30AF\u30C8\u30EB\nusing Vector = Point;\n\nll dot(const Vector& a,\
    \ const Vector& b) {\n    return a.x * b.x + a.y * b.y;\n}\nll cross(const Vector&\
    \ a, const Vector& b) {\n    return a.x * b.y - a.y * b.x;\n}\nVector rot90(const\
    \ Vector& a) {\n    return {-a.y, a.x};\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry-integer/Point.hpp
  requiredBy:
  - geometry-integer/ccw.hpp
  timestamp: '2024-03-09 12:07:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry-integer/Point.hpp
layout: document
redirect_from:
- /library/geometry-integer/Point.hpp
- /library/geometry-integer/Point.hpp.html
title: geometry-integer/Point.hpp
---
