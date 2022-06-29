n = int(input())
honor = []
for i in range(n):
    x = int(input())
    honor.append(x)
honor = sorted(honor)

hacker = 0
defile = 1
for i in honor:
    if i>=defile:
        result += i - defile
        defile+=1