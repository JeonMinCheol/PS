n = int(input())
town = []
sum = 0

for i in range(n):
    town.append(list(map(int,input().split())))

town.sort()
left = right = 0

left_index = -1
right_index = n
while left_index < right_index:
    if left >= right:
        right_index -= 1
        right += town[right_index][1]
    else:
        left_index += 1
        left += town[left_index][1]
        

print(town[left_index][0])