from typing import List

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        # check two arrays for the contents - b.c. any number of reverses means that we can basically sort arr as target in any number of iterations
        
        contents_target = self._get_counter(target)
        contents_arr = self._get_counter(arr)
        
        return contents_arr == contents_target
        
    @staticmethod
    def _get_counter(array: List[int]):
        counter = {}
        
        for x in array:
            counter[x] = counter.get(x, 0) + 1
        
        return counter