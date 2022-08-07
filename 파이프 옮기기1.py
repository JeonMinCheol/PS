import sys
input = sys.stdin.readline

n = int(input())
pipe = []
dp = [[[0,0,0] for _ in range(n)] for _ in range(n)]
dp[0][1][0] = 1

for _ in range(n):
    pipe.append(list(map(int,input().split())))

for row in range(n):
    for col in range(n):
        arr = dp[row][col]
        if row < n and col + 1 < n and pipe[row][col + 1] != 1:
            dp[row][col + 1][0] += arr[0] + arr[1]
        if row + 1 < n and col + 1 < n and pipe[row + 1][col + 1] != 1 and pipe[row][col + 1] != 1 and pipe[row + 1][col] != 1:
            dp[row + 1][col + 1][1] += arr[0] + arr[1] + arr[2]
        if row + 1 < n and col < n and pipe[row + 1][col] != 1:
            dp[row + 1][col][2] += arr[2] + arr[1]

print(sum(dp[n-1][n-1]))