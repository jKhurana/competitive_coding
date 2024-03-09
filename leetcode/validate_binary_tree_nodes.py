class Solution:

    def insert_edge(self,graph,u,v):
        if u in graph:
            graph[u].append(v)
        else:
            graph[u] = [v]

    def detect_cycle(self,graph,source,visited):
        visited[source] = True
        result = False
        if source in graph:
            for adj in graph[source]:
                if visited[adj]==True:
                    return True
                result = self.detect_cycle(graph,adj,visited) or result
        return result

    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        n = len(leftChild)

        in_degree = [0] * n
        zero_degree_node = 0
        
        graph = {}
        for i in range(n):
            if leftChild[i]!=-1:
                self.insert_edge(graph,i,leftChild[i])
                in_degree[leftChild[i]] +=1
            if rightChild[i]!=-1:
                self.insert_edge(graph,i,rightChild[i])
                in_degree[rightChild[i]] +=1
        for i,degree in enumerate(in_degree):
            if degree==0:
                zero_degree_node = i
                break


        visited = [False] * n 

        result = self.detect_cycle(graph,zero_degree_node,visited)
        if result:
            return False
        else:
            if all(visited):
                return True
            else:
                return False