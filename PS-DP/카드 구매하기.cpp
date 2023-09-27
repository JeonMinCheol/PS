#include<iostream>
#include<algorithm>
using namespace std;
int n;
int dp[1000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dp[i];
		if (i > 0) {
			int d = 0;
			for (int j = 0; j < i; j++) {
				d = max(d, dp[j] + dp[i - j - 1]);
			}
			dp[i] = max(dp[i], d);
		}
	}	

	cout << dp[n - 1];
	return 0;
}
