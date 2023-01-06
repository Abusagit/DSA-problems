class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<int> current;
        dfs(current, nums, 0);

        return result;
    }

private:
    vector<vector<int>> result;
    void dfs(vector<int>& current, vector<int>& nums, int start_index){
        result.push_back(current);

        for (int i = start_index; i < nums.size(); i++){
            if (i > start_index && nums[i] == nums[i - 1]){ // have already skipped nums[i - 1] => need to skip nums[i]
                continue;
            }
            current.push_back(nums[i]);
            dfs(current, nums, i + 1);
            current.pop_back();
        }


    }
};