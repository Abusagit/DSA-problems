#include <string>
#include <vector>
#include <iostream>

class Solution {

public:
    std::vector<std::string> generateParenthesis(int n){
        this-> n = n;
        std::vector<std::string> result;
        generate_valid(0, 0, result, "");
        
        return result;
    }
private:
    int n;
    void generate_valid(unsigned opened, unsigned closed, std::vector<std::string> & res, std::string s){
        if (opened == this->n && closed == this->n){
            res.push_back(s);
            return;
        }

        if (opened < this->n){
            generate_valid(opened + 1, closed, res, s + '(');
            }
        if (opened > closed){
            generate_valid(opened, closed + 1, res, s + ')');
            
        }
    }
};

int main(){
    int n;
    std::cin >> n;

    Solution s;

    std::vector<std::string> v = s.generateParenthesis(n);

    for (std::vector<std::string>::iterator it=v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }

    return 0;
}

main();