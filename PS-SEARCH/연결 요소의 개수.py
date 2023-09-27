a = list(map(int,input().split()))
n=a[0]
b=a[1]
array = [[] for _ in range(n)]
visit = [0]*1000

def dfs(array,visit,index):
    visit[index] = 1
    for i in array[index]:
        if visit[i] != 1:
            dfs(array,visit,i)


for _ in range(b):
    a = list(map(int,input().split()))
    u = a[0]
    v = a[1]
    array[u-1].append(v-1)
    array[v-1].append(u-1)

ret =0
for i in range(n):
    x = array[i]
    if x == []:
        ret+=1
        continue
    for j in x:
        if visit[j] != 1:
            dfs(array,visit,j-1)
            ret +=1

print(ret)