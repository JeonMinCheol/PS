div = 9901
n = int(input())

none = [1]
up = [1]
down = [1]
for i in range(1,n):
    a = none[-1] + up[-1] + down[-1]
    b = none[-1] + up[-1]
    none.append(a)
    up.append(b)
    down.append(b)

print(none[-1] + up[-1] + down[-1])