import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(row,col):
    global n,m
    visit[row][col] = True
    cnt = 0

    if row == n - 1 and col == m - 1:
        dp[row][col] = 1
    if dp[row][col] != 0: 
        return dp[row][col]
    
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < n and 0 <= newCol < m:
            if visit[newRow][newCol] == False:
                if graph[newRow][newCol] < graph[row][col]:
                    if dfs(newRow,newCol):
                        cnt += dfs(newRow,newCol)
                        visit[newRow][newCol] = False
    dp[row][col] += cnt
    return cnt


n, m = map(int,input().split())
graph = []
dp = [[0] * m for _ in range(n)]    
visit = [[False] * m for _ in range(n)]
for i in range(n):
    graph.append(list(map(int,input().split())))
dfs(0,0)
print(dp[0][0])