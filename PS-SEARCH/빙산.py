import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(visit,r,c):
    global ret
    global row
    global col
    global count
    visit[r][c] = True
    dir = [[1,0],[-1,0],[0,1],[0,-1]]

    ret += 1
    for i in range(4):
        newRow = r + dir[i][0]
        newCol = c + dir[i][1]
        if 0<= newRow < row and 0<= newCol < col:
            if visit[newRow][newCol] == False:
                if graph[newRow][newCol] == 0:
                    if graph[r][c] > 0:
                        graph[r][c] -= 1
                        if graph[r][c] == 0:
                            for i in range(4):
                                if graph[newRow][newCol] != 0:
                                    graph[newRow][newCol] += 1
                            count += 1
                else:
                    dfs(visit,newRow,newCol)

row,col = map(int,input().split())
graph = []
ice = []
for i in range(row):
    a = list(map(int,input().split()))
    for j in range(col):
        if a[j] != 0:
            ice.append([i,j])
    graph.append(a)

cnt = 0
lenIce = len(ice)

while True:
    count = 0
    ret = 0
    if lenIce <= 1:
        print(0)
        break
    a = ice[-1][0]
    b = ice[-1][1]
    if graph[a][b] == 0:
        ice.pop()
        continue
    cnt += 1
    dfs([[False] * col for _ in range(row)],a,b)
    if ret != lenIce:
        print(cnt - 1)
        break
    lenIce -= count

