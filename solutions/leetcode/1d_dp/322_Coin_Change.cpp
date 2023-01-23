class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = 100000;

        vector<int> d(amount + 1, MAX); // fill with maximum values

        d[0] = 0;


        for (int i = 1; i <= amount; i++){
            for (int coin_j: coins){
                if (i >= coin_j){
                    d[i] = min(d[i], 1 + d[i - coin_j]);
                }
            }
        }
        return (d[amount] != MAX) ? d[amount] : -1;

    }
};