#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using std::vector;
using std::stack;
using std::pair;
using std::max;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        stack<pair<int, int>> left_stack, right_stack;
        vector<int> result;

        left_stack.push({nums[0], nums[0]});

        for (int i = 1; i < k; i++){
            left_stack.push({nums[i], max({left_stack.top().second, nums[i]})});
        }

        result.push_back(left_stack.top().second);

        for (int x, max_k, i=k; i < nums.size(); i++){
            x = nums[i];
            
            if (left_stack.size() < k){
                left_stack.push({x, max({x, left_stack.top().second})});
            } else {
                fill_right_stack_in_reverse_order(left_stack, right_stack);
                left_stack.push({x, x});
            }

            if (!right_stack.empty()){
                max_k = max({left_stack.top().second, right_stack.top().second});
                right_stack.pop();
            } else {
                max_k = left_stack.top().second;
            }

            result.push_back(max_k);
        }


        return result;
    }

private:
    void fill_right_stack_in_reverse_order(stack<pair<int, int>>& left, stack<pair<int, int>>& right){
        right.push({left.top().first, left.top().first});

        left.pop();

        while (!left.empty()){
            right.push({left.top().first, max({left.top().first, right.top().second})});
            left.pop();
        }
        if (!left.empty()){
            left.pop();
        }

        right.pop();
    }

};