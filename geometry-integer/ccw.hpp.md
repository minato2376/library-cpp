---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry-integer/Point.hpp
    title: geometry-integer/Point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry-integer/ccw.hpp\"\n\n#line 2 \"geometry-integer/Point.hpp\"\
    \n\n#include <istream>\n#include <ostream>\n\nusing ll = long long;\n\nstruct\
    \ Point {\n    ll x, y;\n\n    Point() : x(0), y(0) {\n    }\n    Point(ll x_,\
    \ ll y_) : x(x_), y(y_) {\n    }\n\n    /**\n     * +1 +1 | +1 +1\n     * +1 +1\
    \ | +1 +1\n     * +1 +1 0  0  0\n     * -1 -1 | -1 -1\n     * -1 -1 | -1 -1\n\
    \     */\n    int pos() const {\n        if (y < 0) return -1;\n        if (y\
    \ == 0 and 0 <= x) return 0;\n        return 1;\n    }\n\n    ll norm() const\
    \ {\n        return x * x + y * y;\n    }\n\n    Point operator+(const Point&\
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
    \ {\n        if (pos() != r.pos()) return pos() < r.pos();\n        if (y * r.x\
    \ != x * r.y) return y * r.x < x * r.y;\n        return norm() < r.norm();\n \
    \   }\n    bool operator>(const Point& r) const {\n        return r < *this;\n\
    \    }\n    bool operator<=(const Point& r) const {\n        return !(r < *this);\n\
    \    }\n    bool operator>=(const Point& r) const {\n        return !(*this <\
    \ r);\n    }\n\n    friend std::istream& operator>>(std::istream& is, Point& r)\
    \ {\n        return is >> r.x >> r.y;\n    }\n\n#ifdef MINATO_LOCAL\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Point& r) {\n        return\
    \ os << \"(\" << r.x << \", \" << r.y << \")\";\n    }\n#endif\n};\n\n// \u30D9\
    \u30AF\u30C8\u30EB\nusing Vector = Point;\n\nll dot(const Vector& a, const Vector&\
    \ b) {\n    return a.x * b.x + a.y * b.y;\n}\nll cross(const Vector& a, const\
    \ Vector& b) {\n    return a.x * b.y - a.y * b.x;\n}\nVector rot90(const Vector&\
    \ a) {\n    return {-a.y, a.x};\n}\n#line 4 \"geometry-integer/ccw.hpp\"\n\nenum\
    \ Position {\n    COUNTER_CLOCKWISE = +1,\n    CLOCKWISE = -1,\n    ONLINE_BACK\
    \ = +2,\n    ONLINE_FRONT = -2,\n    ON_SEGMENT = 0\n};\n\n/**\n * COUNTER_CLOCKWISE:\
    \ p0,p1\u304B\u3089\u898B\u3066p2\u306F\u5DE6\u5074(\u53CD\u6642\u8A08\u56DE\u308A\
    )\n * CLOCKWISE: p0,p1\u304B\u3089\u898B\u3066p2\u306F\u53F3\u5074(\u6642\u8A08\
    \u56DE\u308A)\n * ONLINE_BACK: p2-p0-p1\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\
    \n * ONLINE_FRONT: p0-p1-p2\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\n * ON_SEGMENT:\
    \ p0-p2-p1\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\n */\nPosition ccw(const\
    \ Point& p0, const Point& p1, const Point& p2) {\n    Point a = p1 - p0;\n   \
    \ Point b = p2 - p0;\n    if (cross(a, b) > 0) return COUNTER_CLOCKWISE;\n   \
    \ if (cross(a, b) < 0) return CLOCKWISE;\n    if (dot(a, b) < 0) return ONLINE_BACK;\n\
    \    if (b.norm() - a.norm() > 0) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    }\n"
  code: "#pragma once\n\n#include \"Point.hpp\"\n\nenum Position {\n    COUNTER_CLOCKWISE\
    \ = +1,\n    CLOCKWISE = -1,\n    ONLINE_BACK = +2,\n    ONLINE_FRONT = -2,\n\
    \    ON_SEGMENT = 0\n};\n\n/**\n * COUNTER_CLOCKWISE: p0,p1\u304B\u3089\u898B\u3066\
    p2\u306F\u5DE6\u5074(\u53CD\u6642\u8A08\u56DE\u308A)\n * CLOCKWISE: p0,p1\u304B\
    \u3089\u898B\u3066p2\u306F\u53F3\u5074(\u6642\u8A08\u56DE\u308A)\n * ONLINE_BACK:\
    \ p2-p0-p1\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\n * ONLINE_FRONT: p0-p1-p2\u306E\
    \u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\n * ON_SEGMENT: p0-p2-p1\u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A\n */\nPosition ccw(const Point& p0, const Point& p1,\
    \ const Point& p2) {\n    Point a = p1 - p0;\n    Point b = p2 - p0;\n    if (cross(a,\
    \ b) > 0) return COUNTER_CLOCKWISE;\n    if (cross(a, b) < 0) return CLOCKWISE;\n\
    \    if (dot(a, b) < 0) return ONLINE_BACK;\n    if (b.norm() - a.norm() > 0)\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}"
  dependsOn:
  - geometry-integer/Point.hpp
  isVerificationFile: false
  path: geometry-integer/ccw.hpp
  requiredBy: []
  timestamp: '2024-09-14 03:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry-integer/ccw.hpp
layout: document
redirect_from:
- /library/geometry-integer/ccw.hpp
- /library/geometry-integer/ccw.hpp.html
title: geometry-integer/ccw.hpp
---
