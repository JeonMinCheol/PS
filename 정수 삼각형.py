import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(int,input().split())))
dq = deque()
for i in graph[n-1]:
    dq.append(i)

for i in range(n-2, -1, -1):
    for j in range(len(graph[i])):
        currentNode = graph[i][j]
        a = dq.popleft()
        b = dq.popleft()
        dq.append(currentNode + max(a,b))
        dq.appendleft(b)   
    dq.popleft()
print(dq.pop())