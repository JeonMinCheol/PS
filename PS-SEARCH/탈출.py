import sys
from collections import deque

def bfs(water,biber):
    dir = [[1,0],[-1,0],[0,1],[0,-1]]
    waterq = deque()
    biberq = deque()
    for i in water:
        waterq.append(i)
    biberq.append(biber)
    count = 1

    while biberq:
        waterArr = []
        while waterq:
            a = waterq.popleft()
            waterRow = a[0]
            waterCol = a[1]
            graph[waterRow][waterCol] = '*'
            for i in range(4):
                    newWaterRow = waterRow + dir[i][0]
                    newWaterCol = waterCol + dir[i][1]
            
                    if 0<= newWaterRow < R and 0 <= newWaterCol < C:
                        if graph[newWaterRow][newWaterCol] == '.' or graph[newWaterRow][newWaterCol] == 'S':
                            graph[newWaterRow][newWaterCol] = '*'
                            waterArr.append([newWaterRow, newWaterCol])

        biberArr = []        
        while biberq:
            b = biberq.popleft()
            biberRow = b[0]
            biberCol = b[1]
            graph[biberRow][biberCol] = 'S'
            for i in range(4):
                    newBiberRow = biberRow + dir[i][0]
                    newBiberCol = biberCol + dir[i][1]
            
                    if 0<= newBiberRow < R and 0 <= newBiberCol < C:
                        if graph[newBiberRow][newBiberCol] == 'D':
                                return count
                        if graph[newBiberRow][newBiberCol] == '.':
                            graph[newBiberRow][newBiberCol] = 'S'
                            biberArr.append([newBiberRow, newBiberCol])

        for x in waterArr:
            waterq.append(x)        
        for x in biberArr:
            biberq.append(x)
        
        count += 1
    return 'KAKTUS'


input = sys.stdin.readline

R,C = map(int,input().split())
graph = []
water = []
biber = []
for i in range(R):
    arr = []
    inp = input()
    for j in range(C):
        arr.append(inp[j])
        if inp[j] == '*':
            water.append([i,j])
        elif inp[j] == 'S':
            biber = [i,j]
    graph.append(arr)
if biber != []:
    print(bfs(water,biber))
else:
    print('KAKTUS')