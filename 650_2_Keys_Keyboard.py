class Solution:
    def minSteps(self, n: int) -> int:

        result = 0

        for divisor in range(2, n+1):
            while n % divisor == 0:
                n //= divisor
                result += divisor

        return result