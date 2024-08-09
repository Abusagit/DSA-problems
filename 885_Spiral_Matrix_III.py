from typing import List

class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        
        def is_cell_in_bounds_and_not_all_visited(i, j):
            return all((
                i >= 0, i < rows, j >= 0, j < cols, self.number_of_visited < self.N
            ))
            
        
        
        self.result: List[List[int]] = [[rStart, cStart]]
        i = rStart
        j = cStart
        
        self.number_of_visited = 1
        self.N = rows * cols
        
        k = 1
        while self.number_of_visited < self.N:
            
            ## right. offset == 2k-1
            for step in range(2 * k - 1):
                j += 1
                
                if is_cell_in_bounds_and_not_all_visited(i, j):
                    self.add_to_result_and_update_counter(i, j)
                
            ## down. offset == 2k-1

            for step in range(2 * k - 1):
                i += 1
                if is_cell_in_bounds_and_not_all_visited(i, j):
                    self.add_to_result_and_update_counter(i, j)

                
            ## left. offset == 2k
            for step in range(2 * k):
                j -= 1
                if is_cell_in_bounds_and_not_all_visited(i, j):
                    self.add_to_result_and_update_counter(i, j)
            ## up. offset == 2k
            for step in range(2*k):
                i -= 1
                if is_cell_in_bounds_and_not_all_visited(i, j):
                    self.add_to_result_and_update_counter(i, j)
            
            k += 1
        
        return self.result
    
    
    def add_to_result_and_update_counter(self, i, j):
        self.result.append([i, j])
        self.number_of_visited += 1