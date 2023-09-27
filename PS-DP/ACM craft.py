import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(node):
    dp[node] = 0
    for i in order[node]:
        dp[node] = max(dp[node], dp[i])

    dp[node] += time[node]

    for i in order_reverse[node]:
        dfs(i)
    
T = int(input())
for _ in range(T):
    n,k = map(int,input().split())
    order = [[] for _ in range(n)]
    order_reverse = [[] for _ in range(n)]
    time = list(map(int,input().split()))
    dp = [-1] * n
    for _ in range(k):
        a,b = map(int,input().split())
        order[a-1].append(b-1)
        # 방향
        order_reverse[b-1].append(a-1)
    
    w = int(input()) - 1
    dfs(w)
    print(order)
    print(dp)