//
// Created by Mikhail Mustakimov on 15.06.2018.
//

#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <iostream>
#include "algo.h"

#define PRECISION 0.0000001

using namespace std;

void initArray(double *arr, size_t size, double val);

double **transpose(double **arr, size_t size) {
    auto res = new double *[size];
    for (size_t i = 0; i < size; i++) {
        res[i] = new double[size]{};
    }
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            res[i][j] = arr[j][i];
        }
    }
    return res;
}

vector<pair<int, int>> calc(double **matr, size_t size) {
    double **rmatr = new double *[size];
    for (size_t i = 0; i < size; i++) {
        rmatr[i] = new double[size]{};
    }
    double *minInRow = new double[size];
    for (size_t i = 0; i < size; i++) {
        double min = INT_MAX;
        for (int j = 0; j < size; j++) {
            if (min > matr[i][j])
                min = matr[i][j];
        }
        minInRow[i] = min;
    }

    int *zeros_in_row = new int[size]{};
    int *zeros_in_col = new int[size]{};

    cout << "Loool:" << endl;
    cout << "---------------" << endl;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            rmatr[i][j] = matr[i][j] - minInRow[i];
            cout << rmatr[i][j] << '\t';
            if (abs(rmatr[i][j]) < PRECISION) {
                rmatr[i][j] = 0;
                zeros_in_row[i]++;
                zeros_in_col[j]++;
            }
        }
        cout << endl;
    }
    cout << "---------------" << endl;
    for (int i = 0; i < size; i++) {
        if (zeros_in_col[i] != 1 || zeros_in_row[i] != 1) {
            return vector<pair<int, int>>();
        }
    }

    vector<pair<int, int>> res;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rmatr[i][j] < PRECISION) {
                res.emplace_back(i, j);
            }
        }
    }

    return res;
};

vector<pair<point, point>> getShortestWay(point *fp, point *sp, size_t size) {
    double **matr = new double *[size];
    for (size_t i = 0; i < size; i++) {
        matr[i] = new double[size]{};
    }
    cout << "Distances:" << endl;
    cout << "--------------" << endl;
    for (size_t i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matr[i][j] = dist(fp[i], sp[j]);
            cout << matr[i][j] << '\t';
        }
        cout << endl;
    }
    cout << "--------------" << endl;

    auto res = calc(matr, size);
    if (res.size() != 0) {
        auto r = vector<pair<point, point>>();
        for (auto e : res)
            r.emplace_back(fp[e.first], sp[e.second]);

        return r;
    }

    auto tm = transpose(matr, size);
    auto r2 = calc(tm, size);

    for (int i = 0; i < size; i++)
        delete[] tm[i];
    delete[] tm;

    auto r = vector<pair<point, point>>();
    for (auto e : r2)
        r.emplace_back(fp[e.second], sp[e.first]);

    // TODO: дописать третий вариант, когда несколько нулей в одной строке все равно осталось

    return r;
}

void initArray(double *arr, size_t size, double val) {
    for (int i = 0; i < size; i++)
        arr[i] = val;
}