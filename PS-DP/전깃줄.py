import sys
input = sys.stdin.readline
n = int(input())
graph = []
dp = [1]

for i in range(n):
    arr = list(map(int,input().split()))
    graph.append(arr)
graph.sort()

for i in range(1,n):
    elem = graph[i]
    cnt = 1
    for index, elemDP in enumerate(dp):
        a = graph[index][0]
        b = graph[index][1]
        if a < elem[0] and b < elem[1]:
            cnt = max(cnt, elemDP + 1)
    dp.append(cnt)

print(n - max(dp))