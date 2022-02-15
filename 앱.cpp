#include<iostream>
#include<algorithm>
using namespace std;

int n, M, m[101], c[101], dp[101][10001];
int main() {
	cin >> n >> M;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	int result = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j >= c[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
			else dp[i][j] = max(dp[i - 1][j], dp[i][j]);
			if (dp[i][j] >= M) result = min(result, j);
		}
	}
	cout << result;
}