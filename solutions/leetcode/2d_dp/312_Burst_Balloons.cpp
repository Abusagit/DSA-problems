/*
    Given array of balloons w/ coins, if burst ith, get (i-1) + i + (i+1) coins
    Return max coins can collect by bursting the balloons wisely

    DP to return max coins obtainable in each interval [left, right]
    Divide & conquer left & right depends on previous bursts, so think backwards
    Instead of which one to burst first, need to think which one to burst last

    Time: O(n^3) -> O(n^2) states, for each states, determining max coins is O(n)
    Space: O(n^2) -> O(n^2) to store all states
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); nums.insert(nums.end(), 1);

        int n = nums.size();
        D.resize(n, vector<int>(n, 0));
        return dfs(nums, 1, n - 2);

    }
private:
    vector<vector<int>> D;

    int dfs(vector<int>& nums, int left, int right){

        if (left > right){
            return 0;
        }

        if (D[left][right] != 0){
            return D[left][right];
        }

        int result = 0;

        for (int i = left; i <= right; i++){

            // blasting borders
            int last_balloon_blast = nums[left - 1] * nums[i] * nums[right + 1];
            //                                          
            result = max(result, last_balloon_blast + dfs(nums, left, i - 1) + dfs(nums, i + 1, right));
        }

        D[left][right] = result;

        return result;

    }    
};