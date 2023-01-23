#include <string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0'){
            return 0;
        }
        int n = s.size();
        vector<int> D(n + 1, 0);

        D[0] = 1;
        D[1] = 1;

        for (int i = 2; i <= n; i++){

            int last_tens = stoi(s.substr(i - 2, 2));

            if (last_tens >= 10 && last_tens <= 26){
                D[i] += D[i - 2];
            }

            int current_digit = stoi(s.substr(i - 1, 1));
            if (current_digit > 0){
                D[i] += D[i - 1];
            }
        }

        return D[n];
    }
};