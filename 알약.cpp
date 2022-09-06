#include<iostream>
#include<vector>
using namespace std;
int t, n;
long long dp[31][31] = {0};
long long solve(int a, int b) {
	if (dp[a][b] != 0) return dp[a][b];
	else if (a == 0 && b == 0) return 1;

	if (a > 0) dp[a][b] += solve(a - 1, b);
	if (b > 0) dp[a][b] += solve(a + 1, b - 1);
	return dp[a][b];
}
int main() {
	while (true) {
		cin >> n;
		if (n == 0) break;
		solve(1, n - 1);
		cout << dp[1][n - 1]<<endl;
	}
	return 0;
}