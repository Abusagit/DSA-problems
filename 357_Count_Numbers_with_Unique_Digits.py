class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        
        answer = 10 # for n = 1
        
        combinatorial_number = 9
        
        k = 2
        
        while (k <= 10 and k <= n): # for every greater n, count the number sequentially
            
            combinatorial_number *= (10 - k + 1)
            answer += combinatorial_number

            k += 1
        return answer