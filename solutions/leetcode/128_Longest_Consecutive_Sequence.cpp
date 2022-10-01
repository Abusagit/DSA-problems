#include <vector>
#include <unordered_set>
#include <algorithm>


using std::max;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        using std::vector;
        using std::unordered_set;
        
        unordered_set<int> set;

        for (int x: nums){
            set.insert(x);
        }

        int longest_consequtive_sequence = 0; // for the empty input case

        while (!set.empty()){
        int longest_consequtive_sequence_for_x = 1;
            int x = *set.begin();
            set.erase(set.begin());

            auto x_plus_1 = set.find(x + 1);
            while (x_plus_1 != set.end()){
                longest_consequtive_sequence_for_x++;

                int y = *x_plus_1;
                set.erase(x_plus_1);

                x_plus_1 = set.find(y + 1);
            }

            auto x_minus_1 = set.find(x - 1);
            while (x_minus_1 != set.end()){
                longest_consequtive_sequence_for_x++;

                int y = *x_minus_1;
                set.erase(x_minus_1);

                x_minus_1 = set.find(y - 1);
            }
        
            longest_consequtive_sequence = max({longest_consequtive_sequence, longest_consequtive_sequence_for_x});
        }

        return longest_consequtive_sequence;

    }
};