class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> d(m + 1);

        for (int i = 0; i <= m; i++){
            d[i].resize(n + 1, 0);
        }
        d[1][0] = 1;

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){

                d[i][j] = d[i - 1][j] + d[i][j-1];
            }
        }

        return d[m][n];
    }
};