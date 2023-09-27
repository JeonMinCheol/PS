import heapq
import sys
testCase = int(input())
input = sys.stdin.readline

for _ in range(testCase):
    result = 1
    slime = int(input())
    energy = list(map(int,sys.stdin.readline().split()))
    heapq.heapify(energy)

    while len(energy) > 1:
        a = heapq.heappop(energy)
        b = heapq.heappop(energy)
        newSlimeEnergy = (a * b)

        heapq.heappush(energy, newSlimeEnergy)
        result = (result * (newSlimeEnergy % 1000000007)) % 1000000007;
    print(result)
    
    
