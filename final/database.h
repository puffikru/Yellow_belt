#pragma once

#include "date.h"

#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

#ifndef YELLOW_DATABASE_H
#define YELLOW_DATABASE_H

typedef pair<Date, set<string>> Data;

class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    int RemoveIf();

    Data FindIf() const;

    string Last(const Date& data);

private:
    map<Date, vector<string>> events;
    map<Date, set<string>> storage;
};

#endif //YELLOW_DATABASE_H
