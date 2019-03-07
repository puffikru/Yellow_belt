#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#ifndef YELLOW_DATE_H
#define YELLOW_DATE_H

class Date {
public:
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istringstream& s);

bool operator<(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& os, const Date& date);

#endif //YELLOW_DATE_H
