#include<iostream>
using namespace std;
int arr[5000], dp[5000][2];
string s;

int main() {
	while (cin >> s) {
		memset(arr, 0, sizeof(arr));
		memset(&dp[0][0], 0, sizeof(dp));
		if (s[0] == '0') {
			cout << 0;
			return 0;
		}
		else dp[0][0] = 1, dp[0][1] = 0;

		for (int i = 1; i < s.size(); i++) {

			if (s[i - 1] == '0') {
				if (s[i] != '0')dp[i][0] = dp[i - 1][1], dp[i][1] = 0;
			}
			else {
				if ('0' < s[i] && s[i] <= '9') dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
				if (10 <= (int(s[i - 1]) - 48) * 10 + int(s[i]) - 48 && (int(s[i - 1]) - 48) * 10 + int(s[i]) - 48 <= 26) dp[i][1] = dp[i - 1][0];
			}
			dp[i][0] %= 1000000, dp[i][1] %= 1000000;
		}
		cout << dp[s.size() - 1][0] + dp[s.size() - 1][1]<<endl;
	}
	
}

//ICPC > Regionals > North America > East Central North America Regional > 2004 East Central Regional Contest A¹ø