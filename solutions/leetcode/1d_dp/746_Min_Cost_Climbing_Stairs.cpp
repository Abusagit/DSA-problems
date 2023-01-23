#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int min_cost_two_steps_down = 0;
        int min_cost_one_step_down = 0;

        for (int i = 2; i <= cost.size(); i++){
            int tmp = min_cost_one_step_down;
            min_cost_one_step_down = min(min_cost_one_step_down + cost[i - 1],
                                         min_cost_two_steps_down + cost[i - 2]);
            min_cost_two_steps_down = tmp;
        }

        return min_cost_one_step_down;
    }
};