import sys
input = sys.stdin.readline
row, col = map(int,input().split())

result = 0
def dfs(flag , rr, cc):
    global result
    global dp
    global visit
    global graph
    if rr == row - 1 and cc == col -1:
        result += 1
        return True
    
    visit[rr][cc] = True
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    cnt = 0
    for i in range(4):
        newRow = rr + dir[i][0]
        newCol = cc + dir[i][1]
        if 0 <= newRow < row and 0 <= newCol < col:
            if visit[newRow][newCol] == False:
                current = graph[rr][cc]
                newValue = graph[newRow][newCol]
                if dp[newRow][newCol]:
                    dp[rr][cc] += dp[newRow][newCol]
                    result += dp[rr][cc]
                    print(newRow,newCol)
                    for i in range(row):
                        print(dp[i])
                    print()
                    continue
                if current > newValue:
                    if max(flag, dfs(False, newRow,newCol)):
                        cnt += 1
                    visit[newRow][newCol] = False
    if flag == True:
        dp[rr][cc] += 
    return flag
                    
dp = [[0] * col for _ in range(row)]
visit = [[False] * col for _ in range(row)]
graph = []
for i in range(row):
    inp = list(map(int,input().split()))
    graph.append(inp)
dfs(False,0,0)

print(dp)
print(result)