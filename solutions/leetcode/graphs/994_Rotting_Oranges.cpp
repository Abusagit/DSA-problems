class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        min_rot_time.assign(m, vector<int>(n, MAX));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    queue<pair<pair<int, int>, int>> q;

                    q.push({{i, j}, 0});

                    while (!q.empty()){
                        auto xyt = q.front();
                        q.pop();

                        bfs(grid, xyt.first.first, xyt.first.second, xyt.second, q);
                    }
                    
                }
            }
        }

        int maxmin = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n;j++){
                cout << min_rot_time[i][j] << ' ';
                if (grid[i][j] == 1){
                    maxmin = max(maxmin, min_rot_time[i][j]);
                }
            }
            cout << endl;
        }

        return (maxmin == MAX)? -1 : maxmin;
    }
private:
    const int MAX = 1000;
    int m, n;
    vector<vector<int>> min_rot_time;
    bool out_of_bounds(int i, int j){
        return i < 0 || i >= m || j < 0 || j >= n;
    }

    void bfs(vector<vector<int>>& grid, int i, int j, int time, queue<pair<pair<int, int>, int>>& q){
        if (out_of_bounds(i, j) || grid[i][j] == 0 || min_rot_time[i][j] < time + 1){
            return;
        }

        min_rot_time[i][j] = time;

        q.push({{i - 1, j}, time + 1});
        q.push({{i + 1, j}, time + 1});
        q.push({{i, j - 1}, time + 1});
        q.push({{i, j + 1}, time + 1});
        return;
    }
};