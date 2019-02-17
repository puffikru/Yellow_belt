#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <tuple>
#include <utility>

using namespace std;

template <typename Collection> Collection Sqr(Collection col);
template <typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& m);
template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& p);
template <typename T> vector<T> operator*(const vector<T>& v);

template <typename Collection>
Collection Sqr(Collection col) {
    Collection result;
    for (const auto& i : col) {
        i *= i;
    }
    return result;
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& m) {

};

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p) {

};


template <typename T>
vector<T> operator*(const vector<T>& v) {

}


int main() {

    return 0;
}
