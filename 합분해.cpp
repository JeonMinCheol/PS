#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
int dp[201][201];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	fill_n(&dp[0][0], 201 * 201, 0);
	//0부분을 전부 1로 초기화
	fill(&dp[0][0], &dp[0][0] + 201, 1);
	dp[0][0] = 0;
	for (int index = 0; index <= n; index++) {
		for (int plus = 0; plus <= n; plus++) {
			if (index + plus == 0) continue;
			for (int count = 0; count < k; count++) {
				
				dp[index + plus][count + 1] += dp[index][count];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << " ";
		}cout << endl;
	}
	cout << dp[n][k];
}