#include<iostream>
#include<vector>
using namespace std;


string s1, s2;
int dp[1001][1001];
int main() {
	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++) {
		char c = s1[i - 1];
		for (int j = 1; j <= s2.size(); j++) {
			char x = s2[j - 1];
			//c와 x가 같지 않은 경우
			if (c != x) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			//같은 경우
			else if (c == x) dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << dp[s1.size()][s2.size()];
}