#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//물품의 수 ,버틸 수 있는 무게
int n, k;
int coin[100];
int dp[10001];

int main() {
	cin >> n >> k;
	fill_n(dp, k + 1, 1000000001);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 0; i < n; i++) {
		int c = coin[i];
		for (int j = 1; j <= k; j++) {
			if (j == c) dp[j] = 1;
			else if (j > c) dp[j] = min(dp[j],dp[j - c] + 1);
		}
	}

	
	if(dp[k] == 1000000001) cout<<-1;
	else cout << dp[k];
	
}