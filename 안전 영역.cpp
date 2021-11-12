#include<iostream>
#include<queue>
using namespace std;

int N, mAx = 0, cnt, result=1;
int map[100][100] ,temp[100][100];

int drow[4] = { 1,-1,0,0 };
int dcol[4] = { 0,0,-1,1 };

int bfs(int row, int col , int height) {
	queue<pair<int, int>>q;
	q.push({ row,col });
	temp[row][col] = -1;
	cnt++;

	while (!q.empty()) {
		int x = q.front().second , y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dcol[i];
			int ny = y + drow[i];

			if (nx < 0 || ny < 0 || N <= nx || N <= ny) continue;
			else if (temp[ny][nx] <= height) continue;
			q.push({ ny,nx });
			temp[ny][nx] = -1;
		}
		
	}
	return cnt;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			mAx = max(mAx, map[i][j]);
		}
	}

	for (int height = 0; height < mAx; height++) {
		copy(&map[0][0], &map[0][0] + 10000, &temp[0][0]);
		cnt = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp[i][j] > height) bfs(i, j, height);
			}
		}
		result = max(result, cnt);
	}
	cout << result;
}