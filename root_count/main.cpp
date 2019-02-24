#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s) {
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
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
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
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m) {
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
void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        } catch (std::exception& e) {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        } catch (...) {
            ++fail_count;
            std::cerr << "Unknown exception caught" << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};


int GetDistinctRealRootCount(double a, double b, double c) {
    double D;
    int result;

    if (a == 0) {
        // Линейное уравнение

        if (b != 0) {
            result = 1;
        } else if (c == 0) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        if (b != 0 && c != 0) {
            // Полное квадратное уравнение
            D = b * b - 4 * a * c;
            if (D > 0) {
                result = 2;
            } else if (D == 0) {
                result = 1;
            } else if (D < 0) {
                result = 0;
            }
        } else if (b == 0 && c == 0) {

            result = 2;
        } else if (b == 0 && c != 0) {
            // Неполное квадратное уравнение
            if ((-1 * c / a) > 0) {
                result = 2;
            } else if ((-1 * c / a) == 0) {
                result = 1;
            } else if ((-1 * c / a) < 0) {
                result = 0;
            }
        } else if (b != 0 && c == 0) {
            // Неполное квадратное уравнение
            result = 2;
        }
    }
    return result;
}


void TestRealRootCount() {
    mt19937 gen;
    uniform_real_distribution<> unif(-10, 10);

    for (auto i = 0; i < 100; ++i) {
        const auto a = unif(gen);
        const auto b = unif(gen);
        const auto c = unif(gen);

        int count = GetDistinctRealRootCount(a, b, c);

        Assert(count >= 0 && count <= 2, "TestRootCount");
    }
}


void TestOneRootCount() {
    AssertEqual(GetDistinctRealRootCount(1, 4, 4), 1, "1 4 4 - 1 root");
    AssertEqual(GetDistinctRealRootCount(0, 10, 4), 1, "Test one root 10 4");
    AssertEqual(GetDistinctRealRootCount(0, -10, 4), 1, "Test one root -10 4");
    AssertEqual(GetDistinctRealRootCount(0, 10, -4), 1, "Test one root 10 -4");
}

void TestNoRoots() {
    AssertEqual(GetDistinctRealRootCount(1, 4, 10), 0, "1 4 10");
    AssertEqual(GetDistinctRealRootCount(0, 0, 7), 0, "0 0 7");
    AssertEqual(GetDistinctRealRootCount(1, 0, 3), 0, "1 0 3");
}


void TestConstant() {
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "0 0 1");
    AssertEqual(GetDistinctRealRootCount(0, 0, -10), 0, "0 0 -10");
    AssertEqual(GetDistinctRealRootCount(0, 0, 123410), 0, "0 0 123410");
}




int main() {
    TestRunner runner;
    runner.RunTest(TestRealRootCount, "TestRealRootCount");
    runner.RunTest(TestOneRootCount, "TestOneRootCount");
    runner.RunTest(TestNoRoots, "TestNoRoots");
    runner.RunTest(TestConstant, "TestConstant");

    return 0;
}