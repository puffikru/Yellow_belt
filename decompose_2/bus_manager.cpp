//
// Created by Igor Bulakh on 2019-02-24.
//

#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    for (auto& s : stops) {
        buses_on_stop[s].push_back(bus);
        stops_for_bus[bus].push_back(s);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse stops;
    if (buses_on_stop.count(stop) == 0) {
        cout << "No stop";
    } else {
        for (const auto& bus : buses_on_stop.at(stop)) {
            stops.buses.push_back(bus);
        }
    }
    return stops;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse bus_stops;
    if (stops_for_bus.count(bus) == 0) {
        cout << "No bus" << endl;
    } else {
        for (const auto& stop : stops_for_bus.at(bus)) {
            bus_stops.stops.push_back(stop);
            for (const auto& b : buses_on_stop.at(stop)) {
                if (b != bus) {
                    bus_stops.buses[stop].push_back(b);
                }
            }
        }
    }
    return bus_stops;
}

AllBusesResponse BusManager::GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse all_buses;
    if (stops_for_bus.empty()) {
        cout << "No buses" << endl;
    } else {
        for (const auto& bus : stops_for_bus) {
            for (const auto& st : bus.second) {
                all_buses.buses_stops[bus.first].push_back(st);
            }
        }
    }
    return all_buses;
}