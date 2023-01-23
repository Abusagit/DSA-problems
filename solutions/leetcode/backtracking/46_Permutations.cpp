class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }

private:
    vector<vector<int>> result;

    void dfs(vector<int>& nums, int start){
        if (start == nums.size()){
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
            
        }
    }
};