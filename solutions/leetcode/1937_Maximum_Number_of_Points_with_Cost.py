from typing import List

class Solution:

    def maxPoints(self, points: List[List[int]]) -> int:
        
        def get_left(array):
            left = [0 for _ in range(n)]
            left[0] = array[0]
            
            for i in range(1, n):
                left[i] = max(array[i], left[i-1] - 1)
            
            return left
        
        
        def get_right(array):
            right = [0 for _ in range(n)]
            right[-1] = array[-1]
            
            
            for i in range(n-2, -1, -1):
                right[i] = max(array[i], right[i+1] - 1)
            
            return right
                
        
        m = len(points)
        n = len(points[0])
        
        if n == 1:
            return sum((sum(a) for a in points))
        if m == 1:
            return max(points[0])
        
        
        previous_D = points[0]
        
        
        for i in range(1, m):

            current = [0 for _ in range(n)]
            # construct left array
            max_from_left = get_left(previous_D)
            
            # construct right array
            max_from_right = get_right(previous_D)
            
            for j in range(n):
                current[j] = max(max_from_left[j], max_from_right[j]) + points[i][j]
            
            previous_D = current
        
        return max(previous_D)