#include "database.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

Database::Database(const Date& date, const string& event) {
    storage.first = date;
    storage.second.insert(event);
}

void Database::Add(const Date& date, const string& event) {
    storage.first = date;
    storage.second.insert(event);
}

pair<Date, set<string>> Database::Print(ostream& os) {

}

int Database::RemoveIf() {

}

pair<Date, set<string>> Database::FindIf() {

}

string Database::Last(const Date& data) {

}