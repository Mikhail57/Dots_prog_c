#include <iostream>
#include <cmath>
#include <vector>
#include "structs.h"
#include "iohelpers.h"
#include "algo.h"

/**
 * Похоже, что надо использовать венгерский алгоритм.
 * Ссылка на объяснение: https://ru.wikipedia.org/wiki/Венгерский_алгоритм
 */


using namespace std;

ostream &operator<<(ostream &output, point p) {
    output << "Point(x=" << p.x << ", y=" << p.y << ", type=" << p.type << ");";
    return output;
}


int main() {
    point *w_arr = NULL;
    size_t w_size;

    cout.flush();
    readPointsFromFile("/tmp/lol/white.txt", &w_arr, &w_size);

    point *b_arr = NULL;
    size_t b_size;
    readPointsFromFile("/tmp/lol/black.txt", &b_arr, &b_size);

    if (w_size != b_size) {
        cerr << "Dimensions should be equals";
        return -1;
    }

    auto res = getShortestWay(w_arr, b_arr, b_size);

    for (auto p : res) {
        cout << p.first << '\t' << p.second << endl;
    }

    return 0;
}

