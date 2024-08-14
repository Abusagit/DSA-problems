from typing import List

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        """
        Leftmost binsearch over the answer
        """

        def number_of_distances_ge_than_k(current_abs_distance):
            total = 0

            j = 1
            for i in range(n):
                while j < n and nums[j] - nums[i] <= current_abs_distance:
                    j += 1
                total += j - i - 1
            return total >= k


        nums.sort() # sort in ascending order
        n = len(nums)

        left = 0
        right = nums[-1] - nums[0]

        while left < right:
            mid = left + (right - left) // 2 # check for the upper bound of the absolute distance

            if number_of_distances_ge_than_k(mid):
                right = mid # b.c. condition is >=, so mid can be the answer
            else:
                left = mid + 1
        
        return left