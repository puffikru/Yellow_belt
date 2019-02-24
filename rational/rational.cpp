#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};


class Rational {
public:
    // Вы можете вставлять сюда различные реализации,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный

    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
        // сократим дробь, разделив числитель и знаменатель на их НОД
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        // знаменатель должен быть положительным
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    int GreatestCommonDivisor(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GreatestCommonDivisor(b, a % b);
        }
    }
private:
    int numerator;
    int denominator;
};


bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator();
}

bool operator != (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() != rhs.Numerator() ||
        lhs.Denominator() != rhs.Denominator();
}


ostream& operator << (ostream& os, const Rational& r) {
    return os << r.Numerator() << '/' << r.Denominator();
}


Rational operator+(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() != rhs.Denominator()){
        int cn = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
        int cd = lhs.Denominator() * rhs.Denominator();
        return {cn, cd};
    }
    return {lhs.Numerator() + rhs.Numerator(), lhs.Denominator()};
}

Rational operator-(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() != rhs.Denominator()){
        int cn = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
        int cd = lhs.Denominator() * rhs.Denominator();
        return {cn, cd};
    }
    return {lhs.Numerator() - rhs.Numerator(), lhs.Denominator()};
}

Rational operator*(const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

/*int operator*(Rational& lhs, int& rhs){
    return lhs.GreatestCommonDivisor(lhs.Numerator() * rhs, lhs.Denominator());
}*/

Rational operator/(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() == 0|| rhs.Numerator() == 0){
        throw domain_error("Division by zero");
    }
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

istream& operator>>(istream& stream, Rational& rational){
    stringstream temp;
    int n = 0;
    int d = 0;
    string line;
    stream >> line;
    if(line.empty()){
        return stream;
    }
    temp << line;
    temp >> n;
    temp.ignore(1);
    temp >> d;
    rational = {n, d};
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() != rhs.Denominator()){
        return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
    }
    return lhs.Numerator() < rhs.Numerator();
}

bool operator>(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() != rhs.Denominator()){
        return lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator();
    }
    return lhs.Numerator() > rhs.Numerator();
}


void TestRational() {
    {
        Rational rational(0, 1);
        Rational expected(0, 1);
        AssertEqual(rational, expected, "0 / 1");
    }
    {
        Rational rational(0, -1);
        Rational expected(0, 1);
        AssertEqual(rational, expected, "0 / -1");
    }
    {
        Rational rational(-20, 10);
        Rational expected(-20, 10);
        AssertEqual(rational, expected, "-20 / 10");
    }
    {
        Rational rational(4, 23);
        Rational expected(4, 23);
        AssertEqual(rational, expected, "4 / 23");
    }
    {
        Rational rational(-7, -13);
        Rational expected(-7, -13);
        AssertEqual(rational, expected, "-7 / -13");
    }
    {
        Rational rational(2147483647, -2147483647);
        Rational expected(-1, 1);
        AssertEqual(rational, expected, "2147483647 / 2147483647");
    }
    {
        Rational rational(0, 2147483647);
        Rational expected(0, 2147483647);
        AssertEqual(rational, expected, "-214748364 / 214748364");
    }
    {
        Rational rational(0, -2147483648);
        Rational expected(0, 2147483647);
        AssertEqual(rational, expected, "0 / 2147483647");
    }
    {
        Rational rational(2147483647, -2147483647);
        Rational expected(-2147483647, 2147483647);
        AssertEqual(rational, expected, "214748364 / 214748364");
    }
    {
        Rational rational;
        Rational expected(0, 1);
        AssertEqual(rational, expected, "0 / 1");
    }
    {
        Rational rational(9, 15);
        Rational expected(3, 5);
        AssertEqual(rational, expected, "3 / 5");
    }
    {
        Rational rational(9, -15);
        Rational expected(3, -5);
        AssertEqual(rational, expected, "3 / -5");
    }
    {
        Rational rational(0, 1);
        Rational expected;
        AssertEqual(rational, expected, "0 / 1");
    }
    {
        Rational rational(6, 4);
        Rational expected(-6, -4);
        AssertEqual(rational, expected, "-6 / -4");
    }
    {
        Rational rational(3, 2);
        Rational expected(6, 4);
        AssertEqual(rational, expected, "6 / 4");
    }
    {
        Rational rational(6, -4);
        Rational expected(-3, 2);
        AssertEqual(rational, expected, "-3 / -2");
    }
    {
        Rational rational;
        Rational expected;
        AssertEqual(rational, expected, "0 / 1");
    }
}



int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(TestRational, "TestRational");

    return 0;
}