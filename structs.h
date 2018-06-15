//
// Created by Mikhail Mustakimov on 15.06.2018.
//

#ifndef DOTS_STRUCTS_H
#define DOTS_STRUCTS_H

#include <cstdint>

struct point {
    double x;
    double y;
    short type;

    point() {}

    point(double x, double y) : x(x), y(y) {}

    point(double x, double y, short type) : x(x), y(y), type(type) {}
};

#endif //DOTS_STRUCTS_H
