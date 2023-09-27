n = int(input())
arr = list(map(int,input().split()))

result = 0

while True:
    flag = True
    for i in range(n):
        if arr[i] != 0 and arr[i] - 1 != 0:
            flag = False
        
        if arr[i] % 2 != 0:
            arr[i] -= 1
            result += 1
    if flag:
        break

    for i in range(n):
        arr[i] /= 2
    result += 1

print(result)