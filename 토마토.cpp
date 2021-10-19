#include<iostream>
#include<queue>
using namespace std;

int n, m, k;
int map[1001][1001];
pair<int, int>p[4] = { {1,0}, {-1,0},{0,1},{0,-1} };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int row = x + p[i].first;
			int col = y + p[i].second;

			if (row < 1 || col < 1 || n < row || m < col) {
				continue;
			}
			else if (map[row][col] == 0) {
				map[row][col] = map[x][y] + 1;
				q.push({ row,col });
				k = map[row][col];
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];

		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0) {
				cnt++;
			}
		}
	}

	if (cnt == n * m) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0 && map[i][j] != -1) {
				bfs(i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << k;
}