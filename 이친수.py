n = int(input())
ret = [0] * (100)
ret[0] = ret[1] = 1
for i in range(2,n):
    ret[i] = ret[i-1] + ret[i-2]
print(ret[n-1])