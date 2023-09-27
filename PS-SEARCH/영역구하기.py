import heapq
import sys

sys.setrecursionlimit(10**6)
m,n,k = map(int,input().split())
graph = [[0] * n for _ in range(m)]
for _ in range(k):
    low_x,low_y,high_x,high_y = map(int,input().split())

    for x in range(low_x, high_x):
        for y in range(low_y,high_y):
           row = m - 1 - y
           col = x 
           graph[row][col] = 1

def dfs(row, col,area):
    area += 1
    graph[row][col] = 1
    dir = [[1,0],[-1,0],[0,1],[0,-1]]

    for i in range(4):
        n_row = row + dir[i][0]
        n_col = col + dir[i][1]
        if 0<=n_row<m and 0<=n_col<n:
            if graph[n_row][n_col] == 0:
                area = max(area, dfs(n_row, n_col,area))
    return area
    
ret = 0
area = []
for i in range(m):
    for j in range(n):
        if graph[i][j] == 0:
            ret += 1
            heapq.heappush(area,dfs(i,j,0))
print(ret)
for _ in range(len(area)):
    print(heapq.heappop(area), end =" ")