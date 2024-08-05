from typing import Dict
from collections import Counter

class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        return self._count_common_words_with_one_occurrence(Counter(words1), Counter(words2))


    
    
    @staticmethod
    def _count_common_words_with_one_occurrence(words1_counts: Dict[str, int], words2_counts: Dict[str, int]):
        if len(words1_counts) > len(words2_counts):
            return Solution._count_common_words_with_one_occurrence(words2_counts, words1_counts)
        

        result = 0

        for word, count in words1_counts.items():
            if count == 1 and words2_counts.get(word, 0) == 1:
                result += 1
        return result
