import sys
import copy
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

n = int(input())
maxDP = [0,0,0]
minDP = [0,0,0]
for i in range(n):
    arr = list(map(int,input().split()))
    maxTemp = [0,0,0]
    minTemp = [0,0,0]

    maxTemp[0] = max(maxDP[0], maxDP[1]) + arr[0]
    minTemp[0] = min(minDP[0], minDP[1]) + arr[0]

    maxTemp[1] = max(maxDP) + arr[1]
    minTemp[1] = min(minDP) + arr[1]
    
    maxTemp[2] = max(maxDP[1],maxDP[2]) + arr[2]
    minTemp[2] = min(minDP[1],minDP[2]) + arr[2]

    maxDP = maxTemp
    minDP = minTemp
print(max(maxDP), min(minDP))