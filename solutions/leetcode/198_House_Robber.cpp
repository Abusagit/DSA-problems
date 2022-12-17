#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2){
            return nums[0];
        }


        int rob_1 = 0;
        int rob_2 = nums[0];

        for (int i = 1; i <= nums.size() - 1; i++){
            int tmp = rob_2;

            rob_2 = max(rob_2, rob_1 + nums[i]);
            rob_1 = tmp;

        }


        return rob_2;
    }


};