#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// MST Prim`s algorithm



using namespace std;

class Solution {

public:
    int minCostConnectPoints(vector<vector<int> >& points) {
        int root = 0;
        int n = points.size();
        const int INF = 1000000000;

        connected.resize(n, false);
        // connected[0] = true;

        distance_to_root.resize(n, INF);
        distance_to_root[root] = 0;

        int MINcost = 0;
        int nodes_connected = 0;

        while (nodes_connected < n){
            int current_min_edge = INF;
            int current_node = -1;

            for (int i = 0; i < n; i++){
                if (!connected[i] && current_min_edge > distance_to_root[i]){
                    current_min_edge = distance_to_root[i];
                    current_node = i;
                }
            }

            MINcost += current_min_edge;
            connected[current_node] = true;

            //update

            for (int i = 0; i < n; i++){
                int cost = dist(current_node, i, points);

                if (!connected[i] && cost < distance_to_root[i]){
                    distance_to_root[i] = cost;
                }
            }

            nodes_connected++;

        }

        return MINcost;
    }
private:
    vector<bool> connected;
    vector<int> distance_to_root;

    int dist(int i, int j, vector<vector<int> >& points){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
};