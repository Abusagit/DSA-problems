#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1){
            return nums[0];
        }
        

        // since they are encircled, rob houses 1...n-1 and 2...n and compare the results
        return max(rob_houses(nums, 0, nums.size() - 1),
                    rob_houses(nums, 1, nums.size()));
    }

private:
    
    int rob_houses(vector<int>& nums, int i, int j){

        int prev_prev_house_max_sum = 0, prev_hous_max_sum = 0;

        for (int k = i; k < j; k++){
            int tmp = prev_hous_max_sum;

            prev_hous_max_sum = max(prev_prev_house_max_sum + nums[k], prev_hous_max_sum);
            prev_prev_house_max_sum = tmp;
        }

        return prev_hous_max_sum;
    }
};