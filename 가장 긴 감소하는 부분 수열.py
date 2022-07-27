import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int,input().split()))
arr.reverse()
dp = [[arr[0]]]
for i in range(1,n):
    index = -1
    size = 0
    for j in range(len(dp)):
        if dp[j][-1] < arr[i] and size < len(dp[j]):
            size = len(dp[j])
            index = j
    a = []
    if index != -1:
        for j in dp[index]:
            a.append(j)
    a.append(arr[i])
    dp.append(a)

result = 0
for i in dp:
    result = max(result,len(i))
print(result)