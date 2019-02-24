#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
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
    template <class TestFunc>
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



bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный

    string temp = str;

    size_t sting_size = 0;
    if (temp.size() % 2 == 1) {
        sting_size = temp.size() / 2 + 1;
    } else {
        sting_size = temp.size() / 2;
    }

    if (temp.size() == 1) { return true; }
    for(size_t i = 0; i < sting_size; ++i){
        if(temp[i] != temp[temp.size() - i - 1]){
            return false;
        }
    }
    return true;
}


void TestIsPalindrom() {
    AssertEqual(IsPalindrom("a"), true, "a");
    AssertEqual(IsPalindrom("ss"), true, "ss");
    AssertEqual(IsPalindrom("ss!"), false, "ss!");
    AssertEqual(IsPalindrom("ss "), false, "ss ");
    AssertEqual(IsPalindrom(" ss"), false, " ss");
    AssertEqual(IsPalindrom(" ss "), true, " ss ");
    AssertEqual(IsPalindrom("Ss"), false, "Ss");
    AssertEqual(IsPalindrom("или"), false, "или");
    AssertEqual(IsPalindrom(" "), true, " ");
    AssertEqual(IsPalindrom(""), true, "");
    Assert(IsPalindrom("aaa"), "aaa");
    Assert(!IsPalindrom("aaa "), "aaa");
    Assert(IsPalindrom(" aaa "), "aaa");
    Assert(!IsPalindrom(" aaa"), "aaa");
    Assert(!IsPalindrom("Aaa"), "Aaa");
    Assert(!IsPalindrom("Aaab"), "Aaab");
    Assert(IsPalindrom("Aaab baaA"), "Aaab baaA");
    Assert(!IsPalindrom("aaab baaa!"), "aaab baaa!");
    Assert(IsPalindrom("aaab  baaa"), "aaab  baaa");
    Assert(!IsPalindrom("aaab baaa sdf."), "aaab baaa sdf.");
    Assert(IsPalindrom("aaaa bbbb aaaa"), "aaaa bbbb aaaa");
    Assert(!IsPalindrom("aaaa bbbb  aaaa"), "aaaa bbbb  aaaa");
    Assert(!IsPalindrom("aaaa bbbb-aaaa"), "aaaa bbbb-aaaa");
    Assert(IsPalindrom("aaaa-bbbb-aaaa"), "aaaa-bbbb-aaaa");
    Assert(!IsPalindrom("aaaa - bbbb- aaaa"), "aaaa-bbbb-aaaa");
    Assert(IsPalindrom("vrbrv"), "vrbrv");
    Assert(IsPalindrom("vr b rv"), "vrbrv");
    Assert(IsPalindrom("v r b r v"), "vrbrv");
    Assert(IsPalindrom(" v r b r v "), "vrbrv");
    Assert(!IsPalindrom(" v r b r v v"), "vrbrv");
    Assert(IsPalindrom(" v r b b r v "), "vrbrv");
    Assert(IsPalindrom("-"), "-");
    Assert(!IsPalindrom("- "), "-");
    Assert(IsPalindrom("--"), "-");
    Assert(!IsPalindrom("Top spot"), "Top spot");
    Assert(IsPalindrom("topspot"), "topspot");
    Assert(!IsPalindrom("Red rum, sir, is murder"), "Red rum, sir, is murder");
}



int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(TestIsPalindrom, "TestIsPalindrom");

    return 0;
}

