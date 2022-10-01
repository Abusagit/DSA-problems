#include <string>
#include <unordered_map>
#include <vector>


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()){
            return false;
        }


        std::unordered_map<char, int> map_s, map_t;

        for (int i=0; i < s.size(); i++){
        increment_counter(map_s, s[i]);
        increment_counter(map_t, t[i]);
            
        }

        // traversing elements:
        for (auto key_value: map_t){
            char character = key_value.first;
            int count = key_value.second;

            if (map_s.find(character) == map_s.end()){
                return false;
            }

            if (map_s[character] != count){
                return false;
            }


        }

        for (auto key_value: map_s){
            char character = key_value.first;
            int count = key_value.second;

            if (map_t.find(character) == map_t.end()){
                return false;
            }

            if (map_t[character] != count){
                return false;
            }


        }
        


        return true;

    }

    bool isAnagram_2(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        std::vector<int> count(26);
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        for (int j = 0; j < t.size(); j++) {
            count[t[j] - 'a']--;
            if (count[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }

private:

    void increment_counter(std::unordered_map<char, int> & map, char x){
        if (map.find(x) == map.end()){ // x is not found;
            map[x] = 1;
        } else {
            map[x] += 1;
        }
    }
    
};