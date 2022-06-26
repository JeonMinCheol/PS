import heapq
n = int(input())
class_room = list()
result = []

for i in range(n):
    klas = list(map(int,input().split()))
    class_room.append(klas[1:])
class_room = sorted(class_room)
for i in range(n):
    heapq.heappush(result,class_room[i][1])
    if result[0] <= class_room[i][0]:
        heapq.heappop(result)
    
        
    

print(len(result))

