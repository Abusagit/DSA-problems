#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> occurences_num;

        for (auto x: nums){
            if (occurences_num.find(x) != occurences_num.end()){
                occurences_num[x]++;

            } else {
                occurences_num[x] = 1;    
            }
        }

        std::vector<std::pair<int, int>> items;
        for (auto x: occurences_num){
            items.push_back({x.second, x.first});
        }

        std::sort(items.begin(), items.end());

        std::vector<int> result;

        for (int n=items.size(), i=0; i < k; i++){
            result.push_back(items[n - i - 1].second);
        }
        
        return result;
    }

    std::vector<int> topKFrequent_faster(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> occurences_num;

        for (auto x: nums){
            if (occurences_num.find(x) != occurences_num.end()){
                occurences_num[x]++;

            } else {
                occurences_num[x] = 1;    
            }
        }

        std::vector<std::pair<int, int>> items;
        for (auto x: occurences_num){
            items.push_back({x.second, x.first});
        }

        std::sort(items.begin(), items.end());

        std::vector<int> result;

        for (int n=items.size(), i=0; i < k; i++){
            result.push_back(items[n - i - 1].second);
        }
        
        return result;
    }

};
