from typing import List, MutableSet, Dict
from collections import defaultdict

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.grid = grid
        
        self.col1_sum = 0
        self.col2_sum = 0
        self.col3_sum = 0
        self.row1_sum = 0
        self.row2_sum = 0
        self.row3_sum = 0
        self.main_diag_sum = 0
        self.submain_diag_sum = 0

        if self.rows < 3 or self.cols < 3:
            return 0
        
        self.sliding_window_elements_counter: Dict[int, int] = defaultdict(int)
        
        max_magic_squares = 0
                
        for row_idx_start in range(self.rows - 3 + 1):
            self._initialize_sliding_box(row_start_index=row_idx_start, col_start_index=0)
            max_magic_squares += self._check_box_for_magic()
            print(f"{row_idx_start=} col_idx_start=0 \n{self.col1_sum=}\n{self.col2_sum=}\n{self.col3_sum=}\n{self.row1_sum=}\n{self.row2_sum=}\n{self.row3_sum=}\n{self.main_diag_sum=}\n{self.submain_diag_sum=}")
            
            for col_idx_start in range(1, self.cols - 3 + 1):
                
                
                self._update_sliding_box_after_right_shift(row=row_idx_start, new_col_start_index=col_idx_start)
                print(f"{row_idx_start=} {col_idx_start=} \n{self.col1_sum=}\n{self.col2_sum=}\n{self.col3_sum=}\n{self.row1_sum=}\n{self.row2_sum=}\n{self.row3_sum=}\n{self.main_diag_sum=}\n{self.submain_diag_sum=}")
                max_magic_squares += self._check_box_for_magic()
                

        return max_magic_squares
    
    def _check_box_for_magic(self) -> bool:
        """
        self.sliding_box_contains == {1, 2, 3, 4, 5, 6, 7, 8, 9}
        """
        
        all_sums_equal = self.col1_sum == self.col2_sum == self.col3_sum == self.row1_sum == self.row2_sum == self.row3_sum == self.main_diag_sum == self.submain_diag_sum

        all_values_are_distinct = all([self.sliding_window_elements_counter[x] == 1 for x in range(1, 9 + 1)])
        
        
        
        return all_sums_equal and all_values_are_distinct
    
    def _update_sliding_box_after_right_shift(self, row: int, new_col_start_index: int) -> None:
        col_to_remove = new_col_start_index - 1
        col_to_add = new_col_start_index + 3 - 1
        
        elements_to_remove = [self.grid[row+i][col_to_remove] for i in range(3)]
        elements_to_add = [self.grid[row+i][col_to_add] for i in range(3)]
                
        for e_to_remove in elements_to_remove:
            self.sliding_window_elements_counter[e_to_remove] -= 1
        
        for e_to_add in elements_to_add:
            self.sliding_window_elements_counter[e_to_add] += 1

        # update all sums
        self.row1_sum = self.row1_sum - elements_to_remove[0] + elements_to_add[0]
        self.row2_sum = self.row2_sum - elements_to_remove[1] + elements_to_add[1]
        self.row3_sum = self.row3_sum - elements_to_remove[2] + elements_to_add[2]
        
        self.col1_sum, self.col2_sum, self.col3_sum = self.col2_sum, self.col3_sum, sum(elements_to_add)
        
        self.main_diag_sum = self.grid[row][new_col_start_index] + self.grid[row+1][new_col_start_index+1] + self.grid[row+2][new_col_start_index+2]
        self.submain_diag_sum = self.grid[row+2][new_col_start_index] + self.grid[row+1][new_col_start_index+1] + self.grid[row][new_col_start_index+2]


    def _initialize_sliding_box(self, row_start_index, col_start_index) -> None:
        
        rows_sums = [0, 0, 0]
        cols_sums = [0, 0, 0]
        
        self.main_diag_sum = self.grid[row_start_index][col_start_index] + self.grid[row_start_index+1][col_start_index+1] + self.grid[row_start_index+2][col_start_index+2]
        self.submain_diag_sum = self.grid[row_start_index+2][col_start_index] + self.grid[row_start_index+1][col_start_index+1] + self.grid[row_start_index][col_start_index+2]
        
        self.sliding_window_elements_counter: Dict[int, int] = defaultdict(int)

        for i in range(3):
            for j in range(3):
                x = self.grid[row_start_index + i][col_start_index + j]
                
                self.sliding_window_elements_counter[x] += 1
                
                rows_sums[i] += x
                cols_sums[j] += x

        self.row1_sum, self.row2_sum, self.row3_sum = rows_sums
        self.col1_sum, self.col2_sum, self.col3_sum = cols_sums