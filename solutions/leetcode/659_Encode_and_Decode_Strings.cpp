#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;

// Time: O(n)
// Space: O(1)
class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        vector<string> encoded;

        for (auto s: strs){
            encoded.push_back(std::to_string(s.size()));
            encoded.push_back(this->delim);
            encoded.push_back(s);
        }

        std::stringstream result;
        std::copy(encoded.begin(), encoded.end(), std::ostream_iterator<string>(result, ""));
        string s = result.str();
        s = s.substr(0, s.length()-1); // get rid of trailing -

        return s;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> result;

        int delim_size = (this->delim).size();
        
        int i = 0;

        while (i < str.size()){
            int j = i + 1;
            for(; !std::isdigit(str[j]) ;j++){}

            int substring_len = std::stoi(str.substr(i, j - i)); // substring from index i with length j - i

            string s = str.substr(j + 1, substring_len);

            result.push_back(s);
            i += j + substring_len + delim_size;
        }

        return result;
    }
private:
    string delim = "@";

};
