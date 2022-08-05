from collections import deque
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    ret = 0
    k = int(input())
    arr = deque(map(int,input().split()))

    while len(arr) > 2:
        while len(arr) >= 3:
            a = arr.popleft()
            b = arr.popleft()
            # arr의 원소가 1개 남거나 (그러면 옆에 있는 DP와 더함.) 인접 DP와 더한 것이 인접 원소와 더한 것 보다 크다면. (등호는 모르것다)
            comp = 0
            if len(arr) == 0 or a > arr[0]:
                comp = a + b
                arr.appendleft(comp)
            else:
                comp = arr.popleft() + b
                arr.appendleft(comp)
                arr.appendleft(a)
            print(arr)
            ret += comp
    ret += arr[0] + arr[1]
    print(ret)
