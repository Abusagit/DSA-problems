#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    long long maxStrength(vector<int>& nums) {

        if (nums.size() == 1){
            return nums[0];
        }

        sort(nums.begin(), nums.end());


        long long max_prod = 1;

        int i = 0;

        bool found_any_number = false;

        while (i + 1 < nums.size() && nums[i + 1] < 0){
            max_prod *= nums[i] * nums[i + 1];
            i += 2;
            found_any_number = true;
        }
        while (i < nums.size()){
            if (nums[i] > 0){
                max_prod *= nums[i];
                found_any_number = true;
            }

            i += 1;
        }

        if (found_any_number) return max_prod;
        else return 0;


    }

    long long maxStrength(vector<int>& nums) {
        long long prod = 1;
        int largestNegative = INT_MIN, negCount = 0, largest_value = INT_MIN;

        for (auto x: nums){

            if (x) {
                prod *= x;
            }

            if (x < 0){
                largestNegative = max(largestNegative, x);
                negCount++;
            }

            largest_value = max(largest_value, x);
        }


        if (largest_value < 0 && negCount == 1){
            return largestNegative;
        }
        
        if (largest_value == 0 && negCount < 2){
            return 0;
        }
        if (prod > 0){
            return prod;
        }
        return prod / largestNegative;

    }
};