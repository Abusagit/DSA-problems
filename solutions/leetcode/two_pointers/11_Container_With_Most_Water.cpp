#include <algorithm>
#include <vector>


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        using std::max;
        int max_area = 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        
        while (left < right){
            // max_area = max({max_area, std::min({height[left], height[right]}) * (right - left)});
            int width = right - left;

            if (height[left] < height[right]){
                max_area = max({max_area, width * height[left++]});
            } else {
                max_area = max({max_area, width * height[right--]});
            }
        }


        return max_area;
    }
};