#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int, vector<int>> q;

    for (int i = 0; i < n; i++){
        int command;
        cin >> command;

        if (command == 1){
            int max = q.top();
            q.pop();

            cout << max << '\n';
        } else {
            int value;
            cin >> value;
            q.push(value);
        }
    }
}