def dfs(index,visit,computer):
    visit[index] = True
    cnt = 1
    for i in computer[index]:
        if visit[i] != True:
            cnt+=dfs(i,visit,computer)
    return cnt

n = int(input())
m = int(input())
visit = [False]*(n)
computer = [[] for _ in range(n)]

for _ in range(m):
    a,b = map(int,input().split())
    computer[a-1].append(b-1)
    computer[b-1].append(a-1)


print(dfs(0,visit,computer)-1)