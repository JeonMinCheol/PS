#include<iostream>
#include<queue>
using namespace std;

int n, m;
int map[100][100];
pair<int, int> xy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
void bfs() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xy[i].first;
			int ny = y + xy[i].second;

			if (nx < 0 || ny < 0 || n <= nx || m <= ny) {
				continue;
			}
			else if (map[nx][ny] != 1) {
				continue;
			}
			q.push({ nx,ny });
			map[nx][ny] = map[x][y] + 1;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;

			map[i][j] = int(c) - 48;
		}
	}

	bfs();
	cout << map[n - 1][m - 1];
	return 0;
}