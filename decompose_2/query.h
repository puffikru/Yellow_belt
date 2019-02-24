//
// Created by Igor Bulakh on 2019-02-24.
//

#ifndef YELLOW_QUERY_H
#define YELLOW_QUERY_H
#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q);

#endif //YELLOW_QUERY_H
