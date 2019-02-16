#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint32_t N;
    int t;
    int64_t avg = 0;

    cin >> N;
    vector<int> temperature(N);
    for (uint32_t i = 0; i < N; ++i){
        cin >> t;
        avg += t;
        temperature[i] = t;
    }

    avg /= (int32_t)temperature.size();

    size_t j = 0;

    for (size_t i = 0; i < temperature.size(); ++i){
        if(temperature[i] > avg){
            temperature[j] = i;
            ++j;
        }
    }

    cout << j << endl;
    for(size_t i = 0; i < j; ++i){
        if(i > 0){
            cout << " ";
        }
        cout << temperature[i];
    }

    return 0;
}
