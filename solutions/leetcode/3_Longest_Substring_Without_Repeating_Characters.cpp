#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::unordered_map;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_length = 0;

        std::unordered_map<char, int> last_position;
        int start_idx = 0;
        for (int i=0; i < s.size(); i++){

            char x = s[i];
            if (!((last_position.find(x) == last_position.end()) || (last_position[x] < start_idx))){ // x has already been met or wasn`t met only in the previous sunstring 
                longest_length = max({longest_length, i - start_idx});
                start_idx = last_position[x] + 1;
            }
            last_position[x] = i;

        }


        return max({longest_length, static_cast<int>(s.size() - start_idx)}); // here I deleted "-1" bc the last character in the sequence can be also unique and thus length of a substring is 1 character bigger
                                                                                // Moreover this max() checks string with 1 length and strings-longest substring themselves
                                                                                // This is valid bc 1st case - last char is unique - explained earlier
                                                                                //  2nd case - last char is non-unique --> values s.size() - start_idx will be 1 as start_idx was updated on the last iteration

    }
};