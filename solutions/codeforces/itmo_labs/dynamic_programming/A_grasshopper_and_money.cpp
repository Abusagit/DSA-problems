#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<ll> d;
vector<int> earn;
vector<int> prev_index;


int main(){
    int n, k; cin >> n >> k;

    earn.resize(n);
    d.resize(n, -100000);
    prev_index.resize(n);

    prev_index[0] = -1;

    earn[0] = 0;
    earn[n-1] = 0;

    d[0] = 0;

    for (int i = 1; i < n - 1; i++){
        cin >> earn[i];
    }


    for (int i = 0; i <= n - 2; i++){
        // for (int m = 0; m < n; m++){
        //     cout << d[m] << " ";
        // }
        // cout << "\n";

        for (int j = 1; i + j < n && j <= k; j++){
            if (earn[i + j] + d[i] > d[i + j]){
                prev_index[i + j] = i;
                d[i + j] = d[i] + earn[i + j];
            }
        }
    }

    vector<int> result;

    int index = n - 1;

    while (index >= 0){
        result.push_back(index + 1);
        index = prev_index[index];
    }

    cout << d[n - 1] << '\n' << result.size() - 1 << "\n";

    for (int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }

    cout << '\n';


    return 0;
}


