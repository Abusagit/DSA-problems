"""
Sort values in the ascending order

1) Try to spend power on smaller tokens (use left pointer for that)
2) If couldn't spend power - try to add it by spending score on the largets token possible to get as much power as possible - do it if pointer don't overlap, b.c. in the next iteration you will guaranteed to at least regain your score back 

"""

from typing import List

class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        
        tokens.sort()
        left_pointer = 0
        right_pointer = len(tokens) - 1
        
        max_score = 0
        current_capacity = power
        
        while left_pointer <= right_pointer:
            
            token_left = tokens[left_pointer]
            token_right = tokens[right_pointer]
            
            if current_capacity >= token_left:
                max_score += 1
                current_capacity -= token_left
                left_pointer += 1
            elif max_score >= 1 and left_pointer < right_pointer:
                max_score -= 1
                current_capacity += token_right
                right_pointer -= 1
            else:
                break
                
        return max_score