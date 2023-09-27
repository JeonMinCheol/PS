#include<iostream>
using namespace std;

int r, c;
char map[10000][500];
char chk[10000][500];
int row[3] = { -1,0,1 };
int col[3] = { 1,1,1 };

int dfs(int y, int x) {
	chk[y][x] = 'x';
	if (x == c - 1) return 1;

	for (int i = 0; i < 3; i++) {
		int nx = x + col[i];
		int ny = y + row[i];

		if (nx < 0 || ny < 0 || c <= nx || r <= ny) {
			continue;
		}
		else if (chk[ny][nx] == 'x') continue;

		if (dfs(ny, nx) == 1) return 1;
	}

	return 0;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			chk[i][j] = map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		cnt+=dfs(i, 0);
	}

	cout << cnt;
}