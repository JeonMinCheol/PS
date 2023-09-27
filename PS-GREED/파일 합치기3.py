import heapq
import sys
input = sys.stdin.readline
test = int(input())
while(test):
    test-=1
    k = int(input())
    inp = list(map(int,input().split()))
    heapq.heapify(inp)
    
    result = 0
    while len(inp):
        temp = 0
        for i in range(2):
            temp+=inp[0]
            heapq.heappop(inp)

        result += temp
        if len(inp) == 0:
            break

        heapq.heappush(inp,temp)

    print(result)
    
