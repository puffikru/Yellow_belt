//
// Created by Igor Bulakh on 2019-02-24.
//

#ifndef YELLOW_RESPONSE_H
#define YELLOW_RESPONSE_H
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct BusesForStopResponse {
    // Наполните полями эту структуру
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    // Наполните полями эту структуру
    vector<string> stops;
    map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

#endif //YELLOW_RESPONSE_H
