import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

ret = 0
graph = []
visit = [False] * 26
dir = [[1,0],[-1,0],[0,1],[0,-1]]
r,c = map(int,input().split())

for i in range(r):
    graph.append(input())


def dfs(row, col, cnt):
    global ret
    currentVal = graph[row][col]
    visit[ord(currentVal) - 65] = True
    if ret < cnt:
        ret = cnt

    for i in range(4):
        newRow = row + dir[i][0]
        newCol = col + dir[i][1]
        if 0 <= newRow < r and 0 <= newCol < c:
            nextVal = graph[newRow][newCol]
            nextIndex = ord(nextVal) - 65
            if visit[nextIndex] == False:
                dfs(newRow,newCol,cnt + 1)
                visit[nextIndex] = False

dfs(0,0,1)
print(ret)

