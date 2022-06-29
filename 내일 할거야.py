def compare(x,y):
    if x[1] > y[1]:
        return True
    return False

n = int(input())
work = [];

for x in range(n):
    t_and_d = list(map(int,input().split()))
    work.append(t_and_d)
work.sort(key = lambda x:x[1], reverse=True)

result = 0 
day = work[0][1] - work[0][0] + 1
for i in range(1,len(work)):
    t = work[i][0]
    end = work[i][1]
    if end >= day:
        end = day - 1
    day = end - t + 1
print(day - 1)