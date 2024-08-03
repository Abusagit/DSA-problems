from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
    
        end_nums_1 = m - 1
        end_nums_2 = n - 1
        
        end_all = m + n -1
        
        while end_all >= 0 and end_nums_1 >= 0 and end_nums_2 >= 0:
            ai = nums1[end_nums_1]
            bj = nums2[end_nums_2]
            
            tmp = nums1[end_all]

            if ai > bj: # swap ai to the end_all-th index b.c. this is our current maximum
                nums1[end_all] = ai
                nums1[end_nums_1] = tmp
                
                end_nums_1 -= 1
            else: # swap bj to the end_all-th index b.c. this is our current maximum
                nums1[end_all] = bj
                nums2[end_nums_2] = tmp
                
                end_nums_2 -= 1
                
            end_all -= 1
                
                
        # process what's left (by analogue to the merge sort algorithm)
        while end_nums_2 >= 0 and end_all >= 0:
            nums1[end_all] = nums2[end_nums_2]
            end_nums_2 -= 1
            end_all -= 1