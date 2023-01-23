class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> subset_sums({0});

        int half_sum = accumulate(nums.begin(), nums.end(), 0);

        if (half_sum % 2){
            return false;
        }

        half_sum /= 2; // divide by 2


        // count all subsets dynamically
        for (auto x: nums){
            unordered_set<int> current_sums;

            // here subset_sums create sums of every subset of subarray of nums[0], nums[1], ..., <last element before x>.
            for (auto subset_before_x_sum: subset_sums){
                
                int y = x + subset_before_x_sum;
                if (y == half_sum){
                    return true;
                }
                current_sums.insert(y);
                
            }

            for (auto y: current_sums){
                subset_sums.insert(y);
            }
        }

        return false;
    }
};