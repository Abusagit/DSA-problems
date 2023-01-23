class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, int> dp; // dp[(i, j)] = # of ways to get to target if we start at index i with sum value j

        return dfs(nums, dp, 0, 0, target);
    }
private:

    int dfs(vector<int>& nums, map<pair<int,int>, int>& dp, int index, int current_sum, int target){

        if (index == nums.size()){
            return current_sum == target;
        }
        pair<int, int> current_pair({index, current_sum});

        if (dp.find(current_pair) != dp.end()){
            return dp[current_pair];
        }

        dp[current_pair] =  dfs(nums, dp, index + 1, current_sum + nums[index], target) + 
                            dfs(nums, dp, index + 1, current_sum - nums[index], target);

        return dp[current_pair];
    }
};