#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

void count_values_SLOW(vector<long long>& values, int k) {
    int n = values.size();
    long long overall_sum = 0;

    for (int i = 0; i < n; ++i) {
        overall_sum += values[i];
        overall_sum %= MOD;
    }

    for (int step = 0; step < k; ++step) {

        for (int i = 0; i < n; ++i) {
            long long new_coord = (overall_sum - values[i]) % MOD;
            overall_sum = (overall_sum - values[i]) % MOD + new_coord;
            overall_sum %= MOD;

            values[i] = new_coord;
        }
    }

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> coords(n);

        for (int i = 0; i < n; ++i) {
            cin >> coords[i];
        }

        vector<long long> final_positions = count_values(coords, k);

        for (int i = 0; i < n; ++i) {
            cout << final_positions[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
