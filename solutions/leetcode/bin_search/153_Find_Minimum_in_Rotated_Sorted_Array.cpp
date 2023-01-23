#include<algorithm>
#include<vector>


class Solution {
public:
    int findMin (std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        int minimum = 10000;
        
        while (left <= right){
            
            int middle = right + (left - right) / 2;
            
            int x_middle = nums[middle];
            
            minimum = std::min(minimum, x_middle);
            
            if (nums[left] < x_middle && nums[left] > nums[right]){
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        
        
        return minimum;
    }
};