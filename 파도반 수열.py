import sys
input = sys.stdin.readline
t = int(input())
dp = [0,1,1,1,2,2,3,4,5,7,9]
while t:
    t -= 1
    i = int(input())
    if i >= len(dp):
        for x in range(len(dp)-1, i):
            dp.append(dp[x] + dp[x - 4])
    print(dp[i])
