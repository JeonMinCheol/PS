testCase = int(input())


def dfs(graph,row,col):
    graph[row][col] = 0

    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    for i in range(4):
        if row + dx[i] <= -1 or row + dx[i] >= n or col + dy[i] <= -1 or col + dy[i] >= m:
            continue 
        elif graph[row+dx[i]][col+dy[i]] == 0:
            continue
        dfs(graph,row+dx[i],col+dy[i])
    
while(testCase > 0):
    testCase-=1
    m,n,k = map(int,input().split())
    graph = [[0]*(50) for _ in range(50)]

    for i in range(k):
        a = list(map(int,input().split()))
        graph[a[1]][a[0]] = 1

    ret = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                ret+=1
                dfs(graph,i,j)
    print(ret)