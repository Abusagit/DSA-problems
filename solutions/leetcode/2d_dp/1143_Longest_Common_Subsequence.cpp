class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<vector<int>> d(n + 1, vector<int>(m+1));

        d[0].assign(m+1, 0);

        for (int i =1; i<= n; i++){
            d[i][0] = 0;
        }

        // d[i][j] = length of LCS in first i letters from text1 and first j letters from text2

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (text1[i - 1] == text2[j -1]){
                    d[i][j] = 1 + d[i -1][j - 1];
                } else {
                    d[i][j] = max(
                        {d[i - 1][j], d[i][j - 1], d[i -1][j-1]}
                    );
                }
            }
        }

        return d[n][m];

    }
};