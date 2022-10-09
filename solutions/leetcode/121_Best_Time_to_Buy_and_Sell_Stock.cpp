#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_purchase_price = prices[0];
        int max_sell_price = -1;

        int max_profit = 0;

        for (auto price = prices.begin() + 1; price != prices.end(); price++){
            if (*price < min_purchase_price){
                max_profit = max({max_profit, max_sell_price - min_purchase_price});
                max_sell_price = *price;
                min_purchase_price = *price;
            } else if (*price > max_sell_price){
                max_sell_price = *price;
                max_profit = max({max_profit, max_sell_price - min_purchase_price});
            
            }

        }

    return max({max_profit, max_sell_price - min_purchase_price});

    }
};
