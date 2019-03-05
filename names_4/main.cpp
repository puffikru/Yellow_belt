#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


string FindNameByYear(const map<int, string>& names, int year) {
    auto iter_after = names.upper_bound(year);
    string name;
    if (iter_after != names.begin()) {
        name = (--iter_after)->second;
    }
    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& name) {
        first_name[year] = name;
    }
    void ChangeLastName(int year, const string& name) {
        last_name[year] = name;
    }
    string GetFullName(int year) {
        const string first = FindNameByYear(first_name, year);
        const string last = FindNameByYear(last_name, year);
        if (first.empty() && last.empty()) {
            return "Incognito";
        } else if (first.empty()) {
            return last + " with unknown first name";
        } else if (last.empty()) {
            return first + " with unknown last name";
        } else {
            return first + " " + last;
        }
    }
private:
    map<int, string> first_name;
    map<int, string> last_name;
};

int main() {
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