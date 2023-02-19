// for each index determine farthest reachable index and compare this point with current farthest reachable index


class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size(), reachable_index = 0;

        for (int i = 0; i < n; i++){
            if (i > reachable_index){
                // can`t jump here
                return false;
            }

            // can jump to this index

            reachable_index = max(i + nums[i], reachable_index);

            if (reachable_index >= n - 1){
                break;
            }
        }

        return true;

    }
};