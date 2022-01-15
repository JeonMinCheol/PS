#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, re = 2;
int dp[100000][2];
void solve() {
	for (int i = 1; i < n; i++) {
		dp[i][0] += re - dp[i - 1][0];
		dp[i][1] += re - dp[i - 1][1];
		dp[i][0] % 9901;
		dp[i][1] % 9901;

		re += (dp[i][0] + dp[i][1]);
		re %= 9901;
	}
}
int main() {
	cin >> n;
	fill_n(&dp[0][0], 100000 * 2, 1);
	solve();
	
	cout << (re + 1)% 9901;
}