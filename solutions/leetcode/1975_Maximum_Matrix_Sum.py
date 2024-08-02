from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        
        matrix_abs_sum = 0
        
        num_of_negatives = 0
        smallest_abs_value = float("inf")
        for row in matrix:
            for x in row:
                if x < 0:
                    num_of_negatives += 1
                
                abs_x = abs(x)
                
                matrix_abs_sum += abs_x
                smallest_abs_value = min(smallest_abs_value, abs_x)
                
        
        if num_of_negatives % 2 == 0:
            return matrix_abs_sum
        
        # subtract it twice b.c. we included it in the absolute sum once and then we actually subtract it, b.c. it's still negative after all
        return matrix_abs_sum - 2 * smallest_abs_value 