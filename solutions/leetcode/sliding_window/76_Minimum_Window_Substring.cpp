#include <string>
#include <unordered_map>

using std::string;

typedef std::unordered_map<char, int> string_dict;

class Solution {
public:
    string minWindow(string s, string t) {
        const int MAX_LENGTH = 100000;

        string_dict s_dict, t_dict;
        int correct = 0, left = 0;

        int min_substring_start_index = 0;
        int min_substring_length = MAX_LENGTH;

        for (char x: t){
            t_dict[x]++;
            s_dict[x] = 0;
        }


        for (int right = 0; right < s.size(); right++){
            char s_right = s[right];

            if (t_dict.find(s_right) == t_dict.end()){ // s[right] is not presented in t ==> move on
                continue;
            }

            s_dict[s_right]++;

            if (t_dict[s_right] >= s_dict[s_right]){ // s_right is presented less then or equal times in a given substring s[left, right] than in t ==> increment counter
                correct++;
            }
            if (correct == t.size()){

                while (correct == t.size() && left <= right){ // try to reduce the size of a correct substring - move left pointer
                    char s_left = s[left++];

                    if (t_dict.find(s_left) == t_dict.end()){
                        continue;
                    }
                    s_dict[s_left]--;
                    if (s_dict[s_left] < t_dict[s_left]){ //letter s_left is now represented less times in a reduced substring s[left+1, right] than in t
                        correct--;
                    }
                }

                int correct_substring_length = right - left + 2; // works even in single-letter t : because in this case left will be = right + 1 ==> length = right - right - 1 + 2 = 1 !! :)

                if (correct_substring_length < min_substring_length){
                    min_substring_length = correct_substring_length;
                    min_substring_start_index = left - 1;
                }


            }
        
        }

        if (min_substring_length < MAX_LENGTH){
            return s.substr(min_substring_start_index, min_substring_length);
        }

        return "";


    }
};