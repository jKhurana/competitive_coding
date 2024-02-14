class Solution:
    def uniquePaths(self, m: int, n: int) -> int:

        # make dp matrix
        dp_matrix = [[1] * n for i in range(m)]

        for i in range(m):
            for j in range(n):
                if i>0 and j>0:
                    dp_matrix[i][j] = dp_matrix[i-1][j] + dp_matrix[i][j-1]
                elif i>0:
                    dp_matrix[i][j] = dp_matrix[i-1][j]
                elif j>0:
                    dp_matrix[i][j] = dp_matrix[i][j-1]
        return dp_matrix[m-1][n-1]