#include "phone_number.h"
#include <iostream>

using namespace std;

PhoneNumber::PhoneNumber(const string& international_number) {
    int dash_count = 0;
    string country;
    string city;
    string num;
    for (auto i = 0; i < international_number.size(); ++i) {
        if (international_number[0] != '+') {
            throw invalid_argument("некорректный номер - не начинается на '+'");
        } else if (international_number[i] == '+') {
            continue;
        } else if (international_number[i] != '-' && dash_count == 0) {
            country += international_number[i];
            country_code_ = country;
        } else if (international_number[i] != '-' && dash_count == 1) {
            city += international_number[i];
            city_code_ = city;
        }else if (dash_count == 2) {
            num += international_number[i];
            local_number_ = num;
        } else if (international_number[i] == '-' && dash_count < 2) {
            ++dash_count;
            continue;
        } else {
            throw invalid_argument("некорректный номер");
        }
    }

    if (country.length() == 0 || city.length() == 0 || num.length() == 0) {
        throw invalid_argument("некорректный номер");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + GetCountryCode() + "-" + GetCityCode()  + "-" + GetLocalNumber();
}
