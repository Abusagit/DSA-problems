"""
- If the grid is already disconnected --> return 0
- If there exists at least one articulation point (AP) [see https://codeforces.com/blog/entry/71146] --> return 1
- Otherwise, any island can be set to disconnected by 2 deletions --> return 2


""
In DFS tree, a vertex u is an articulation point if one of the following two conditions is true:

1) u is the root of the DFS tree and it has at least two children. 
2) u is not the root of the DFS tree and it has a child v such that:
    - no vertex in the subtree rooted with v has a back edge to one of the ancestors in DFS tree of u.

""


"""

from typing import List
class Solution:
    OFFSETS: List[int] = [-1, 0, 1, 0, -1]
    TIMER = 0
    
    def construct_adgacency(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        
        adj_dict ={}
        
        for i in range(rows):
            for j, cell_value in enumerate(grid[i]):
                if cell_value == 0: # consider only island cells
                    continue
                
                cell__ij_id = i * cols + j
                                
                cell_ij_neighbours = []
                for k in range(4):
                    dy = self.OFFSETS[k]
                    dx = self.OFFSETS[k+1]
                    
                    r = i + dy
                    c = j + dx

                    if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == 0: # neighbour is out of bounds or it's a water
                        continue
                    
                    neighbour_cell_id = r * cols + c
                    
                    
                    cell_ij_neighbours.append(neighbour_cell_id)
                
                adj_dict[cell__ij_id] = cell_ij_neighbours
                
        
        return adj_dict
    
    def minDays(self, grid: List[List[int]]) -> int:
        
        self.adj_dict = self.construct_adgacency(grid=grid)
        # self.parents = {node: -1 for node in self.adj_dict}
        
        self.discovery_times = {}
        self.low = {}
        
        self.articulation_points = set()
        
        number_of_connected_components = 0
        for node in self.adj_dict:
            if node not in self.discovery_times:
                number_of_connected_components += 1
     
                self.dfs(node=node, parent_node=node)
        

        if len(self.adj_dict) <= 1: # Corner case for a single cells
            return len(self.adj_dict)
        
        if number_of_connected_components > 1:
            return 0
        if self.articulation_points:
            return 1
        
        return 2
        
    
    def dfs(self, node, parent_node):
        self.TIMER += 1
        
        number_of_children_in_DFS_traversal = 0
        
        self.discovery_times[node] = self.TIMER
        self.low[node] = self.TIMER
        
        is_AP = False
        
        for neighbour in self.adj_dict[node]:
            if neighbour == parent_node:
                continue
            
            
            if neighbour in self.discovery_times:
                self.low[node] = min(self.low[node], self.discovery_times[neighbour])
            else:
                number_of_children_in_DFS_traversal += 1
                self.dfs(neighbour, node)

                if self.low[neighbour] >= self.discovery_times[node] and node != parent_node: # Condition 1
                    is_AP = True
                    
                self.low[node] = min(self.low[neighbour], self.low[node])
        
        if node == parent_node and number_of_children_in_DFS_traversal > 1: # Condition 2
            is_AP = True
        
        if is_AP:
            self.articulation_points.add(node)