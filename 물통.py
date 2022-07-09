import sys
sys.setrecursionlimit(10**6)
A,B,C = map(int,input().split())
ret = []
visit = []
def dfs(water):
    visit.append(water)
    if water[0] == 0:
        ret.append(water[2])
    q = water[0]
    w = water[1]
    e = water[2]
    for i in range(3):
        if i == 0:
            if q <= B - w:
                if [0,w + q,e] not in visit:
                    dfs([0,w + q, e])
            else:
                if [q - B + w, B, e] not in visit:
                    dfs([q - B + w, B, e])
                    
            if q <= C - e:
                if [0, w, q + e] not in visit:
                    dfs([0, w, q + e])
            else:
                if [q - C + e, w, C] not in visit:
                    dfs([q - C + e, w, C])
                    
        elif i == 1:
            if w <= A - q:
                if [q + w, 0, e] not in visit:
                    dfs([q + w, 0, e])
            else:
                if [A, w - A + q, e] not in visit:
                    dfs([A, w - A + q, e])
                    
            if w <= C - e:
                if [q, 0, w + e] not in visit:
                    dfs([q, 0, w + e])
            else:
                if [q, w - C + e, C] not in visit:
                    dfs([q, w - C + e, C])
            
        else:    
            if e <= A - q:
                if [q + e, w, 0] not in visit:
                    dfs([q + e, w, 0])
            else:
                if [A, w, e - A + q] not in visit:
                    dfs([A, w, e - A + q])
                    
            if e <= B - w:
                if [q, w + e, 0] not in visit:
                    dfs([q, w + e, 0])
            else:
                if [q, B, e - B + w] not in visit:
                    dfs([q, B, e - B + w])        

dfs([0,0,C])
for i in sorted(ret):
    print(i, end = " ")