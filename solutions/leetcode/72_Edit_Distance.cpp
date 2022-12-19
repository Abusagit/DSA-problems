class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> d(m + 1, vector<int>(n + 1));

        for (int j = 0; j <= n; j++){
            d[0][j] = j;
        }

        for (int i = 1; i <= m; i++){
            d[i][0] = i;
        }

        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){

                d[i][j] = min(
                    (word2[i - 1] != word1[j - 1]) + d[i - 1][j - 1],
                    1 + min(d[i - 1][j], d[i][j - 1])
                );
                // d[i][j] = 1;
            }
        }

        return d[m][n];
    }
};