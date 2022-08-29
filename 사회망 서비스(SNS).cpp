#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>>friends;
vector<vector<int>>dp(1000001,vector<int>(2)); // dp[node][0] : node = early  /  dp[node][1] : node = normal
vector<bool>visited;

void setSize(int n) {
	friends.resize(n + 1);
	visited.resize(n + 1);
	// dp.resize(n + 1); dp�� 1���� �迭�� �ʱ�ȭ�Ź���.
}

void solve(int node) { 
	visited[node] = true;
	dp[node][0] = 1;

	for (int i = 0; i < friends[node].size(); i++) {
		int child = friends[node][i];
		if (visited[child]) continue;
		solve(child);

		// early�� �ڽ��� early or normal�̰� , normal�� �ڽ��� ������ early�̴�.
		dp[node][0] = dp[node][0] + min(dp[child][0], dp[child][1]);
		dp[node][1] = dp[node][1] + dp[child][0];
	}
}
int main() {
	cin >> n;
	setSize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	solve(3);
	cout << min(dp[3][0], dp[3][1]) << endl;
}