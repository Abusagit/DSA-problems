from typing import List
import heapq

class Solution:
    def rangeSum_slow(self, nums: List[int], n: int, left: int, right: int) -> int:
        MOD: int = 10**9 + 7
        
        prefix_sum = [0] * (n + 1)
    
        for i, x in enumerate(nums, 1):
            prefix_sum[i] = (prefix_sum[i-1] + x) % MOD
            
        
        sums = [prefix_sum[j] - prefix_sum[i] for j in range(1, n+1) for i in range(j)]

        
        heapq.heapify(sums)        
        
        result = 0
        
        number_of_extracted = 0
        # print(prefix_sum)
        # print(sums)

        # print()
        while len(sums) > 0 and number_of_extracted < right:
            current_min = heapq.heappop(sums)
            
            number_of_extracted += 1
            
            if number_of_extracted < left:
                continue
            
            result = (result + current_min) % MOD

            # print(sums, number_of_extracted, current_min, result)

        
        return result
            
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        MOD: int = 10**9 + 7
        
        
        heap = [(x % MOD, i) for i, x in enumerate(nums)]
        heapq.heapify(heap)
        
        
        number_of_operations = 0
        
        result = 0
        
        while number_of_operations < right:
            current_minimal_subarray_sum, current_index_of_minimal_subarray_sum = heapq.heappop(heap)
            number_of_operations += 1
            
            if number_of_operations >= left:
                result = (result + current_minimal_subarray_sum) % MOD
                
            
            if current_index_of_minimal_subarray_sum < n - 1:

                new_subarray_sum = current_minimal_subarray_sum + nums[current_index_of_minimal_subarray_sum + 1]
                new_subarray_index = current_index_of_minimal_subarray_sum + 1
                
                new_query = (new_subarray_sum, new_subarray_index)
                
                heapq.heappush(new_query)
                
                
        return result