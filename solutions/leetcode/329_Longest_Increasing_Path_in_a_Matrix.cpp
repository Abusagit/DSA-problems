class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();

        longest_path.assign(rows, vector<int>(cols, -1));
        // for (int i = 0; i < rows; i++){
        //     for (int j = 0; j < cols; j++){
        //         cout << longest_path[i][j];
        //     }
        // }

        int max_len = 1;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                max_len = max(max_len, dfs(i, j, -1, matrix));
            }
        }

        return max_len;
    }
private:
    vector<vector<int>> longest_path;
    int cols, rows;


    int dfs(int i, int j, int prev_value, vector<vector<int>>& matrix){
        if (i < 0 || i >= rows || j < 0 || j >= cols){
            return 0;
        }

        if (matrix[i][j] <= prev_value){
            return 0;
        }

        if (longest_path[i][j] != -1){
            return longest_path[i][j];;
        }

        int current = matrix[i][j];

        longest_path[i][j] = 1 + max({dfs(i - 1, j, current, matrix),
                                      dfs(i + 1, j, current, matrix),
                                      dfs(i, j - 1, current, matrix),
                                      dfs(i, j + 1, current, matrix)});
        
        return longest_path[i][j];

        
    }
};