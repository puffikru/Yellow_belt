#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <tuple>
#include <utility>

using namespace std;

template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2);
template <typename Key, typename Value> map<Key, Value> operator*(map<Key, Value> m1, map<Key, Value> m2);
template <typename T> vector<T> operator*(const vector<T>& v1, const vector<T>& v2);
template <typename _T> auto Sqr(const _T& x);

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
    return make_pair(p1.first * p2.first, p1.second * p2.second);
};


template <typename Key, typename Value>
map<Key, Value> operator*(map<Key, Value> m1, map<Key, Value> m2) {
    for (const auto& item : m1) {
        m2[item.first] = item.second * item.second;
    }
    return m2;
};

template <typename T>
vector<T> operator*(const vector<T>& v1, const vector<T>& v2) {
    vector<T> res(v1.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        res[i] = v1[i] * v2[i];
    }
    return res;
};

template <typename _T> auto Sqr(const _T& x) {
    return x * x;
}


int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
