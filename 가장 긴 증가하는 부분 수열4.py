import sys
import copy
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))
dp = [[0] for _ in range(n)] 
dp[0] = [a[0]]
index = 0
size = 1
for i in range(1,n):
    value = a[i]
    for j in range(0,i):
        arr = dp[j]
        leng = len(arr)
        if arr[-1] < value and leng >= len(dp[i]):
            dp[i] = copy.deepcopy(arr)
            dp[i] += [value]
    dp[i][-1] = value
    if len(dp[i]) > size:
        index = i
        size = len(dp[i])

print(size)
for i in dp[index]:
    print(i,end = " ")