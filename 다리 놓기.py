import sys
input = sys.stdin.readline
def c(a,b):
    ret = 1
    for i in range(1,a + 1):
        ret *= b
        ret //= i
        b -= 1

    return int(ret)

t = int(input())
while t:
    t-= 1
    a, b = map(int,input().split())
    print(c(a,b))
    