def change(arr,x, y):
    temp = arr[x]
    arr[x] = arr[y]
    arr[y] = temp

n = int(input())
arr = list(map(int,input().split()))
s = int(input())
start = 0

while(s > 0):
    if start + 1 >= n:
        break

    end = start + s + 1
    index = start
    maximum = arr[index]
   
    for i in range(1 + start, min(n,end)):
        if maximum < arr[i]:
            index = i
            maximum = arr[i]
    
    while index - start > 0:
        change(arr,index,index-1)
        index -=1
        s -=1

    start+=1

    
for i in arr:
    print(i, end=" ")
        
    
