#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        using namespace std;
        int left = 0;
        int right = s.size() -1;
        
        while (left < right){
            
            if (!iswalnum(s[left])){
                left++;
                continue;
                
                }
            if (!iswalnum(s[right])){
                right--;
                continue;
                }
            
            if (tolower(s[left++]) != tolower(s[right--])){
                return false;
                }
            
    }
        
        return true;
        }
};