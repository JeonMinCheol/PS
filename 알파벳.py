import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

graph = []
visit = [False] * 26
r,c = map(int,input().split())
dir = [[1,0],[-1,0],[0,1],[0,-1]]

ret = 0
def dfs(row, col, cnt):
    global ret
    currentVal = graph[row][col]
    visit[ord(currentVal) - 65] = True
    ret = max(ret, cnt )

    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < r and 0 <= newCol < c:
            nextVal = graph[newRow][newCol]
            nextIndex = ord(nextVal) - 65
            if visit[nextIndex] == False:
                dfs(newRow,newCol,cnt + 1)
                visit[nextIndex] = False



for i in range(r):
    graph.append(input())
dfs(0,0,1)
print(ret)