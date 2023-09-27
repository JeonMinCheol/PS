#include<iostream>
using namespace std;

int cost[3];
int big_sum[3], small_sum[3];
int big_dp[3], small_dp[3];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		big_dp[0] = cost[0] + max(big_sum[0], big_sum[1]);
		big_dp[1] = cost[1] + max(max(big_sum[0], big_sum[1]), big_sum[2]);
		big_dp[2] = cost[2] + max(big_sum[1], big_sum[2]);

		small_dp[0] = cost[0] + min(small_sum[0], small_sum[1]);
		small_dp[1] = cost[1] + min(min(small_sum[0], small_sum[1]), small_sum[2]);
		small_dp[2] = cost[2] + min(small_sum[1], small_sum[2]);

		for (int j = 0; j < 3; j++) {
			big_sum[j] = big_dp[j];
			small_sum[j] = small_dp[j];
		}
	}
	
	// 최대 점수
	int big = 0;
	int small = 999999999;

	//최소 점수
	for (int i = 0; i < 3; i++) {
		if (big < big_sum[i]) big = big_sum[i];
		if (small > small_sum[i]) small = small_sum[i];
	}
	cout << big << " " << small;
}