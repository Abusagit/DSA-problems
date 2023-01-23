#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int, std::vector<int>> min_q(stones.begin(), stones.end()); // construct max_heap queue

        while (min_q.size() > 1){
            int y = min_q.top();
            min_q.pop();
            int x = min_q.top();
            min_q.pop();

            if (y != x){
                min_q.push(y - x);
            }
        }

        if (!min_q.empty()){
            return min_q.top();
        }
        return 0;
    }
};
