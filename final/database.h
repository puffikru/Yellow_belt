#pragma once

#include "date.h"
#include "node.h"

#include <string>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

#ifndef YELLOW_DATABASE_H
#define YELLOW_DATABASE_H

typedef pair<Date, string> Entry;

class Database {
public:
    Database() = default;
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    template<typename Predicate>
    int RemoveIf(Predicate p) {
        int remove_cnt = 0;

        auto pred = [p](const Entry& e) {
            return !p(e.first, e.second);
        };

        for (const auto& date : dates) {

            vector<Entry>& v = events.at(date);
            set<Entry>& s = storage.at(date);

            auto to_del = stable_partition(begin(v), end(v), pred);

            remove_cnt += (end(v) - to_del);

            for (auto it = to_del; it != end(v); ++it) {
                s.erase(*it);
            }

            v.erase(to_del, end(v));
        }

        for (const auto& e : storage) {
            if (storage.at(e.first).empty()) {
                dates.erase(e.first);
            }
        }

        return remove_cnt;
    }

    template<typename Predicate>
    vector<Entry> FindIf(Predicate p) const {
        vector<Entry> result;
        for (const auto& date : dates) {
            vector<Entry> v = events.at(date);
            copy_if(begin(v), end(v), back_inserter(result), [p](const Entry& e) {
                return p(e.first, e.second);
            });
        }
        return result;
    }

    Entry Last(const Date& data) const;

private:
    set<Date> dates;
    map<Date, vector<Entry>> events;
    map<Date, set<Entry>> storage;
};

ostream& operator<<(ostream& os, const Entry& e);

#endif //YELLOW_DATABASE_H
