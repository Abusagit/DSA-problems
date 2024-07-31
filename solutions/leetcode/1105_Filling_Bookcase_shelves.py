from typing import List
'''
Iteratively refine DP solution. For each book, try to place it and the last books on the same shelf until maximum width is exceeded.

'''
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        
        N = len(books)
        D = [float("inf") for _ in range(N+1)] # D[k]==minimal height needed to rearrange first k books
        D[0] = 0
        
        for book_number in range(1, N):
            current_book_height = 0
            current_book_width = 0
            
            for last_book_index in range(book_number-1, -1, -1): # iterate over last books and try to rearrange them
                
                thickness_i, height_i = books[last_book_index]
                
                
                if current_book_width + thickness_i > shelfWidth:
                    break
                
                current_book_height = max(current_book_height, height_i)
                current_book_width += thickness_i
                
                
                current_arrangement_height = D[last_book_index] + current_book_height
                D[book_number] = min(D[book_number], current_arrangement_height)
                     
        return D[N]