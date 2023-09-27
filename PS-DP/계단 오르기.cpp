#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int arr[301] = {};
int dp[300][2];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0][1] = dp[0][2] = 0;
	dp[1][1] = dp[1][2] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][2] + arr[i];
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
	}
	cout << max(dp[n][1], dp[n][2]);
	return 0;
}