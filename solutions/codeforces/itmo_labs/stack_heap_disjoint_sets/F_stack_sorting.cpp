#include <vector>
#include <iostream>
#include <deque>
#include <stack>
#include <string>
#include <utility>

using namespace std;

#define DUMMY 1000000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    deque<int> stack_A;
    // stack<pair<int, int>> stack_B;
    stack<int> stack_B;

    vector<string> commands;

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        stack_A.push_back(x);
    }

    // stack_B.push({DUMMY, DUMMY});

    stack_B.push(DUMMY);

    int last_printed = -DUMMY;

    while (!stack_A.empty()){

        int A_top = stack_A.front();
        int B_top = stack_B.top();

        // cout << A_top << " " << B_top << '\n';
        if (A_top <= B_top){ // current min in stack B

            if (A_top >= last_printed){
                commands.push_back("push");
                stack_A.pop_front();
                stack_B.push(A_top);
            } else {
                cout << "impossible\n";
                return 0;
            }

        } else {
            commands.push_back("pop");
            stack_B.pop();
            last_printed = B_top;
        }

    }

    for (auto command: commands){
        cout << command << '\n';
    }

    for (int i = 0; i < stack_B.size() - 1; i++){
        cout << "pop\n";
    }

    return 0;
}