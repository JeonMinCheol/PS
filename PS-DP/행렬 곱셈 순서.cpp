#include<iostream>
using namespace std;

int n;
long long rc[501][2];
long long dp[501][501];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rc[i][0]>>rc[i][1];
	}

	for (int d = 1; d < n; d++) {
		for (int i = 1; d + i <= n; i++) {
			int j = i + d;
			dp[i][j] = 9999999999;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + rc[i][0] * rc[k + 1][0] * rc[j][1]);
			}
			
		}
	}
	
	cout << dp[1][n];
}