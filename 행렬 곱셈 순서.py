import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
dp = [[0] * (n+1) for _ in range(n+1)] 
arr = [[]]
for _ in range(n):
    arr.append(list(map(int,input().split())))

ret = 0
for i in range(1, n+1):
    for j in range(1, n + 1 - i):
        value = 987654321
        index = j
        for k in range(j, i + j):
            if k == j and value > arr[j][0] * arr[k][1] * arr[i+j][1] + dp[j][k] + dp[k+1][i+j]:
                value = arr[j][0] * arr[k][1] * arr[i+j][1] + dp[j][k] + dp[k+1][i+j]
                index = k
            elif value > arr[j][0] * arr[k][1] * arr[i+j][1] + dp[j][k] + dp[k+1][i+j]:
                value = arr[j][0] * arr[k][1] * arr[i+j][1] + dp[j][k] + dp[k+1][i+j]
                index = k
        dp[j][i+j] = value
print(dp[1][n])
