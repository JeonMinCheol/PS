#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int t, p;
int main() {
	cin >> n;
	vector<pair<int,int>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		v[i] = make_pair(p, t);
	}

	vector<pair<int, int>>dp(n);
	dp[0] = v[0];

	for (int i = 1; i < n; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (dp[j].second <= i) {
				if (m < dp[j].first) m = dp[j].first;
			}
			dp[i] = { v[i].first + m , i + v[i].second };
		}
	}

	int result = 0;
	for (auto elem : dp) {
		if (elem.second > n) continue;
		result = max(result, elem.first);
	}
	cout<<result;
	return 0;
}
