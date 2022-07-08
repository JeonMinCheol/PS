import sys
sys.setrecursionlimit(10**6)
normal = []
greenRed = []
n = int(input())

def dfs(char,graph,row,col):
    graph[row][col] = 'X'
    dx = [1,-1,0,0]
    dy = [0,0,1,-1]
    for i in range(4):
        if row + dx[i] <= -1 or row + dx[i] >= n or col + dy[i] <= -1 or col + dy[i] >= n:
            continue 
        elif graph[row+dx[i]][col+dy[i]] != char:
            continue
        dfs(char, graph,row+dx[i],col+dy[i])

def Print(graph):
    ret = 0
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] != 'X':
                dfs(graph[i][j],graph,i,j)
                ret+=1
    print(ret, end=" ")

for _ in range(n):
    string = input()
    a = []
    b = []
    for j in range(n):
        char = string[j]
        a.append(char)
        if char == 'R':
            b.append('G')
        else:
            b.append(char)
    normal.append(a)
    greenRed.append(b)

Print(normal)
Print(greenRed)