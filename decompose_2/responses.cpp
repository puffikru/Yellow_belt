//
// Created by Igor Bulakh on 2019-02-24.
//

#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    // Реализуйте эту функцию
    for (size_t i = 0; i < r.buses.size(); ++i) {
        if (i > 0) {
            os << " ";
        }
        os << r.buses[i];
    }
    os << endl;
    return os;
}


ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    // Реализуйте эту функцию
    int index = 0;
    for (const string& s : r.stops) {
        os << "Stop " << s << ":";
        if(r.buses.count(s) == 0) {
            os << " no interchange";
        } else {
            for (const auto& i : r.buses.at(s)) {
                os << " " << i;
            }
        }
        ++index;
        if (index < r.stops.size()) {
            os << endl;
        }
    }
    return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    // Реализуйте эту функцию
    int index = 0;
    for (const auto& b : r.buses_stops) {
        os << "Bus " << b.first <<  ":";
        for (const auto& s : b.second) {
            os << " " << s;
        }
        if (index < r.buses_stops.size() - 1) {
            os << endl;
        }
        ++index;
    }
    return os;
}