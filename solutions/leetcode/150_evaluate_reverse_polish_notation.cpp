#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<long long> calc;
        long long result, n1, n2;
        
        for (std::string x: tokens){
            if ((x!="+" && x !="-" && x !="/" && x !="*")){
                calc.push(stoi(x));
                continue;
            }
            
            
            n2 = calc.top();
            calc.pop();
            
            n1 = calc.top(); // leftmost element has been pushed earlier ==> ejected later
            calc.pop();
            
            if (x == "+"){
                result = n1 + n2;
            } else if (x == "-"){
                result = n1 - n2;
            } else if (x == "*"){
                result = n1 * n2;
            } else {
                result = n1 / n2;
            }
            calc.push(result);
            
        }
        
        return calc.top();
        }
    };