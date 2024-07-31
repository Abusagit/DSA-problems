from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:

        sorted_indices = sorted(range(len(names)), key=lambda x: heights[x], reverse=True)


        return [names[i] for i in sorted_indices]