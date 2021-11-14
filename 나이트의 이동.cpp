#include<iostream>
#include<queue>
using namespace std;

int t, l, ax, ay, tx, ty;
int chess[300][300];
bool check[300][300];
int xy[8][2] = { {2,1} , {2,-1} , {1,2} , {1,-2} , {-1, 2}, {-1, -2} , {-2, 1} , { -2, -1} };
void bfs() {
	queue <pair<int, int>>q;
	q.push({ ay,ax });
	check[ay][ax] = true;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		int cnt = chess[y][x];
		q.pop();
		if (y == ty && x == tx) {
			cout << chess[y][x] << endl;
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + xy[i][0];
			int ny = y + xy[i][1];

			if (ny < 0 || nx < 0 || l <= nx || l <= ny) continue;
			if (check[ny][nx] == true) continue;
			q.push({ ny,nx });
			check[ny][nx] = true;
			chess[ny][nx] = cnt + 1;
		}
	}
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l >> ay >> ax >> ty >> tx;
		memset(chess, 0, sizeof(chess));
		memset(check, false, sizeof(check));
		bfs();
	}
}