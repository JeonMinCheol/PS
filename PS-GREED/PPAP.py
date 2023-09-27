PPAP = input().rstrip()
str = []
result = "PPAP"
for i in range(len(PPAP)):
    if PPAP[i] == "P":
        str.append("P")
    else:
        # A다음에 P가 나오지 않는 경우
        if i == len(PPAP)-1 or PPAP[i+1] != "P":
            result = "NP"
            break
        # 현재까지 저장된 문자열의 길이가 2보다 작은 경우 
        elif len(str) < 2: 
            result = "NP"
            break
        str.pop()
        str.pop()
if len(str) != 1:
    print("NP")
else:
    print(result)

