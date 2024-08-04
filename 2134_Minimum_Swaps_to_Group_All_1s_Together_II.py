from typing import List
class Solution:
    def minSwaps_almost_correct(self, nums: List[int]) -> int:
        self.N = len(nums)
        self.nums = nums
        self.visited = [False] * self.N
        
        
        connected_components_sizes: List[int] = []
        
        for i in range(self.N):
            if self.nums[i] == 1:
                cc_size: int = self._dfs(index=i)
                
                if cc_size > 0:
                    connected_components_sizes.append(cc_size)
        
        
        connected_components_sizes.sort()
        
        K = len(connected_components_sizes)
        
        
        result = 0
        for i in range(K-1):
            result += connected_components_sizes[i]
            
        return result
        
                    
        
    def _dfs(self, index: int) -> int:
        index = index % self.N # correct index to the bounds [0, N-1]
        
        if self.nums[index] == 0 or self.visited[index]:
            return 0
        
        self.visited[index] = True
        
        dfs_right: int = self._dfs(index-1)
        dfs_left: int = self._dfs(index+1)
        
        return 1 + dfs_left + dfs_right
    
    
    def minSwaps(self, nums: List[int]) -> int:
        
        number_of_ones = nums.count(1)
        N = len(nums)
        
        # We'll slide with sliding window = number_of_ones and calculate the minimal number of zeros in it -> this will be the final answer
        
        
        number_of_ones_in_a_window = 0
        for k in range(number_of_ones):
            number_of_ones_in_a_window += nums[k] == 1
        
        
        # iterate over circular array:
        result = number_of_ones - number_of_ones_in_a_window
        
        for i in range(1, N + number_of_ones - 1):
            
            right_border = i + number_of_ones - 1
            
            number_of_ones_in_a_window = number_of_ones_in_a_window - (nums[(i-1)%N] == 1) + (nums[right_border%N] == 1)

            result = min(result, number_of_ones - number_of_ones_in_a_window)
        
        return result

if __name__ == '__main__':
    nums = [1,1,1,0,0,1,0,1,1,0]
    
    print(Solution().minSwaps(nums=nums))