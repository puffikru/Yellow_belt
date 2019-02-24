#include "sum_reverse_sort.h"
#include <algorithm>
#include <iostream>

using namespace std;


int Sum(int x, int y) {
    return x + y;
}


string Reverse(string s) {
    string temp = "";
    int index = 0;

    for (int i = (int)s.size() - 1; i >= 0; --i) {
        temp += s[i];
        ++index;
    }
    return temp;
};


string _Reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}



void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}
