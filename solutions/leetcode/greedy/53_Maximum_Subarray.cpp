// for each x: check if this x alone is greater then previous sum => if yes ==> make new sum and update current sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0], result = nums[0];


        for (auto x = nums.begin() + 1; x != nums.end(); x++){
            current = max(current + *x, *x);
            result = max(result, current);
        }

        return result;
    }
};
