#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;


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
            int j = 1;
            for(;std::isdigit(str[i+j]);j++){}

            int substring_len = std::stoi(str.substr(i, i+j));

            string s = str.substr(i+j+delim_size, i+j+substring_len+delim_size);

            result.push_back(s);
            i += j + substring_len + delim_size;
        }

        return result;
    }
private:
    string delim = "@";

};
