class DFS():

    def __init__(self,n,adjacency_list):
        self.adjacency_list = adjacency_list
        self.n = n 
    
    def _perform_dfs(self,start_node,visited):

        visited[start_node] = True
        print(start_node)

        for adj_nodes in self.adjacency_list[start_node]:
            if not visited[adj_nodes]:
                self._perform_dfs(adj_nodes,visited)
    
    def dfs(self,start_node):

        visited = [False] * n 

        self._perform_dfs(start_node,visited)



n = 5
adjacency_list = {
    0:[1,2],
    1:[0,3],
    2:[0,3,4],
    3:[1,2,4],
    4:[2,3]
}
dfs_obj = DFS(n,adjacency_list)
dfs_obj.dfs(0)
