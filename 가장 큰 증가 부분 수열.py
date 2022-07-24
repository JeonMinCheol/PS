import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int,input().split()))
dp = [10000] * n
dp[0] = arr[0]
ret = [dp[0]]


print(ret)