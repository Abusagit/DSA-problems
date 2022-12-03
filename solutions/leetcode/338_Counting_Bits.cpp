#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        
        for (int i = 1; i <=n; i++){

            //       look i / 2    look LSB
            // number of ones in x equals the number of ones in double-less number (x/2) and +1 if x is odd and +0 if x is even
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};