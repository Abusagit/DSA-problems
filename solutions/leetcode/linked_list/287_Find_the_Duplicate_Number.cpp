#include <vector>
#include <numeric>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        //Floyd`s algorithm

        int fast = nums[nums[0]];
        int slow = nums[0];

        while (fast != slow){

            fast = nums[nums[fast]];
            slow = nums[slow];
        }

        int slow_1 = 0;

        while (slow_1 != slow){
            slow_1 = nums[slow_1];
            slow = nums[slow];
        }

        return slow_1;
    }
};