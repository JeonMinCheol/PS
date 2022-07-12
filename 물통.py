import sys
import copy
sys.setrecursionlimit(10**8)
a,b,c = map(int,input().split())
visit = []
ret = []

def dfs(water):
    if water in visit:
        print(water)
        return False
    elif water[0] == 0:
        ret.append(water[2])

    print(water)
    visit.append(water)
    
    x = copy.deepcopy(water[0])
    y = copy.deepcopy(water[1])
    z = copy.deepcopy(water[2])
    # A에서 다른 물통으로 물을 줄 때
    if x + y <= b:
        dfs([0,y + x, z])  
    if x + y > b:
        dfs([x-(b-y), b, z])

    if x + z <= c:
        dfs([0,y,x+z])
    if x + z > c:
        dfs([x-(c-z),y,c])

    # B에서 다른 물통으로 물을 줄 때
    if x + y <= a:
        water[0] += y
        water[1] = 0
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z       
    if x + y > a:
        water[0] = a
        water[1] -= x
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z   

    if y + z <= c:
        water[2] += y
        water[1] = 0
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z       
    if y + z > c:
        water[2] = c
        water[1] -= z
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z    

    # C에서 다른 물통으로 물을 줄 때
    if z + x <= a:
        water[0] += z
        water[2] = 0
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z       
    if z + x > a:
        water[0] = a
        water[2] -= x
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z   

    if y + z <= b:
        water[1] += z
        water[2] = 0
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z       
    if y + z > b:
        water[1] = b
        water[2] -= y
        dfs(water)
    water[0] = x 
    water[1] = y
    water[2] = z   
dfs([0,0,c])
print(sorted(ret))