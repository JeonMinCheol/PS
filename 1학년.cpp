#include<iostream>
#include<vector>
using namespace std;

int n;
long long dt[101], dp[101][901];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> dt[i];

	dp[1][dt[1]] = 1;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j <= i * 9; j++) {
			if (dp[i - 1][j] != 0) {
				if (j - dt[i] >= 0) dp[i][j - dt[i]] += dp[i - 1][j];
				if (j + dt[i] <= 20) dp[i][j + dt[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n-1][dt[n]];
}