#include <string>

class Solution {
public:
    bool isValid(string s) {
        std::stack<int> stack;
        std::unordered_map<char, char> complement = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        
        
        for (auto x: s){
            if (x == '(' || x == '['|| x == '{'){
                stack.push(x);
            } else if (stack.empty()){
                return false;
            } else if (stack.top() == complement[x]){
                stack.pop();
            } else {
                return false;
            }
        }
        
        if (stack.empty()){
            return true;
        } else {
            return false;
        }
        
    }
};