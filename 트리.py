import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
def dfs(row):
    global ret
    visit[row] = True
    arr = graph[row]
    if len(arr) == 0:
        ret += 1 

    for i in range(len(arr)):
        if visit[arr[i]]:
            continue
        elif graph[arr[i]] == []:
            ret += 1
        else:
            dfs(arr[i])

n = int(input())
graph = [[] for _ in range(50)]

arrInput = list(map(int, input().split()))
deleteNode = int(input())

rootNode = -1
for i,value in enumerate(arrInput):
    if i == deleteNode:
        continue

    if value == -1:
        rootNode = i
    else:
        if value == deleteNode:
            continue
        graph[value].append(i)

ret = 0
visit = [False] * 50

if rootNode == -1:
    print(0)
else:
    dfs(rootNode)
    print(ret)
