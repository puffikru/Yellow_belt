#include "date.h"

#include <iostream>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.GetYear() <<
       "-" << setw(2) << setfill('0') << date.GetMonth() <<
       "-" << setw(2) << setfill('0') << date.GetDay();
    return os;
}

Date::Date(const int& year, const int& month, const int& day)
    : year(year),
      month(month),
      day(day) {}

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
    Date date(year, month, day);
    return date;
}
