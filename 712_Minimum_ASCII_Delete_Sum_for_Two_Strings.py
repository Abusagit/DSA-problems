"""
Search for congest common subsequence via DP, track sums of ascii symbols which aren't included to the subsequence
(in other words, which should be deleted)
"""

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        len_s1 = len(s1)
        len_s2 = len(s2)
        
        
        # LCS problem, but try to get the sum of ord(chars) which do not participate in it
        D = [[0 for _ in range(len_s1+1)] for _ in range(len_s2+1)]
        for j in range(1, len_s1+1):
            D[0][j] = D[0][j-1] + ord(s1[j-1])
        for i in range(1, len_s2+1):
            D[i][0] = D[i-1][0] + ord(s2[i-1])
            
        for i in range(1, len_s2+1):
            s2_i_ascii = ord(s2[i-1])
            
            for j in range(1, len_s1+1):
                s1_i_ascii = ord(s1[j-1])
                
                if s2_i_ascii == s1_i_ascii:
                    D[i][j] = D[i-1][j-1]
                else:
                    D[i][j] = min(D[i-1][j] + s2_i_ascii, # delete s2_i [VERTICAL STRING]
                                  D[i][j-1] + s1_i_ascii, # delete s2_j [HORIZONTAL STRING]
                                  )
        
        # for d in D:
        #     print(*d, sep='\t')
        
        
        return D[-1][-1]

if __name__ == '__main__':
    s1 = "sea"
    s2 = "eat"
    
    print(Solution().minimumDeleteSum(s1, s2))