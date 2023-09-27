import sys
input = sys.stdin.readline
coins = []
n,k = map(int,input().split())
for i in range(n):
    coins.append(int(input()))
coins = sorted(coins)

dp = [99999] * (k+1)
dp[0] = 0
for coin in coins:
    c = coin
    while coin <= k:
        dp[coin] = min(dp[coin - c] + 1, dp[coin]) 
        coin += 1
if dp[k] >= 99999:
    print(-1)
else:
    print(dp[k])