class Solution:

    def __init__(self):
        self.total_size = 0
    
    def dfs(self,source,grid,m,n,visited):
        i = source[0]
        j = source[1]
        visited[i][j] = True
        self.total_size +=1

        if i-1 >= 0 and visited[i-1][j]==False and grid[i-1][j]!=0:
            self.dfs((i-1,j),grid,m,n,visited)
        if i+1<m and visited[i+1][j]==False and grid[i+1][j]!=0:
            self.dfs((i+1,j),grid,m,n,visited)
        if j-1>=0 and visited[i][j-1]==False and grid[i][j-1]!=0:
            self.dfs((i,j-1),grid,m,n,visited)
        if j+1<n and visited[i][j+1]==False and grid[i][j+1]!=0:
            self.dfs((i,j+1),grid,m,n,visited)
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])

        visited = [[False]*n for i in range(m)]

        max_len = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j]!=0 and visited[i][j]==False:
                    self.total_size = 0
                    self.dfs((i,j),grid,m,n,visited)
                    if self.total_size > max_len:
                        max_len = self.total_size
        return max_len
