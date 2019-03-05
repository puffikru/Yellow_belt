#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iterator>

using namespace std;


struct Lang {
    string name;
    int age;
};


using LangIt = vector<string>::iterator;

template <typename It>
void PrintRange(
    It range_begin,
    It range_end) {

    for (auto it = range_begin;
         it != range_end; ++it) {
        cout << *it << ", ";
    }
}


template <typename It>
void PrintMapRange(
    It range_begin,
    It range_end) {

    for (auto it = range_begin;
         it != range_end; ++it) {
        cout << it->first << '/' << it->second << " ";
    }
}


int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    vector<string> c_langs;
    auto it = find_if(begin(langs), end(langs),
                      [](const string& lang) {
                          return lang[0] == 'C';
                      });
    cout << it - begin(langs) << endl;
//    PrintRange(begin(c_langs), end(c_langs));

    set<int> s = {1, 6, 8, 9};
    auto it2 = s.find(6);
    PrintRange(next(it2), end(s));

    return 0;
}

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    vector<string> c_langs;
    auto it = find_if(begin(langs), end(langs),
                      [](const string& lang) {
                          return lang[0] == 'C';
                      });
    cout << it - begin(langs) << endl;
    cout << *it << endl;
//    PrintRange(begin(c_langs), end(c_langs));

    set<int> s = {1, 6, 8, 9};
    auto it2 = s.find(6);
    PrintRange(next(it2), end(s));

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    vector<string> c_langs;
    copy_if(begin(langs), end(langs), back_inserter(c_langs),
            [](const string& lang) {
                return lang[0] == 'C';
            });
    PrintRange(begin(c_langs), end(c_langs));

    set<int> a = {1, 3, 8};
    set<int> b = {3, 7, 8};
    set<int> res;
    set_intersection(begin(a), end(a), begin(b), end(b), inserter(res, end(res)));
    PrintRange(begin(res), end(res));

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    vector<string> c_langs(langs.size());
    auto it = copy_if(begin(langs), end(langs), begin(c_langs),
                      [](const string& lang) {
                          return lang[0] == 'C';
                      });
    PrintRange(begin(c_langs), it);

    set<int> a = {1, 8, 3};
    set<int> b = {3, 6, 8};
    vector<int> v(a.size());
    auto it2 = set_intersection(begin(a), end(a),
                                begin(b), end(b), begin(v));
    PrintRange(begin(v), it2);

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    auto it = partition(begin(langs), end(langs),
                        [](const string& lang) {
                            return lang[0] == 'C';
                        });
    PrintRange(begin(langs), it);

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    sort(rbegin(langs), rend(langs));
    PrintRange(begin(langs), end(langs));

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    auto it = find_if(rbegin(langs), rend(langs),
                      [](const string& lang) {
                          return lang[0] == 'C';
                      });
    cout << *it << endl;

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    PrintRange(rbegin(langs), rend(langs));

    auto it = rbegin(langs);
    cout << *it << " ";
    ++it;
    cout << *it << " ";

    return 0;
}*/

/*int main() {

    set<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    cout << all_of(begin(langs), end(langs),
                   [](const string& lang) {
                       return lang[0] >= 'A' && lang[0] <= 'Z';
                   });

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    auto it = min_element(begin(langs), end(langs));
    cout << *it << endl;
    auto it2 = max_element(begin(langs), end(langs));
    cout << *it2 << endl;
    auto p = minmax_element(begin(langs), end(langs));
    cout << *p.first << ' ' << *p.second << endl;

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C++", "Java", "C++"
    };
    auto it = unique(begin(langs), end(langs));
    langs.erase(it, end(langs));
    PrintRange(begin(langs), end(langs));

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    auto it = remove_if(begin(langs), end(langs),
                        [](const string& lang) {
                            return lang[0] == 'C';
                        });
    langs.erase(it, end(langs));
    PrintRange(begin(langs), end(langs));

    return 0;
}*/

/*int main() {
http://cpp.com.ru/lippman/c21.html
    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    auto it = find(begin(langs), end(langs), "C++");
    langs.erase(it, end(langs));
    langs.insert(begin(langs), "C++");
    PrintRange(begin(langs), end(langs));

    return 0;
}*/

/*int main() {

    vector<string> langs = {
        "Python", "C++", "C", "Java", "C#"
    };
    auto it = end(langs);
    while(it != begin(langs)) {
        --it;
        cout << *it << " ";
    }

    return 0;
}*/

/*int main() {
    map<string, int> langs ={
        {"Python", 26},
        {"C++", 34},
        {"C", 45},
        {"Java", 22},
        {"C#", 17}
    };

    auto it = langs.find("C++");

    PrintMapRange(begin(langs), it);
    cout << endl;
    PrintMapRange(it, end(langs));

    return 0;
}*/

/*int main() {
    vector<string> langs ={
        "Python",
        "C++",
        "C",
        "Java",
        "C#"
    };

    PrintRange(begin(langs), end(langs));
    PrintRange(begin(langs[0]), end(langs[0]));

    return 0;
}*/

/*int main() {
    vector<Lang> langs ={
        {"Python", 26},
        {"C++", 34},
        {"C", 45},
        {"Java", 22},
        {"C#", 17}};
    auto result = find_if(
        begin(langs), end(langs),
        [](const Lang& lang) {
            return lang.name[0] == 'D';
        });
    cout << begin(langs)->name << " "
         << langs.begin()->age << endl;

    return 0;
}*/
