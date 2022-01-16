#include<iostream>
#include<algorithm>
using namespace std;

int n,i,j;
int map[500][500];
int dp[500][500];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0, 1,-1};
int solve(int row, int col) {
	int& ret = dp[row][col];
	if (ret != 0) return ret;
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		int num = map[row][col];
		
		if (nr < 0 || nc < 0 || n <= nr || n <= nc) continue;
		int n_num = map[nr][nc];
		if (n_num <= num) continue;
		dp[row][col] = max(dp[row][col], solve(nr,nc) + 1); 
	}
	return ret;
}
int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	fill(&dp[0][0], &dp[0][0] + 250000, 0);
	
	int result = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (dp[i][j] == 0) solve(i, j);;
			result = max(result, dp[i][j]);
		}
	}
	
	cout << result;
}
