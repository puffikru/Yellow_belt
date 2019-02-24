//
// Created by Igor Bulakh on 2019-02-24.
//

#include "query.h"

istream& operator >> (istream& is, Query& q) {
    string command;
    int stop_cnt = 0;
    string stop;
    is >> command;
    if (command == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus >> stop_cnt;
        q.stops.clear();
        for (int i = 0; i < stop_cnt; ++i) {
            is >> q.stop;
            q.stops.push_back(q.stop);
        }
    } else if (command == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (command == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (command == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}