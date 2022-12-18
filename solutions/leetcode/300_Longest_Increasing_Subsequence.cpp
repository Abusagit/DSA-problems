

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // O(n^2)
        vector<int> d(nums.size(), 1);

        int result = 1;
        for (int i = 1; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    d[i] = max(d[i], 1 + d[j]);
                }
            }

            result = max(result, d[i]);
        }

        return result;
    }
};