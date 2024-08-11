from typing import List
from functools import reduce
from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        letter_counts: List[int] = sorted([count for _letter, count in Counter(word).items()], reverse=True)
        
        
        
        score = reduce(lambda x, y: x + (y[0] // 8 + 1) * y[1], enumerate(letter_counts), 0)
        
        # result = 0
        # for order, count in enumerate(letter_counts):
            
        #     number_of_taps = order // 8 # first 8 most common letters will have 1 tap, second 8 - 2 taps, etc
            
        #     result += number_of_taps * count
        
        # return result
        
        return score