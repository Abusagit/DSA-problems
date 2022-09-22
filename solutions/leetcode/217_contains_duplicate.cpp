#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        
        for (auto x: nums){
            if (set.find(x) != set.end()){
                return true;
                
            } else {
                set.insert(x);
            }
        }
        
        
        return false;
    }
};