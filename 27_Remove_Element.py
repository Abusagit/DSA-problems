from typing import List



class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        border_index = len(nums) - 1
        
        i = 0
        
        k = 0
        while i <= border_index:
            x = nums[i]
            
            if x == val:
                nums[i] = nums[border_index]
                nums[border_index] = x
                border_index -= 1
            else:
                i += 1        
                k += 1

        return k
    
    def removeElement2(self, nums: List[int], val: int) -> int:
        
        
        k = 0
        
        for x in nums:
            
            if x != val:
                nums[k] = x
                k += 1
        
        return k