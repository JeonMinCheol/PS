import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(row, col):
    global R, C, ret
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    visit[row][col] = True
    graph[row][col] = 0

    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < R and 0 <= newCol < C:
            if visit[newRow][newCol] == False:
                if graph[newRow][newCol] == 1:
                    ret += 1
                    graph[newRow][newCol] = 0
                    visit[newRow][newCol] = True
                else:
                    dfs(newRow,newCol)

R, C = map(int,input().split())
ret = 0
graph = []

for i in range(R):
    graph.append(list(map(int,input().split())))

temp = 0
cnt = 1
while True:
    temp = ret
    ret = 0
    visit = [[False] * C for _ in range(R)]
    dfs(0,0)
    if ret == 0:
        print(cnt - 1)
        print(temp)
        break
    cnt += 1
    

