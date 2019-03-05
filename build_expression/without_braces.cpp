#include <iostream>
#include <string>
#include <vector>
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
    vector<string> operations;
    for (auto i = 0; i < N; ++i) {
        cin >> operation >> num;
        operations.push_back(operation);
        if (operation == "*" || operation == "/") {
            if (operations[i - 1] == "+" || operations[i - 1] == "-") {
                op.emplace_front("(");
                op.emplace_back(")");
            }
        }
        op.emplace_back(" " + operation + " " + to_string(num));
    }
    for (const auto& i : op) {
        cout << i;
    }
    return 0;
}