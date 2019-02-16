#include <iostream>
#include <vector>

using namespace std;

int main() {
    uint32_t N = 0;
    uint16_t R = 0;

    cin >> N >> R;

    uint16_t W = 0;
    uint16_t H = 0;
    uint16_t D = 0;
    uint64_t mass_final = 0;

    for(uint32_t i = 0; i < N; ++i){
        cin >> W >> H >> D;
        uint64_t t = static_cast<uint64_t>(W) * H * D;
        mass_final += t * R;
    }

    cout << mass_final;

    return 0;
}
