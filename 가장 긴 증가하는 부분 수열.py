n = int(input())
matrix = list(map(int,input().split()))
dp = [9999] * (n+1)
#dp[i-1] < matrix[i]일때 dp[i] = min(matrix[i],dp[i])
dp[1] = matrix[0]
ret = 1
for i in range(1, n):
    val = matrix[i]
    for j in range(1,n+1):
        if j == 1:
            dp[j] = min(val,dp[1])
        elif dp[j-1] < val:
            dp[j] = min(val, dp[j])
            ret = max(ret,j)
        elif dp[j] == 9999:
            break
print(ret)