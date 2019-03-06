#pragma once

#include "date.h"

#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

#ifndef YELLOW_DATABASE_H
#define YELLOW_DATABASE_H

class Database {
public:
    Database() = default;

    Database(const Date& date, const string& event);

    void Add(const Date& date, const string& event);

    pair<Date, set<string>> Print(ostream& os);

//    pair<Date, set<string>> Find(ostream& os);

    int RemoveIf();

    pair<Date, set<string>> FindIf();

    string Last(const Date& data);

private:
    pair<Date, set<string>> storage = {{1,1,1}, {""}};
};

#endif //YELLOW_DATABASE_H
