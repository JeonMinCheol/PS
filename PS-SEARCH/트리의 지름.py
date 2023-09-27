import sys
input = sys.stdin.readline
def dfs(node):
    global ret
    global sp
    visit[node] = True
    stack = []
    stack.append([node,0])
    cnt = 0
    while len(stack) != 0:
        arr = stack.pop()
        currentNode = arr[0]
        cnt = arr[1]
        if cnt > ret:
            sp = currentNode
            ret = cnt
        for data in graph[currentNode]:
            v = data[0]
            w = data[1]
            if visit[v]:
                continue
            visit[v] = True
            stack.append([v, cnt + w])  
n = int(input())

ret = 0
sp = 1
graph = [[] for _ in range(n + 1)]
visit = [False] * (n+1)

for _ in range(n-1):
    parentNode, childNode, weight = map(int,input().split())
    graph[parentNode].append(([childNode,weight]))
    graph[childNode].append(([parentNode,weight]))

dfs(sp)
ret = 0
visit = [False] * (n+1)
dfs(sp)

print(ret)