#include<iostream>
#include<vector>
using namespace std;

int n;
int ti[501];
int dp[501];
int solve(int i , vector<vector<int>>& build) {
	int& ret = dp[i];
	if (ret != 0) return ret;

	if (build[i].size() == 0) return ret = ti[i];
	for (int j = 0; j < build[i].size(); j++) {
		ret = max(ret , solve(build[i][j], build));
	}
	ret += ti[i];
	return ret;
}
int main() {
	cin >> n;
	vector<vector<int>>build(501);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> ti[i];
		while (true) {
			cin >> x;
			if (x == -1) break;
			build[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << solve(i, build) << endl;
	}
}