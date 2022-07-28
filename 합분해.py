div = 1000000000
n,k = map(int,input().split())
result = 0
dp = [0] * (n+1)

while k > 0:
    for i in range(1,n+1):
        j = 0
        while i + j <= n:
            dp[i + j] += 1
            j += i
    k = k - 1
print(dp)
print(dp[k] % div)