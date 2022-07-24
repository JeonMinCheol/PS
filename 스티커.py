import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    dp = [[0] * n for _ in range(2)]
    arr = []
    
    ret = 0
    for _ in range(2):
        arr.append(list(map(int,input().split())))
    for i in range(n):
        if i == 0:
            dp[0][i] = arr[0][i]
            dp[1][i] = arr[1][i]
        elif i == 1:
            dp[0][i] = dp[1][i-1] + arr[0][i]
            dp[1][i] = dp[0][i-1] + arr[1][i]
        else:
            dp[0][i] = max(dp[0][i-2] + arr[0][i], dp[1][i-2] + arr[0][i], dp[1][i-1] + arr[0][i])
            dp[1][i] = max(dp[1][i-2] + arr[1][i], dp[0][i-2] + arr[1][i], dp[0][i-1] + arr[1][i])
    ret = max(max(dp[0]),max(dp[1]))
    print(ret)