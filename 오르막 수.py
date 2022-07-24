n = int(input())
dp = [[1] * 10 for _ in range(n)]
ret = 10
for i in range(1,n):
    ret = 0
    arr = [0] * 10
    for j in range(0,10):
        for k in range(j,10):
            arr[k] = (arr[k] + dp[i-1][j]) % 10007
        ret = (ret + arr[j]) % 10007
    dp[i] = arr
print(ret % 10007)