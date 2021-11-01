#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int T, M, N , K;
int map[50][50] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int y , int x) {
	queue<pair<int, int>>q;
	q.push({y , x});
	map[y][x] = 0;

	while (!q.empty()) {
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int row = ny + dy[i];
			int col = nx + dx[i];

			if (row < 0 || col < 0 || M <= col || N <= row) continue;
			if (map[row][col] != 1) continue;
			q.push({ row,col });
			map[row][col] = 0;
		}
	}
	return 1;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int r = 0; r < N; r++) {
			for (int e = 0; e < M; e++) {
				if (map[r][e] == 1) cnt += bfs(r, e);
			}
		}
		cout << cnt << endl;
	}
}