#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

#ifndef YELLOW_DATE_H
#define YELLOW_DATE_H

class Date {
public:
    Date() = default;
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& s);

bool operator<(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& os, const Date& date);

#endif //YELLOW_DATE_H
