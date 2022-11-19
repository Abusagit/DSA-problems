#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>

using namespace std;

typedef pair<int, int> val_cooldown_pair;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        //count tasks types:

        for (char x: tasks){
            counter[x - 65]++;
        }

        // push non-zero values to max_heap
        for (int x: counter){
            if (x > 0){
                max_heap.push(x);
            }
        }

        int time = 0;

        while (!max_heap.empty() || !cooldown_queue.empty()){

            if (max_heap.empty()){
                max_heap.push(cooldown_queue.front().first);
                time = cooldown_queue.front().second;
                cooldown_queue.pop();
            }

            // max_heap has at least 1 element

            int remained_times_from_most_frequent_task = max_heap.top() - 1;
            max_heap.pop();

            time++;

            if (remained_times_from_most_frequent_task > 0){
                cooldown_queue.push({remained_times_from_most_frequent_task, time + n});
            }

            if (cooldown_queue.front().second == time){
                max_heap.push(cooldown_queue.front().first);
                cooldown_queue.pop();
            }
        
        }

        return time;
    }
private:
    priority_queue<int> max_heap;
    queue<val_cooldown_pair> cooldown_queue;

    vector<int> counter = vector<int>(26, 0);
};