class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        n = edges.size();
        create_graph(edges);

        dfs(1, 1);

        return edges[edge_order.top()];
    }
private:
    int n;
    vector<char> color;
    unordered_map<int, vector<int>> neighbors;
    unordered_map<int, unordered_map<int, int>> order;
    priority_queue<int, vector<int>> edge_order;

    void create_graph(vector<vector<int>>& edges){
        color.resize(n + 1, 'W');
        for (int i = 0; i < n; i++){
            int u = edges[i][0], v = edges[i][1];

            order[u][v] = i;
            order[v][u] = i;

            neighbors[u].push_back(v);
            neighbors[v].push_back(u);
 
        }
    }

    int dfs(int vertex, int prev){
        if (color[vertex] == 'G'){
            cout << vertex << endl;
            return vertex;
        }

        color[vertex] = 'G';

        // bool found_circle = false;

        for (int neighbor: neighbors[vertex]){
            if (neighbor == prev){
                continue;
            }

            int v = dfs(neighbor, vertex);

            if (v != -1 && v != vertex){
                // cout << vertex << ' ' << neighbor << endl;
                edge_order.push(order[neighbor][vertex]);
                return v;
            }

            if (v == vertex){
                break;
            }
            // if (dfs(neighbor, vertex)){
            //     cout << vertex << ' ' << neighbor << endl;
            //     edge_order.push(order[neighbor][vertex]);
            //     return true;
            // }
        }

        color[vertex] = 'B';
        return -1;
    }
};