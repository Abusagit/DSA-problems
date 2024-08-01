from typing import List


"""
1) Search for the farthest element not in its place - which is less than largest maximum on a current prefix
2) Search for the nearest elememnt not in place - which is greater than smallest minimum on a current suffix

"""
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        N = len(nums)
        
        largest_previous_element = nums[0]
        
        end_index = 0
        
        for i, x_i in enumerate(nums):    
            if x_i < largest_previous_element:
                end_index = i
            else:
                largest_previous_element = x_i
            
        
        smallest_next_element = nums[-1]
        start_index = N - 1
        
        for j in range(N-1, -1, -1):
            
            x_j = nums[j]
            
            if x_j > smallest_next_element:
                start_index = j
            else:
                smallest_next_element = x_j
        
        if end_index != 0:
            return end_index - start_index + 1
        
        return 0