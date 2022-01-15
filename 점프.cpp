#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long int re = 0;
int map[100][100];
long long  dp[100][100];
bool check[100][100];

void solve() {
	fill_n(&check[0][0], 10000, false);
	check[0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1 || (!check[i][j])) continue;
			int jump = map[i][j];

			if (i + jump < n) {
				dp[i + jump][j] += dp[i][j];
				check[i + jump][j] = true;
			}
			if (j + jump < n) {
				dp[i][j + jump] += dp[i][j];
				check[i][j + jump] = true;
			}
		}
	}
}
int main() {
	cin >> n;	
	fill_n(&dp[0][0], 10000, 0);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << dp[n-1][n-1];
}