a = input()
b = input()
maxLength = max(len(a),len(b))
minLength = min(len(a),len(b))
dp = [[0] * (maxLength + 1) for _ in range(minLength + 1)]
result = []

def dfs(row,col,m):
    global dp, result
    if row and col:
        if dp[row-1][col] == dp[row][col]:
            dfs(row-1,col,m)
        elif dp[row][col-1] == dp[row][col]:
            dfs(row,col-1,m)
        else:
            result.append(m[col-1])
            dfs(row-1,col-1,m)
    else:
        return

if maxLength != len(a):
    for row,letter_a in enumerate(a):
        for col,letter_b in enumerate(b):
            if letter_a == letter_b:
                dp[row+1][col+1] = dp[row][col] + 1
                continue

            dp[row+1][col+1] = max(dp[row+1][col], dp[row][col+1])
else:
    for row,letter_b in enumerate(b):
        for col,letter_a in enumerate(a):
            if letter_a == letter_b:
                dp[row+1][col+1] = dp[row][col] + 1
                continue

            dp[row+1][col+1] = max(dp[row+1][col], dp[row][col+1])
if len(a) == maxLength:
    dfs(minLength,maxLength,a)
else:
    dfs(minLength,maxLength,b)
result.reverse()
print(dp[minLength][maxLength])
print(''.join(result))