#pragma once

#include "date.h"

#include <string>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

#ifndef YELLOW_DATABASE_H
#define YELLOW_DATABASE_H

typedef pair<Date, set<string>> Data;

class Database {
public:
    Database() = default;
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    //TODO: RemoveIf
    template <typename Predicate>
    int RemoveIf(Predicate p) {
        int remove_cnt = 0;

        /*auto pred = [p](const Date& date, const string& event) {
            return !p(date, event);
        };*/

        /*for (const auto& item : events) {
            auto to_delete = stable_partition(begin(item.second), end(item.second), p);

            remove_cnt += (end(item.second) - to_delete);

            cout << remove_cnt << endl;

            cout << *to_delete << endl;
        }*/

        return remove_cnt;
    }

    //TODO: FindIf
    template <typename Predicate>
    Data FindIf(Predicate p) const {

    }

    string Last(const Date& data);

private:
    map<Date, vector<string>> events;
    map<Date, set<string>> storage;
};

#endif //YELLOW_DATABASE_H
