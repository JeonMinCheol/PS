#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int w = 1, h = 1, cnt;
int map[50][50] = { 0, };
int dy[8] = { 1,-1,0,0 , 1,1,-1,-1 };
int dx[8] = { 0,0, 1,-1 , 1, -1 ,1,-1 };

void bfs(int row, int col) {
	queue<pair<int, int>>q;
	q.push({ row,col });
	map[row][col] = 0;
	cnt++;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = a + dy[i];
			int nx = b + dx[i];

			if (ny < 0 || nx < 0 || h <= ny || w <= nx) continue;
			if (map[ny][nx] != 1) continue;
			q.push({ ny,nx });
			map[ny][nx] = 0;
		}
	}
}
int main() {
	while (w != 0 && h != 0) {
		cin >> w >> h;
		cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) bfs(i, j);
			}
		}
		if(w!=0 || h!=0) cout << cnt << endl;
	}
}