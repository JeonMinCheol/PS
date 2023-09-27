import sys
n = int(input())
h = list(map(int,sys.stdin.readline().rstrip().split()))
arrow_height = list() # 현재 화살의 높이를 저장하는 리스트

for height in h:
    if height in arrow_height: # 풍선의 높이와 같은 화살이 존재할 경우
        arrow_height.remove(height)
    arrow_height.append(height-1)
print(len(arrow_height)) # arrow_height에 남아있는 화살의 개수만큼 화살이 필요함.