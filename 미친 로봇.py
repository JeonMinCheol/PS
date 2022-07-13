import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

array = list(map(int, input().split()))
n = array[0]
visit = set()
ret = 0
prob = list(map(lambda x : (x/100), array[1:]))
def dfs(x, y, cnt,p):
    global ret
    if (x,y) in visit:
        ret+=p
        return 
    else:
        visit.add((x,y))

    if cnt < n:
        dir = [[1,0],[-1,0],[0,1],[0,-1]]
        for i in range(4):
            if (x + dir[i][0], y + dir[i][1]) in visit:
                dfs(x + dir[i][0], y + dir[i][1],  cnt + 1, p * prob[i])
            else:
                dfs(x + dir[i][0], y + dir[i][1],  cnt + 1, p * prob[i])
                visit.remove((x + dir[i][0],y + dir[i][1]))

dfs(0,0,0,1)
print("%0.11f"%(1 - ret))

