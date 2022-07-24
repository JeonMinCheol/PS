import sys
input = sys.stdin.readline
n = int(input())
graph = []
dp = [0] * (n+1)
ret = 0
for i in range(0,n):
    time, cost = map(int,input().split())
    for j in range(0,i+1):
        if i + time > n:
            continue
        dp[i + time] = max(dp[i+time], cost + dp[j])
        ret = max(ret, dp[i+time])

print(dp)
print(ret)