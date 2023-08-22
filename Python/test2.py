import sys

x = sys.stdin.readline()
x = list(x.rstrip().split())

print(x)

for i in range(len(x)):
    x[i] = int(x[i])
print(x)
x.sort()
print(x)
