class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        connected_components = 0, m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    connected_components++;
                    dfs(grid, i, j);
                }
            }
        }

        return connected_components;

    }
private:
    int connected_components, n, m;
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if (i < 0 ||i >= m || j < 0 || j >= n || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);

    }
};