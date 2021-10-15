#include<iostream>
#include<queue>
using namespace std;
// 처음 위치는 (1,1) , 출구는 (N,M)
// 괴물이 있는 부분은 0, 괴물이 없는 부분은 1
// 움직이는 최소 칸 수를 구하라
//첫째줄에 N,M(3 < N,M < 201)이 주어지고 다음 N개의 줄에 M개의 정수 0 혹은 1이 공백없이 붙어서 주어진다.

/*
5 6
101010
111111
000001
111111
111111
*/

int n, m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[201][201];

void bfs() {
	queue<pair<int,int>>q;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int visit = map[x][y];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			else if (map[nx][ny] == 0) continue;
			else if (map[nx][ny] == 1) {
				map[nx][ny] = map[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			
		}
	}

	cout << map[n][m];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tile;
			cin >> tile;
			map[i][j] = int(tile) - 48;
		}
	}

	bfs();
	return 0;
}