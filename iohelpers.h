//
// Created by Mikhail Mustakimov on 15.06.2018.
//

#ifndef DOTS_IOHELPERS_H
#define DOTS_IOHELPERS_H

#include <cstddef>
#include "structs.h"

void readPointsFromFile(const char *filename, point **arr, size_t *size);

void writePointsToFile(const char *filename, const point *arr, size_t size);

#endif //DOTS_IOHELPERS_H
