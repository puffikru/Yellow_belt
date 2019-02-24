#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
//    cout << s << endl;
    auto it = begin(s);
    uint start = 0;
    uint ends = 0;
    vector<string> result;
    uint index = 0;
    while (it != end(s)) {
        if (*it == ' ') {
            ends = index - start;

            string word(s, start, ends);
            result.push_back(word);
            start = index + 1;
        } else if (index == s.size() - 1) {
            ends = index - start + 1;
            string word(s, start, ends);
            result.push_back(word);
        }

        ++it;
        ++index;
    }
    return result;
}

int main() {
    string s = "C Cpp Java Python C# Javascript Php";
//    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}