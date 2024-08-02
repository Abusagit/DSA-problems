class Solution:
    def largestOddNumber(self, num: str) -> str:
                
        odd_chars = set([str(x) for x in range(1, 9+1, 2)])
        
        
        right_border = 0
        
        for right_pointer in range(len(num)):
            if num[right_pointer] in odd_chars: # => num[left_pointer: right_pointer+1] is ODD
                right_border = right_pointer + 1

        return num[:right_border]