#include <iostream>
#include <stdio.h>
#include <stack>
#include <utility>
#include <algorithm>


#define MAX 1000000001

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    stack<pair<int, int>> min_stack;

    min_stack.push({MAX, MAX});


    for (int i = 0; i < n; i++){
        int command;
        scanf("%d", &command);

        if (command == 1){
            int k;

            scanf("%d", &k);
            min_stack.push({k, min(k, min_stack.top().second)});
        } else if (command == 2){
            min_stack.pop();
        } else {
            printf("%d\n", min_stack.top().second);
        }
    }

    return 0;
}