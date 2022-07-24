import sys
input = sys.stdin.readline
n,k = map(int,input().split())
bp = []
dp = [0] * (k+1)
ret = 0
for _ in range(n):
    w,v = map(int,input().split())
    for i in range(k, -1 , -1):
        if i + w <= k and dp[i] != 0 and dp[i + w] < dp[i] + v:
            dp[i+w] = dp[i] + v
            
    if w <= k and dp[w] < v:
        dp[w] = v

print(max(dp))
