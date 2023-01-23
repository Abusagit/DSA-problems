#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> location;
        int id_1, id_2;

        for (int i=0; i < nums.size(); i++){
            int num = nums[i];

            if (location.find(target - num) != location.end()){
                id_1 = i;
                id_2 = location[target - num];
                break;
            }

            
            if (location.find(num) == location.end()){
                location[num] = i;
            }
        }

        return std::vector<int>{id_1, id_2};

    }
};

