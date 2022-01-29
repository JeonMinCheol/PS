#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int t, n, k, w;
int d[1001];
int dp[1001];

int solve(int node, vector<vector<int>>& b) {
	int& ret = dp[node];
	if (ret != -1) return ret;
	else if (b[node].empty()) return ret = d[node];

	ret = 0;
	for (int i = 0; i < b[node].size(); i++) {
		ret = max(ret, d[node] + solve(b[node][i], b));
	}
	return ret;
}
int main() {
	cin >> t;

	while (t--) {
		cin >> n >> k;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
		}

		vector<vector<int>>build(n + 1);
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			build[y].push_back(x);
		}
		cin >> w;
		cout << solve(w, build) << endl;
	}

}