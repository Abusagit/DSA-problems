"""
Maintain running minimum and maximum. 
For each array, we need only the last and the first values, as they produce the largest distances with previous arrays.

"""

from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        INF = 999_999_999
        
        current_max_before_current_array = -INF
        current_min_before_current_array = INF
        
        result = 0
        
        for arr in arrays:
            array_min, array_max = arr[0], arr[-1]
            
            
            result = max(result, 
                         current_max_before_current_array - array_min, 
                         array_max - current_min_before_current_array)
            
            current_max_before_current_array = max(current_max_before_current_array, array_max)
            current_min_before_current_array = min(current_min_before_current_array, array_min)
        
        return result