import sys
from collections import deque
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

# 각 대륙별로 가장자리를 구하고 분류한다.
def findEdge(row,col):
    global n, visit, graph
    ret = set()
    dq = deque()
    dq.append([row,col])
    visit[row][col] = True
    
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    while(len(dq)):
        land = dq.pop()
        for i in range(4):
            newRow = land[0] + dir[i][0]
            newCol = land[1] + dir[i][1]
            if 0 <= newRow < n and 0 <= newCol < n:
                if visit[newRow][newCol] == False:
                    if graph[newRow][newCol] == 0:
                        ret.add((land[0],land[1]))
                    else:
                        dq.append([newRow,newCol])
                        visit[newRow][newCol] = True
    return ret

def dfs(row, col, cnt):
    # 매번 dfs해가면서 가장 짧은 거리 찾을 거임.
    global ret
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < n and 0 <= newCol < n:
            if visit[newRow][newCol] != 0 and visit[newRow][newCol] < cnt:
                cnt = visit[newRow][newCol] + 1
    visit[row][col] = cnt

    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < n and 0 <= newCol < n:
            if visit[newRow][newCol] == False:
                if cnt <= ret:
                    for subset in edge:
                        if (newRow,newCol) in subset:
                            ret=min(ret,cnt-1)
                    ret = min(dfs(newRow,newCol,cnt+1),ret)
    return ret




n = int(input())
visit = [[False] * n for _ in range(n)]
graph = []
edge = []

for i in range(n):
    graph.append(list(map(int,input().split())))

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1 and visit[i][j] != True:
            edge.append(findEdge(i,j))

ret = 99999999
for i in range(len(edge)):
    # 같은 대륙에 방문하지 못하도록 방문처리
    arr = list(edge[i])

    for a in arr:
        visit = [[0] * n for _ in range(n)]
        for j in arr:
            visit[j[0]][j[1]] = True
        ret = min(dfs(a[0],a[1],1),ret)
print(ret)
    