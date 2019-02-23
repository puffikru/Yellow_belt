#include <string>
#include <iostream>
#include <vector>
#include <map>

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

struct BusesForStopResponse {
    // Наполните полями эту структуру
    vector<string> buses;
};

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


struct StopsForBusResponse {
    // Наполните полями эту структуру
    vector<string> stops;
    map<string, vector<string>> buses;
};


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


struct AllBusesResponse {
    // Наполните полями эту структуру
    map<string, vector<string>> buses_stops;
};


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


class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        // Реализуйте этот метод
        for (auto& s : stops) {
            buses_on_stop[s].push_back(bus);
            stops_for_bus[bus].push_back(s);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
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

    StopsForBusResponse GetStopsForBus(const string& bus) const {
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

    AllBusesResponse GetAllBuses() const {
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

private:
    map<string, vector<string>> buses_on_stop;
    map<string, vector<string>> stops_for_bus;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }
    return 0;
}
