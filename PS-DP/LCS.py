a = input().rstrip()
b = input().rstrip()
lcs = [[0] * len(a) for _ in range(len(b))] 

for row, rowElement in enumerate(b):
    flag = True
    for col, colElement in enumerate(a):
        if row == 0 and col != 0:
                lcs[0][col] = lcs[0][col-1]
        elif row != 0 and col == 0:
            lcs[row][col] = lcs[row-1][col]
        elif row > 0 and col > 0:
            lcs[row][col] = max(lcs[row-1][col], lcs[row][col-1])
        
        if rowElement == colElement:
            if row == 0 or col == 0:
                lcs[row][col] = 1
            else:
                lcs[row][col] = lcs[row-1][col-1] + 1
print(lcs[-1][-1])