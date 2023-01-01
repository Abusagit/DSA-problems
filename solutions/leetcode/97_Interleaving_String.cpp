class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();

        if (n + m != s3.size()){
            return false;
        }

        vector<vector<bool>> d(n + 1, vector<bool>(m + 1));

        d[0][0] = true;

        for (int i = 0; i < m; i++){
            d[0][i + 1] = s2[i] == s3[i] && d[0][i];
        }

        for (int j = 0; j < n; j++){
            d[j + 1][0] = s1[j] == s3[j] && d[j][0];
        }

        for (int i = 1; i <= n; i++){
            char s1_last = s1[i - 1];
            for (int j = 1; j <= m; j++){
                char s2_last = s2[j - 1];
                char s3_last = s3[i + j - 1];

                d[i][j] = (s1_last == s3_last && d[i - 1][j]) || (s2_last == s3_last && d[i][j - 1]);
            }
        }

        return d[n][m];

    }
};