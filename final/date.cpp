#include "date.h"

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.GetYear() <<
       "-" << setw(2) << setfill('0') << date.GetMonth() <<
       "-" << setw(2) << setfill('0') << date.GetDay();
    return os;
}

Date::Date(int new_year, int new_month, int new_day)
    : year(new_year),
      month(new_month),
      day(new_day) {}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(istringstream& s) {
    int year;
    s >> year;
    if (s.peek() == '-') {
        s.ignore(1);
    }
    int month;
    s >> month;
    if (s.peek() == '-') {
        s.ignore(1);
    }
    int day;
    s >> day;
    return {year, month, day};
}
