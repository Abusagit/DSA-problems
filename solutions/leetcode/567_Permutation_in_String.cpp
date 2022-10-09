#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


// m = len(s1)
// n = len(s2)
// construct hashmaps for counting occurences of characters comprising s1 in any substring of length m in s2
// until element occures in s2 more times than it occures in s1, increment counter of matches
// when it starsts occuring more than needed - stop incrementing counter
// use sliding window approach of window size m

//T(n) = O(n)
//Space = O(m)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_chars;

        unordered_map<char, int> sliding_chars;


        for (auto x: s1){
            s1_chars[x]++;
            sliding_chars[x] = 0;
        }

        int n = s2.size();
        int m = s1.size();

        int correct = 0;

        for (auto x: s2.substr(0, m)){
            if (s1_chars.find(x) != s1_chars.end()){
                sliding_chars[x]++;
                if (sliding_chars[x] <= s1_chars[x]){
                    correct++;
                }
                
            }
        }

        //sliding_chars contains for each character from s1 number of its occurrences in the sliding window size m s2[i, m + i - 1]
        //correct - number of correct matches in a string

        if (correct == m){
            return true;
        }

        int i = 1;
        while (i <= n - m){
            char next_char = s2[i - 1 + m];
            char prev_char = s2[i - 1];

            if (sliding_chars.find(prev_char) != sliding_chars.end()){ //prev_char has been being found in a permutation substring previously - need to reset counter
                if (sliding_chars[prev_char] <= s1_chars[prev_char]){ // prev chars was spotted no more times than it occures in s1 --> lost chance of correct permutation string  
                    correct--;
                }
                sliding_chars[prev_char]--;
            }

            if (sliding_chars.find(next_char) != sliding_chars.end()){ //next_char presents in s1_chars ==> can be addition to permutation substrings!
                if (sliding_chars[next_char] < s1_chars[next_char]){
                    correct++;
                }
                sliding_chars[next_char]++;
            }

            if (correct == m){
                return true;
            }

            i++;

        }

        return false;


    }

};