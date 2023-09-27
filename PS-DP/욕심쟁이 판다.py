import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(row,col,cnt):
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    ret = cnt

    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < n and 0 <= newCol < n:
            if forest[row][col] < forest[newRow][newCol]:
                if dp[newRow][newCol] != 0:
                    ret = max(ret, cnt + dp[newRow][newCol])
                else:
                    ret = max(ret, dfs(newRow,newCol,cnt + 1))

    dp[row][col] = ret - cnt + 1
    return ret

n = int(input())
dp = [[0] * n for _ in range(n)]
forest = []
result = 1
for _ in range(n):
    forest.append(list(map(int,input().split())))
for i in range(n):
    for j in range(n):
        if dp[i][j] == 0:
            dfs(i,j,1)
        result = max(result, dp[i][j])

print(result)