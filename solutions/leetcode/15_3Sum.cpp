#include <vector>
#include <algorithm>


using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());

        for (int i=0; i< nums.size(); i++){
            int a = nums[i];
            if (i > 0 && (a == nums[i-1])){
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;


            int target = -a;
            while (left < right){

                int current_s = nums[left] + nums[right];

                if (current_s < target){
                    left++;
                } else if (current_s > target){
                    right--;

                } else {
                    result.push_back({a, nums[left], nums[right]});
                    left++;

                    while (left < right && (nums[left] == nums[left-1])){
                        left++;// shift and prevent duplicates
                    }
                }
            
            }
        
        }


        
        return result;

    }
};