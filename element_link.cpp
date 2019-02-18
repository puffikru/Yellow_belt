#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <tuple>
#include <utility>
#include <exception>

using namespace std;

template <typename Llink, typename Rlink> Rlink& GetRefStrict(map<Llink, Rlink>& m, Llink key);

template <typename Llink, typename Rlink>
Rlink& GetRefStrict(map<Llink, Rlink>& m, Llink key) {
    if (m.count(key) <= 0) {
        throw runtime_error("No such element");
    } else {
        return m[key];
    }
}

int main() {
    map<int, string> m = {{1, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}
