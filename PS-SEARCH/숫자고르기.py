import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(index, indexSet, valueSet):
    visit[index] = True
    ret = []

    value = graph[index]
    indexSet.add(index)
    valueSet.add(value)

    if indexSet == valueSet and indexSet != set():
        ret = list(indexSet)

    if not visit[value]:
       ret = dfs(value,indexSet,valueSet)
    if ret == []:
        visit[index] = False

    return ret

n = int(input())
graph = [0]*(n+1)
visit = [False]*(n+1)
for i in range(1,n+1):
    graph[i] = int(input())

result = []
for i in range(1,n+1):
    if visit[i] == False:
        ret = dfs(i,set(),set())
        if ret != []:
            result += ret

result.sort()
print(len(result))
for i in result:
    print(i)
