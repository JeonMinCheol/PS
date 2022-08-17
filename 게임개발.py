import sys
from collections import deque
input = sys.stdin.readline

def topology():
    global n
    dq = deque()
    for i in range(n):
        if len(orders[i]) == 0:
            dq.append(i)
            visit[i] = True
            dp[i] += time[i]
    
    while len(dq) > 0:
        index = dq.pop()
        for i in range(n):
            if visit[i]:
                continue

            if index in orders[i]:
                orders[i].remove(index)
                dp[i] = max(dp[i], dp[index])
            if len(orders[i]) == 0:
                dq.append(i)
                dp[i] += time[i]
                visit[i] = True

n = int(input())
time = []
dp = [0] * n
orders = [[] for _ in range(n)]
visit = [False] * n
for i in range(n):
    inp = list(map(int, input().split()))
    for j in range(len(inp)-1):
        if j == 0:
            time.append(inp[j])
        else:
            orders[i].append(inp[j]-1)
topology()
for elem in dp:
    print(elem)