matrix = [
    [1,2,3,4],
    [5,6,7,8],
]
transposed = []
matrix.reverse()
print(matrix)
print(list(reversed(matrix)))
print("column = ",len(matrix[0]), "\n", "row = ", len(matrix))

for i in range(len(matrix[0])):
    transposed.append([row[i] for row in matrix])

print(transposed)
