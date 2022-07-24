n = int(input())
arr = [987654321] * (n+1)
arr[1] = -1
for i in range(1, n+1):
    if i % 3 == 0:
        arr[i] = arr[int(i/3)]
    if i % 2 == 0:
        arr[i] = min(arr[int(i/2)], arr[i]) 
    arr[i] = min(arr[i],arr[i-1]) + 1
print(arr[n])