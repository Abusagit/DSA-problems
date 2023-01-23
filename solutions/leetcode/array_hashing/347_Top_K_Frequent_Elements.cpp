#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

class Solution {
public:

    // get val:num map -> sort -> get desired information
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


    // count occurences -> place numbers to buckets according to their amount
    std::vector<int> topKFrequent_faster(std::vector<int>& nums, int k) { // but it occured twice slower on leetcode!
        std::unordered_map<int, int> occurences_num;

        for (auto x: nums){
            occurences_num[x]++;
        }


        int n = nums.size();
        std::vector<std::vector<int>> buckets(n + 1);
        for (auto it=occurences_num.begin(); it != occurences_num.end(); it++){
            buckets[it->second].push_back(it->first);
        }

        std::vector<int> result;

        for (int i=n; i >=0; i--){
            if (result.size() >= k){
            break;
            }

            if (!buckets[i].empty()){
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }

};
