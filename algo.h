//
// Created by Mikhail Mustakimov on 15.06.2018.
//

#ifndef DOTS_ALGO_H
#define DOTS_ALGO_H

#include <cstddef>
#include "structs.h"
#include "mhelpers.h"

std::vector<std::pair<point, point>> getShortestWay(point *fp, point *sp, size_t size);

#endif //DOTS_ALGO_H
