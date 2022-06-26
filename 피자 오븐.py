import math
t = int(input())
for i in range(t):  
    result = [0]*5
    case = int(input())
    while True:
        if case >= 60:
            result[0]+= case // 60
            case %= 60
            continue
        elif case >= 10:
            temp = case
            if temp % 10 == 5: 
                temp += 5
            temp = round(temp,1)
            if case >= 35:
                if case // 10 + case % 10 <= 1 + 6 - temp // 10 + abs(temp - case):
                    result[1] += case // 10
                    result[3] += case % 10
                else:
                    result[0] += 1
                    result[2] += 6 - temp // 10
                    if temp < case:
                        result[3] += abs(temp - case)
                    else:   
                        result[4] += abs(temp-case)
            else: 
                if(case % 10 <= 5):
                    result[1] += case // 10
                    result[3] += case % 10
                else:
                    result[1] += case // 10  + 1
                    result[4] += abs(temp - case)
        else:
            if case > 5:
                result[1] +=1
                result[4] += 10 - case
            else:
                result[3] += case
        break
    
    for i in range(5):
        print(result[i], end = " ")