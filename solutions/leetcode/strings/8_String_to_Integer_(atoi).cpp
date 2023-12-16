#include <string>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {

        int i = 0, base = 0, sign = 1;;

        while (i < s.size() && s[i] == ' '){
            i++;
        }

        if (i >= s.size()){
            return 0;
        }


        if (s[i] == '-'){
            sign = -1;
            i++;
        } else if(s[i] == '+'){
            i++;
        }

        while (i < s.size() && (s[i] >= '0' && s[i] <= '9')){

            int value = s[i++] - '0';
            
            // check for positive and negative overflow
            if (base > 214748364 || (base == 214748364 && value > 7)){
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            base = 10 * base + value;

        }

        return sign * base;

    }
};