#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 1e9 + 1
using namespace std;

int n, dx[4] = { 1,-1,0,0 }, dy[4] = {0,0,1,-1};
long long dist[51][51];
vector<vector<int>>v(51,vector<int>(51));

int stra() {
	queue<vector<int>>q;
	q.push({ 0, 1, 1 });
	dist[1][1] = 0;
	while (!q.empty()) {
		int x = q.front()[1];
		int y = q.front()[2];
		int cost = -q.front()[0];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int row = x + dx[i];
			int col = y + dy[i];
			if (row < 1 || col < 1 || n < row || n < col) continue;
			else if (v[row][col] == 1 && dist[row][col] > cost) {
				q.push({ -cost,row,col });
				dist[row][col] = cost;
			}
			else if (v[row][col] == 0 && dist[row][col] > cost + 1) {
				q.push({ -cost - 1, row,col });
				dist[row][col] = cost + 1;
			}
		}

	}
	return dist[n][n];
}

int main() {
	cin >> n;
	fill_n(&dist[0][0], 51 * 51, INF);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			v[i][j] = 1;
			if (c == '0') v[i][j] = 0;
		}
	}
	cout << stra();
}