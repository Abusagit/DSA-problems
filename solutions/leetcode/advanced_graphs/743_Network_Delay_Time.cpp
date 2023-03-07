#include <vector>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int> >& times, int n, int k) {
        time.resize(n + 1, INT_MAX);
        time[k] = 0;

        //visited.resize(n + 1, false);

        for (auto tup: times){
            int from = tup[0], to = tup[1], time = tup[2];
            graph[from][to] = time;
        }


        queue<int> q;
        q.push(k);

        while (!q.empty()){
            int source = q.front();
            q.pop();

            for (auto destination_weight: graph[source]){
                int destination = destination_weight.first, weight = destination_weight.second;

                //time[destination] = min(time[destination], time[source] + weight);
                //cout << time[destination] << endl;
                if (time[source] + weight < time[destination]){
                    time[destination] = time[source] + weight;
                    q.push(destination);
                }

            }

        }

        int max_time = *max_element(time.begin() + 1, time.end()); // get max element
        return (max_time < INT32_MAX) ? max_time : -1;

    }
private:
    unordered_map<int, unordered_map<int, int> > graph;

    vector<int> time;
    //vector<bool> visited;
};