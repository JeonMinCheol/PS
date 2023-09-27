import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
subset = list(map(int,input().split()))
inclineDP = []
declineDP = deque()

for i in range(n):
    if i == 0:
        inclineDP.append([subset[i]])
    else:
        arr = []
        index = -1
        size = 0
        for k in range(len(inclineDP)):
            if size < len(inclineDP[k]) and inclineDP[k][-1] < subset[i]:
                index = k
                size = len(inclineDP[k])

        if index != -1:
            for k in inclineDP[index]:
                arr.append(k)
        arr.append(subset[i])
        inclineDP.append(arr)
        
subset.reverse()        
for i in range(n):
    if i == 0:
        declineDP.append([subset[i]])
    else:
        arr = []
        index = -1
        size = 0
        for k in range(len(declineDP)):
            if size < len(declineDP[k]) and declineDP[k][-1] < subset[i]:
                index = k
                size = len(declineDP[k])

        if index != -1:
            for k in declineDP[index]:
                arr.append(k)
        arr.append(subset[i])
        declineDP.appendleft(arr)


ret = 0
for i in range(n):
    ret = max(ret, len(inclineDP[i]) + len(declineDP[i]) - 1)
print(ret)