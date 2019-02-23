#ifndef YELLOW_ROOT_COUNT_H
#define YELLOW_ROOT_COUNT_H
#pragma once

#include <cmath>

int GetDistinctRealRootCount(double a, double b, double c) {
    double D;
    int result;

    if (a == 0) {
        if (b != 0) {
            result = 1;
        } else if (c == 0) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        if (b != 0 && c != 0) {
            D = b * b - 4 * a * c;
            if (D > 0) {
                result = 2;
            } else if (D == 0) {
                result = 1;
            } else if (D < 0) {
                result = 0;
            }
        } else if (b == 0 && c == 0) {
            result = 2;
        } else if (b == 0 && c != 0) {
            if ((-1 * c / a) > 0) {
                result = 2;
            } else if ((-1 * c / a) == 0) {
                result = 1;
            } else if ((-1 * c / a) < 0) {
                result = 0;
            }
        } else if (b != 0 && c == 0) {
            result = 2;
        }
    }
    return result;
}

#endif //YELLOW_ROOT_COUNT_H
