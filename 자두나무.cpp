#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int dp[1000][30], n, w, rs = 0;
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a > b ? b : a;
}
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		int tree;
		cin >> tree;

		// W가 짝수이면 A에 위치.
		for (int j = 0; j <= min(i + 1, w); j++) {
			if ((j % 2 == 0 && tree == 1) || (j % 2 != 0 && tree == 2)) dp[i][j] = 1;
			if (i) {
				if (j == 0) dp[i][j] += dp[i - 1][j];
				else dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			rs = max(dp[i][j], rs);
		}
		cout << endl;
	}
	cout << rs;
}