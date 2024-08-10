from typing import List

class Solution:
        
    def regionsBySlashes(self, grid: List[str]) -> int:
        self.N = len(grid)
        self.M = 3 * self.N
        
        self.adjacency: List[List[int]] = self._construct_graph(grid=grid)        
    
        number_of_connected_components: int = 0
        
        for i in range(self.M):
            for j in range(self.M):
                if self.adjacency[i][j] == 1:
                    
                    self._dfs(i, j)
                    number_of_connected_components += 1
        
                            
        return number_of_connected_components
    
    def _dfs(self, i, j) -> None:
        if i < 0 or i >= self.M or j < 0 or j >= self.M    or    self.adjacency[i][j] == 0:
            return
        
        # Not visited, and current cell is 1 => we are in connected component
        
        self.adjacency[i][j] = 0
        
        self._dfs(i-1, j)
        self._dfs(i, j-1)
        self._dfs(i, j+1)
        self._dfs(i+1, j)
        

    def _construct_graph(self, grid: List[str]) -> List[List[int]]:
        adj = [[1 for _ in range(self.M)] for _ in range(self.M)]
        for k in range(self.N):
            for m in range(self.N):            
                char = grid[k][m]
                if char == "/":
                    adj[3*k][3*m+2] = 0
                    adj[3*k+1][3*m+1] = 0
                    adj[3*k+2][3*m] = 0
                    
                elif char == "\\":
                    adj[3*k][3*m] = 0
                    adj[3*k+1][3*m+1] = 0
                    adj[3*k+2][3*m+2] = 0

                
        
        return adj

if __name__ == '__main__':
    
    example = ["//","/ "]
    solution = Solution()
    
    print(solution.regionsBySlashes(example))
    