n=int(input())
a = input()
text = a.split()

print("n=", n, "text = ", text)
# n = 100
# c = 0
# k = 2
# text = []
# for i in range(99):
#     c += k
#     text.append(c)
#     if c == 100:
#         c -= 1
#         k = -2
#         text.append(c)

b=[]
for i in text:
    b.append(i)

print("b = ", b)

print("sort b")

b.sort()

print("b = ", b)

c=[]
for j in range(n):
    for i in b:
        c.append(text.index(i))


r = 0
for i in range(n-1):
    if(r%2==0):
        if(c[i] > c[i+1]):
            r+=1
    elif r%2 == 1:
        if c[i+1] > c[i]:
            r +=1
print(r)