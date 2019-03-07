#include "database.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void Database::Add(const Date& date, const string& event) {
    if (storage[date].count(event) == 0) {
        storage[date].insert(event);
        events[date].push_back(event);
    }
}

void Database::Print(ostream& os) const {
    for (const auto& date : events) {
        for (const auto& e: date.second) {
            cout << date.first << " " << e << endl;
        }
    }
}

int Database::RemoveIf() {

}

Data Database::FindIf() const {

}

string Database::Last(const Date& data) {

}