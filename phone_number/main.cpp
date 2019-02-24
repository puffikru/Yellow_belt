#include <iostream>
#include <string>

using namespace std;

#include "phone_number.h"

int main() {
    string number = "+7-495-111-22-33";
    try {
        PhoneNumber ph(number);
        cout << ph.GetInternationalNumber() << endl;
        cout << ph.GetCityCode() << endl;
        cout << ph.GetCountryCode() << endl;
        cout << ph.GetLocalNumber() << endl;
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
