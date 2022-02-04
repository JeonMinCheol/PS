#include<iostream>
using namespace std;

int n, dt[1001], dp[1001] = {1 , 1};
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dt[i];
	}

	int result = 0;
	for (int i = 2; i <= n; i++) {
		int x = 0;
		for (int j = 1; j < i; j++) {
			if ((dt[i] > dt[j]) && x < dp[j]) x = dp[j];
		}
		dp[i] = x + 1;
		if (result < dp[i]) result = dp[i];
	}
	cout << result;
}