#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int n, k;
int bag[101][2];
int dp[101][100001];
void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int weight = bag[i][0];
			int value = bag[i][1];

			if (j >= weight) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
			else dp[i][j] = dp[i - 1][j];
		}
	}
}
int main() {
	cin >> n >> k;
	fill_n(&dp[0][0], 101 * 100001, 0);
	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		bag[i][0] = w;
		bag[i][1] = v;
	}
	solve();
	
	cout << dp[n][k];

	return 0;
}