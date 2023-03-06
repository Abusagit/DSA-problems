class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        create_graph(numCourses, prerequisites);

        for (int i = 0; i < numCourses; i++){
            if (!dfs(i)){
                return {};
            }
        }

        for (int i = 0; i < numCourses / 2; i++){
            swap(result[i], result[numCourses - i - 1]);
        }

        return result;
    }
private:
    vector<char> color;
    unordered_map<int, vector<int>> neighbors;

    vector<int> result;

    bool dfs(int vertex){
        if (color[vertex] == 'B'){
            return true;
        }
        color[vertex] = 'G';

        bool no_circles = true;
        for (int neighbor: neighbors[vertex]){
            if (color[neighbor] == 'W'){
                no_circles = no_circles && dfs(neighbor);
            } else if (color[neighbor] == 'G'){
                no_circles = false;
                break;
            }
        }

        color[vertex] = 'B';
        result.push_back(vertex);

        return no_circles;
    }

    void create_graph(int numCourses, vector<vector<int>>& prerequisites){
        color.assign(numCourses, 'W');

        for (auto edge: prerequisites){
            int from = edge[1], to = edge[0];

            if (neighbors.find(from) != neighbors.end()){
                neighbors[from].push_back(to);
            } else {
                neighbors[from] = {to};
            }
        }
    }
};