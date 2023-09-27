import sys
input = sys.stdin.readline
n = int(input())
card = list(map(int,input().split()))
dp = [0] * (n+1)
ret = 0
for i in range(n):
    price = card[i]
    for j in range(n):
        cost = (i + 1) + j
        if cost <= n:
            if dp[cost] < price + dp[j]:
                dp[cost] = price + dp[j]
                ret = max(ret,dp[cost])
print(ret)
