from functools import cache
from typing import List

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        N = len(piles)

        presum = [p for p in piles] # number of points we can get after collecting all remaining piles

        for i in range(N-2, -1, -1):
            presum[i] += presum[i+1]

        @cache
        def D(i, m):
            """
            D[i, m] = max score after after starting the game at i-th pile with 1 <= X <= 2*m
            """

            if i + 2 * m >= N:
                return presum[i] # can grab ALL remaining piles
            
            minimal_optimal_strategy_of_other_player = min(
                D(i + x, max(m, x)) for x in range(1, 2*m+1)
            )

            return presum[i] - minimal_optimal_strategy_of_other_player
        
        return D(0, 1)