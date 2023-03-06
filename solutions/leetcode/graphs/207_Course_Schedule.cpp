class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        create_graph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++){
            bool no_circles = dfs(i);

            if (!no_circles){
                return false;
            }
        }



        return true;
    }
private:
    vector<char> color;
    unordered_map<int, vector<int>> neighbors;

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


    bool found_circle(int vertex){

        if (color[vertex] == 'B'){
            return false;
        }

        color[vertex] = 'G';

        bool found = false;

        for (int neighbor: neighbors[vertex]){

            if (color[neighbor] == 'W'){
                found = found || found_circle(neighbor);

            } else if (color[neighbor] == 'G'){
                found = true;
                
                break;
            }
        }

        color[vertex] = 'B';

        return no_circles;
    }

};