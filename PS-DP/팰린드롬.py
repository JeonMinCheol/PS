import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(a,b,p):
    global front, end, dp
    if p == 0 or numbers[a] != numbers[b]:
        dp[a][b] = 0
        if a > front and b < end:
            dfs(a - 1,b + 1,0)    
    else:
        dp[a][b] = 1
        if a > front and b < end:
            dfs(a - 1, b + 1, 1) 
n = int(input())
numbers = list(map(int,input().split()))
k = int(input())
dp = [[-1] * n for _ in range(n)]

for _ in range(k):
    front,end = map(int,input().split())
    front -= 1
    end -= 1
    a = front
    b = end
    while a <= b:
        if dp[a][b] >= 0 or b - a <= 1:
            dfs(a,b,dp[a][b])
            print(dp[front][end])
            break
        a = a + 1
        b = b - 1
