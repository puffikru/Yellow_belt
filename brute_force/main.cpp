#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums;
    for (int i = N; i > 0; --i) {
        nums.push_back(i);
    }
    sort(rbegin(nums), rend(nums));
    do {
        for (const auto& i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }while(prev_permutation(begin(nums), end(nums)));

    return 0;
}
