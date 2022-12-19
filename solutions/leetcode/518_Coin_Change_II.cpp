class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> d(amount + 1);

        d[0].resize(n + 1, 1);

        for (int i = 1; i <= amount; i++){
            d[i].resize(n + 1, 0);
        }

        for (int i = 1; i <= amount; i++){
            for (int j = 1; j <= n; j++){
                d[i][j] = d[i][j - 1];

                int coin_j = coins[j - 1];
                d[i][j] += (i >= coin_j) ? d[i - coin_j][j]: 0;
            }
        }

        return d[amount][n];
    }
};