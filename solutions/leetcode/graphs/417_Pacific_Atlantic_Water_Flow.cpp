class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        // check how water can flow to atlantic ocean, but backwards, and then to pacific

        for (int i = 0; i < m; i++){
            dfs(heights, atlantic, i, n - 1);
            dfs(heights, pacific, i, 0);
        }

        for (int j = 0; j < n; j++){
            dfs(heights, atlantic, m - 1, j);
            dfs(heights, pacific, 0, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (atlantic[i][j] && pacific[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
private:
    int m, n;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j){

        ocean[i][j] = true;

        if (i > 0 && !ocean[i - 1][j] && heights[i][j] <= heights[i-1][j]){
            dfs(heights, ocean, i - 1, j);
        }

        if (i < m - 1 && !ocean[i + 1][j] && heights[i][j] <= heights[i+1][j]){
            dfs(heights, ocean, i + 1, j);
        }

        if (j > 0 && !ocean[i][j - 1] &&heights[i][j] <= heights[i][j - 1]){
            dfs(heights, ocean, i, j - 1);
        }

        if (j < n - 1 && !ocean[i][j + 1] &&heights[i][j] <= heights[i][j + 1]){
            dfs(heights, ocean, i, j + 1);
        }
    }

};