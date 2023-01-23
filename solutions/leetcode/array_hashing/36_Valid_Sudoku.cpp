// O(n^2) - n - size of Sudoku board

#include <vector>
#include <unordered_map>
#include <unordered_set>

typedef std::unordered_map<int, std::unordered_set<char>> one_line_map;

using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        one_line_map row_map;
        one_line_map col_map;
        one_line_map quadrants;

        for (int n=board.size(), i=0; i < n; i++){
            for (int j=0; j < n; j++){
                int quadrant_id = 3 * (i / 3) + (j / 3); // converts quadrants to linear array from upper left to down right order
                char x = board[i][j];

                if (x == '.'){
                    continue;
                }

                if (!(check_valid_and_insert_to_map(row_map, x, i) && check_valid_and_insert_to_map(col_map, x, j) && check_valid_and_insert_to_map(quadrants, x, quadrant_id))){
                    return false;
                }

            }
        }
        
        return true;
    }

private:
    bool check_valid_and_insert_to_map(one_line_map& map, char x, int id){
        if (map[id].find(x) != map[id].end()){//item is already in the row/col/quadrant
            return false;
        } else {
            map[id].insert(x);
        }
        return true;
    }
};