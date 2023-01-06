class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;

        vector<int> current;

        dfs(result, current, nums, 0);

        return result;
    }

private:
    void dfs(vector<vector<int>>& result, vector<int>& current, vector<int>& nums, int start_index){

        result.push_back(current);
        for (int i = start_index; i < nums.size(); i++){
            current.push_back(nums[i]);
            dfs(result, current, nums, i + 1);
        }

        current.pop_back();
    }
};