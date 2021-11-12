#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<char>>normal;
vector<vector<char>>Red_green;
int cnt1=0, cnt2=0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(vector<vector<char>>& v, int& cnt, int row, int col) {
	queue<pair<int, int>>q;
	q.push({ row,col });
	char temp = v[row][col];
	v[row][col] = 'X';
	cnt++;

	while (!q.empty()) {
		char y = q.front().first;
		char x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || n <= nx || n <= ny) continue;
			else if (v[ny][nx] != temp) continue;
			q.push({ ny,nx });
			v[ny][nx] = 'X';
		}
	}
}
int main() {
	cin >> n;
	normal.resize(n);
	Red_green.resize(n);

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < n; j++) {
			char x = st[j];
			normal[i].push_back(x);

			if (x == 'G') x = 'R';
			Red_green[i].push_back(x);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (normal[i][j] != 'X') bfs(normal, cnt1, i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Red_green[i][j] != 'X') bfs(Red_green, cnt2, i, j);
		}
	}

	cout << cnt1 << " " << cnt2;
}