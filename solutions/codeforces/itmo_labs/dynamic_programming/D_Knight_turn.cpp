#include <iostream>
#include <vector>

#define MOD 1000000000


typedef unsigned long int ull;

using namespace std;

int main(){
    int n; cin >> n;

    vector<vector<ull>> d(n, vector<ull>(10, 1)); // d[i][j] = amount of phone numbers with length i ending with digit j

    vector<vector<int>> numbers_to_visit({
        {4, 6}, // 0
        {6, 8}, // 1
        {7, 9}, // 2
        {4, 8}, // 3
        {3, 9, 0}, // 4
        {}, // 5 - no way how to go from 5 to another digits
        {1, 7, 0}, // 6
        {2, 6}, // 7
        {1, 3}, // 8
        {2, 4} // 9
    });

    d[0][0] = 0;
    d[0][8] = 0;


    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 9; j++){
            ull s = 0;

            for (auto x = numbers_to_visit[j].begin(); x != numbers_to_visit[j].end(); x++){
                s +=  d[i - 1][*x];
                s %= MOD;
            }

            d[i][j] = s;
        }
    }

    ull s = 0;

    for (int j = 0; j <= 9; j++){
        s += d[n - 1][j];
        s %= MOD;
    }

    s %= MOD;
    cout << s << endl;

    return 0;
}
