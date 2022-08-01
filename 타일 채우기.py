n = int(input())
dp = [0] * (n+1)
dp[0] = 1

cnt = 0
for i in range(2, n+1, 2):
    dp[i] = 3 * dp[i - 2]
    for j in range(4, i+1, 2):
        dp[i] += 2 * dp[i - j]
    
print(dp[n])
