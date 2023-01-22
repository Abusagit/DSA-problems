#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
 
 
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
 
    vector<vector<long long int>> d(n, vector<long long int>(m));
    vector<vector<long long int>> earn(n, vector<long long int>(m));


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> earn[i][j];

            if (j == 0){
                if (i > 0) {
                    d[i][j] = d[i - 1][j] + earn[i][j];
                } else {
                    d[i][j] = earn[i][j];
                }
            }

            if (i == 0) {
                if (j > 0) {
                    d[i][j] = d[i][j - 1] + earn[i][j];
                }
            }
        }
    }
 
 
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
 
            d[i][j] = max(d[i-1][j], d[i][j-1]) + earn[i][j];
 
        }
    }
 
 
    string result = "";
    int x = n - 1, y = m - 1;
 
    while (x != 0 || y != 0){
        if (x > 0 && d[x][y] == d[x - 1][y] + earn[x][y]){
            result += "D";
            x--;
        } else {
            result += "R";
            y--;
        }
    }
 
    reverse(result.begin(), result.end());
 
 
    cout << d[n - 1][m - 1] << '\n' << result << endl;
    return 0;
}