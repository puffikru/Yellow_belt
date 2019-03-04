#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    } else {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        auto it = begin(elements);
        auto it_end = it + (elements.size() / 2);
        MergeSort(it, it_end);
        MergeSort(it_end, end(elements));
        merge(it, it_end, it_end, end(elements), range_begin);
    }
}*/

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    } else {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        auto it = begin(elements);
        auto it_middle = it + (elements.size() / 3);
        auto it_end = it_middle + (elements.size() / 3);
        MergeSort(it, it_middle);
        MergeSort(it_middle, it_end);
        MergeSort(it_end, end(elements));
        vector<typename RandomIt::value_type> first;
        merge(it, it_middle, it_middle, it_end, back_inserter(first));
        merge(begin(first), end(first), it_end, end(elements), range_begin);
    }
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}