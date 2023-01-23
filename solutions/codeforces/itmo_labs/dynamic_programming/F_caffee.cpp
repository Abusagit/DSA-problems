#include <iostream>
#include <utility>
#include <vector>
 
 
#define MAX 30001
using namespace std;


int main(){
    int n; cin >> n;

    if (n == 0){
        cout << 0 << '\n' << 0 << ' ' << 0 << endl;
        return 0;
    }

    vector<int> prices(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> prices[i];

    vector<vector<int>> d(n + 1, vector<int>(n + 1, MAX));
    d[0][0] = 0;
    // d[i][j] = min cost for meals in the first i days with j coupons remaining
    // d[0][j] = inf; j > 0



    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            int p = prices[i + 1];

            if (j < n && p > 100){
                d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + p);
            }

            if (p <= 100){
                d[i + 1][j] = min(d[i + 1][j], d[i][j] + p);
            }

            if (j > 0){
                d[i + 1][j - 1] = min(d[i + 1][j - 1], d[i][j]);
            }
        }
    }

    int mi = -1;
    int m = MAX;
    for(int i = 0; i <= n; i++) {
        if(d[n][i] <= m) {
            m = d[n][i];
            mi = i;
        }
    }

    vector<int> coupon_days; 
    
    int j = mi; int i = n;
    while(i != 0) {
        
        if(d[i - 1][j] == (d[i][j] - prices[i])) {
            i--;
            continue;
        }

        if(j > 0 && d[i - 1][j - 1] == (d[i][j] - prices[i])) {
            i--;
            j--;
            continue;
        }

        if(j < n && d[i - 1][j + 1] == d[i][j]) {
            coupon_days.push_back(i);
            i--;
            j++;
            continue;
        }
    }

    cout << m << '\n';
    cout << mi << " " << coupon_days.size() << '\n';

    for(int q = coupon_days.size() - 1; q >= 0; q--) {
        cout << coupon_days[q] << '\n';
    }

    return 0;
}
