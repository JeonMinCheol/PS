n = int(input())
dp = [999999] * (n + 1)
for i in range(n+1):
    x = i * i
    if x > n:
        break
    dp[x] = 1
    for j in range(n+1):
        if j + x > n:
            break
        dp[j + x] = min(dp[j + x], dp[j] + 1)
print(dp[n])