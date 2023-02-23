class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int top_row = 0, bottom_row = matrix.size() - 1;
        int left_col = 0, right_col = matrix[0].size() - 1;

        while (top_row <= bottom_row && left_col <= right_col){
            for (int j = left_col; j <= right_col; j++){
                result.push_back(matrix[top_row][j]);
            }
            top_row++;

            for (int i = top_row; i <= bottom_row; i++){
                result.push_back(matrix[i][right_col]);
            }
            right_col--;

            if (top_row <= bottom_row){ // want to go left
                for (int j = right_col; j >= left_col; j--){
                    result.push_back(matrix[bottom_row][j]);
                }
            }
            bottom_row--;

            if (left_col <= right_col){ // want to go up
                for (int i = bottom_row; i >= top_row; i--){
                    result.push_back(matrix[i][left_col]);
                }
            }
            left_col++;


        }
        return result;
    }
};