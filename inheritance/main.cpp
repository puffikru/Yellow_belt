#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& s)
    : Name(s) {
    }

    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& t)
    : Animal(t) {
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {

    return 0;
}