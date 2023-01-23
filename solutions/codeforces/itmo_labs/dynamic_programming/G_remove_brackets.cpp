#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

#define vint vector<int>
#define INF 1 << 6
#define ALL(a) a.begin(), a.end()

unordered_map<char, char> complement({
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
    {')', '('},
    {']', '['},
    {'}', '{'}
});

vector<vint> dp;
vector<vint> best;
string s;



bool is_complement(char l, char r){
    if ((l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}')){
        return true;
    }
    return false;
}


void print_output(int left, int right){
    if (dp[left][right] == right - left + 1){
        return;
    }


    if (dp[left][right] == 0){
        cout << s.substr(left, right - left + 1);
        return;
    }
    
    if (best[left][right] == -1){
        cout << s[left];
        print_output(left + 1, right - 1);
        cout << s[right];
        return;
    }

    print_output(left, best[left][right]);
    print_output(best[left][right] + 1, right);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> s;
    int n = s.length();

    dp.resize(n, vint(n, INF));
    best.resize(n, vint(n, -1));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j){
                dp[i][i] = 1;
            } else if (i < j){
                dp[j][i] = 0;
            }
        }
    }


    for (int length = 2; length <= n; length++){
        for (int left_index= 0; left_index <= n - length; left_index++){
            int right_index = left_index + length - 1;

            if (is_complement(s[left_index], s[right_index])){
                dp[left_index][right_index] = min(dp[left_index][right_index], dp[left_index + 1][right_index - 1]);
            }

            for (int mid = left_index; mid < right_index; mid++){

                int current = dp[left_index][mid] + dp[mid+1][right_index];

                if (dp[left_index][right_index] > current){
                    dp[left_index][right_index] = current;
                    best[left_index][right_index] = mid;
                }
            }
        }
    }

    // cout << dp[0][n - 1] << '\n';

    print_output(0, n-1);

    cout << endl;

    return 0;
}
