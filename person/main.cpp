#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "test_runner.h"

//class Person {
//public:
//    void ChangeFirstName(int year, const string &name) {
//        first_name[year] = name;
//    }
//    void ChangeLastName(int year, const string &name) {
//        last_name[year] = name;
//    }
//    string GetFullName(int year) {
//        string first, second;
//        first = CheckName(year, first_name);
//        second = CheckName(year, last_name);
//        if (first == "" && second == "") {
//            return "Incognito";
//        } else if (first == ""){
//            return second + " with unknown first name";
//        }else if(second == ""){
//            return first + " with unknown last name";
//        }
//        return first + " " + second;
//    }
//private:
//    map<int, string> first_name, last_name;
//    string CheckName(int year, map<int, string> name) {
//        int temp = 0;
//        for (const auto &n : name) {
//            if (n.first == year) {
//                return n.second;
//            } else if (n.first < year) {
//                if (n.first > temp) {
//                    temp = n.first;
//                }
//            }
//        }
//        return name[temp];
//    }
//};


void TestPersonName() {
    Person person;
    person.ChangeFirstName(1987, "Igor");
    person.ChangeLastName(1980, "Uhov");
    person.ChangeFirstName(1990, "Vasiliy");
    person.ChangeLastName(1998, "Ribin");
    person.ChangeLastName(1972, "Cherniy");
    person.ChangeFirstName(2001, "Nikolay");
    person.ChangeLastName(1993, "Ivanov");
    person.ChangeFirstName(2005, "Boris");
    person.ChangeFirstName(2017, "Jenya");

//    string full_name;
//    for (const auto& i : {1970, 1973, 1987, 1990, 1995, 2001, 2005, 2017}) {
//        full_name = person.GetFullName(i);
//    }

    AssertEqual(person.GetFullName(1987), "Igor Uhov", "1987 - Igor Uhov");
    AssertEqual(person.GetFullName(1993), "Vasiliy Ivanov", "1993 - Vasiliy Ivanov");
    AssertEqual(person.GetFullName(1998), "Vasiliy Ribin", "1998 - Vasiliy Ribin");
    AssertEqual(person.GetFullName(2003), "Nikolay Ribin", "2003 - Nikolay Ribin");
    AssertEqual(person.GetFullName(2006), "Boris Ribin", "2006 - Boris Ribin");
    AssertEqual(person.GetFullName(2018), "Jenya Ribin", "2018 - Jenya Ribin");

}


void TestNoFirstName() {
    Person person;
    person.ChangeLastName(1982, "Ivanov");
    person.ChangeLastName(2001, "Petrov");
    person.ChangeLastName(1995, "Sidorof");

    AssertEqual(person.GetFullName(1982), "Ivanov with unknown first name", "1982 - Ivanov");
    AssertEqual(person.GetFullName(2002), "Petrov with unknown first name", "2002 - Petrov");
    AssertEqual(person.GetFullName(1998), "Sidorof with unknown first name", "1998 - Sidorof");
}

void TestNoLastName() {
    Person person;
    person.ChangeFirstName(1950, "Igor");
    person.ChangeFirstName(1977, "Alexander");
    person.ChangeFirstName(1963, "Oleg");

    AssertEqual(person.GetFullName(1951), "Igor with unknown last name", "1951 - Igor");
    AssertEqual(person.GetFullName(1965), "Oleg with unknown last name", "1965 - Oleg");
    AssertEqual(person.GetFullName(1980), "Alexander with unknown last name", "1980 - Alexander");
}


void TestNoName() {
    Person person;
    AssertEqual(person.GetFullName(1998), "Incognito", "1998 - Incognito");
    AssertEqual(person.GetFullName(1970), "Incognito", "1970 - Incognito");
    AssertEqual(person.GetFullName(2004), "Incognito", "2004 - Incognito");
}


int main() {
    TestRunner runner;
    runner.RunTest(TestPersonName, "TestPersonName");
    runner.RunTest(TestNoFirstName, "TestNoFirstName");
    runner.RunTest(TestNoLastName, "TestNoLastName");
    runner.RunTest(TestNoName, "TestNoName");

    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
