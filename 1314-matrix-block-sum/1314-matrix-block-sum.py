class Solution(object):
    def matrixBlockSum(self, mat, k):
        m, n = len(mat), len(mat[0])
        prefix_sum = [[0 for i in range(n+1)] for j in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] + mat[i-1][j-1] - prefix_sum[i-1][j-1]
        
        result = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                row1, col1 = max(0, i-k), max(0,j-k)
                row2, col2 = min(m-1, i+k), min(n-1,j+k)
                result[i][j] = prefix_sum[row2+1][col2+1] - prefix_sum[row1][col2+1] - prefix_sum[row2+1][col1] + prefix_sum[row1][col1]
        return result