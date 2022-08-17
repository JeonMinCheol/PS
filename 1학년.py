import sys
input = sys.stdin.readline

ret = 0
n = int(input())
arr = list(map(int,input().split()))
dp = [[0] * 21 for _ in range(n)]
dp[0][arr[0]] = 1
for i in range(1,n-1):
    next = dp[i]
    for j in range(21):
        now = dp[i-1][j]
        if now != 0:
            if j - arr[i] >= 0:
                next[j - arr[i]] += now
            if j + arr[i] < 21:
                next[j + arr[i]] += now
print(dp[n-2][arr[-1]])