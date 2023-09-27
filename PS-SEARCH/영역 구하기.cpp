#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int m, n, k;
int map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int bfs(int x, int y) {
	queue<pair<int, int>>q;
	int size = 1;
	map[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];

			if (nx < 0 || ny < 0 || m <= nx || n <= ny)continue;
			else if (map[nx][ny] != 0) continue;
			map[nx][ny] = 1;
			size++;
			q.push({ nx,ny });
		}
	}
	return size;
}

void build(int a, int b, int c, int d) {
	int fr = m - b;
	int fc = a;
	int sr = m - d;
	int sc = c - 1;

	for (int i = sr; i< fr; i++) {
		for (int j = fc; j <= sc; j++) {
			map[i][j] = 1;
		}
	}
}
int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		build(a, b, c, d);
	}

	vector<int>v;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 1) v.push_back(bfs(i, j));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int elem : v) {
		cout << elem << " ";
	}
}
