#include<iostream>
#include<cmath>
using namespace std;

int n, m;
int box[1001][1001] = {0};
int dp[1001][1001] = {0};
int min(int a, int b) {
	if (a > b) return b;
	return a;
}
int main() {
	cin >> n >> m;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			box[i][j] = int(x) - 48;
			if (box[i][j] == 1) dp[i][j] = 1;
			int minnum = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			dp[i][j] += minnum;
			if (ret < dp[i][j]) ret = dp[i][j];
		}
	}

	if (n == 1 && m == 1) {
		if (box[1][1] == 1) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << ret * ret << endl;
}