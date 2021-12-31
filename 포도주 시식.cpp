#include<iostream>
#include<vector>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int>v(n);
	vector<int>dp(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = v[0];
	if (n > 1) dp[1] = v[0] + v[1];
	if (n > 2) dp[2] = max(v[0], v[1]) + v[2];
	if (n > 3) {
		for (int i = 3; i < n; i++) {
			int a = -1, b = -1;
			for (int j = 0; j < i - 2; j++) {
				if (a < dp[j]) a = dp[j];
				if (b < dp[j] + v[i - 1]) b = dp[j] + v[i - 1];
			}
			a = max(a, dp[i - 2]);
			dp[i] = max(a, b) + v[i];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}
	cout << result;
}