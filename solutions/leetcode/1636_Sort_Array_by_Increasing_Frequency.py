from typing import List
from collections import Counter

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        self.counter = Counter(nums)
        
        return sorted(nums, key=self.sorter_function)
    
    def sorter_function(self, value):
        
        return (self.counter[value], -value)