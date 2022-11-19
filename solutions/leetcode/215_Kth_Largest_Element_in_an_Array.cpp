#include <vector>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
private:
    int quickSelect(vector<int> nums, int l, int r, int k){
        int pivot = nums[r];
        
        int pointer = l;
        int i = l;
        
        while (i != r){
            if (nums[i] < pivot){
                swap(nums[i], nums[pointer]);
                pointer++;
            }
            i++;
        }
        
        swap(nums[pointer], nums[r]);
        
        if (nums.size() - pointer == k){
            return pivot;
        } else if (nums.size() - pointer < k){
            return quickSelect(nums, l, pointer - 1, k);
        } else {
            return quickSelect(nums, pointer + 1, r, k);
        }
        
        
    }
};