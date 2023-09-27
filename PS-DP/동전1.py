import sys
input = sys.stdin.readline
n,k = map(int,input().split())
coins = []
arr = [0] * 10001
for _ in range(n):
    coins.append(int(input()))

coins = sorted(coins)
for coin in coins:
    for i in range(1, k+1):
        if i == coin:
            arr[i] += 1
        elif i > coin:
            arr[i] += arr[i-coin]
print(arr[k])