class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0]){    
                    if (dfs(board, word, i, j, 0)){
                        return true;
                    }
                }   
            }
        }

        return false;
    }
private:
    int m, n;
    char MASK = '#';

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int current_letter_index){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[current_letter_index]){
            return false;
        }

        if (current_letter_index == word.size() - 1){
            return true;
        }

        // mask letter for preventing loops:
        board[i][j] = MASK;

        if (dfs(board, word, i, j + 1, current_letter_index + 1) || 
            dfs(board, word, i, j - 1, current_letter_index + 1) ||
            dfs(board, word, i + 1, j, current_letter_index + 1) ||
            dfs(board, word, i - 1, j, current_letter_index + 1)){
                return true;
            }


        //unmask for next searches
        board[i][j] = word[current_letter_index];

        return false;
    }
    
};