import sys
sys.setrecursionlimit(10**6)

def dfs(graph,row,col):
    graph[row][col] = 0

    dx = [1,1,1,-1,-1,-1,0,0]
    dy = [1,-1,0,1,-1,0,1,-1]
    for i in range(8):
        if row + dx[i] <= -1 or row + dx[i] >= h or col + dy[i] <= -1 or col + dy[i] >= w:
            continue 
        elif graph[row+dx[i]][col+dy[i]] == 0:
            continue
        dfs(graph,row+dx[i],col+dy[i])
    
while True:
    w,h = map(int,input().split())
    if w == 0 and h == 0:
        break
    graph = []

    for i in range(h):
        a = list(map(int,input().split()))
        graph.append(a)

    ret = 0
    for i in range(h):
        for j in range(w):
            if graph[i][j] == 1:
                ret+=1
                dfs(graph,i,j)
    print(ret)