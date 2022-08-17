import sys
input = sys.stdin.readline 
n, m = map(int, input().split())

memory = list(map(int,input().split()))
cost = list(map(int,input().split()))
arr = []
for i in range(n):
    arr.append([cost[i],memory[i]])

arr = sorted(arr)
print(arr)
