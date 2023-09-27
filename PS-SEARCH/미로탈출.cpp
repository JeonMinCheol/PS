#include<iostream>
#include<queue>
using namespace std;
// ó�� ��ġ�� (1,1) , �ⱸ�� (N,M)
// ������ �ִ� �κ��� 0, ������ ���� �κ��� 1
// �����̴� �ּ� ĭ ���� ���϶�
//ù°�ٿ� N,M(3 < N,M < 201)�� �־����� ���� N���� �ٿ� M���� ���� 0 Ȥ�� 1�� ������� �پ �־�����.

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