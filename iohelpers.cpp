//
// Created by Mikhail Mustakimov on 15.06.2018.
//

#include "iohelpers.h"
#include <fstream>
#include <iostream>

using namespace std;

void readPointsFromFile(const char *filename, point **arr, size_t *size) {
    ifstream in(filename);
    if (!in.is_open()) {
        cerr << "Error reading points from file '" << filename << "'!" << endl;
        in.close();
        return;
    }
    if (*arr != NULL)
        delete[] *arr;
    in >> *size;

    *arr = new point[*size];

    point t;
    for (size_t i = 0; i < *size; i++) {
        in >> t.x >> t.y >> t.type;
        (*arr)[i].x = t.x;
        (*arr)[i].y = t.y;
        (*arr)[i].type = t.type;
    }

    in.close();
}
