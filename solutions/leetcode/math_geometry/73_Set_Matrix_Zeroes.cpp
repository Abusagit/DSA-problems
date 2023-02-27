class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<bool> rows_to_zero_out(m, false);
        vector<bool> cols_to_zero_out(n, false);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    rows_to_zero_out[i] = true;
                    cols_to_zero_out[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++){
            if (rows_to_zero_out[i]){
                matrix[i].assign(n, 0);
            }
        }

        for (int j = 0; j < n; j++){
            if (cols_to_zero_out[j]){
                for (int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};