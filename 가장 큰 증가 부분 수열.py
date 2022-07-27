
from collections import deque
import sys
input = sys.stdin.readline
size = int(input())
arr = list(map(int,input().split()))
dp = deque()
dp_size = deque() 
for i in range(size-1, -1, -1):
    if i == size - 1:
        dp.appendleft([arr[i]])
        dp_size.appendleft(arr[i])
    else:
        a = [arr[i]]
        z = 0
        index = -1
        for j in range(len(dp_size)):
            if z < dp_size[j] and dp[j][0] > arr[i]:
                z = dp_size[j]
                index = j
        
        if index != -1:
            for j in dp[index]:
                a.append(j)
        dp.appendleft(a)
        dp_size.appendleft(z + arr[i])
        
print(max(dp_size))
            
            