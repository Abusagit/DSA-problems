#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
// pq with items {cost, m flights between points, destination_to_point}
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        for (auto flight: flights){
            m[flight[0]][flight[1]] = flight[2];
        }

        // vector<bool> visited(n, false);
        // visited[src] = true;

        vector<int> distance(n, INF);
        distance[src] = 0;

        vector<int> stops(n, INF);
        distance[src] = 0;

        pq.push({0, 0, src});

        while (!pq.empty()){
            auto current = pq.top();
            pq.pop();

            int cur_cost = current[0], cur_stops = current[1], cur_destination = current[2];
            
            if (cur_destination == dst){
                return cur_cost;
            }
            if (cur_stops > k){
                continue;
            }
            // cout << cur_cost << " " << cur_stops << " " << cur_destination << endl;



            for (auto neighbor_cost: m[cur_destination]){

                int neighbor = neighbor_cost.first;
                int cost_to_neighbor = neighbor_cost.second;

                int neighbor_distance = distance[neighbor];
                int neighbor_stops = stops[neighbor];

                // check if can improve cost
                if (neighbor_distance > cost_to_neighbor + cur_cost || cur_stops + 1 < stops[neighbor]){

                    stops[neighbor] = cur_stops;
                    distance[neighbor] = cost_to_neighbor + cur_cost;

                    pq.push({cost_to_neighbor + cur_cost, cur_stops + 1, neighbor});

                } else if (neighbor_stops > cur_stops){
                    pq.push({cost_to_neighbor + cur_cost, cur_stops + 1, neighbor});
                }

                stops[neighbor] = cur_stops;

            }

        }

        // return -1;

        return (distance[dst] < INF) ? distance[dst] : -1;

    }
private:
    unordered_map<int, unordered_map<int, int> > m;
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
    const int INF = 100000000;

};