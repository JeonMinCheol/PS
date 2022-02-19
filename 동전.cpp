#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int t,n,m;
int coin[20];
int dp[10001];
int main() {
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		cin >> n;
		for (int i = 0; i < n; i++) cin >> coin[i];
		cin >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				if (coin[i] <= j) dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[m] << endl;
	}

	return 0;
}