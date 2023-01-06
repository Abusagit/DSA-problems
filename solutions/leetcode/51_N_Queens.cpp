class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> board(n, string(n, '.'));

        backtrack(board, 0);
        return res;
    }
private:
    unordered_set<int> pos_diag, neg_diag, cols;
    vector<vector<string>> res;
    int n;

    void backtrack(vector<string>& board, int row){ //backtrack by rows - b.c. every queen should be placed at each row
        if (row == n){ // we got to n-th row ==> placed every queen
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++){
            if (cols.find(col) != cols.end()               || 
                pos_diag.find(row + col) != pos_diag.end() || 
                neg_diag.find(row - col) != neg_diag.end()    ){
                    continue;
            }

            board[row][col] = 'Q';

            cols.insert(col);
            pos_diag.insert(row + col);
            neg_diag.insert(row - col);

            backtrack(board, row + 1);

            cols.erase(col);
            pos_diag.erase(row + col);
            neg_diag.erase(row - col);


            board[row][col] = '.';

        }

    }
};