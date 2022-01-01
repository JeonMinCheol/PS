#include<iostream>
#include<vector>
using namespace std;
int n, t;
long long int dp[2][100000];
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>>v(2, vector<int>(n));
		for (int i = 0; i < 2 * n; i++) {
			if (i < n) cin >> v[0][i];
			else cin >> v[1][i - n];
		}

		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		if (n > 1) {
			dp[0][1] = dp[1][0] + v[0][1];
			dp[1][1] = dp[0][0] + v[1][1];

			for (int i = 2; i < n; i++) {
				dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
				dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
			}
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]);
	}
	return 0;
}
