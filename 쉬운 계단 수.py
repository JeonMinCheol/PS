import copy
n = int(input())
arr = [0,1,1,1,1,1,1,1,1,1]
div = 1000000000
cnt = 9
for i in range(1,n):
    cnt = 0
    temp = [0] * 10
    for i in range(10):
        if i == 0:
            temp[1] += arr[0] % div
            cnt = (cnt + arr[0]) % div
        elif i == 9:
            temp[8] += arr[9] % div
            cnt = (cnt + arr[9]) % div
        else:
            temp[i-1] += arr[i] % div
            temp[i+1] += arr[i] % div
            cnt = (cnt + 2 * arr[i]) % div
    arr = temp
print(cnt)     
    