#include<iostream>
#include<vector>
using namespace std;
int n, result;
vector<int>arr;
int dp[100000][2];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	dp[0][0] = arr[0];
	dp[0][1] = 0;
	result = dp[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i] + max(dp[i - 1][0], 0);
		dp[i][1] = max(arr[i] + dp[i - 1][1], dp[i - 1][0]);
		result = max(result, max(dp[i][0], dp[i][1]));
	}
	cout << result;
}
