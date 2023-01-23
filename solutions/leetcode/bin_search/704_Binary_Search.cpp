#include <vector>


using std::vector;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int middle = right + (left - right) / 2;

            if (target < nums[middle]){
                right = --middle;
            }
            else if (target > nums[middle]){
                left = ++middle;
            } else {
                return middle;
            }
        }
        

        return -1;
        
    }
};