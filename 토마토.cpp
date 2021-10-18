#include<iostream>
using namespace std;

int n, m;
int cnt = 0;
int box[1001][1001];
bool visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || 1000 < nx || 1000 < ny) {
			continue;
		}
		if (!visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int check() {
	for (auto& row : box) {
		for (auto col : row) {
			if (col == 0) return 0;
		}
	}
	return 1;
}

int main() {
	cin >> n >> m;
	int x = 0, y=0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			cin >> box[i][j];
			visited[i][j] = false;
			cnt++;

			if (box[i][j] == -1 || box[i][j] == 1) visited[i][j] = true;
		}
	}

	if (check()) {
		cout << 0;
		return 0;
	}


	for (auto& row : box) {
		for (auto col : row) {
			if (col == 0) {
				dfs(x, y);
			}
			y++;
		}
		x++;
		y = 0;
	}

	

	for (auto& row : visited) {
		for (auto col : row) {
			if (col == false) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt;
	return 0;
}