#include <vector>

using std::vector;


class Solution {
public:
    vector<int> productExceptSelf(vector<int> & nums) {

        // Space: O(n)
        // Time: O(n)
        int n = nums.size();
        vector<int> forward_product(n, 1);
        vector<int> reverse_product(n, 1);

        for (int i=1; i < n; i++){
            forward_product[i] = forward_product[i - 1] * nums[i - 1];
            reverse_product[n - i - 1] = reverse_product[n - i] * nums[n - i];
        }

        vector<int> result;

        for (int i=0; i < n; i++){
            result.push_back(forward_product[i] * reverse_product[i]);
        }

        return result;
    }

    vector<int> productExceptSelf_space_efficient(vector<int> & nums) { // Do exactly the same but in result array

        // Space: O(1)
        // Time: O(n)
        int n = nums.size();

        vector<int> result(n, 1);
        for (int i=1; i < n; i++){
            result[i] = result[i-1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i=1; i <=n; i++){
            result[n-i] *= postfix;
            postfix *= nums[n-i];
        }


        return result;
    }

};