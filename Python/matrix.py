from sys import stdin

def flip(matrix):
    return list(reversed(matrix))

def rotate(matrix):
    tmp=[]
    row=len(matrix)
    col=len(matrix[0])
    for i in range(col):
        combine=[]
        for j in range(row):
            combine.append(matrix[j][i])
        tmp.append(combine)
    return list(reversed(tmp))

for read in stdin:
    R,C,M=map(int,read.rstrip().split())
    matrix=[]
    for i in range(R): matrix.append([int(x) for x in input().split()])
    operates=[int(x) for x in input().split()]
    for i in list(reversed(operates)):
        if i==0: matrix=rotate(matrix)
        elif i==1: matrix=flip(matrix)
    print(len(matrix),len(matrix[0]))
    for i in matrix: print(*i,sep=' ')