def maximum_path(mat, i, j):
    n = len(mat)
 
    if i == n - 1 and j == n - 1:
        return mat[i][j]
 
    if i >= n or i < 0 or j >= n or j < 0:
        return 0
 
    return max(maximum_path(mat, i + 1, j),
               maximum_path(mat, i +1, j - 1),
               maximum_path(mat, i +1, j + 1)) + mat[i][j]
 
# Example usage
matrix = [[4, 2, 3, 4],
          [2, 9, 1, 10],
          [15, 1, 3, 0],
          [16, 92, 41, 44]]
 
result = maximum_path(matrix, 0, 0)
print("Maximum Path Sum:", result)