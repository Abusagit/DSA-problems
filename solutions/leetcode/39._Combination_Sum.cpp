class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        vector<int> current;

        dfs(candidates, result, current, 0, 0, target);
        return result;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int sum, int start_index, int& target){
        if (sum > target){
            return;
        }
        
        if (sum == target){
            result.push_back(current);
            return;
        }

        for (int i = start_index; i < candidates.size(); i++){

            current.push_back(candidates[i]);
            dfs(candidates, result, current, sum + candidates[i], i, target);
            current.pop_back();
        }

        
    }

};