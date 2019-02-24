//
// Created by Igor Bulakh on 2019-02-24.
//

#ifndef YELLOW_BUS_MANAGER_H
#define YELLOW_BUS_MANAGER_H
#pragma once
#include "responses.h"

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;

private:
    map<string, vector<string>> buses_on_stop;
    map<string, vector<string>> stops_for_bus;
};

#endif //YELLOW_BUS_MANAGER_H
