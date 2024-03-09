#pragma once

#include "Point.hpp"

enum Position {
    COUNTER_CLOCKWISE = +1,
    CLOCKWISE = -1,
    ONLINE_BACK = +2,
    ONLINE_FRONT = -2,
    ON_SEGMENT = 0
};

/**
 * COUNTER_CLOCKWISE: p0,p1から見てp2は左側(反時計回り)
 * CLOCKWISE: p0,p1から見てp2は右側(時計回り)
 * ONLINE_BACK: p2-p0-p1の順に一直線上
 * ONLINE_FRONT: p0-p1-p2の順に一直線上
 * ON_SEGMENT: p0-p2-p1の順に一直線上
 */
Position ccw(const Point& p0, const Point& p1, const Point& p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a, b) > 0) return COUNTER_CLOCKWISE;
    if (cross(a, b) < 0) return CLOCKWISE;
    if (dot(a, b) < 0) return ONLINE_BACK;
    if (b.norm() - a.norm() > 0) return ONLINE_FRONT;
    return ON_SEGMENT;
}