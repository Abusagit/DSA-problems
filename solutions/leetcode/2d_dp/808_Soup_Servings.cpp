#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    double soupServings(int m) {
        if (m > 5000){
            return 1.0;
        }

        int n = ceil(m / 25.0);

        vector<vector<double> > d(n+1, vector<double>(n+1, 0.0));

        d[0][0] = 0.5;

        for (int i=1; i <= n; i++){
            for (int j=1; j <= n; j++){
                d[i][0] = 0;
                d[0][j] = 1;

               // cout << i << " " << j << " " << current_val << endl;

                
                
                d[i][j] = (d[max(i-1, 0)][max(j-3, 0)] + d[max(i-2, 0)][max(j-2, 0)] + d[max(i-3, 0)][max(j-1, 0)] + d[max(i-4, 0)][j]) / 4;
            }
        }

        return d[n][n];

    }
};