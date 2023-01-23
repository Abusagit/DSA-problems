#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::vector;
using std::get;
using std::max;

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> frequency;

        // want to keep all characters in a window length N the same as the most frequent character: N - frequency[most] <= k --> N <= k + frequency[most] <= k + max_frequency --> maximize max_frequency

        int max_length = 0;

        int left = 0;
        int max_frequency = 0;

        for (int right=0; right < s.size(); right++){ // for each right pointer value calculate valid window size and keep maximum
            frequency[s[right]]++;
            max_frequency = max({max_frequency, frequency[s[right]]});

            while (((right - left + 1) - max_frequency ) > k){
                frequency[s[left]]--; //keep contracting window until condition is valid
                left++;
            }


            max_length = max({max_length, right - left + 1});
            
        }

        return max_length;

    }
};




// typedef std::vector<std::tuple<int, int>> vector_of_tuples;
// typedef std::unordered_map<char, vector_of_tuples> char_substrings;


//
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         char_substrings char_substrings;

//         fill_dict(char_substrings, s);

//         int max_adjusted_length = 0;

//         for (auto key_value: char_substrings){

//             vector_of_tuples v = key_value.second;

//             std::sort(v.begin(), v.end());

//             int remained = k;
//             int current_length = -get<0>(v[0]); //max length as default max_length

//             for (int i=1; i<v.size(); i++ ){

//                 if (get<1>(v[i]) < get<1>(v[i-1])){ //next repeat is shorter and further from start
//                     int distance = get<1>(v[i]) + (get<0>(v[i-1]) + get<1>(v[i-1])); // asdasdasdasd
//                     if (distance <= remained){
//                         current_length = max({current_length, current_length})
//                     }
//                 } else {

//                 }
            
//             }



        
//         }


//     }

// private:

//     void fill_dict(char_substrings& v, string s){

//         int start = 0;
//         char current_char = s[0];

//         for (int i = 1; i < s.size(); i++){
//             if (s[i] != current_char){
//                 v[current_char].push_back({start - i, start});
//                 current_char = s[i];
//                 start = i;
//             }
//         }

//         v[current_char].push_back({static_cast<int>(start - s.size()), start}); // {start, -length [for sorting purposes]}
//     }
// };