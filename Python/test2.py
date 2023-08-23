# import sys

# x = sys.stdin.readline()
# x = list(x.rstrip().split())

# print(x)

# for i in range(len(x)):
#     x[i] = int(x[i])
# print(x)
# x.sort()
# print(x)

c = 0
k = 2
x = []
for i in range(99):
    c += k
    x.append(c)
    if c == 100:
        c -= 1
        k = -2
        x.append(c)

for e in x:
    print(e, end= ' ')

x.sort()
print(x)