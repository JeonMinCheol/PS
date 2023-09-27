import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    dp = [[0] * (n+1) for _ in range(n+1)] 
    arr = deque(map(int,input().split()))
    arr.appendleft(0)
    arr = list(arr)
    
    for i in range(1,n+1):
        for j in range(1,n+1-i):
            ret = 987654321
            for k in range(j,i+j):
                ret = min(ret,dp[j][k] + dp[k+1][i+j])
            dp[j][i + j] = sum(arr[j:i+j+1]) + ret
    print(dp[1][n])