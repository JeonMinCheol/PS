div = 1000000000
n,k = map(int,input().split())
result = 0
dp = [[0] * (n+1) for _ in range(k)]

for i in range(k):
    for j in range(n+1):
        if i == 0:
            dp[0][j] += 1
            continue
        for l in range(j + 1):
            dp[i][j] += dp[i-1][l]
        dp[i][j] %= 1000000000

print(dp[k-1][n] % div)