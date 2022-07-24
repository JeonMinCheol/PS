n = int(input())
arr = [0] * (n+1)
arr[0] = 1
arr[1] = 1
for i in range(2, n+1):
    arr[i] += (arr[i-2] + arr[i-1]) % 10007
    
print(arr[n])