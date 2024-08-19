class Solution:
    def minSteps(self, n: int) -> int:
        """O(n)"""
        result = 0

        for divisor in range(2, n+1):
            while n % divisor == 0:
                n //= divisor
                result += divisor

        return result

    def minSteps(self, n: int) -> int:
        """O(logn)"""
        if n == 1:
            return 0

        result = 0

        divisor = 2

        while divisor * divisor <= n:
            while n % divisor == 0:
                n //= divisor
                result += divisor

            divisor += 1
        

        return result + n if n > 1 else result # if n > 1 then n is Prime => add n