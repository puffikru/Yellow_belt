#include "root_count.h"
#include <iostream>

int GetDistinctRealRootCount(double a, double b, double c) {
    double D;
    int result;

    if (a == 0) {
        // Линейное уравнение

        if (b != 0) {
            result = 1;
        } else if (c == 0) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        if (b != 0 && c != 0) {
            // Полное квадратное уравнение
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
            // Неполное квадратное уравнение
            if ((-1 * c / a) > 0) {
                result = 2;
            } else if ((-1 * c / a) == 0) {
                result = 1;
            } else if ((-1 * c / a) < 0) {
                result = 0;
            }
        } else if (b != 0 && c == 0) {
            // Неполное квадратное уравнение
            result = 2;
        }
    }
    return result;
}