#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, pair<int, int>>>q; // height , pair<row,col>
int row, col, height;
int tomato[100][100][100];
int dh[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 0,0,0,0,1,-1 };

void bfs(int z, int y, int x) {
	int max_day = 0;

	while (!q.empty()) {
		int h = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		int count = tomato[h][r][c];
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = h + dh[i];
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nh < 0 || nr < 0 || nc < 0 || height <= nh || row <= nr || col <= nc) continue;
			if (tomato[nh][nr][nc] != 0) continue;
			q.push({ nh,{nr,nc} });
			tomato[nh][nr][nc] = count + 1;
		}
	}
}
int main() {
	cin >> col >> row >> height;
	int raw = 0;
	for (int h = height - 1; h >= 0; h--) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				cin >> tomato[h][r][c];
				if (tomato[h][r][c] == 0) raw++;
				else if (tomato[h][r][c] == 1) q.push({ h,{r,c} });
			}
		}
	}
	if (raw == 0) {
		cout << 0;
		return 0;
	}

	for (int h = height - 1; h >= 0; h--) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (tomato[h][r][c] == 1) bfs(h, r, c);
			}
		}
	}

	int max = 0;
	for (int h = height - 1; h >= 0; h--) {
		for (int r = row - 1; r >= 0; r--) {
			for (int c = 0; c < col; c++) {
				if (tomato[h][r][c] == 0) {
					cout << -1;
					return 0;
				}
				if (tomato[h][r][c] > max) max = tomato[h][r][c];
			}
		}
	}
	cout << max - 1;
	return 0;
}