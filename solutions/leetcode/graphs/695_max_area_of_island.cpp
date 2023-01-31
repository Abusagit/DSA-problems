class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max_area = 0, m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                max_area = max(max_area, dfs(grid, i, j, 0));
            }
        }


        return max_area;
    }
private:
    int max_area, m, n;
    
    int dfs(vector<vector<int>>& grid, int i, int j, int current_area){
        if (i < 0 ||i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return 0;
        }

        grid[i][j] = 0;
        int area = 1 + dfs(grid, i - 1, j, 0) + dfs(grid, i, j - 1, 0) + dfs(grid, i + 1, j, 0) + dfs(grid, i, j + 1, 0);

        return current_area + area;

    }
};