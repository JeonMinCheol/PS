import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(ret, node, visit, level):
    visit[node] = True
    arr = graph[node]
    for x in arr:
        if visit[x] != True:
            ret.append([level,x])
            dfs(ret,x,visit,level+1)

test = int(input())


while test:
    test -= 1
    Node = int(input())
    visit = [False] * (Node+1)
    graph = [[] for _ in range(Node + 1)]
    for _ in range(Node-1):
        parent , child = map(int,input().split())
        graph[child].append(parent)

    parent1, parent2 = map(int, input().split())
    a = [[0,parent1]]
    b = [[0,parent2]]
    dfs(a, parent1, [False] * (Node+1), 1)
    dfs(b, parent2, [False] * (Node+1), 1)
    a = sorted(a)
    b = sorted(b)

    flag = True
    for i in a:
        if flag == False: 
            break
        flag = True
        for j in b:
            if i[1] == j[1]:
                print(i[1])
                flag = False
                break

