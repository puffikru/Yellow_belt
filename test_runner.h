//
// Created by Igor Bulakh on 2019-02-22.
//



#ifndef YELLOW_TEST_RUNNER_H
#define YELLOW_TEST_RUNNER_H
#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
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

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
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


template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assert faild: " << t << " != " << u << "Hint: " << hint;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error& e) {
            ++fail_count;
            cerr << test_name << " fail:" << e.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " tests faild. Terminate";
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

#endif //YELLOW_TEST_RUNNER_H