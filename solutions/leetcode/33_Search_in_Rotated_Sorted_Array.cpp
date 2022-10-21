#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        
        while (left <= right){
            
            int middle = right + (left - right)  / 2;
            
            int x_middle = nums[middle];
            
            if (x_middle == target){
                return middle;
            }
            
            
            //
            if (nums[left] < x_middle){ // in left sorted portion of an array
                if (target > x_middle || target < nums[left]){ // either we need to proceed to shifted part of an array or continue searching in the same portion
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else {
                
                if (target < x_middle || target > nums[right]){
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
            
        }
        
        return -1;
    }
};