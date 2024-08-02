"""
Try to remove any element which is bigger then the next to it's right - b.c. that's how to make a number as less as possible

track to the end how many digits to remove remained, keep the budget of deletions
"""

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        N = len(num)
        stack = []
        
        to_remove = k
        
        i = 0
        
        while i < N:
            # print(i, stack, end="->")

            if len(stack) == 0:
                stack.append(num[i])
                i += 1

            elif stack[-1] > num[i] and to_remove > 0: # len(stack) >= 1
                stack.pop(-1)
                to_remove -= 1
            else:
                stack.append(num[i])
                i +=1
            # print(stack)

        while stack and to_remove > 0:
            stack.pop(-1)
            to_remove -= 1
            
        # check leading zeros
        
        start = 0
        while start < len(stack) and stack[start] == '0':
            start += 1
            
        if len(stack) - start == 0: # check if the stack is "empty"
            return '0'
        
        return ''.join(stack[start:])