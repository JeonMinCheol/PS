import sys
input = sys.stdin.readline
n = int(input())
arr = []
dp = []
for i in range(n):
    arr.append(int(input()))
    if i == 0:
        dp.append(arr[0])
    elif i == 1:
        dp.append(arr[0]+arr[1])
    elif i == 2:
        dp.append(max(arr[0] + arr[2], arr[1] + arr[2]))
    elif i == 3:
        dp.append(max(dp[1] + arr[3], arr[0] + arr[2] + arr[3]))
    else:
        dp.append(max(dp[i-2] + arr[i], arr[i] + arr[i-1] + dp[i-3]))
print(dp[n-1])

      
