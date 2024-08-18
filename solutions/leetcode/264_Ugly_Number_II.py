import heapq

class Solution:
    def nthUglyNumber(self, n: int) -> int:

        pointer_2 = pointer_3 = pointer_5 = 0
        D = [1 for _ in range(n)]

        for i in range(1, n):

            L_2 = D[pointer_2] * 2
            L_3 = D[pointer_3] * 3
            L_5 = D[pointer_5] * 5

            current_min = min(L_2, L_3, L_5)

            if current_min == L_2:
                pointer_2 += 1
            
            if current_min == L_3:
                pointer_3 += 1
            
            if current_min == L_5:
                pointer_5 += 1
            
            D[i] = current_min
        
        return D[-1]    
    def nthUglyNumber_nlogn(self, n: int) -> int:
        

        heap = [1]

        used_numbers = set()

        for _ in range(n):

            current = heapq.heappop(heap)

            new_1 = current * 2
            new_2 = current * 3
            new_3 = current * 5

            if new_1 not in used_numbers:
                heapq.heappush(heap, new_1)
                used_numbers.add(new_1)
            if new_2 not in used_numbers:
                heapq.heappush(heap, new_2)
                used_numbers.add(new_2)
            if new_3 not in used_numbers:
                heapq.heappush(heap, new_3)
                used_numbers.add(new_3)
        
        return current