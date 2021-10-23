#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int t, row, col, k;
int map[50][50];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<pair<int, int>>v;

int result;

void bfs(int r , int c) {
	queue<pair<int, int>>q;
	q.push({ r,c });
	result += 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		map[x][y] = 0;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || row <= nx || col <= ny) continue;
			else if (map[nx][ny] == 0) continue;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		result = 0;
		map[50][50];
		v.clear();
		cin >> row >> col >> k;

		//지도 0으로 초기화
		for (int a = 0; a < row; a++) {
			for (int b = 0; b < col; b++) {
				map[a][b] = 0;
			}
		}

		//1 집어넣기
		for (int c = 0; c < k; c++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
			map[x][y] = 1;
		}
		
		for (int x = k-1; x >= 0; x--) {
			int r = v[x].first;
			int c = v[x].second;

			if (map[r][c] == 1) {
				bfs(r, c);
			}
		}
		
		cout << result<<"\n";
	}
	
}