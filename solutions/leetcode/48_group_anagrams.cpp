// Example:
// Input: strs = ["eat", "tea","tan","ate","nat","bat"]
// Output: [["bat"], ["nat","tan"],["ate","eat","tea"]]


#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iterator>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (std::string x: strs){
            std::vector<int> encoding(26, 0);

            for (std::string::iterator c=x.begin(); c != x.end(); c++)
            {
                encoding[*c - 'a']++;
            }


            // vector<int> -> string
            std::stringstream result;
            std::copy(encoding.begin(), encoding.end(), std::ostream_iterator<int>(result, "-"));
            std::string s = result.str();
            s = s.substr(0, s.length()-1); // get rid of trailing -

            if (map.find(s) == map.end()){
                map[s] = {x};
            } else {
                map[s].push_back(x);
            }


        }

        std::vector<std::vector<std::string>> result;

        for (auto key_value: map){
            result.push_back(key_value.second);

        }

        return result;
    }
};