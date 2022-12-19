class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ///max_buy_0, by today, the max profit you can make when your last action was BUY.
        ///max_buy_0 initially is INT_MIN, because this means you can't just sell at day 0.

        ///max_sell_0, by today, the max profit you can make when your last action was SELL.
        ///max_sell_1, by YESTERDAY, the max profit you can make when your last action was SELL.

        int max_buy_0 = INT_MIN, max_sell_0 = 0, max_sell_1 = 0;

        for (auto p: prices){

            max_buy_0 = max(max_buy_0, max_sell_1 - p); //either cooldown or spend money on buying stuff on the money after cooldown
            max_sell_1 = max_sell_0; // live one day -> simple variable transition

            max_sell_0 = max(max_sell_0, max_buy_0 + p); //either cooldown or sell stock for price p ("update" max_buy)
        }

        return max_sell_0;

        
    }
};