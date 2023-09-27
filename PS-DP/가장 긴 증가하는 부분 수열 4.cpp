#include<iostream>
using namespace std;

int n, a[1001];
pair<int, int>dp[1001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = {1,1};
	if (n == 1) {
		cout << 1 << "\n" << a[1];
		return 0;
	}
	pair<int, int>result;
	int m = 1;
	for (int i = 2; i <= n; i++) {
		int ret = 0, index = i;
		for (int j = 1; j < i; j++) {
			if (dp[j].first > ret && a[i] > a[j]) {
				ret = dp[j].first;
				index = j;
			}
		}
		dp[i].first = ret + 1;
		dp[i].second = index;
		result = result.first > dp[i].first ? result : dp[i];
		if (result.first == dp[i].first) m = i;
	}
	cout << result.first <<endl;
	int arr[1001];
	for (int i = 1; i <= result.first; i++) {
		arr[i] = a[m];
		m = dp[m].second;
	}
	for (int i = result.first; i > 0; i--) {
		cout << arr[i] << " ";
	}
}