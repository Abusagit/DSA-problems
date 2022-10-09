#include <string>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

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

    int lengthOfLongestSubstring_2_pointers(string s) { //analogous approach
        std::unordered_set<char> letters;
        int i = 0; //lower bound of a substring
        int j = 0; // upper bound of a substring
        int result = 0;
        while (j < s.size()) {
            if (letters.count(s[j]) == 0) { //s[j] is not in set
                letters.insert(s[j]);
                result = max(result, j - i + 1); //update after each non-repeating character --> also deals with single-char string and string-substrings themselves
                j++;
            } else {
                letters.erase(s[i]);
                i++; // shift lower bound b.c. new element replaces last element and new substring will be 1 character shorted than previous (we 'delete' duplicate and contract string by doing this) 
            }
        }
        return result;
    }
};