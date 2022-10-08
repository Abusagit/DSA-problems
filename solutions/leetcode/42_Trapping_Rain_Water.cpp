#include <vector>
#include <algorithm>


class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int area = 0;

        while (left < right){
            int pivot_left = height[left];
            int pivot_right = height[right];


            if (pivot_left <= height[left + 1]){
                left++;
                continue;
            }

            if (pivot_right <= height[right - 1]){
                right--;
                continue;
            }

            if (pivot_left <= pivot_right){
                left++;
                while ((left < right) && (height[left] < pivot_left)){
                    area += pivot_left - height[left];
                    left++;
                }
            } else {
                right--;
                while ((left < right) && (height[right] < pivot_right)){
                    area += pivot_right - height[right];
                    right--;
                }
            }
        
        }

        return area;
    }


    int trap_faster(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int area = 0;
        
        
        int max_L = height[left];
        int max_R = height[right];
        
        while(left < right){
            if (max_L <= max_R){ //left rectangle is lower than right
                left++;
                max_L = std::max({max_L, height[left]});
                
                area += max_L - height[left];
                
            } else {
                right--;
                max_R = std::max({max_R, height[right]});
                area += max_R - height[right];
                
            }
            
        }

        return area;
    }
};