#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> langs = {"python", "C++", "C", "Java", "C#"};
    auto result = find_if(begin(langs), end(langs),
        [](const string& lang) {
            return lang[0] == 'C';
    });
    string& ref = *result;
    cout << ref << endl;
    return 0;
}