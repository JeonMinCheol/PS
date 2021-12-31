#include<iostream>
#include<vector>
using namespace std;

int t, n;
long long int dp[100] = {0, };
long long int search(int x) {
	long long int& ret = dp[x];
	if (ret > 0) return ret;
	else return ret = search(x - 5) + search(x - 1);
}
int main() {
	cin >> t;
	for (int i = 0; i < 5; i++) {
		if (i < 3) dp[i] = 1;
		else dp[i] = 2;
	}
	while (t--) {
		cin >> n;
		cout << search(n-1)<<endl;
	}
	return 0;
}
