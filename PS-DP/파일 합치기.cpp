#include<iostream>
#include<cstring>
using namespace std;

int t, k;
int dp[501][501];
int cost[501];
int sum[501];

int solve(int pos1, int pos2) {
	if (pos1 == pos2) return dp[pos1][pos2] = 0;
	if (pos2 - pos1 == 1) return dp[pos1][pos2] = cost[pos1] + cost[pos2];

	int& ret = dp[pos1][pos2];
	ret = 99999999;
	for (int pv = pos1; pv < pos2; pv++) {
		ret = min(ret, solve(pos1, pv) + solve(pv + 1, pos2) + sum[pos2] - sum[pos1 - 1]);
	}
	return ret;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> k;
		memset(&dp[0][0], 0, sizeof(dp));
		memset(cost, 0, sizeof(cost));
		memset(sum, 0, sizeof(sum));

		for (int i = 1; i <= k; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}

		
		// 1. bottome-up :
		for (int d = 1; d < k; d++) {
			for (int i = 1; i + d <= k; i++) {
				int j = i + d;
				dp[i][j] = 99999999;
				for (int pv = i; pv < j; pv++) {
					dp[i][j] = min(dp[i][j], dp[i][pv] + dp[pv + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[1][k]<<endl;
		
		
		// 2.top-down :
		cout<< solve(1, k)<<endl;
		
		
	}
}