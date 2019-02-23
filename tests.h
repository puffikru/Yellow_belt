//
// Created by Igor Bulakh on 2019-02-22.
//

#ifndef YELLOW_TESTS_H
#define YELLOW_TESTS_H
#pragma once
#include <random>

#include "test_runner.h"

void TestRootCount() {
    mt19937 gen;
    uniform_real_distribution<> unif(-10, 10);

    for (auto i = 0; i < 100; ++i) {
        const auto a = unif(gen);
        const auto b = unif(gen);
        const auto c = unif(gen);

        const auto count = GetDistinctRealRootCount(a, b, c);

        Assert(count >= 0 && count <= 2, "");
    }
}

void TestLinearEquation() {
    mt19937 gen;
    uniform_real_distribution<> unif(-10, 10);

    for (auto i = 0; i < 100; ++i) {
        const auto b = unif(gen);
        const auto c = unif(gen);

        AssertEqual(GetDistinctRealRootCount(0, b, c), 1, "");
        AssertEqual(GetDistinctRealRootCount(0, 0, c), 0, "");
    }
}

void TestRealRootsCount() {
    mt19937 gen;
    uniform_real_distribution<> unif(-10, 10);
    int count;
    double D;

    for (auto i = 0; i < 100; ++i) {
        const auto a = unif(gen);
        const auto c = unif(gen);
        count = GetDistinctRealRootCount(a, 0, c)

        Assert(count >= 0 && <= 2, "");
    }
}


void TestOtherRootsCount() {
    AssertEqual(GetDistinctRealRootCount(2, 0, 0), 2, "");
    AssertEqual(GetDistinctRealRootCount(10, 0, 0), 2, "");
    AssertEqual(GetDistinctRealRootCount(8, 5, 0), 2, "");
    AssertEqual(GetDistinctRealRootCount(1, 32, 0), 2, "");
    AssertEqual(GetDistinctRealRootCount(0, 3, -2), 1, "");
    AssertEqual(GetDistinctRealRootCount(0, 6, 0), 1, "");
    AssertEqual(GetDistinctRealRootCount(0, 0, 10), 0, "");
}


#endif //YELLOW_TESTS_H
