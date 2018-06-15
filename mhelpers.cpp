//
// Created by Mikhail Mustakimov on 15.06.2018.
//

#include <cmath>
#include "mhelpers.h"

inline double pow2(double a) {
    return a * a;
}

double dist(point p1, point p2) {
    return sqrt(pow2(p1.x - p2.x) + pow2(p1.y - p2.y));
}