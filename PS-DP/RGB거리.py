import sys
input = sys.stdin.readline
n = int(input())
rgb = []
ret = [[1000001] * 3 for _ in range(n)]
for i in range(n):
    arr = list(map(int,input().split()))
    rgb.append(arr)
    
ret[0] = rgb[0]
for i in range(1,n):
    for j in range(3):
        ret[i][j] = min(ret[i-1][(j+1) % 3], ret[i-1][(j+2) % 3]) + rgb[i][j]

print(min(ret[n-1][0],ret[n-1][1],ret[n-1][2]))