from collections import Counter


class Solution:
 
   def kthDistinct(self, arr: List[str], k: int) -> str:
        symbols_counts = Counter(arr)

        current_distinct_char_number = 0

        for symbol in arr:
            if symbols_counts[symbol] == 1: 
                current_distinct_char_number += 1
                if current_distinct_char_number == k:
                    return symbol
        


        return ""
