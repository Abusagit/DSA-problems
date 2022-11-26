#include <stack>
#include <string>
#include <iostream>

#define int long long int

using namespace std;

signed main(){

    
    ios_base::sync_with_stdio(false);

    stack<int> calc;
    int n1, n2, result;

    string character;
    while (cin >> character){
        if ((character!="+" && character !="-" && character !="/" && character !="*")){
                calc.push(static_cast<int>(stoi(character))); // int to long long int

                continue;
            }
        n2 = calc.top();
        calc.pop();
        
        n1 = calc.top(); // leftmost element has been pushed earlier ==> ejected later
        calc.pop();
        
        if (character == "+"){
            result = n1 + n2;
        } else if (character == "-"){
            result = n1 - n2;
        } else if (character == "*"){
            result = n1 * n2;
        } else {
            result = n1 / n2;
        }
        calc.push(result);
    
    }

    cout << calc.top() << '\n';
}