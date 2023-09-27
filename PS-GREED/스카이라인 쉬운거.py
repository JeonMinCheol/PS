n = int(input())
building = []
result = 0
for i in range(n):
    a = list(map(int,input().split()))
    if len(building) == 0:
        if a[1] != 0:
            building.append(a[1])
        continue
        
    while building[-1] > a[1] and len(building)>0:
        building.pop()
        result+=1
        if len(building) == 0:
            break
        
    if (len(building) == 0 or building[-1] < a[1]) and a[1] != 0:
        building.append(a[1])

print(result + len(building))

