#include <iostream>
#include <vector>


#define int unsigned long long
#define vint vector<int>

using namespace std;

const int INF = 1 << 30;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;

    const int N = 1 << n;
    vector<vint> distances(n, vint(n));
    vector<vint> dp(N, vint(n, INF));


    // dp[mask][j] = min distance through cities encoded in mask with starting city j (also presents in mask)
  
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> distances[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        dp[1 << i][i] = 0;
    }

    for (int mask = 0; mask < N; mask++){
        for (int i = 0; i < n; i++){
            if (!(mask >> i) & 1){ // city i doesn`t present in mask
                continue;
            }

            for (int j = 0; j < n; j++){
                if (!(mask >> j) & 1){ // city j doesn`t present in mask
                    continue;
                }

                dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + distances[i][j]);
                                    // ^                        ^
                                    // |                        |
                                    // |                        |
                                    // initial value            distance through cities except i with start in j and before that travel transfer from i to j
                                    //                              (i-th bit is always 1 before XOR) ==> we only go back in mask
            }
        }
    }


    int minimal_distance = INF, city = -1;

    for (int i = 0; i < n; i++){
        if (dp[N-1][i] < minimal_distance){
            minimal_distance = dp[N - 1][i];
            city = i;
        }
    }
    cout << minimal_distance << '\n';

    int mask = N - 1;

    // iterate over all cities
    for (int i = 0; i < n; i++){
        cout << city + 1 << ' ';
        for (int j = 0; j < n; j++){

            if (dp[mask][city] == dp[mask ^ (1 << city)][j] + distances[city][j]){ // found valid transition
                // go back in mask (exclude city j because it is next city)
                mask ^= (1 << city);
                city = j;
                break;
            }
        }
    }

    cout << endl;
    return 0;
}
