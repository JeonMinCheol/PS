n = int(input())
arr = [1000000] * (n+1)
arr[0] = 0
for i in range(n+1):
    if i >= 5:
        arr[i] = min(arr[i-5], arr[i-3]) + 1
    elif i >= 3:
        arr[i] = min(arr[i], arr[i-3]) + 1
if arr[n] >= 1000000:
    print(-1)
else:
    print(arr[n])