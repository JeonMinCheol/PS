#include<iostream>
#include<queue>
using namespace std;

int n, m, day = -1;
int map[1000][1000];

queue<pair<int, int>> q;
pair<int, int>p[4] = { {1,0}, {-1,0},{0,1},{0,-1} };

void bfs() {
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int l = 0; l < 4; l++)
		{
			int nx = cur.first + p[l].first;
			int ny = cur.second + p[l].second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (map[nx][ny] != 0) continue;

			map[nx][ny] = map[cur.first][cur.second] + 1;

			q.push({ nx,ny });

			day = max(day, map[nx][ny]);
		}
	}
}

int main() {
	cin >> m >> n;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) q.push({ i,j });
			else if (map[i][j] == 0) zero = true;
		}
	}

	if (!zero) {
		cout << 0;
		return 0;
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day - 1;
}