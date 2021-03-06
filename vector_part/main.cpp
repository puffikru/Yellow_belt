#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto it = find_if(numbers.begin(), numbers.end(),
        [](int number) {
        return number < 0;
    });
    for (auto i = it; i != numbers.begin(); ) {
        cout << *(--i) << " ";
    }
}

int main() {
    PrintVectorPart({6, 1, 8, -5, 4});
    cout << endl;
    PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
    cout << endl;
    PrintVectorPart({6, 1, 8, 5, 4});
    cout << endl;
    return 0;
}