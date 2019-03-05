#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    int x = 0;
    uint N = 0;
    cin >> x >> N;
    string operation;
    int num = 0;
    deque<string> op;
    op.push_back(to_string(x));
    for (auto i = 0; i < N; ++i) {
        cin >> operation >> num;
        op.emplace_front("(");
        op.emplace_back(") ");
        op.emplace_back(operation + " " + to_string(num));
    }
    for (const auto& i : op) {
        cout << i;
    }
    return 0;
}