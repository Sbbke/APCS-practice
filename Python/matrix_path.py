def MaximumPath(grid):
 
    # Dimensions of grid[][]
    N = len(grid)
    M = len(grid[0])
 
    # Stores maximum sum at each cell
    # sum[i][j] from cell sum[0][0]
    sum = [[0 for i in range(M + 1)]
              for i in range(N + 1)]
 
    # Iterate to compute the maximum
    # sum path in the grid
    for i in range(1, N + 1):
        for j in range(1, M + 1):
 
            # Update the maximum path sum
            sum[i][j] = (max(sum[i - 1][j],
                             sum[i][j - 1]) +
                        grid[i - 1][j - 1])
 
    # Return the maximum sum
    return sum[N][M]
 
# Driver Code
if __name__ == '__main__':
 
    grid = [ [ 1, 2 ,-101,50,67,0,54], [ 3, 5 ,0,-4,-5,7,10] ]
 
    print(MaximumPath(grid))