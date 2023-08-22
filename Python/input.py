x = int(input())

for i in range(x):
    y = input()
    array = y.split()
    for i in range(len(array)):
        print(array[i],type(i))