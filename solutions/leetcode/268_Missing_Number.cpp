class Solution {
public:
    int missingNumberARITHMETICS(vector<int>& nums) {
        int n = nums.size();
        
        int s = (n * (n + 1)) / 2;
        
        for (int x: nums){
            s -= x;
        }
        
        return s;
    }

    int missingNumberBIT_MAGIC(vector<int>& nums) {
        int n = nums.size();
        int result = n;

        for (int i = 0; i < n; i++){
            result ^= (i ^ nums[i]);
        }

        return result;
    }
};