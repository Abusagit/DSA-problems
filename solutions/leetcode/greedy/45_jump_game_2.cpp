// LOOK AT THE NEXT JUMP AND USE IT IF IT BRINGS FURTHEST REACHABLE INDEX

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int result = 0;

        int i = 0;

        while (i < n - 1){
            if (i + nums[i] >= n - 1){ // we already jump further than last index
                result++;
                break;
            }



            // variables for max next jump
            int max_index = i + 1;
            int max_value_to_jump_from_next = 0;


            // determine where will be the largest jump in the next jump and count jumps
            for (int j = i + 1; j <= i + nums[i]; j++){ // look at all reachable indices from current indx
                if (j + nums[j] > max_value_to_jump_from_next){
                    max_index = j;
                    max_value_to_jump_from_next = j + nums[j];
                }
            }

            i = max_index;
            result++;
        }

        return result;

    }
};