#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <cstring>
using namespace std;
int n, m;
int map[1001][1001];
int temp[1001][1001];
int chk[1001][1001] = { 0, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs() {
	vector<int>v(3);
	v[0] = 0, v[1] = 0, v[2] = 1;

	queue<vector<int>>q;
	q.push(v);
	chk[0][0] = 1;
	temp[0][0] = 1;

	while (!q.empty()) {
		int setY = q.front()[0];
		int setX = q.front()[1];
		int broke = q.front()[2];
		if (setY == n - 1 && setX == m - 1) return temp[n - 1][m - 1];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + setY;
			int nx = dx[i] + setX;

			if (nx < 0 || ny < 0 || m <= nx || n <= ny) continue;
			if (broke == 2 && chk[ny][nx] != 0) continue;
			if (broke == 1 && chk[ny][nx] == 1) continue;
			if (map[ny][nx] != 1) {
				v[2] = broke;
				v[0] = ny, v[1] = nx;
				chk[ny][nx] = broke;
				temp[ny][nx] = temp[setY][setX] + 1;
				q.push(v);
			}
			else if (broke == 1) {
				v[2] = 2;
				v[0] = ny, v[1] = nx;
				chk[ny][nx] = 2;
				temp[ny][nx] = temp[setY][setX] + 1;
				q.push(v);
			}
			if (ny == n - 1 && nx == m - 1) return temp[n - 1][m - 1];
		}
	}
	return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;

		for (int j = 0; j < m; j++) {
			map[i][j] = static_cast<int>(x[j]) - 48;
			temp[i][j] = static_cast<int>(x[j]) - 48;
			if (static_cast<int>(x[j]) - 48 == 1) chk[i][j] = 2;
		}
	}
	cout << bfs();
}