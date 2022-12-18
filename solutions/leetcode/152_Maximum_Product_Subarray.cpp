class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int current_max = nums[0];
        int current_min = nums[0];

        int res = nums[0];

        for (int i = 1; i < nums.size(); i++){

            int tmp = current_max;

            current_max = max({nums[i] * tmp, nums[i] * current_min, nums[i]});
            current_min = min({nums[i] * tmp, nums[i] * current_min, nums[i]});

            // cout << current_max << " " << current_min << " " << res << "\n";


            res = max(res, current_max);
        }

        return res;

    }
};