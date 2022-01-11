#include<iostream>
#include<vector>
using namespace std;

int row, col;
int map[500][500];
int dp[500][500];
int dcol[4] = { 1,-1,0,0 };
int drow[4] = { 0,0,-1,1 };
int solve(int r, int c) {
	int& ret = dp[r][c];
	if (r == row - 1 && c == col - 1) return 1;

	
	if (ret != 0) return ret;
	
	for (int i = 0; i < 4; i++) {
		int nr = r + drow[i];
		int nc = c + dcol[i];

		if(nr < 0 || nc < 0 || row <= nr || col <= nc) continue;
		if (map[nr][nc] >= map[r][c]) continue;
		ret += solve(nr, nc);
	}
	return ret;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	solve(0,0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << dp[i][j] << " ";
		}cout<<"\n";
	}
	cout << dp[0][0];
}