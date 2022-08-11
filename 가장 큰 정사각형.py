import sys
input = sys.stdin.readline
n,m = map(int,input().split())
arr = []
arr.append([0] * (m+1))
for i in range(n):
    array = [0]
    inp = input()
    for j in range(m):
        array.append(int(inp[j]))
    arr.append(array)

ret = 0
for i in range(n+1):
    for j in range(m+1):
        if arr[i][j] == 0:
            continue
        arr[i][j] = min(arr[i-1][j-1], arr[i][j-1], arr[i-1][j]) + 1
        ret = max(ret, arr[i][j])
print(ret * ret)