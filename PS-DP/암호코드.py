div = 1000000
inp = input()
dp = [0] * (len(inp) + 1)

if len(inp) >= 1:
    dp[0] = 1
    if inp[0] != '0':
        dp[1] = 1

for i in range(2, len(inp)+1):
    if int(inp[i-1]) != 0:
        dp[i] = dp[i-1]
    if int(inp[i-2: i]) <= 26:
        if inp[i-2] != '0':
            dp[i] += dp[i-2]
    dp[i] %= div

print(dp[len(inp)])