#include "database.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void Database::Add(const Date& date, const string& event) {
    Entry e = make_pair(date, event);
    if (storage[e.first].count(e) == 0) {
        storage[e.first].insert(e);
        events[e.first].push_back(e);
        dates.insert(e.first);
    }
}

void Database::Print(ostream& os) const {
    for (const auto& date : events) {
        for (const auto& e: date.second) {
            cout << date.first << " " << e.second << endl;
        }
    }
}


//TODO: Last
string Database::Last(const Date& data) {

}