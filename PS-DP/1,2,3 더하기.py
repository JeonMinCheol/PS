import sys
input = sys.stdin.readline
t = int(input())

def dp(n,ret):
    for i in range(1,n+1):
        if i >= 3:
            ret[i] += ret[i-3]
        if i >= 2:
            ret[i] += ret[i-2]
        if i >= 1:
            ret[i] += ret[i-1]
    return ret[n]            
while t:
    t -= 1
    n = int(input())
    ret = [0] * (n+1)
    ret[0] = 1
    print(dp(n,ret))
