import sys
sys.setrecursionlimit(10**6)
n,m = map(int,input().split())
graph = [[] for _ in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(x,visit):
    visit.append(x)
    if len(visit) == 5:
        return True

    for i in graph[x]:
        if not i in visit:
            if dfs(i,visit):
                return True
    
    visit.remove(x)
    
for i in range(n):
    if dfs(i,[]):
        print(1)
        break

    if i == n-1:
        print(0)
