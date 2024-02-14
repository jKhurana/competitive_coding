from typing import List
class Solution:
        
    
    def bfs(self,visited,grid,m,n):
        from queue import Queue
        qu = Queue(maxsize=0)

        # put all the rotten oranges into queue
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    qu.put((i,j))
                    visited[i][j] = True
        if qu.empty():
            return 0
        ans = 0
        while not qu.empty():
            qu.put((-1,-1))
            p,q = qu.get()

            while p!=-1 and q!=-1:
                grid[p][q] = 2
                # put all adjacent oranges to queue
                if (p-1)>=0 and grid[p-1][q]!=0 and not visited[p-1][q]:
                    qu.put((p-1,q))
                    visited[p-1][q] = True
                if p+1 < m and grid[p+1][q]!=0 and not visited[p+1][q]:
                    qu.put((p+1,q))
                    visited[p+1][q] = True
                if (q-1)>=0 and grid[p][q-1]!=0 and not visited[p][q-1]:
                    qu.put((p,q-1))
                    visited[p][q-1] = True
                if (q+1)<n and grid[p][q+1]!=0 and not visited[p][q+1]:
                    qu.put((p,q+1))
                    visited[p][q+1] = True
                p,q = qu.get()
            ans +=1
        return ans-1
            



    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])

        visited = [[False]*n for i in range(m)]

        ans = self.bfs(visited,grid,m,n)
        is_all_visited = True
        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid[i][j]!=0:
                    is_all_visited = False
        
        if is_all_visited:
            return ans
        else:
            return -1


s = Solution()
print(s.orangesRotting([[2,2],[1,1],[0,0],[2,0]]))