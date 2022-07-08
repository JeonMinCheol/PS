def dfs(visit,graph,row,col):
    visit[row][col] = True
    arr = [i for i in graph[row][col]]
    ret = 1
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    for i in range(4):
        if r <= row+dy[i] or row + dy[i] < 0 or c <= col + dx[i] or col + dx[i] < 0:
            continue
        if visit[row + dy[i]][col + dx[i]] == True:
            continue
        if Alphabet[row + dy[i]][col + dx[i]] in graph[row][col]:
            continue
        
        arr.append(Alphabet[row + dy[i]][col + dx[i]])
        
        graph[row + dy[i]][col + dx[i]] = arr

        
        ret = max(dfs(visit,graph,row+dy[i],col + dx[i]) + 1, ret)

    return ret

r,c = map(int,input().split())
Alphabet = []
visit = [[False]*c for _ in range(r)]
graph = [[[]]*c for _ in range(r)]
for i in range(r):
    arr = []
    string = input()
    for j in range(c):
        arr.append(string[j])
    Alphabet.append(arr)

graph[0][0].append(Alphabet[0][0])
ret = 0
for i in range(r):
    for j in range(c):
        if visit[i][j] == False:
            ret = max(ret,dfs(visit,graph,i,j))
            
for i in range(r):
    print(graph[i])
print(ret)
