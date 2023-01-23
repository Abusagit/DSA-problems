#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right){
            int current_sum = numbers[right] + numbers[left];

            if (current_sum > target){
                right--;
            } else if (current_sum < target){
                left++;
            } else {
                break;
            }
        }

        return {++left, ++right};
    }
};