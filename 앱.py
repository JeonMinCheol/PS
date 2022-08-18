import sys
input = sys.stdin.readline 
n, m = map(int, input().split())

memory = list(map(int,input().split()))
cost = list(map(int,input().split()))

dp = [[0] * 100 for _ in range(n)]
dp[0][cost[0]] = memory 
for i in range(1, n):
    
    for j in range(m):
