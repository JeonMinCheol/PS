#include<iostream>
#include<cstring>
using namespace std;

int n, m, s, e;
int inp[2001];
int dp[2001][2001];
int solve(int pos1, int pos2) {
	int& ret = dp[pos1][pos2];
	if (ret == 0) return ret;
	if (inp[pos1] != inp[pos2] || dp[pos1 + 1][pos2 - 1] == 0) {
		ret = 0;
		return 0;
	}
	else if (inp[pos1] == inp[pos2]) {
		ret = 1;
		if(pos1 != s && pos2 != e) solve(pos1 - 1, pos2 + 1);
	}
	
	return ret;
}
int main() {
	memset(&dp[0][0], -1, sizeof(dp));
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> inp[i];
	

	cin >> m;
	while (m--) {
		cin >> s >> e;
		int mid = (s + e) / 2;
		if (s == e) {
			cout << 1 << "\n";
			continue;
		}
		else if (dp[s][e] != -1) {
			cout << dp[s][e] << "\n";
			continue;
		}
		if ((s + e) % 2 == 0) cout << solve(mid, mid) << "\n";
		else cout << solve(mid, mid + 1) << "\n";
	}

}
