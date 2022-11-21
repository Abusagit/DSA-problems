#include <iostream>
#include <stdio.h>
#include <stack>
#include <utility>
#include <algorithm>


#define DUMMY -1

using namespace std;


void clean_top_of_stack(stack<pair<int,int>>& stack, int times){
    for (int i = 0; i < times; i++){
        stack.pop();
    }
}

int main(){

    int n = 0;

    stack<pair<int, int>> stack;

    stack.push({DUMMY, 0});

    int k;

    while (scanf("%d", &k) == 1){
        pair<int, int> top = stack.top();

        if (k == top.first){
            stack.push({k, top.second + 1});
            continue;
        } else if (top.second >= 3){
            n += top.second;

            clean_top_of_stack(stack, top.second);

            if (stack.top().first == k){
                stack.push({k, stack.top().second + 1});
                continue;
            }
        }

        stack.push({k, 1});
    }

    if (stack.top().second >= 3){
        n += stack.top().second;
    }

    printf("%d\n", n);

    return 0;
}