#include <iostream>
#include <string>

using namespace std;

#include "synonyms.h"
#include "test.h"

int main() {
    TestAll();

    int q;
    cin >> q;

    Synonyms synonyms;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "ADD") {
            string first_word, second_word;
            cin >> first_word >> second_word;
            AddSynonyms(synonyms, first_word, second_word);
        } else if (operation_code == "COUNT") {
            string word;
            cin >> word;
            cout << GetSynonymsCount(synonyms, word) << endl;
        } else if (operation_code == "CHECK") {
            string first_word, second_word;
            cin >> first_word >> second_word;
            if (AreSynonyms(synonyms, first_word, second_word)) {
                cout << "Yes" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}